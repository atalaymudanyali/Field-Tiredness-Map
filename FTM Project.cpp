#include <iostream>
#include <fstream>

int main() {
    int sizeX;
    int sizeY;
    int currentYear;
    int plantingCount;
    int startXCoord;
    int startYCoord;
    int endXCoord;
    int endYCoord;
    int yearIndex;
    int plantingIndex;
    int firstYear;

    std::string fileName;
    std::cin >> fileName;

    std::ifstream inputFile;
    inputFile.open(fileName);
    inputFile >> sizeX >> sizeY >> currentYear;
    firstYear = currentYear;

    int newTirednessMap[sizeY][sizeX];
    int tirednessMap[sizeY][sizeX];

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            tirednessMap[i][j] = 0;
        }
    }

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            newTirednessMap[i][j] = 0;
        }
    }
    if(sizeX <= 40 && sizeY <= 40) {
        for (yearIndex = currentYear; yearIndex <= 2017; yearIndex++) {

            inputFile >> plantingCount;

            for (plantingIndex = 0; plantingIndex < plantingCount; plantingIndex++) {
                inputFile >> startXCoord >> startYCoord >> endXCoord >> endYCoord;
                for (int i = startYCoord; i <= endYCoord; i++) {
                    for (int j = startXCoord; j <= endXCoord; j++) {
                        newTirednessMap[i][j] += 1;

                        if (newTirednessMap[i][j] > 1){
                            std::cout << "Invalid Operation!";
                            return 0;
                        }
                    }
                }
            }

            if (currentYear == firstYear) {
                for (int i = 0; i < sizeY; i++) {
                    for (int j = 0; j < sizeX; j++) {
                        tirednessMap[i][j] = newTirednessMap[i][j];
                    }
                }
            }
            else {
                for (int i = 0; i < sizeY; i++) {
                    for (int j = 0; j < sizeX; j++) {
                        if (newTirednessMap[i][j] == 0 && tirednessMap[i][j] > 0) {
                            tirednessMap[i][j] -= 1;
                            if (tirednessMap[i][j] < 0) {
                                tirednessMap[i][j] = 0;
                            }
                        } else if (newTirednessMap[i][j] > 0 && tirednessMap[i][j] >= 0)
                            tirednessMap[i][j] += 1;
                    }
                }
            }

            for (int i = 0; i < sizeY; i++) {
                for (int j = 0; j < sizeX; j++) {
                    newTirednessMap[i][j] = 0;
                }
            }
            inputFile >> currentYear;
        }
    }
    else {
        std::cout << "Invalid Operation!";
        return 0;
    }
    inputFile.close();

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            std::cout << tirednessMap[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
