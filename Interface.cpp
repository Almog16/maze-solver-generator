#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Interface.h"


void Interface::menu()
{
	cout << "Maze: 1) From input 2) Random" << endl;
	menuOptions();
}

void Interface::menuOptions()
{
	int option;
	unsigned int rows, cols;

	cin >> option;
	cin.ignore();
	switch (option)
	{
	case 1:
		readMaze(rows, cols);
		solveTheMaze = new solveMaze(maze, rows, cols);
		deleteMaze(rows);
		delete solveTheMaze;
		break;
	case 2:
		readCreateMazeDimension(rows, cols);
		createTheMaze = new createMaze(rows, cols);
		maze = createTheMaze->getMaze();
		solveTheMaze = new solveMaze(maze, rows, cols);
		delete createTheMaze;
		delete solveTheMaze;
		break;
	}
}

void Interface::readSolveMazeDimension(unsigned int& rows, unsigned int& cols)
{
	cin >> rows;
	if (rows > 25)
		failInterface();
	cin >> cols;
	if (cols > 80)
		failInterface();
}

void Interface::readCreateMazeDimension(unsigned int& rows, unsigned int& cols)
{
	cin >> rows;
	if (isEven(rows))
		failInterface();
	else if (rows > 25)
		failInterface();
	cin >> cols;
	if (isEven(cols))
		failInterface();
	else if (cols > 80)
		failInterface();
}

void Interface::readMaze(unsigned int& rows, unsigned int& cols)
{
	readSolveMazeDimension(rows, cols);
	this->maze = new char*[rows];
	for (unsigned int i = 0; i < rows; i++)
		maze[i] = new char[cols + 1];
	cin.ignore();
	for (unsigned int i = 0; i < rows; i++)
	{

		cin.getline(maze[i], cols + 1);
		if (strlen(maze[i]) != cols) //the length is invalid
			failInterface();
		else //the length is valid, now we will run the rest of the validation
		{
			if (!validateRow(maze[i], i, rows, cols))
				failInterface();
		}
	}

}

void Interface::failInterface()
{
	cout << "invalid input" << endl;
	exit(1);
}

bool Interface::validateRow(const char* row, unsigned int rowIndex, unsigned int rows, unsigned int cols)
{
	bool rowIsValid = true;
	for (unsigned int col = 0; col < cols; col++)
	{
		if (rowIndex == 0 || rowIndex == rows - 1) {
			if (row[col] != '*')
				rowIsValid = false;
		}
		else if ((rowIndex == 1 && col == 0) || (rowIndex == rows - 2 && col == cols - 1)) {
			if (row[col] != ' ')
				rowIsValid = false;
		}
		else if ((col == 0) || (col == cols - 1)) {
			if (row[col] != '*')
				rowIsValid = false;
		}
		else if ((row[col] != ' ') && (row[col] != '*'))
			rowIsValid = false;
	}
	return rowIsValid;
}

void Interface::deleteMaze(unsigned int rows) {
	for (unsigned int i = 0; i < rows; ++i)
		delete[] this->maze[i];
	delete[] this->maze;
}

bool Interface::isEven(unsigned int num)
{
	return(num % 2 == 0);
}
