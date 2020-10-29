
#include <iostream>
using namespace std;
#include "solveMaze.h"

solveMaze::solveMaze(char** maze, unsigned int rows, unsigned int cols) : mazeQueue(rows, cols)
{
	this->maze = maze;
	this->mazeRows = rows;
	this->mazeCols = cols;
    bool reachedToExit=false;
    unsigned int x=1, y=0;
    Point currentPoint(x,y);
    mazeQueue.EnQueue(currentPoint);
    while(!mazeQueue.IsEmpty() && !reachedToExit)
    {
        removeSquareFromQueue(currentPoint,x,y);
        updateSquareWithPath(x,y);
        if(isExit(currentPoint))
            reachedToExit=true;
        else
        {
            addNeighborsToQueue(x,y);
        }
    }
	checkIfMazeSolved();
	if (!solved)
		cout<< "no solution" << endl;
	else
		printMaze();
}

void solveMaze::checkIfMazeSolved()
{
	if (maze[mazeRows - 2][mazeCols - 1] == PATH_SIGN)
		solved=true;
	else
		solved=false;
}

solveMaze::~solveMaze()
{
}

void solveMaze::addNeighborsToQueue(unsigned int x, unsigned int y)
{
    //Check right neighbor
	if ((this->mazeCols - 1 != y)) {
		if (maze[x][y + 1] == ' ')
		{
			mazeQueue.EnQueue(Point(x, y + 1));
		}
	}
    //Check down neighbor
	if ((this->mazeRows - 1 != x)) {
		if (maze[x + 1][y] == ' ')
		{
			mazeQueue.EnQueue(Point(x + 1, y));
		}
	}
    //Check left neighbor
	if (y != 0) {
		if (maze[x][y - 1] == ' ')
		{
			mazeQueue.EnQueue(Point(x, y - 1));
		}
	}
    //Check up neighbor
	if (x != 0) {
		if (maze[x - 1][y] == ' ')
		{
			mazeQueue.EnQueue(Point(x - 1, y));
		}
	}
}

void solveMaze::updateSquareWithPath(unsigned int& x, unsigned int& y)
{
    this->maze[x][y]=PATH_SIGN;
}

void solveMaze::removeSquareFromQueue(Point& currentPoint, unsigned int& x, unsigned int& y)
{
    currentPoint=mazeQueue.DeQueue();
    x = currentPoint.getX();
    y = currentPoint.getY();
}

bool solveMaze::isExit(Point& point)
{
    if(point.getY() == mazeCols - 1 && point.getX() == mazeRows - 2)
        return true;
    else
        return false;
}

void solveMaze::printMaze()
{
	for (unsigned int i = 0; i < mazeRows; i++)
	{
		for (unsigned int j = 0; j < this->mazeCols; j++)
		{
			cout << this->maze[i][j] << " ";
		}
		cout << endl;
	}
}
