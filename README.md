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
make
./doublepen

### Windows
1. Install SFML and configure your environment
2. Open the project in your IDE (e.g. Visual Studio)
3. Link SFML (graphics, window, system)
4. Build & run
```

---

🎮 Controls

Key / Mouse         | Action
--------------------|---------------------------------------------------------
ESC                 | Exit application
Space               | Toggle between simulation and manual mode
← / →               | Decrease / increase simulation speed
Mouse drag          | Click and drag either pendulum mass

---

📁 Project Structure

DoublePendulum/
├── main.cpp          # Entry point
├── Pendulum.hpp/.cpp # Simulation and rendering logic
├── Trail.hpp/.cpp    # Trail rendering system
├── CMakeLists.txt    # Optional CMake build file
└── README.md

---

🌱 Future Plans

- [ ] ImGui interface for real-time parameter adjustment
- [ ] Save/load preset configurations
- [ ] Export to image/GIF
- [ ] Multi-pendulum chaos visualization

---

📸 Preview

A preview GIF or screenshot can be added here after running the simulation.

---

🤝 Contributing

Pull requests are welcome! If you’d like to add a feature, refactor the code, or improve visuals, feel free to fork and submit a PR.

