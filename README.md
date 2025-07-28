# 🌀 Double Pendulum Visualizer

A C++ application for simulating and visualizing the chaotic behavior of a double pendulum in real-time using SFML.

<p align="center">
  <img src="preview.gif" alt="Double Pendulum Simulation Preview" width="500"/>
</p>

---

## 📦 Features

- ✅ **Realistic Physics Simulation** using Lagrangian mechanics
- 🎮 **Interactive Mode** – click & drag pendulum masses to set custom positions
- 🔁 **Simulation Mode** – toggle between real-time simulation and manual control
- 🖍️ **Visual Trails** that trace the path of the second pendulum
- ⏩ **Adjustable Speed** using keyboard shortcuts (`←` and `→`)
- 🧱 **Modular C++ Codebase** for easy expansion (ImGui, exports, etc.)

---

## 🔧 Installation

### Requirements:
- C++17 compatible compiler
- [SFML 2.5+](https://www.sfml-dev.org/)

### Ubuntu (Linux)
```bash
sudo apt install libsfml-dev g++
git clone https://github.com/yourusername/double-pendulum.git
cd double-pendulum
make run  # or cmake . && make
