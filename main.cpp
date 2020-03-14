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
  int width;
  int height;
  int density;
  int mode = 1;
  int speed = 1;
  bool stable = false;
  bool quit = false;
  Menu *m1 = new Menu();

  //Grid *g1 = new Grid();

  cout << "Welcome to Game of Life!" << endl;
  cout << "You will be presented with some options." << endl;


  int userChoice = m1->userGenInput();
  // if user chooses option 1 for output
  if(userChoice == 1){
    cout << "You chose for random configuration." << endl;
    //cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << "------------Entering height------------" << endl;
    height = m1->userMapDimensions();

    cout << endl << "------------Entering width-------------" << endl;
    width = m1->userMapDimensions();

    cout << endl << "------------Entering density-------------" << endl;
    density = m1->userMapDensity();

  }
  // if user chooses option 2 for output
  else if(userChoice == 2){
    cout << "You chose for a set configuration." << endl;
    cout << "-------------------------------------------" << endl;
    string fileName = m1->userFileName();
    fileReader *fr = new fileReader(fileName);
    fr->ReadFile(fileName);

  }

  cout << endl;
  int modeChoice = m1->userMode();
  int outputChoice = m1->userSpeed();

  cout << "-------------------------------------";
  cout << endl << "To start, press enter. To end simulation press 'q': ";
  cin.get();
  bool stillRunning = true;
  int numGens = 1;
  Grid *g1 = new Grid(height, width, density, modeChoice);

  if(cin.get() == '\n'){

    // if user chooses choice 1 for output
    if(outputChoice ==1){
      g1->randomizeGrid(density)
      string currString = g1->printGrid();
      //g1->countNeighbors(height, width);
      cout << "Generation 1: " << endl;
      cout << "Population Count: " << g1->countPopulation(currString) << endl;
      //g1->printGrid();
      cout << currString << endl;
      sleep(1);


      while(numGens < 1000 && stillRunning == true){
        numGens++;

        string nextString = g1->nextGen();
        cout << nextString << endl;
        // create new object for Grid
        Grid *g2 = new Grid(height, width, modeChoice, nextString);
        string printString = g2->printGrid();
        cout << "Generation " << numGens << endl;
        cout << "Population: " << g2->countPopulation(printString) << endl;
        cout << printString;
        sleep(1);
        //g1->printGrid();
    }
  }
  // if user chooses choice 2 for output
    else if(outputChoice == 2){
      string currString = g1->printGrid();
      g1->randomizeGrid(density);
      cout << "Generation 0: " << endl;
      cout << "Population Count: " << g1->countPopulation(currString) << endl;
      cout << currString << endl;
      cout << "Press enter for next generation." << endl;
      cin.get();
      while(numGens < 1000 && stillRunning == true){
        numGens++;
        string nextString = g1->nextGen();
        Grid *g2 = new Grid(height, width, modeChoice, nextString);
        string printString = g2->printGrid();
        cout << "Generation " << numGens << endl;
        cout << "Population count: " << g2->countPopulation(printString) << endl;
        cout << printString << endl;
        cout << "Press enter for next generation." << endl;
        cin.get();
      }
  }

  else if(outputChoice ==3){
      //do something

  }

  else if(cin.get() == 'Q' || cin.get() == 'q'){
    exit(1);
  }


}
}
