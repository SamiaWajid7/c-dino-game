## 🦖 Dino Game – Sprint 4 (Final Release)

### ✅ Project Overview

This is a side-scrolling **Dino Game** developed using the **Simple2D** graphics library in C. **Sprint 4** marks the final release of the project, integrating sound effects and refined obstacle generation to deliver a more complete and polished gaming experience.


### ✨ What’s New in Sprint 4

* ✅ **Sound Integration**:

  * 🎵 *Jump sound effect* when the Dino jumps (`jump.wav`)
  * 💥 *Collision sound effect* when the Dino hits an obstacle (`hit.wav`)


* ✅ **Resource Management**:

  * Frees all game assets (images, sounds, and the window) properly at the end of the game.

* ✅ **Code Refactoring & Stability**:

  * Clean and organized code structure with comments for maintainability.
  * Obstacle removal logic updated to prevent glitches when multiple obstacles exit the screen.


### 🧠 Core Game Mechanics

* Press **Spacebar** to make the Dino jump.
* **Collision** with obstacles ends the game.
* Press **R** to restart the game.


### 🎮 Gameplay Features

* 🕹️ **Real-time Jumping and Gravity**
* 🧱 **Pattern-based Obstacle Generation**:

  * *Pattern 1*: Three small obstacles grouped.
  * *Pattern 2*: Two large obstacles.
  * *Pattern 3*: A single large obstacle.
* 🧠 **Randomized but Controlled Spawning Logic** for fair gameplay.
* 📈 **Scoring System**: Score increases with survival time.
* 📛 **Game Over Screen**: Displays message and allows restart via `R` key.
* 🔊 **Sound Effects**: Jump and collision actions play corresponding sounds.


### 📁 Project Files

#### Source Code

* `sprint4.c`: Final game logic including event handling, physics, scoring, sound integration, and rendering.
* `simple2d.h`: External graphics and audio library.

#### Assets

* `pngtree.jpg`: Background image for game window.
* `jump.wav`: Sound when the Dino jumps.
* `hit.wav`: Sound on collision with an obstacle.
* `arialbd.ttf`: Font for displaying score and game over message.
