# Connect-Four
This is a C++ implementation of the classic Connect Four game. The game features a console-based interface and allows players to compete against each other or against an AI opponent.

## How to Compile and Run
To compile the code, you need to have a C++ compiler installed on your system, such as g++. From the terminal, navigate to the directory containing the source code files (puissance4.cpp and puissance4.h) and execute the following command:

```bash
g++ -o puissance4.exe puissance4.cpp
````
This will compile the code and generate an executable file named puissance4.exe. You can then run the executable to start the game:
```bash
./puissance4.exe
````

## How to Play
Before starting the game of Connect Four, you'll need to input a height (not exceeding 10), which will determine the complexity of the algorithm. The higher the height, the more trained and challenging the AI will be to beat.
The game follows the standard rules of Connect Four. Players take turns dropping colored discs into a grid. The discs fall straight down, occupying the lowest available space within the chosen column. The objective is to be the first to form a horizontal, vertical, or diagonal line of four discs of your color.
To select a column to drop your disc, enter the column number when prompted.
The game will alternate between players, and the AI opponent will automatically make its move.

## Screenshot

![Connect Four](game.png)

### Have fun playing Connect Four!

Feel free to customize and extend the code as needed. If you encounter any issues or have suggestions for improvements, please don't hesitate to open an issue on GitHub. Contributions are welcome!
