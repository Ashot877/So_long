# Project: so_long

## 📌 Goal
Create a simple 2D game using the MiniLibX library where the player collects all collectibles and reaches the exit.

## 🎮 Game Rules
- Player is controlled with W, A, S, D keys.
- Goal is to collect all `C` and reach the `E` (exit).
- Player cannot walk through walls (`1`).
- Every move prints the current movement count in the terminal.
- Map is read from a `.ber` file passed as an argument.

## 🧱 Map Elements
The map uses:
- `0` — empty space
- `1` — wall
- `C` — collectible
- `E` — exit
- `P` — player's starting point
  
## 🖼️ Graphics
- Uses MiniLibX
- A window displays the game
- ESC or window close button quits the game cleanly
- Image is refreshed on every move
