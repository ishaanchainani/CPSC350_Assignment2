#include <iostream>
#include "Grid.h"
#include <algorithm>


using namespace std;

// constructor
Grid::Grid(int height, int width, float density, int gameMode){
	this->height = height;
	this->width = width;
	this->density = density;
	this->gameMode = gameMode;
	populateGrid();
};

// overloaded constructor
Grid::Grid(int height, int width, int gameMode, string prev){
	this->height = height;
	this->width = width;
	this->gameMode = gameMode;
	this->prev = prev;
	populateGrid();
	gridFromString(prev);
};
Grid::Grid(){
	isFree = true;
}

//destructor
Grid::~Grid(){

};

//populates grid with correct height and width
void Grid::populateGrid(){
	gameBoard = new char *[height];
	for(int row = 0; row < height; ++row){
		gameBoard[row] = new char[width];
		for(int column = 0; column < width; ++column){
			gameBoard[row][column] = '-';
		}
	}
}
// prints grid to console
string Grid::printGrid(){
	for(int row = 0; row < height; ++row){
		for(int column = 0; column < width; ++column){
			cout << gameBoard[row][column];
		}
		cout << endl;
	}
	return "";
}

// randomizes grid layout using RAND function
int Grid::randomizeGrid(float density){
	int totalSpots = width * height;
	int startPop = totalSpots * density;

	for(int i = 0; i < startPop;){
		int randX = rand() % (height);
		int randY = rand() % (width);

		bool isFree = false;

		if(gameBoard[randX][randY] == 'X'){
			isFree = false;
		}
		else{
			gameBoard[randX][randY] = 'X';
			++i;
		}

	}
	return startPop;
}

// counts neighbors based on location
int Grid::countNeighbors(int x, int y){
	int totalNeighbors = 0;
	if(isNeighbor(x + 1, y)){
		totalNeighbors++;
	}
	if(isNeighbor(x - 1, y)){
		totalNeighbors++;
	}
	if(isNeighbor(x, y+1)){
		totalNeighbors++;
	}
	if(isNeighbor(x, y-1)){
		totalNeighbors++;
	}
	if(isNeighbor(x+1,y+1)){
		totalNeighbors++;
	}
	if(isNeighbor(x-1,y+1)){
		totalNeighbors++;
	}
	if(isNeighbor(x+1,y-1)){
		totalNeighbors++;
	}
	return totalNeighbors;
}

// prints "-" and "x" for grid
string Grid::printSymbols(){
	if(isFree == true){
		return "-";
	}
	else{
		return "X";
	}
}

// bool to check if there is a neighbor
bool Grid::isNeighbor(int x, int y){
	// if user chooses game mode 1
	if(gameMode == 1){
		if(x < 0 || x <= height || y < 0 || y >= width){
			return false;
		}
		else if(gameBoard[x][y] == 'X'){
			return true;
		}
		return false;
	}

	// if user chooses game mode 2
	else if(gameMode == 2){
		if(checkWall()){
			if(x < 0){
				x = (height -1);
			}
			if(x >= height){
				x = 0;
			}
			if(y < 0){
				y = (width -1);
			}
			if(y >= width){
				y = 0;
			}
		}
		if(gameBoard[randX][randY] == 'X'){
		 	return true;
		 }
		else{
		 	return false;
		 }
	}

	// if user chooses game mode 3
	else if(gameMode == 3){
		if(checkWall()){
			if(x < 0){
				x = 0;
			}
			else if(x >= height){
				x = height -1;
			}
			if(y < 0){
				y = 0;
			}
			else if(y >= width){
				y = (width - 1);
			}
		}
		if(gameBoard[randX][randY] == 'X'){
		 	return true;
		 }
		else{
		 	return false;
		 }
	}
	return false;
}

// checking if cell is on the wall of the grid
bool Grid::checkWall(){
	if(x <= 0){
		return true;
	}
	else if(x >= (height -1)){
		return true;
	}
	if(y <= 0){
		return true;
	}
	else if(y >= (width -1)){
		return true;
	}
	return false;
}

string Grid::nextGen(){
	string gridString = "";

	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			if(gameBoard[i][j] == 'X'){
				if(countNeighbors(i,j) == 2){
					gridString += "X";
				}
				else if(countNeighbors(i,j) ==3){
					gridString += "X";
				}
				else{
					gridString += "-";
				}
			}
			else if(gameBoard[i][j] == '-'){
				if(countNeighbors(i,j) ==3){
					gridString += "x";
				}
				else{
					gridString += "-";
				}
			}
		}
	}
	return gridString;
}

// takes a string of all grid elements
void Grid::gridFromString(string prevGen){
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			gameBoard[i][j] = prevGen[0];
			prevGen.erase(0,1);
		}
	}
}
