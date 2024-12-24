# Rotating Cube with SDL2

This project renders a 3D rotating cube in a 2D window using SDL2. The cube is implemented with basic 3D math and transformations.

## Features
- Real-time 3D rotation of a cube.
- Perspective projection for realistic depth.
- Simple SDL2 rendering pipeline.

## Requirements
- **Clang** (Version 11 or higher)
- **SDL2**
- **CMake** (Version 3.16 or higher)

## Folder Structure
- `src/`: Contains all source and header files for the project.
- `build/`: Contains the compiled files (ignored by `.gitignore`).
- `CMakeLists.txt`: CMake configuration file.

## How to Compile
1. Install the required dependencies:
   - On **Arch Linux**:
     ```bash
     sudo pacman -S sdl2 cmake clang
     ```
   - On **Debian/Ubuntu**:
     ```bash
     sudo apt install libsdl2-dev cmake clang
     ```

2. Clone the repository and navigate to the project root:
   ```bash
   git clone <repository-url>
   cd <repository-folder>

3. Create the build folder and init cmake:
   ```bash
    mkdir build
    cmake -S ./src -B ./build

4. Run the program
   ```bash
    make && ./rotating_cube
