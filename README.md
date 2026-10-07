*This project has been created as part of the 42 curriculum*

# cub3D

## Description

This project was developed with https://github.com/randosainas.

cub3D is a 3D graphics project inspired by the classic game *Wolfenstein 3D*. It uses **ray casting** to render a first-person view of a maze from a 2D map, using the MiniLibX graphics library. The map, wall textures, and floor and ceiling colors are all loaded from a `.cub` scene file.

## Features

- First-person 3D view rendered with ray casting
- Different wall textures depending on the direction a wall faces (north, south, east, west)
- Configurable floor and ceiling colors
- Map parsing and validation with clear error handling
- Smooth movement and rotation through the maze

## Scene file format

The program takes a `.cub` file as its argument. It defines the textures, the colors, and the map:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

| Element | Meaning |
|---|---|
| `NO` / `SO` / `WE` / `EA` | Path to the texture of the north, south, west, and east walls |
| `F` / `C` | Floor and ceiling color as `R,G,B` (0 to 255) |
| `1` | Wall |
| `0` | Empty space |
| `N` / `S` / `E` / `W` | Player start position and the direction they face |

The map must be **closed**, meaning surrounded by walls, and contain exactly one player start position. Invalid scene files print an error and the program exits.

Sample maps are available in `maps/`.

## Instructions

### Requirements

- **macOS** (the Makefile links the `OpenGL` and `AppKit` frameworks)
- A C compiler (`cc`) and `make`
- The MiniLibX library, included in `minilibx/`

### Build

```bash
make          # builds libft, MiniLibX and the cub3D executable
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # rebuilds everything
```

### Run

```bash
./cub3D maps/<map_name>.cub
```

### Controls

| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Move left / right |
| `←` / `→` | Turn left / right |
| `ESC` | Quit |

## Project structure

```
.
├── Makefile
├── includes/    # header files
├── srcs/        # main source code
├── gnl/         # get_next_line, used to read the scene file
├── libft/       # personal C library
├── minilibx/    # MiniLibX graphics library
├── maps/        # sample .cub scene files
└── textures/    # wall textures
```

## Resources

- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- The 42 cub3D subject PDF
