#include <iostream>
#include <fstream>
#include <queue>

// Function declarations
void PrintEnvironment(int **arry, int width, int height);
bool bfsIsValid(int **arry, bool** visited, int adjx, int adjy, int width, int height);
bool pathIsValid(int **arry, int adjx, int adjy, int width, int height);
void BreadthFirstSearch(int **arry, char **characterArray, bool **visited, int width, int height, int goalY, int goalX, int *mooreRow, int *mooreCol);
void findPath(int **arry, char **characterArray, int width, int height, int goalX, int goalY, int startX, int startY, int *mooreRow, int *mooreCol);
void resultArray(int **arry, char **characterArray, int width, int height, int goalY, int goalX, int startX, int startY);
void printToFile(int **arry, char **characterArray, int width, int height, std::ofstream& fileOut);
void interface();
