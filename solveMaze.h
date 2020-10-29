/*
solveMaze class solves the maze
*/

using namespace std;
#ifndef solveMaze_h
#define solveMaze_h
#include "Queue.h"

class solveMaze
{
    private:
        unsigned int mazeRows;
        unsigned int mazeCols;
		char** maze;
        static const char PATH_SIGN = '$';
        Queue mazeQueue;
		bool solved;

    public:
        solveMaze(char** maze, unsigned int rows, unsigned int cols); //c'tor
        ~solveMaze(); //d'tor
		void checkIfMazeSolved(); //Check if maze is solved
        void addNeighborsToQueue(unsigned int x, unsigned int y); //Add neighbors to queue
        void updateSquareWithPath(unsigned int& x, unsigned int& y); //Mark a square in the maze with path sign
        void removeSquareFromQueue(Point& currentPoint, unsigned int& x, unsigned int& y); //Removes the last square's point from the queue
        bool isExit(Point& point); //Checks if the current square is the exit point of the maze
		void printMaze(); //prints the maze
};


#endif


