#include "ItemClass.h"
const int MAXGAMES = 500;
class ItemDB{
  public:
    ItemDB();
    void addGame();
    void getCstring(const char info[], char val[]);
    void removeGame();
    void findPublishergame();
    void printArrayToScreen();
    void printArrayToFile(const char fileName[]);
    void readgameData();
  private:
    VideoGame Videogames[MAXGAMES];
    int numGames;                                   
};