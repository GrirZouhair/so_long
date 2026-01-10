# 🎮 so_long

A simple 2D game built with the MiniLibX graphics library as part of the 42 school curriculum.

## 📖 Description

**so_long** is a small 2D game where the player must collect all collectibles on a map and reach the exit. The project introduces basic game development concepts including sprite rendering, event handling, and map parsing using the MiniLibX library.

## 🎯 Objectives

- Create a functional 2D game using MiniLibX
- Parse and validate `.ber` map files
- Handle keyboard events for player movement
- Implement game logic (collectibles, exit, walls)
- Display movement count

## 🛠️ Installation

### Prerequisites

- GCC compiler
- Make
- MiniLibX library
- X11 development libraries (Linux)

### Clone & Build

```bash
git clone https://github.com/GrirZouhair/so_long.git
cd so_long
make
```

## 🚀 Usage

```bash
./so_long maps/map.ber
```

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Exit game |

## 🗺️ Map Format

Maps must be `.ber` files with the following specifications:

### Characters

| Character | Description |
|-----------|-------------|
| `1` | Wall |
| `0` | Empty space |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

### Rules

- Map must be rectangular
- Map must be surrounded by walls (`1`)
- Must contain exactly **1** player (`P`)
- Must contain exactly **1** exit (`E`)
- Must contain at least **1** collectible (`C`)
- A valid path must exist to collect all items and reach the exit

### Example Map

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 📁 Project Structure

```
so_long/
├── Makefile
├── includes/
│   └── so_long.h
├── srcs/
│   ├── main.c
│   ├── parsing/
│   │   ├── map_parser.c
│   │   ├── map_validator.c
│   │   └── path_checker.c
│   ├── game/
│   │   ├── game_init.c
│   │   ├── player_movement.c
│   │   └── render.c
│   └── utils/
│       ├── error_handling.c
│       └── free_memory.c
├── textures/
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── player.xpm
│   ├── collectible.xpm
│   └── exit.xpm
├── maps/
│   └── *.ber
└── libft/
```

## ✨ Features

- **Map Validation**: Comprehensive error checking for map files
- **Flood Fill Algorithm**: Validates that all collectibles and exit are reachable
- **Move Counter**: Displays number of movements in terminal
- **Clean Exit**: Proper memory management on window close or ESC

## 🎨 Bonus Features (Optional)

- Enemy patrols that cause game over on collision
- Sprite animations
- On-screen move counter display

## 🧪 Testing

Test with various map configurations:

```bash
# Valid map
./so_long maps/valid.ber

# Invalid maps (should display error)
./so_long maps/no_exit.ber
./so_long maps/not_rectangular.ber
./so_long maps/no_path.ber
```

## 📚 Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)

## 👤 Author

**Zouhair Grir**
- GitHub: [@GrirZouhair](https://github.com/GrirZouhair)
- 42 Intra: zgrir

## 📄 License

This project is part of the 42 school curriculum.

---

*Made with ❤️ at 42*
