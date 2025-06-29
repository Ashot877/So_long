# 🐬 So Long — 42 Yerevan project

**"So Long and thanks for all the fish!"**
A simple 2D game made with **MiniLibX**, where the player must collect all collectibles and reach the exit.
This project is part of the core curriculum at [School 42 Yerevan](https://42yerevan.am).

---

## 📜 Description

This game involves:

* Top-down 2D rendering
* Reading and validating a `.ber` map
* Handling keyboard input (WASD)
* Drawing with textures and sprites using MiniLibX
* Bonus features like enemies and animations *(optional)*

---

## 🚀 How to Run

1. Compile the game:

   ```bash
   make
   ```

2. Run the game with a map:

   ```bash
   ./so_long maps/map1.ber
   ```

---

## 🗺️ Map Format (`.ber`)

Each map must:

* Be rectangular and surrounded by walls (`1`)
* Contain exactly one player start (`P`), at least one collectible (`C`) and one exit (`E`)
* Use only: `0` (empty), `1` (wall), `C`, `E`, `P`

Example:

```
11111  
1P0C1  
10001  
1E001  
11111  
```

---

## 📚 Documentation

* 🇬🇧 [English version](https://github.com/Ashot877/So_long/blob/main/english.md)
* 🇦🇲 [Հայերեն տարբերակ](https://github.com/Ashot877/So_long/blob/main/armenian.md)

---

## ✅ Mandatory Features

* ✅ Map reading and validation
* ✅ Movement (WASD)
* ✅ Step counter in terminal
* ✅ Graphical rendering via MiniLibX
* ✅ Exit and win condition

---

## 🌟 Bonus Features *(optional)*

* ❗ Enemies / patrols
* 🎞️ Sprite animation
* 🧮 Move count displayed on screen
* 🎵 Sound effects (if added manually)

---

## 🧑‍💻 Author

* **Ashot Mkrtchyan**
  [42 Yerevan GitHub Profile](https://github.com/Ashot877)

---

## 📄 License

Project is subject to the 42 school license. Assets (if any) must respect creators’ licenses from sources such as [itch.io](https://itch.io).
