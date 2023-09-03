# LabyrinthineBFSExplorer

An advanced C++ grid-based pathfinding simulation that harnesses the Breadth First Search technique, adeptly navigating through intricate mazes and obstructions to chart the most optimal course from origin to destination.

## Table of Contents

- [Overview](#overview)
- [Structures](#structures)
- [Key Functions](#key-functions)
- [Usage](#usage)
- [License](#license)

## Overview

LabyrinthineBFSExplorer is a pathfinding simulation that employs a breadth-first search approach to determine the shortest route from a starting point to a destination. The simulation offers a detailed representation of the algorithm's execution in a grid environment, accounting for cells that are deemed impassable.

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
  
- `BreadthFirstSearch`: Implements the BFS to explore the grid and mark distances.
  
- `findPath`: Identifies and highlights the shortest path from the start to the goal.
  
- `resultArray`: Constructs the visual representation of the result grid.
  
- `printToFile`: Outputs the environment and result arrays to a file.

## Usage

1. Clone the LabyrinthineBFSExplorer repository.
2. Compile and initiate the program.
3. Follow the on-screen guidelines to input the grid dimensions, the percentage of impassable terrain, the goal position, and the starting point.
4. The simulator will visualize the grid environment and the shortest pathway.
5. The outcomes are also archived in a file titled "labyrinthine.txt".

## License

LabyrinthineBFSExplorer is open source and accessible under the [MIT License](LICENSE).
