#include <string>
using namespace std;

class Menu{
public:
  Menu();
  ~Menu();
  int userGenInput();
  int userMapDimensions();
  float userMapDensity();
  string userFileName();
  int userMode();
  int userSpeed();
  //void checkFile();
  bool checkWidth(string*& linesInFile, int totalLines, int columns);
};
