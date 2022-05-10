#include "ItemClass.h"
#include "ReadUtils.h"
#include <cstring>
#include <iostream>

using namespace std;

void getCstring(const char info[], char val[]){
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

void getInt(const char info[], int &val){
  cout << "Enter the amount of " << info << " of the Game: ";
  cin >> val;
  while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
      cout << "Enter the amount of " << info << "of the Game: ";
      cin >> val;
    }
}

VideoGame::VideoGame() {
for(int index = 0; index < MAX_NAME_CHAR; index++){
  publisher[index] = '0';
}
for(int index = 0; index < MAX_NAME_CHAR; index++){
  publisher[index] = '0';
}
for(int index = 0; index < MAX_NAME_CHAR; index++){
  releasedate[index] = '0';
}
for(int index = 0; index < MAX_NAME_CHAR; index++){
  developer[index] = '0';
}
for(int index = 0; index < MAX_NAME_CHAR; index++){
  platforms[index] = '0';
}
sales = 0;
}

bool VideoGame::issamepublisher(char temp[]){
  if (strcmp(publisher, temp) == 0){
    return true;
  }
  return false;
}

void VideoGame::printGame(ostream &out){
      out << title << " ";
      out << sales << " ";
      out << platforms << " ";
      out << developer << " ";
      out << publisher << " ";
      out << endl;
    }

void VideoGame::addGame() {
  cout << "enter game title: ";
    getCstring("title", title);
  cout << "enter copies sold: ";
    getInt("copies Sold", sales);
  cout << "enter platform(s): ";
    getCstring("platform", platforms);
  cout << "enter developer: ";
    getCstring("developer", developer);
  cout << "enter publisher: ";
    getCstring("publisher", publisher);
}

void VideoGame::readgame(ifstream &inFile){
    inFile.get(title, VideoGame::MAX_NAME_CHAR, ';');
    inFile.ignore(100,';');
    inFile >> sales;
    inFile.ignore(100,';');
    inFile.get(platforms, VideoGame::MAX_NAME_CHAR, ';');
    inFile.ignore(100,';');
    inFile.get(releasedate, VideoGame::MAX_NAME_CHAR, ';');
    inFile.ignore(100,';');
    inFile.get(developer, VideoGame::MAX_NAME_CHAR, ';');
    inFile.ignore(100,';');
    inFile.get(publisher, VideoGame::MAX_NAME_CHAR, '\n');
    inFile.ignore(100, '\n');
}