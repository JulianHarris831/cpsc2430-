//pa3.cpp 
//Julian Harris
//10/21/2020

//DESCRIPTION: Program reads in a list of board games and their relevant data,
//             including max players and time required to play. Allows user to
//             print specific games in the list, and filter search by games
//             user has time to play. Stores information in a BST.

//ASSUMPTIONS: User does not attempt to remove elements once list is empty.

#include <iostream>
#include <fstream>
#include <sstream>
#include "gamebst.h"

using namespace std;

//constants
const string FILENAME = "boardgames.csv";
const int LOAD_SIZE = 3;

//takes in a game list and loads it with data from a file, parsing as needed.
bool fileread(GameBST& myList);
//PRE: Empty list is passed in to be read. 

int main()
{
  GameBST myList;  //declaring tree
  int userTime = 0;
  string userSelection;
  
  cout << "\nWelcome. Loading list of games...\n\n";
  
  //loading boardgames into tree...
  if(!fileread(myList))
    return 0;

  //Height and print test
  cout << "Tree height is " << myList.getHeight() << "\n\n";
  myList.print();
  
  cout << "\nWhich game do you want to print? ";
  getline(cin, userSelection);
  myList.printGame(userSelection);
  
  //Remove and further print tests  //IF YOU NEVER FIX PUT ON BOTTOM
  cout << "\nWhich game do you want to remove? ";
  getline(cin, userSelection);
  myList.remove(userSelection);
  cout << "Here is the updated tree: \n";
  myList.print();

  cout << "\nHow much time do you have (in mins)? ";
  cin >> userTime; 
  myList.printPlayable(userTime);

  //TEST COPY CONSTRUCTOR AND COPY ASSIGNMENT
  cout << "\nCopying list with copy constructor...\n";
  GameBST myCopy(myList);
  myCopy.print();

  cout << "\nAssigning copy to original modified list.\n\n";
  myList = myCopy;
  cout << "Assignment complete\n";
  myList.print();
  
  //END OF TEST
  cout << "\nCompleted main, exiting...\n\n";
  return 0;
}

//bodies
bool fileread(GameBST& myList){

  ifstream infile;
  string load[LOAD_SIZE];
  string lineLoader;
  stringstream parser;
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File read failed, exiting...\n\n";
    return false;
  }
  else{
    while(getline(infile, lineLoader)){
      parser.str(lineLoader);
      for(int i = 0; i < LOAD_SIZE; i++){
        getline(parser, lineLoader, ',');
        load[i] = lineLoader; 
      } 
      //adding to list
      myList.insert(load[0], stoi(load[1]), stoi(load[2]));
      //clear parser to add more
      parser.clear();
    }
  }
  infile.close();
  return true;
}
