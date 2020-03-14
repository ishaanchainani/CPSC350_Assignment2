#include <string>
using namespace std;

class Grid{
public:
  Grid(int height, int width, float density, int gameMode);
  ~Grid();
  void createGrids();
  void deleteGrids();

  int userChoice;
  int numGenerations;
  int width;
  int height;
  float density;
  bool isFree;
  int gameMode;
  char **gameBoard;
  int totalNeighbors;
  int randX, randY;
  int x;
  int population;
  int y;
  string prev;
  Grid();
  Grid(int height, int width, int gameMode, string prev);
  bool checkWall();
  int countNeighbors(int x, int y);
  bool isNeighbor(int x, int y);
  string printSymbols();
  string nextGen();
  string printGrid();
  int randomizeGrid(float density);
  void gridFromString(string prevGen);
  void populateGrid();
  int countPopulation(string stringInput);



};
