#include <fstream>
using namespace std;
#pragma once
class VideoGame{
    public: 
  void addGame();
  void readgame(ifstream &inFile);
  void printGame(ostream &outFile);
  VideoGame();
  bool issamepublisher(char temp[]);
    private:
  enum {MAX_NAME_CHAR=100};
  char title[MAX_NAME_CHAR];
  int sales;
  char platforms[MAX_NAME_CHAR];
  char releasedate[MAX_NAME_CHAR];
  char developer[MAX_NAME_CHAR];
  char publisher[MAX_NAME_CHAR];
};