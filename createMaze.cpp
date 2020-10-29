#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "createMaze.h"

createMaze::createMaze(unsigned int rows, unsigned int cols)
{
    logicNeighborsArraySize=0;
	createNewMaze(rows, cols);
	setRows(rows);
	setCols(cols);
	initMaze();

	cout << endl;
	buildMaze();
	printMaze();

}

createMaze::~createMaze()
{
	deleteMaze();
}

bool createMaze::setRows(unsigned int rows)
{
	this->rows = rows;
	return true; 
}

bool createMaze::setCols(unsigned int cols)
{
	this->cols = cols;
	return true; 
}

void createMaze::createNewMaze(unsigned int rows, unsigned int cols)
{
	this->maze = new char*[rows];
	for (unsigned int i = 0; i < rows; i++)
		maze[i] = new char[cols];
}

void createMaze::deleteMaze() {
	for (unsigned int i = 0; i < this->rows; ++i)
		delete[] this->maze[i];
	delete[] this->maze;
}

void createMaze::initMaze() {
	for (unsigned int row = 0; row < this->rows; row++) {
		if (isEven(row)) {
			for (unsigned int col = 0; col < this->cols; col++) {
				this->maze[row][col] = WALL_SQUARE;
			}
		}
		else {
			for (unsigned int col = 0; col < this->cols; col++) {
				if (isSquareStartOrEndOfMaze(row, col, this->rows, this->cols))
					this->maze[row][col] = FREE_SQUARE;
				else {
					if (isEven(col))
						this->maze[row][col] = WALL_SQUARE;
					else
						this->maze[row][col] = FREE_SQUARE;
				}
			}
		}
	}
}

void createMaze::buildMaze()
{
	bool rightNeighbor = false, downNeighbor = false, leftNeighbor = false, upNeighbor = false;
	unsigned int x = 1, y = 1;
	char direction;
	Point currentPoint(x, y);
	createMazeStack.Push(currentPoint);

	srand((unsigned)time(NULL));

	while (!createMazeStack.IsEmpty()) {
		rightNeighbor = false;
		downNeighbor = false;
		leftNeighbor = false;
		upNeighbor = false;
		currentPoint = createMazeStack.Pop();
		markSquareAsUsed(currentPoint);
		checkUnvisitedNeighbors(currentPoint, rightNeighbor, downNeighbor, leftNeighbor, upNeighbor);
		if (rightNeighbor || downNeighbor || leftNeighbor || upNeighbor)
		{
			setNeighborArray(rightNeighbor, downNeighbor, leftNeighbor, upNeighbor);
			unsigned int choice = selectRandomNeighbor();
			direction = neighborsArray[choice];
			Point neighborPoint = getNeighbor(direction, currentPoint);
			breakWall(direction, currentPoint);
			createMazeStack.Push(currentPoint);
			createMazeStack.Push(neighborPoint);
            resetNeighborsArray();
		}
	}
	cleanMazeFromUsedSquares();
}

void createMaze::resetNeighborsArray()
{
    for(unsigned int i=0; i< NEIGHBORS_ARR_SIZE; i++)
    {
        neighborsArray[i]=EMPTY_ARRAY_CELL;
    }
    logicNeighborsArraySize = 0;
}

void createMaze::breakWall(const char& direction, Point& currentPoint)
{
	int row = currentPoint.getX();
	int col = currentPoint.getY();

	switch (direction)
	{
	case 'R':
		maze[row][col + 1] = FREE_SQUARE;
		break;
	case 'D':
		maze[row + 1][col] = FREE_SQUARE;
		break;
	case 'L':
		maze[row][col - 1] = FREE_SQUARE;
		break;
	case 'U':
		maze[row - 1][col] = FREE_SQUARE;
		break;
	}
}

unsigned int createMaze::selectRandomNeighbor()
{
	return(rand() % logicNeighborsArraySize);
}


void createMaze::setNeighborArray(const bool& rightNeighbor, const bool& downNeighbor, const bool& leftNeighbor, const bool& upNeighbor)
{
	if (rightNeighbor) {
		neighborsArray[logicNeighborsArraySize] = 'R';
		logicNeighborsArraySize++;
	}
	if (downNeighbor) {
		neighborsArray[logicNeighborsArraySize] = 'D';
		logicNeighborsArraySize++;
	}
	if (leftNeighbor) {
		neighborsArray[logicNeighborsArraySize] = 'L';
		logicNeighborsArraySize++;
	}
	if (upNeighbor) {
		neighborsArray[logicNeighborsArraySize] = 'U';
		logicNeighborsArraySize++;
	}
}

void createMaze::checkUnvisitedNeighbors(Point& currentPoint, bool& rightNeighbor, bool& downNeighbor, bool& leftNeighbor, bool& upNeighbor)
{
	int row = currentPoint.getX();
	int col = currentPoint.getY();

	//check right side
	if ((this->cols - 2 == col) || this->cols - 3 == col)
		rightNeighbor = false;
	else if (this->maze[row][col + 2] == FREE_SQUARE)
		rightNeighbor = true;
	//check left side
	if (col == 1 || col == 2)
		leftNeighbor = false;
	else if (this->maze[row][col - 2] == FREE_SQUARE)
		leftNeighbor = true;
	//check up side
	if ((row == 1) || row == 2)
		upNeighbor = false;
	else if (this->maze[row - 2][col] == FREE_SQUARE)
		upNeighbor = true;
	//check down side
	if ((this->rows - 2 == row) || this->rows - 3 == row)
		downNeighbor = false;
	else if (this->maze[row + 2][col] == FREE_SQUARE)
		downNeighbor = true;
}

Point createMaze::getNeighbor(const char& direction, Point& currentPoint)
{
	int row = currentPoint.getX();
	int col = currentPoint.getY();
	Point neighborPoint;
	switch (direction)
	{
	case 'R':
		neighborPoint = Point(row, col + 2);
		break;
	case 'D':
		neighborPoint = Point(row + 2, col);
		break;
	case 'L':
		neighborPoint = Point(row, col - 2);
		break;
	case 'U':
		neighborPoint = Point(row - 2, col);
		break;
	}
	return neighborPoint;
}
char** createMaze::getMaze()
{
	return this->maze;
}
void createMaze::markSquareAsUsed(Point& point) {
	int row = point.getX();
	int col = point.getY();
	this->maze[row][col] = USED_SQUARE;
}

void createMaze::cleanMazeFromUsedSquares()
{
	for (unsigned int row = 1; row < this->rows - 1; row++)
	{
		for (unsigned int col = 1; col < this->cols - 1; col++)
		{
			if (this->maze[row][col] == USED_SQUARE)
				this->maze[row][col] = FREE_SQUARE;
		}
	}
}

bool createMaze::isSquareStartOrEndOfMaze(unsigned int row, unsigned int col, unsigned int rows, unsigned int cols)
{
	return(((row == 1) && (col == 0)) || ((row == rows - 2) && (col == cols - 1)));
}

void createMaze::printMaze()
{
	for (unsigned int i = 0; i < this->rows; i++)
	{
		for (unsigned int j = 0; j < this->cols; j++)
		{
			cout << this->maze[i][j] << " ";
		}
		cout << endl;

	}
}

bool createMaze::isEven(unsigned int num)
{
	return(num % 2 == 0);
}
