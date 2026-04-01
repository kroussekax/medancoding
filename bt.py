import serial

bt = serial.Serial('COM6', 115200)  # change to your COM port

def send_command(command, value):
    bt.write(bytes([command, value]))

send_command(1, 25)   # Set Kp = 25
send_command(3, 10)   # Set Ki = 10
send_command(5, 8)    # Set Kd = 8
send_command(7, 1)    # Turn robot ON
