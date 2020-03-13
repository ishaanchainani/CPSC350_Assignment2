#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class fileReader{
public:

  fileReader(string fileName);
  ~fileReader();
  void ReadFile(string fileName);
  bool checkWidth(string*& fileLines, int totalLines, int columns);
  void WriteToFile(string fileName, string writeToFile);

  ifstream fileStream;
  int rows;
  int totaLines;
  int columns;
  string fileGridString;


};
