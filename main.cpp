#include <iostream>
#include "Menu.h"
#include "Grid.h"
#include "fileReader.h"
#include <string>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv){
  srand(time(NULL));
  Grid *gridObject = new Grid(5,5,0.4,1);
  gridObject->printGrid();
  float density = 0.4;
  gridObject->randomizeGrid(density);
  gridObject->printGrid();
  string nextGen = gridObject->nextGen();
  cout << nextGen << endl;
  Grid *gridObject2 = new Grid(5,5,1,nextGen);
  gridObject2->printGrid();

  //string fileName = "mapGrid.txt";
  //cout << "Creating filereader"<< endl;
  //fileReader *fr = new fileReader(fileName);
  //fr->ReadFile(fileName);

}
//
// int main(int argc, char** argv){
//   Menu *menuObject = new Menu();
//   Grid *gridObject;
//   FileReader fr;
//   int w;
//   int h;
//   int mode = 1;
//   int speed = 1;
//   bool isStable = true;
//   bool userQuit = true;
//
//
//   cout << "Welcome to Game of Life!" << endl;
//   cout << "You will be presented with some options." << endl;
//
//   menuObject.genChoice = menuObject.userGenInput();
//
//   //if user chooses for random generation
//   if(menuObject.genChoice == 1){
//     gridObject = menuObject.userMapDimensions();
//     int height = 0;
//     int width = 0;
//     float density = 0;
//     height = menuObject.userMapDimensions();
//     width = menuObject.userMapDimensions();
//
//     density = menuObject.userMapDensity();
//     int gameMode = menuObject.userMode();
//     gridObject = new Grid();
//     //gameObject.createGrid();
//   }
//
//   //if user chooses to enter input file
//   if(menuObject.genChoice == 2){
//     gridObject.fileName = menuObject.userFileName();
//     //gridObject.generateGridFromFile();
//     gridObject.width = gridObject.getWidthFromFile();
//     //gameObject.height = gameObject.getHeighFromFile();
//   }
//
//   menuObject.getMode = menuObject.genChoice();
//   menuObject.getSpeed = menuObject.userSpeed();
//   speed = menuObject.getSpeed;
//
//   gridObject.gen = 0;
//   cout << "To start, press enter. To end simulation press 'q': ";
//   cin.get();
//
//   while(!isStable && gridObject.gen < 1000 && cin.get() != 'q'){
//     if(menuObject.getSpeed == 1){
//         gridObject.displayGen(gridObject.height, gridObject.width);
//         cout << endl;
//         sleep(1);
//       }
//     else if(menuObject.getSpeed ==2){
//       gridObject.displayGen1(gridObject.height,gridObject.width);
//       cout << "Press enter for next generation or 'q' to quit: ";
//     }
//
//     else if(menuObject.getSpeed == 3){
//       gridObject.outputGen1();
//     }
//     if(cin.get() == 'q'){
//       isStable = true;
//     }
//     gridObject.prepGen();
//     gridObject.progressGens(menuObject.genChoice);
//     stable = gridObject.checkIfStable();
//     gridObject.overwriteGen1();
//     gridObject.gen++;
//     }
//     if(isStable){
//       cout << "Simulation stabalized. Press enter to end.";
//       cin.get();
//     }
//     else if(cin.get() == 'q'){
//       cout << "Quitting application" << endl;
//     }
//   }
