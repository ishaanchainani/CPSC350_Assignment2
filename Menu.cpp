using namespace std;
#include "Menu.h"
#include "Grid.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iostream>

int gameMode = 0;
int outputMode = 0;
int dimension = 0;
string fileName;
int totalLines = 0;
string line;
ifstream fileStream;
int linesInFile = 0;
int userMode = 0;
int modeChoice = 0;

//constructor
Menu::Menu(){


};

//destructor
Menu::~Menu(){


};

// gives user option on which configuration they would like to use
int Menu::userGenInput(){
  int userMode = 0;
  bool validInput = true;
  while(!validInput){
    cout << "Would you like to start with a random configuration or read in a file?" << endl;
    cout << "Press '1' for random, and '2' for set configuration: " << endl;
    cin >> userMode;
    if(userMode != 1 || userMode != 2){
      cout << "You did not enter a valid input. Please try again." << endl;
      validInput = false;
    }
    else if(userMode == 1 || userMode ==2){
      validInput = true;
    }
  }
  return userMode;
};

// prompts user for map dimensions
int Menu::userMapDimensions(){
  bool isValid = false;
  while(!isValid){
    cout << "Please enter a value from 1 to 100: ";
    cin >> dimension;
    if(dimension > 0 && dimension < 100){
      isValid = true;
    }
    else{
      cout << "Input not valid. Please try again." << endl;
      isValid = false;
    }
  }
  return dimension;
};


// prompts user for density of map
float Menu::userMapDensity(){
  bool validInput = true;
  float mapDensity;

  cin >> mapDensity;
  while(!validInput){
    cout << "Enter a decimal value greater than 0 and less than or equal to 1 for population density:  ";
    cin >> mapDensity;
    if(mapDensity > 1 || mapDensity < 0){
      cout << "You did not enter a valid input. Please try again." << endl;
    }
    else{
      validInput = true;
    }
  }
  return mapDensity;
};

// prompts user for name of file they would like to use
string Menu::userFileName(){
  ifstream masterFile;
  cout << "Please enter the name and extension of your file: ";
  cin >> fileName;

  masterFile.open(fileName);
  bool fileExists = true;
  char tryAgain;

  // if file does not exist, continue loop until file exists
  while(!masterFile){
    fileExists = false;
    cout << endl << ("The file does not exist. ");
    cout << ("Would you like to try again? (y/n) ");

    cin >> tryAgain;
    if(tolower(tryAgain) == 'y'){
      cout << ("Please enter the file you would like to open: ");
      ifstream file;
      cin >> fileName;
      masterFile.open(fileName);
      if(masterFile){
        continue;
      }
    }
    else {
      exit(1);
    }
  }
  masterFile.close();
  return fileName;
};

//checks if user file is correct
// void Menu::checkFile(string fileName){
//   ifstream inputFileStream;
//   inputFileStream.open(fileName);
//   while(getline(inputFileStream,line)){
//     totalLines++;
//   }
//   inputFileStream.clear();
//   inputFileStream.seekg(0);
//
//   string* linesInFiles = new string[totalLines];
//   int counter = 0;
//
//   while(getline(inputFileStream,line)){
//     linesInFile[counter] = line;
//     counter++;
//   }
//   inputFileStream.clear();
//   inputFileStream.seekg(0);
//   fileStream.close();
//   this -> rows = stoi((string)linesInFile[0]);
//   this -> columns = stoi((string)linesInFile[1]);
//   if(this -> rows != totalLines - 2 || isWidthCorrect(linesInFile, totalLines, columns) == false) {
//     throw runtime_error("This file does not have a correct layout. ");
//   }
//   int numCells = 0;
//   int numPopCells = 0;
//   // creating a fileGridString, adding each element to the string and counting the number of total cells and populated cells
//   for(int i = 2; i < totalLines; ++i)
//   {
//     for(int j = 0; j < linesInFile[i].length(); ++j)
//     {
//       numCells++;
//       fileGridString += fileLines[i][j];
//       if(linesInFile[i][j] == 'X')
//         ++numPopCells;
//     }
// }
// };

// checking if width is valid
bool Menu::checkWidth(string*& linesInFile, int totalLines, int columns){
  for(int i = 2; i < totalLines; ++i){
    if(linesInFile[i].length() != columns){
      return false;
    }
  }
  return true;
};


// asks user which mode they would like to play in
int Menu::userMode(){
  bool gameModeIsValid = true;
  while(!gameModeIsValid){
    cout << endl;
    cout << "Would you like to play in classic mode, doughnut mode, or mirror mode?" << endl;
    cout << "Enter '1' for classic, '2' for doughnut, or '3' for mirror: ";
    cin >> gameMode;
    if(gameMode == 1 || gameMode == 2 || gameMode == 3){
      gameModeIsValid = true;
    }
    else{
      cout << endl;
      cout << "You did not enter a valid option. Please try again." << endl;
      gameModeIsValid = false;
    }
  }
  return gameMode;
};

// prompts user what speed they would like to run in
int Menu::userSpeed(){
  bool userOutputChoice = false;
  while(!userOutputChoice){
    cout << endl;
    cout << "How would you like to output the game results?" << endl;
    cout << "Press '1' for a brief pause between generations, '2' to print out one by one, '3' to print results to an ouput file: ";
    cin >> outputMode;
    if(outputMode == 1 || outputMode == 2 || outputMode == 3){
      userOutputChoice = true;
    }
    else{
      cout << "You did enter a valid option. Please try again." << endl;
      userOutputChoice = false;
    }
  }
  return outputMode;
};
