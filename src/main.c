#include <stdio.h>
#include <webots/distance_sensor.h>
#include <webots/led.h>
#include <webots/light_sensor.h>
#include <webots/motor.h>
#include <webots/robot.h>

// -------------------- DEFINES --------------------
#define TRUE 1
#define FALSE 0
#define NO_SIDE -1
#define LEFT 0
#define RIGHT 1
#define TIME_STEP 32

// -------------------- PID --------------------
float Kp = 0.6;
float Ki = 0.0;
float Kd = 0.2;

float error = 0;
float previous_error = 0;
float integral = 0;
float derivative = 0;

// -------------------- SENSORS --------------------
#define NB_DIST_SENS 8
WbDeviceTag ps[NB_DIST_SENS];
int ps_value[NB_DIST_SENS];

#define NB_GROUND_SENS 3
#define GS_LEFT 0
#define GS_CENTER 1
#define GS_RIGHT 2
WbDeviceTag gs[NB_GROUND_SENS];
unsigned short gs_value[NB_GROUND_SENS];

// -------------------- MOTORS --------------------
WbDeviceTag left_motor, right_motor;

// -------------------- MODULE OUTPUTS --------------------
int lfm_speed[2];
int oam_speed[2];
int ofm_speed[2];
int lem_speed[2];

// -------------------- FLAGS --------------------
int oam_active = FALSE;
int oam_side = NO_SIDE;
int ofm_active = FALSE;
int lem_active = FALSE;

// ============================================================
// 🔵 LINE FOLLOWING MODULE (PID VERSION)
// ============================================================
void LineFollowingModule(void) {
  // Error: difference between left and right sensors
  error = (float)(gs_value[GS_LEFT] - gs_value[GS_RIGHT]);

  // Normalize (important for stability)
  error = error / 1000.0;

  // PID
  integral += error;
  derivative = error - previous_error;

  float correction = (Kp * error) + (Ki * integral) + (Kd * derivative);

  previous_error = error;

  int base_speed = 200;

  lfm_speed[LEFT] = base_speed - correction * 100;
  lfm_speed[RIGHT] = base_speed + correction * 100;
}

// ============================================================
// 🔵 OBSTACLE AVOIDANCE (UNCHANGED)
// ============================================================
void ObstacleAvoidanceModule(void) {
  oam_active = FALSE;

  if (ps_value[0] > 80 || ps_value[7] > 80) {
    oam_active = TRUE;

    if (ps_value[0] > ps_value[7]) {
      oam_side = RIGHT;
      oam_speed[LEFT] = 150;
      oam_speed[RIGHT] = -150;
    } else {
      oam_side = LEFT;
      oam_speed[LEFT] = -150;
      oam_speed[RIGHT] = 150;
    }
  } else {
    oam_speed[LEFT] = 0;
    oam_speed[RIGHT] = 0;
  }
}

// ============================================================
// 🔵 OBSTACLE FOLLOWING (UNCHANGED)
// ============================================================
void ObstacleFollowingModule(int side) {
  if (side != NO_SIDE) {
    ofm_active = TRUE;
    if (side == LEFT) {
      ofm_speed[LEFT] = -100;
      ofm_speed[RIGHT] = 100;
    } else {
      ofm_speed[LEFT] = 100;
      ofm_speed[RIGHT] = -100;
    }
  } else {
    ofm_active = FALSE;
    ofm_speed[LEFT] = 0;
    ofm_speed[RIGHT] = 0;
  }
}

// ============================================================
// 🔵 LINE ENTERING MODULE (SIMPLIFIED)
// ============================================================
void LineEnteringModule(void) {
  if (gs_value[GS_CENTER] < 500) {
    lem_active = TRUE;
    lem_speed[LEFT] = 100;
    lem_speed[RIGHT] = 100;
  } else {
    lem_active = FALSE;
  }
}

// ============================================================
// 🔴 MAIN
// ============================================================
int main() {
  wb_robot_init();

  // Init sensors
  char name[20];
  for (int i = 0; i < NB_DIST_SENS; i++) {
    sprintf(name, "ps%d", i);
    ps[i] = wb_robot_get_device(name);
    wb_distance_sensor_enable(ps[i], TIME_STEP);
  }

  for (int i = 0; i < NB_GROUND_SENS; i++) {
    sprintf(name, "gs%d", i);
    gs[i] = wb_robot_get_device(name);
    wb_distance_sensor_enable(gs[i], TIME_STEP);
  }

  // Init motors
  left_motor = wb_robot_get_device("left wheel motor");
  right_motor = wb_robot_get_device("right wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);

  wb_motor_set_velocity(left_motor, 0);
  wb_motor_set_velocity(right_motor, 0);

  // MAIN LOOP
  while (wb_robot_step(TIME_STEP) != -1) {

    // Read sensors
    for (int i = 0; i < NB_DIST_SENS; i++)
      ps_value[i] = wb_distance_sensor_get_value(ps[i]);

    for (int i = 0; i < NB_GROUND_SENS; i++)
      gs_value[i] = wb_distance_sensor_get_value(gs[i]);

    int speed[2];

    // ---------- SUBSUMPTION ----------

    // 1. Line Following (PID)
    LineFollowingModule();
    speed[LEFT] = lfm_speed[LEFT];
    speed[RIGHT] = lfm_speed[RIGHT];

    // 2. Obstacle Avoidance
    ObstacleAvoidanceModule();

    // 3. Obstacle Following
    ObstacleFollowingModule(oam_side);

    if (oam_active || ofm_active) {
      speed[LEFT] = oam_speed[LEFT] + ofm_speed[LEFT];
      speed[RIGHT] = oam_speed[RIGHT] + ofm_speed[RIGHT];
    }

    // 4. Line Entering
    LineEnteringModule();

    if (lem_active) {
      speed[LEFT] = lem_speed[LEFT];
      speed[RIGHT] = lem_speed[RIGHT];
    }

    // ---------- APPLY SPEED ----------
    wb_motor_set_velocity(left_motor, 0.00628 * speed[LEFT]);
    wb_motor_set_velocity(right_motor, 0.00628 * speed[RIGHT]);
  }

  wb_robot_cleanup();
  return 0;
}