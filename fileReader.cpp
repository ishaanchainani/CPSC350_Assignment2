#include "fileReader.h"
using namespace std;
//constructor
fileReader::fileReader(string fileName){
  cout << fileName << endl;
  ReadFile(fileName);
};

//destructor
fileReader::~fileReader(){

};

// this opens file
void fileReader::ReadFile(string fileName){
  fileStream.open(fileName);

  cout << fileName << endl;
  // if file is unable to open
  if(!fileStream){
    throw runtime_error("Could not open " +fileName);
  }



  string line;
  int totalLines = 0;

  // collect lines
  while(getline(fileStream,line)){
    ++totaLines;
  }
  cout << "here" << endl;
  fileStream.clear();
  //resets fileStream to position 0
  fileStream.seekg(0);
  cout << "here now" << endl;
  cout << "Total lines " << totaLines << endl;

  //creating an array to hold totalLines
  string* fileLines = new string[totalLines];


  int counter = 1;

  //placing lines in the array
  while(getline(fileStream,line)){
    cout  << line << endl;
    fileLines[counter] = line;
    ++counter;
  }

  fileStream.clear();
  fileStream.seekg(0);
  fileStream.close();

  // parsing rows into integer
  this->rows = stoi((string)fileLines[0]);
  // parsing columns into integer
  this->columns = stoi((string)fileLines[1]);
  // check for layout of file
  if(this->rows!= totalLines -2 || checkWidth(fileLines,totalLines, columns) == false){
    throw runtime_error("This file layout is incorrect. ");
  }

  int numCells = 0;
  int numPopCells = 0;
  // adding each element to string and keeping count of cells and populated cells
  for(int i = 2; i < totalLines; ++i){
    for(int j = 0; j<fileLines[i].length(); ++j){
      numCells++;
      fileGridString += fileLines[i][j];
      if(fileLines[i][j]=='X'){
        ++numPopCells;
      }
    }
  }

  // file only contains 'X' and '-'
  for(int i = 0; i< fileGridString.length(); ++i){
    if(fileGridString[i] == 'X' || fileGridString[i] == '-')
    {}

  // if file is not correct layout
    else {
      throw runtime_error("Your file does not contain 'X' or '-'");
    }
  }
}

// checking if width is valid
bool fileReader::checkWidth(string*& fileLines, int totalLines, int columns){
  // if not valid, return false
  for(int i =2; i < totalLines; ++i){
    if(fileLines[i].length() != columns){
      return false;
    }
  }
  return true;
}

// method to write to file
void fileReader::WriteToFile(string fileName, string strToWrite){
  // declaring output file stream
  ofstream outfileStream;
  outfileStream.open(fileName, ofstream::app);
  // if can't open file
  if(!outfileStream){
    throw runtime_error("Cannot open.");
  }
  outfileStream << strToWrite << endl;
  outfileStream.close();
}
