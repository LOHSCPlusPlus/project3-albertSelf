#include <iostream>
#include "ItemDB.h"
#include "ItemClass.h"
using namespace std;


void menu()
 {
  ItemDB Name;
  int option = 0;
  while(option != 7){
    cout << "Welcome to the Video Game list" << endl;
    cout << "Select a menu option: " << endl; 
    cout << "1. Show entire game list" << endl;
    cout << "2. Add a game to the list" << endl;
    cout << "3. Search a game by publisher" << endl;
    cout << "4. Remove a game from the list" << endl;
    cout << "5. Reload the list from data base" << endl;
    cout << "6. Save data to file" << endl;
    cout << "7. Exit List Program" << endl;
    cin >> option;
    switch (option)
    {
      case 1:
      Name.printArrayToScreen();
      break;
      case 2:
      Name.addGame();
      break;
      case 3:
      Name.findPublishergame();
      break;
      case 4:
      Name.removeGame();
      break;
      case 5:
      Name.readgameData();
      break;
      case 6:
      Name.printArrayToFile("output.txt");
    }
  }
  cout << "Thank you for using our Game list" << endl;
}


int main() {
  menu();
  return 0;
}
