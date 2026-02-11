*This project has been created as part of the 42 curriculum by vsenniko, chrmarqu.*

# Cube3D

## Description

**Cube3D** is a project inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever implemented. The goal of this project is to create a dynamic view inside a maze using the **Raycasting** technique.

This program parses a scene description file (`.cub`), which includes map layout, texture paths, and floor/ceiling colors. It then opens a graphical window and renders the 3D perspective of the maze, allowing the player to navigate through it.

## Instructions

### Compilation

To compile the project, run the following command at the root of the repository:

```bash
make
```

 This will build the `cub3d` executable, along with the necessary libraries (`libft` and `minilibx`).

### Execution

To run the program, provide a valid `.cub` map file as an argument:

```bash
./cub3D <path_to_map.cub>
```

**Example:**

```bash
./cub3D test.cub
```

### Controls

*   **W / A / S / D**: Move the player.
*   **Left / Right Arrows**: Rotate the camera.
*   **ESC**: Close the window and exit the program.
*   **Red Cross (Window)**: Close the window and exit the program.

## Resources

*   **Raycasting Documentation**: Lodev's Raycasting Tutorial - The primary reference for understanding and implementing the raycasting algorithm.
*   **MiniLibX Documentation**: 42's internal graphics library documentation.
*   **42 Subject**: The official project subject PDF outlining requirements and constraints.

### AI Usage

Artificial Intelligence was used to assist in the development of this project for the following tasks:

*   **Documentation**: AI was used to create this **README.md** file.
*   **Testing**: AI generated test cases to validate map parsing and game logic.
*   **Code Quality**: AI checked the code for possible errors, memory leaks, and norminette compliance issues.
