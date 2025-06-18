# c-dino-game

A simple side-scrolling Dino Runner game built in C using the [Simple2D](https://github.com/simple2d/simple2d)  game development library.

## 🎮 Features

- Smooth jumping physics
- Procedurally generated obstacle patterns (logs, cacti, rocks)
- Increasing score as you survive
- Collision detection with sound effects
- Game Over screen with restart option
- Basic background and sprite images

---

## 🧰 Prerequisites

✅ You must have the following installed:

- [MSYS2 64-bit](https://www.msys2.org/)
- `simple2d` installed via MSYS2

To install Simple2D (if not already done):
```
pacman -Syu        # First time only: update system and restart terminal
pacman -S mingw-w64-x86_64-simple2d
```

## 📸 Preview

https://github.com/user-attachments/assets/9a526d99-d2fe-4d07-a947-a3e90b4ad4bd

---

## 🚀 How to Run

### 1. Install Simple2D

Follow the [Simple2D installation guide](https://github.com/simple2d/simple2d#install) based on your OS

### 2. Build the Game
In the MSYS2 64-bit terminal, navigate to your project folder:

```
cd /c/Users/YourName/path/to/game
simple2d build dino.c
```

### 3. Run the Game
```
./dino.exe
```
---

## 🕹 Controls

* **Space** – Jump
* **R** – Restart after Game Over

---

## 📁 Assets Required

Ensure the following files are in the project directory:

* `bg4.jpg` – Background image
* `dinonew.png` – Dino sprite
* `log.png` – Log obstacle
* `cactus.png` – Cactus obstacle
* `rock1.png` – Rock obstacle
* `jump.wav` – Jump sound
* `hit.wav` – Collision sound
* `arialbd.ttf` – Font file for text display

---

## 🛠 Project Structure

```
dino_game/
│
├── dino_game.c          # Main game logic
├── bg4.jpg              # Background image
├── dinonew.png          # Dino sprite
├── log.png              # Obstacle image
├── cactus.png           # Obstacle image
├── rock1.png            # Obstacle image
├── jump.wav             # Jump sound effect
├── hit.wav              # Hit/collision sound
├── arialbd.ttf          # Font used for text
└── README.md            # Project documentation
```

---

## 📄 License

This project is for educational purposes and personal use. You may modify and redistribute it freely.

---

## ✍️ Author

Created by SAMIA WAJID – A fun C-based game project using Simple2D.

---

