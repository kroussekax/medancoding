# Home-Manager

> This is my personal NixOS HM configuration with minimal packages, optimal configurations, and clean code (or at least i try)

## 💻 Technologies ✨

- [`Git`](https://nix-community.github.io/home-manager/) -> Version control yang digunakan

- [`Platform.io`](https://nix-community.github.io/home-manager/) -> Software untuk flash dan monitor microcontroller

- [`C++`](https://nix-community.github.io/home-manager/) -> Programming language yang digunakan

- [`Neovim`](https://nix-community.github.io/home-manager/) -> Texteditor yang digunakan

- [`Proportional-Integral-Derivative`](https://nix-community.github.io/home-manager/) -> Feedback loop mechanism

- [`ESP32`](https://nix-community.github.io/home-manager/) -> Microcontroller yang digunakan

- [`L298N Motor Driver`](https://nix-community.github.io/home-manager/) -> Motor Driver H-Bridge yang digunakan

- [`Dinamo Generic`](https://nix-community.github.io/home-manager/) -> Hardware untuk menggerakkan motor

- [`ESP32 30pin Extension Board`](https://nix-community.github.io/home-manager/) -> Hardware untuk menambah pin yang ada di ESP32

- [`Baterai 18650 3x`](https://nix-community.github.io/home-manager/) -> Baterai yang digunakan untuk robot line follower

- [`REES52 Infrared Sensor 5x`](https://nix-community.github.io/home-manager/) -> Sensor infrared yang digunakan untuk mendeteksi garis

- [`Kabel jumper, Breadboard, dan semacamnya`](https://nix-community.github.io/home-manager/) -> Hardware yang digunakan untuk wiring dan semacamnya

- [`Chassis robot 2wd`](https://nix-community.github.io/home-manager/) -> Chassis yang digunakan untuk line follower

## 🪐 Features 🦄

Every apps are configured in their own file. For example, the hyprland config is stored neatly in modules/hyprland.nix and same goes for other apps. This allows for a more clean code enviorement and easier code to debug in general

## ⌨️ Keyboard Shortcuts 💨

The majority of shortcuts can be found in modules/hyprland.nix. I purposely made them vim based because thats just what I'm used to. Altough. there are in fact issues with conflicting keybinds between hyprland and ambxst. 

## ⏰ The Process ‼️

I started using Nix right around the end of 2025 and immidietly tried out HomeManager. I fell in love with the concept and continuesly use it until now. There has been issues like the learning curve but I think it's all very worthi t. I can't imagine a life without Nix and/or HomeManager. The biggest and most noticable part of this HM config is ofcourse its hyprland config. I'm using a slightly modifed version of Axenide/ambxst for the hyprland shell and its just amaaxing. Althought, there was some isseus with conflicting apps and ongoing issues with conflicting keybinds

## 📔 What I Learned 🧠

