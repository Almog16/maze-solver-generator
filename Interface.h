/*
Handles communication with the user
*/

#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "solveMaze.h"
#include "createMaze.h"

class Interface
{

private:
	char** maze;
	createMaze* createTheMaze;
	solveMaze* solveTheMaze;

public:
	void menu(); //The main menu of the program
	void menuOptions(); //The menu options
	bool validateRow(const char* row, unsigned int rowIndex, unsigned int rows, unsigned int cols); //Checks if row in the maze is valid
	void failInterface(); //If the input is valid prints an error
	void deleteMaze(unsigned int rows); //Free the memory of the maze matrix
	void readSolveMazeDimension(unsigned int& rows, unsigned int& cols); //Gets the dimensions of the maze in option 1 of the menu
	void readCreateMazeDimension(unsigned int& rows, unsigned int& cols); //Gets the dimensions of the maze in option 2 of the menu
	void readMaze(unsigned int& rows, unsigned int& cols); //Read maze from the user in option 1 of the menu
	bool isEven(unsigned int num); //Checks if a number is even
};

#endif// __INTERFACE_H