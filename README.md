# so_long

A small 2D game written in C using the MiniLibX graphics library.

This project is part of the 42 School curriculum. The goal is to create a top-down 2D game where the player navigates a map, collects all collectibles, and exits once all collectibles are gathered. :contentReference[oaicite:1]{index=1}

---

## 📌 Table of Contents

- [About](#about)  
- [Features](#features)  
- [Map Rules](#map-rules)  
- [Requirements](#requirements)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Controls](#controls)  
- [Game Rules](#game-rules)  
- [Project Structure](#project-structure)  
- [License](#license)

---

## 🧠 About

`so_long` is a simple 2D game implemented in C that uses the MiniLibX library to manage window rendering, sprites, and keyboard input. The player must collect all items (`C`) and then reach the exit (`E`) without walking through walls. :contentReference[oaicite:2]{index=2}

---

## 🎯 Features

- Parse and validate map files with `.ber` extension  
- Display using MiniLibX  
- Keyboard input for player movement  
- Collision detection  
- Movement counter printed to terminal  
- Basic game logic (collectibles, finish condition) :contentReference[oaicite:3]{index=3}

---

## 🗺️ Map Rules

Your `.ber` map must:

1. Be a rectangular grid  
2. Be surrounded by walls (`1`)  
3. Include at least one collectible (`C`)  
4. Include one starting position (`P`)  
5. Include one exit (`E`)  
6. Only contain these characters:  
   - `1` — wall  
   - `0` — empty space  
   - `P` — player  
   - `C` — collectible  
   - `E` — exit :contentReference[oaicite:4]{index=4}

Example valid map:

