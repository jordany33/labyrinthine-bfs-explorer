# WaveFront Pathfinding Implementation

This project provides an implementation of the WaveFront pathfinding algorithm using C++.

## Table of Contents

- [Overview](#overview)
- [Structures](#structures)
- [Key Functions](#key-functions)
- [Usage](#usage)
- [License](#license)

## Overview

The WaveFront algorithm is a pathfinding algorithm that uses a breadth-first search to find the shortest path from a starting point to a goal. This implementation provides a clear demonstration of the algorithm in a grid environment where some cells are impassable.

## Structures

- `Position`: A simple structure to store the x and y coordinates.
  
- `Environment`: This structure aggregates the following:
  - `arry`: A 2D integer array that represents the grid.
  - `characterArray`: A 2D character array that represents the resultant path.
  - `visited`: A 2D boolean array to keep track of visited nodes.
  - `width` and `height`: Dimensions of the grid.

## Key Functions

- `initialize2DArray`: Initializes a 2D array of any given type.
  
- `release2DArray`: Releases (deallocates) a 2D array from memory.
  
- `promptForPosition`: Prompts the user for either the start or goal position.
  
- `bfsIsValid` and `pathIsValid`: Validate potential moves within the grid.
  
- `BreadthFirstSearch`: Implements the BFS part of the WaveFront algorithm.
  
- `findPath`: Finds and marks the shortest path from the start to the goal.
  
- `resultArray`: Sets up the visual representation of the result grid.
  
- `printToFile`: Outputs the environment and result arrays to a file.

## Usage

1. Clone the repository.
2. Compile and run the program.
3. Follow the on-screen prompts to input the grid dimensions, impassable terrain percentage, goal position, and start position.
4. The program will display the grid environment and the shortest path (if available).
5. Results are also saved to a file named "wave.txt".

## License

This project is open source and available under the [MIT License](LICENSE).

