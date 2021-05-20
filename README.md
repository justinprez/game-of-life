# Conway's Game of Life

This project is a C++ implementation of the Game of Life. This zero-player game is a cellular automaton invented by Cambridge mathmatician John Conway in 1970. The evolution of the game depends on the initial state, and the cells form various patterns throughout the course of the game. You interact with the game by creating the initial configuration and observing how it evolves.

The Game of Life involves an infinite two-dinmensional orthogonal grid of square cells, with each cell existing in one of two state, _live_ or _dead_. Each cell interacts with 8 neighbouring cells (horizontally, vertically, or diagonally). At each step in time, the following transitions occur:

1. Any live cell with two or three live neighbours survives.
2. Any dead cell with three live neighbours becomes a live cell.
3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

With the initial pattern acting as the seed, the subsequent generations are pure functions of the preceding one. The rules are continually applied to create further generations and in some cases produce patterns with particular properties as shown below.

