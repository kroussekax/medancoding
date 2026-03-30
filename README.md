# S4YAP

> Projek line follower untuk kompetisi Medan Coding 2026

## 💻 Technologies ✨

- [`Git`](https://git-scm.com) -> Version control yang digunakan

- [`Platform.io`](https://platformio.org) -> Software untuk flash dan monitor microcontroller

- `C++` -> Programming language yang digunakan

- [`Neovim`](https://neovim.io) -> Texteditor yang digunakan

- [`Proportional-Integral-Derivative`](https://https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller) -> Feedback loop mechanism

- [`ESP32`](https://www.espressif.com/en/products/socs/ESP32) -> Microcontroller yang digunakan

- [`L298N Motor Driver`](https://components101.com/modules/l293n-motor-driver-module) -> Motor Driver H-Bridge yang digunakan

- `Dinamo Generic` -> Hardware untuk menggerakkan motor

- `ESP32 30pin Extension Board` -> Hardware untuk menambah pin yang ada di ESP32

- `Baterai 18650 3x` -> Baterai yang digunakan untuk robot line follower

- `Infrared Sensor 5x` -> Sensor infrared yang digunakan untuk mendeteksi garis

- `Kabel jumper, Breadboard, dan semacamnya` -> Hardware yang digunakan untuk wiring dan semacamnya

- [`Chassis robot 2wd`](https://components101.com/modules/l293n-motor-driver-module) -> Chassis yang digunakan untuk line follower

## 🪐 Features 🦄

- Menggunakan 5 IR sensor sebagai alternatif dari IR array sensor yang memiliki harga yang cukup mahal

- Menggunakan Teknologi Proportional-Integral-Derivative (PID) yaitu mekanisma feedback loop yang mengkakulasikan corrections berdasarkan error antara posisi yang diinginkan dan posisi nyata. Untuk kasus line follower ini, PID digunakan untuk terus menerus mengoreksi kecepatan motor untuk menjaga robot tetap berada di tengah garis

- 

## ⌨️ How to Make 💨

- Assembly chassis, roda, dan motor.

- Tempel busa di bawah motor driver, ESP extension pin, dan socket battery sebagai safety meassure. Tempel motor driver di antara motor, ESP di depannya, battery socket di depannya. Terakhir, tempel dua breadboard bagian sampingnya (+ dan -) di samping kanan kiri battery socket sekalian baterainya. Tempel 5 IR sensor di paling depan chassis

- Flash code dari src/ ke ESP32 dengan USB type C.

- Enjoy !!!

## ⏰ The Process ‼️

I started using Nix right around the end of 2025 and immidietly tried out HomeManager. I fell in love with the concept and continuesly use it until now. There has been issues like the learning curve but I think it's all very worthi t. I can't imagine a life without Nix and/or HomeManager. The biggest and most noticable part of this HM config is ofcourse its hyprland config. I'm using a slightly modifed version of Axenide/ambxst for the hyprland shell and its just amaaxing. Althought, there was some isseus with conflicting apps and ongoing issues with conflicting keybinds

## 📔 What I Learned 🧠

