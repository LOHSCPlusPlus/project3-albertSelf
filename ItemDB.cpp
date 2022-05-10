#include <iostream>
#include <fstream>
#include "ItemDB.h"
#include "ReadUtils.h"


ItemDB::ItemDB(){
  numGames = 0;
}

void ItemDB::readgameData() {
    ifstream gameFile("videogames.txt");
    numGames = 0;
    while(gameFile.peek() != EOF && numGames < MAXGAMES){
        Videogames[numGames].readgame(gameFile);
        numGames++;
    }
}
 
void ItemDB::addGame() {
    if(numGames == MAXGAMES){
      cout << "Maximum amount of games reached";
      return;
    }
  Videogames[numGames].addGame();
    numGames++;
}



void ItemDB::printArrayToScreen() {
    for (int index = 0; index < numGames; index++) {
        cout << "Index " << index << ": ";
        Videogames[index].printGame(cout);
    }
}

void ItemDB::printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numGames; index++) {
        Videogames[index].printGame(outFile);
    }
}


void ItemDB::removeGame(){
  cout << "Which game number would you like to remove? ";
  int index = 0;
  cin >> index;
  for(int count = index; count < numGames; count++){
    Videogames[count] = Videogames[count + 1];
  }
  numGames--;
}

void ItemDB::getCstring(const char info[], char val[]){
  cout << "Enter the " << info << " of the Game: ";
  cin.ignore(100, '\n');
  cin.getline(val, 100);
  while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
      cout << "Enter the " << info << "of the Game: ";
      cin >> val;
    }
}

  void ItemDB::findPublishergame(){
    char temp[100];
    cout << "Enter the name of the publisher: ";
    cin >> temp;
    for(int count = 0; count < numGames; count++){
  if(Videogames[count].issamepublisher(temp)){
      Videogames[count].printGame(cout);
  }
}
    
    }