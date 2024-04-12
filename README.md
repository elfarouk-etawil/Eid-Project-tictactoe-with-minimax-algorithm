# Tic Tac Toe with Minimax Algorithm

## Introduction

This project is a command-line implementation of the classic game Tic Tac Toe. It features an AI opponent powered by the Minimax algorithm, providing a challenging gaming experience.

## Features

- **Minimax Algorithm**: The computer opponent utilizes the Minimax algorithm to make optimal moves.
- **Interactive Gameplay**: Players can make their moves by entering numbers corresponding to board positions.
- **Dynamic Board Display**: The game displays the current board state after each move.
- **Win Detection**: The game detects wins, losses, and ties, providing feedback to the player.
- **Unbeatable AI**: Due to the Minimax algorithm, the AI is unbeatable when playing optimally.

## Usage

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Follow the on-screen instructions to play the game.
4. Enter a number (1-9) to make your move.
5. Try to force a tie against the unbeatable AI!

## Files

- **main.cpp**: Contains the main function and the game loop.
- **board.h**: Defines functions related to the game board.
- **computer.h**: Implements the Computer class with the Minimax algorithm.

## Dependencies

- This project relies only on standard C++ libraries and does not require any external dependencies.

## Minimax Algorithm

The Minimax algorithm is a decision-making algorithm commonly used in two-player turn-based games. In the context of Tic Tac Toe, it allows the computer opponent to analyze all possible future moves and choose the best one, assuming that the opponent also plays optimally. This ensures that the computer always makes the best move possible, making it impossible for the player to win in perfect play scenarios.


![alt text](https://www.sciencebuddies.org/b7jHYJK9CDgSwyDTWcXqSKw4noc=/750x418/-/https/www.sciencebuddies.org/cdn/Files/20103/5/game-tree-tic-tac-toe.png)
