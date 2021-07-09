//Julian Harris
//pa1.cpp
//DATE SUBMITTED REVISE THIS YOU DUMBASS

//DESCRIPTION: This program is intended to read in a list of activites and
//             store them in a priority queue, with options to sort and
//             modify list.

#include "activity.h"
#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std;

//constants, typedefs
const string FILENAME = "activities.csv";
const int LOAD_SIZE = 4;

//fileread for loading list
bool fileread(ActivityList& myList); 


int main()
{
  ActivityList myList;

  cout << "\nWelcome to ActivityList testing!\n\n";
    
  myList.dequeue("Pallet Town"); //test of dequeue empty list edge
  
  if(!fileread(myList))
    return 0;

  cout << "Printing myList.\n\n";
  myList.printList();  //testing standard initialization of list

  ActivityList test1List(myList); //test of copy constructor

  cout << "Printing test1List\n\n";
  test1List.printList(); 

  //test of dequeue edge cases, last element, first, and second
  test1List.dequeue("Beneath the Streets Tour"); 
  test1List.dequeue("Space Needle");
  test1List.dequeue("Pike Place Market");
  test1List.dequeue("Seattle Great Wheel");

  cout << "Assigning test1List to myList\n";
  myList = test1List; 
  
  cout << "Printing revised myList\n\n"; //printing to show removals
  myList.printList();
  
  ActivityList test2List;

  //testing createList
  cout << "Adding elements of priority 1 from myList to test2List\n";
  myList.createList(test2List, 2);
  cout << "Printing test2List.\n";
  test2List.printList(); 

  //final test of getRating and getSize
  cout << "The rating of Chihuly Garden and Glass is "
       << test2List.getRating("Chihuly Garden and Glass") << '\n';
  cout << "The size of test2List is " << test2List.getSize() << '\n'
       << "\n";
  
  return 0;
}

//function bodies
bool fileread(ActivityList& myList){
  
  ifstream infile;
  string load[LOAD_SIZE]; 
  string lineLoad;
  stringstream parser; 
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File read failed. Exiting program...\n\n";
    return false;
  }
  else{
    while(getline(infile, lineLoad)){
      parser.str(lineLoad); 
      
      for(int i = 0; i < LOAD_SIZE; i++){
        getline(parser, lineLoad, ',');
        load[i] = lineLoad;
      }                           
      
      //enqueue
      myList.enqueue(load[0], stof(load[1]), stof(load[2]), stoi(load[3]));
      
      //clear parser
      parser.clear();
    }
  }
  cout << '\n';
  infile.close();
  return true;
}
