#include "utils.h"
#include <random>
#include <sstream>
#include <iostream>
#include <time.h>

std::vector<std::string> splitString(std::string str, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string temp;

    while (std::getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }
    return result;
}

const std::string getDateTime()
{
    // Current time of system
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct);

    return buf;
}

void writeToFile(const std::string &fileName, const std::string &str)
{
    std::ofstream file;
    file.open(fileName, std::ios_base::app);
    file << str + '\n';
    file.close();
}

void writeMultipleStrToFile(const std::string &fileName, std::vector<std::string> vector)
{
    std::ofstream file;
    file.open(fileName);

    for (auto &str : vector)
    {
        file << str + '\n';
    }

    file.close();
}

void deleteAFile(const std::string &fileName)
{
    const int success = std::remove(fileName.c_str());
    if (success == 0)
    {
        std::cout << "Successfully deleted " << fileName << std::endl;
    }

    else
    {
        std::cout << "Failed to delete " << fileName << std::endl;
    }
}

void renameAFile(const std::string &oldName, const std::string &newName)
{
    std::rename(oldName.c_str(), newName.c_str());
}

bool checkIfFileExists(const char *file)
{
    std::ifstream f(file);
    return f.good();
}

void quitGame()
{
    std::cout << std::endl;
    std::cout << "Quitting the game. See you again!" << std::endl;

    // Quit
    exit(0);
}

void shuffleTileBagDirectly(LinkedList<Tile *> *tileBag, int seed)
{
    // Reference made to Fisher-Yates shuffle: https://en.wikipedia.org/wiki/Fisher–Yates_shuffle#Fisher_and_Yates'_original_method

    int min = 0; // Allow tile to not be swaped
    int max = TILE_BAG_BEFORE_SHUFFLE - 1;
    int swapIndex = -1; // Invalid swap index

    // Deckare Seeded Engine
    std::default_random_engine seededEngine(seed);
    // Declare Regular Random Engine
    std::random_device engine;

    // For each tile
    for (int index = max; index > 0; index--)
    {
        // Create new number from decrementing range
        std::uniform_int_distribution<int> uniform_dist(min, max);

        // If seed does not equals 0 -> (0 is read as Seed has not been entered)
        if (seed != IGNORED_SEED)
        {
            // Use Seeded Engine
            swapIndex = uniform_dist(seededEngine);
        }
        else
        {
            // Use Random Engine
            swapIndex = uniform_dist(engine);
        }

        // Swap Tile at Index and Randomised Swap Index
        Tile temp = *tileBag->get(index);
        *tileBag->get(index) = *tileBag->get(swapIndex);
        *tileBag->get(swapIndex) = temp;

        // Decrement Range
        max--;
    }
}
