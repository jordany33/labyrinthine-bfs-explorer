#include "wavefront.h"
#include "utilities.h"
#include <iomanip>

// Implementation for all the functions declared in wavefront.h

void PrintEnvironment(int **arry, int width, int height) {
    int obstacles, goalX, goalY, startX, startY; //input variables
    char **characterArray; //character array that stores the char positions of the obstacles, goal point, starting point, and path
    characterArray = new char *[height]; //create the outer array
    bool **visited; //boolean array that checks if index has been visited before - used for bfs search
    visited = new bool *[height]; //create the outer array

    //moore neighborhood
    int mooreRow[] = {-1,0,1,0,-1,1,-1,1};
    int mooreCol[] = {0,1,0,-1,1,-1,-1,1};

    // initializing 2d int array to width from height
    for (int i = 0; i < height; i++)
    {
        arry[i] = new int[width];
    }
    // initializing 2d char array to width from height
    for (int i = 0; i < height; i++)
    {
        characterArray[i] = new char[width];
    }
    // initializing 2d bool array to width from height
    for (int i = 0; i < height; i++)
    {
        visited[i] = new bool[width];
    }
                        
    char prompt; //collects the input below
    //collects the input for impassible terrain and reprompts user if input is invalid
    do
    {
        std::cout << "Enter the percent of impassible terrain (0 - 100): ";
        std::cin >> obstacles;
        if (obstacles > 35 && obstacles < 100)
        {
            std::cout << "Having a value greater than 35% might create poor results, do you wish to continue? (y/n): ";
            std::cin >> prompt;
        }
        else if (obstacles < 0 || obstacles > 100)
        {
            std::cout << "The value you entered isn't in the valid range. Please enter a value in the valid range." << std::endl;
        }
    } while ((prompt == 'n' && (obstacles > 35 && obstacles < 100)) || obstacles < 0 || obstacles > 100);

    int environment = (height * width * obstacles) / 100; //2d grid size
    int count = 0; //count measure
    while (count < environment) //increment count while it's less than the 2d grid size
    {
        int row = frand() * height; //randomize index
        int col = frand() * width; //randomize index
        if (arry[row][col] == 0)
        {
            arry[row][col] = -1; //set the obstacles
            count++; //increment count
        }
    }

    //print the Environment after creating impassible terrain
    std::cout << "\nEnvironment:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::setw(4) << arry[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //collects the input for the goalX and goalY positions and reprompts user if the input is invalid
    do
    {
        std::cout << "Please enter the Goal Position X: ";
        std::cin >> goalX;
        std::cout << "Please enter the Goal Position Y: ";
        std::cin >> goalY;
        
        if (goalX >= width || goalY >= height || goalX < 0 || goalY < 0)
        {
            std::cout << "Sorry, that position is outside of the environment. Please enter another Goal Position." << std::endl;
        }
        else if (arry[goalY][goalX] == -1)
        {
            std::cout << "Sorry, that position is inside an obstacle. Please enter another Goal Position." << std::endl;
        } 
    } while (goalX >= width || goalY >= height || goalX < 0 || goalY < 0 || arry[goalY][goalX] == -1);

    //set the goal position to 1 in the Environment
    arry[goalY][goalX] = 1;

    //calling BFS function to perform the flood-fill algorithm to arry
    BreadthFirstSearch(arry, characterArray, visited, width - 1, height - 1, goalY, goalX, mooreRow, mooreCol);

    //print the Environment after flooding it with increasing values
    std::cout << "\nEnvironment:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::setw(4) << arry[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //collects the input for the startX and startY positions and reprompts user if the input is invalid
    do
    {
        std::cout << "Please enter the Start Position X: ";
        std::cin >> startX;
        std::cout << "Please enter the Start Position Y: ";
        std::cin >> startY;

        if (startX >= width || startY >= height || startX < 0 || startY < 0)
        {
            std::cout << "Sorry, that position is outside of the environment. Please enter another Start Position." << std::endl;
        }
        else if (startY == goalY && startX == goalX)
        {
            std::cout << "Sorry, that position is the same as your goal position. Please enter another Start Position." << std::endl;
        }
        else if (arry[startY][startX] == -1)
        {
            std::cout << "Sorry, that position is inside an obstacle. Please enter another Start Position." << std::endl;
        } 
    } while (startX >= width || startY >= height || startX < 0 || startY < 0 || (startY == goalY && startX == goalX) || arry[startY][startX] == -1);

    //create result array
    resultArray(arry, characterArray, width, height, goalY, goalX, startX, startY);

    //calling findPath function to find the shortest path
    findPath(arry, characterArray, width, height, goalX, goalY, startX, startY, mooreRow, mooreCol);
    
    //print the Environment after flooding it with increasing values and collecting the starting position
    std::cout << "\nEnvironment:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::setw(4) << arry[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //print the Result Array after creating shortest path
    std::cout << "\nResult Array:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::setw(4) << characterArray[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //find whether or not a path has been found
    int nonValidPaths = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (characterArray[i][j] == '*')
            {
                nonValidPaths++;
            }
        }
    }

    //print whether or not a path has been found
    if (nonValidPaths == 0)
    {
        std::cout << "No Path Found" << std::endl; //path not found
    } else {
        std::cout << "Path Found" << std::endl; //path found
    }

    //open wave.txt file and write the Environment and Result Array to the file
    std::ofstream outfile;
    outfile.open("wave.txt");
    printToFile(arry, characterArray, width, height, outfile);
    outfile.close();
    std::cout << "Environment and Result Array successfully outputted to \"wave.txt\"" << std::endl; //completion statement

    //delete the Environment and Result Array
    for (int i = 0; i < height; i++)
    {
        delete[] arry[i];
        delete[] characterArray[i];
        delete[] visited[i];
    }
    delete[] arry;
    delete[] characterArray;
    delete[] visited;
}

bool bfsIsValid(int **arry, bool** visited, int adjx, int adjy, int width, int height) {
    if (adjX < 0 || adjY < 0 || adjX > width || adjY > height)
    {
        return false;
    }

    if (visited[adjY][adjX])
    {
        return false;
    }

    if (arry[adjY][adjX] == -1)
    {
        return false;
    }

    return true;
}

bool pathIsValid(int **arry, int adjx, int adjy, int width, int height) {
    if (adjX < 0 || adjY < 0 || adjX >= width || adjY >= height)
    {
        return false;
    }

    if (arry[adjY][adjX] == -1)
    {
        return false;
    }

    if (arry[adjY][adjX] == 1)
    {
        return false;
    }

    return true;
}

void BreadthFirstSearch(int **arry, char **characterArray, bool **visited, int width, int height, int goalY, int goalX, int *mooreRow, int *mooreCol) {
    std::queue<std::pair<int, int> > gridValues;

    arry[goalY][goalX] = 1;
    gridValues.push({goalY, goalX});
    visited[goalY][goalX] = true;

    while (!gridValues.empty())
    {
        std::pair<int, int> index = gridValues.front();
        int y = index.first;
        int x = index.second;

        int currVal = arry[y][x];
        gridValues.pop();

        for (int i = 0; i < 8; i++)
        {
            int adjX = x + mooreRow[i];
            int adjY = y + mooreCol[i];

            if (bfsIsValid(arry, visited, adjX, adjY, width, height)) //using bfsIsValid to check for valid movements in the grid
            {
                gridValues.push({adjY, adjX});
                arry[adjY][adjX] = currVal + 1;
                visited[adjY][adjX] = true;
            }
        }
    }
}

void findPath(int **arry, char **characterArray, int width, int height, int goalX, int goalY, int startX, int startY, int *mooreRow, int *mooreCol) {
    std::queue<std::pair<int, int> > gridValues;

    gridValues.push({startY, startX});

    while (!gridValues.empty())
    {
        std::pair<int, int> index = gridValues.front();
        int y = index.first;
        int x = index.second;

        int currVal = arry[y][x];
        gridValues.pop();

        for (int i = 0; i < 8; i++)
        {
            int adjX = x + mooreRow[i];
            int adjY = y + mooreCol[i];
            
            if (pathIsValid(arry, adjX, adjY, width, height)) //using pathIsValid to check for valid movements in the grid
            {
                if (arry[adjY][adjX] < currVal)
                {
                    gridValues.push({adjY, adjX});
                    characterArray[adjY][adjX] = '*';
                    break;
                } 
            }
        }
    }
}

void resultArray(int **arry, char **characterArray, int width, int height, int goalY, int goalX, int startX, int startY) {
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arry[i][j] == -1)
            {
                characterArray[i][j] = '#';
            } else {
                characterArray[i][j] = ' ';
            }
        }
    }

    characterArray[goalY][goalX] = '$';
    characterArray[startY][startX] = '@';
}

void printToFile(int **arry, char **characterArray, int width, int height, std::ofstream& fileOut) {
    outfile << "Environment:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            outfile << std::setw(4) << arry[i][j];
        }
        outfile << std::endl;
    }

    outfile << std::endl << std::endl;
    outfile << "Result Array:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            outfile << std::setw(4) << characterArray[i][j];
        }
        outfile << std::endl;
    }
}

void interface() {
    int **arry;
    int width, height;
    bool running = true;
    while(running)
    {
        //collects the input for the grid width and height
        std::cout << "Welcome to Jordan's CSE240 WaveFront Pather\n" << std::endl;
        std::cout << "Please tell me about the grid you want to generate." << std:: endl;

        do
        {
        std::cout << "Enter the width (at least 10): ";
        std::cin >> width;
        std::cout << "Enter the height (at least 10): ";
        std::cin >> height;
        if (width < 0 || height < 0)
        {
            std::cout << "You can't create an Environment that is less than 0x0, please enter a grid size greater than 0x0." << std::endl;
        }
        } while (width < 0 || height < 0);

        arry = new int *[height]; //create the outer array
        PrintEnvironment(arry, width, height); //print the environments using PrintEnvironment
        running = false; //break the loop
    }
}
