/*
This class handles option 2 from the menu.
It creates a new, random, maze by the user's desired dimensions.
*/

using namespace std;
#ifndef CREATEMAZE_H
#define CREATEMAZE_H
#include "Stack.h"

class createMaze
{
private:
    static const char NEIGHBORS_ARR_SIZE = 4;
	char neighborsArray[NEIGHBORS_ARR_SIZE];
	unsigned int logicNeighborsArraySize;
	char** maze;
	unsigned int cols;
	unsigned int rows;
	static const char USED_SQUARE = '$';
	static const char WALL_SQUARE = '*';
	static const char FREE_SQUARE = ' ';
    static const char EMPTY_ARRAY_CELL = '-';
	Stack createMazeStack;

public:
	createMaze(unsigned int rows, unsigned int cols); //c'tor
	~createMaze(); //d'tor

    void resetNeighborsArray(); //cleans the neighbors array and resets the log size of the neighbors array to 0
	bool setRows(unsigned int rows); //sets the number of rows of the maze
	bool setCols(unsigned int cols); //sets the number of columns of the maze
	bool isEven(unsigned int num); //checks if a number is even or odd
	void createNewMaze(unsigned int rows, unsigned int cols); //allocates the memory needed for the maze 
	void buildMaze(); // removes random walls from the maze
	void initMaze(); // initializes the maze so that all of the walls exist
	bool isSquareStartOrEndOfMaze(unsigned int row, unsigned int col, unsigned int rows, unsigned int cols); //determintes whether the square we are on is the start or the end of the maze
	void cleanMazeFromUsedSquares(); // The algorithm marks used squares. This function deletes them
	void printMaze(); //prints the maze
	void markSquareAsUsed(Point& point); //marks squares which the algorithm used
	void checkUnvisitedNeighbors(Point& currentPoint, bool& rightNeighbor, bool& downNeighbor, bool& leftNeighbor, bool& upNeighbor); //Checks which neighbors are valid
	Point getNeighbor(const char& direction, Point& currentPoint); //returns the neighbor in the desired location
	void setNeighborArray(const bool& rightNeighbor, const bool& downNeighbor, const bool& leftNeighbor, const bool& upNeighbor); //sets an array of the valid neighbors
	unsigned int selectRandomNeighbor(); //selects a random neighbor
	void breakWall(const char& direction, Point& currentPoint); //break wall between the current point and the chosen neighbor
	void deleteMaze(); //free the memory of the maze's matrix
	char** getMaze(); //return the maze
};

#endif


