//Julian Harris
//pa4.cpp 
//11/2/2020

//DESCRIPTION: Program creates a max heap with dynamic array implementation to
//             store words entered by the user. Allows user to print children
//             of the words in the heap, and shows all values entered once
//             heap is made empty. 

//ASSUMPTIONS: User enters a positive integer as the size of the heap. 

//this is an edit for the makefile

#include <iostream>
#include "heap.h"

using namespace std;

//initial array size is 5 (4); 

int main()
{
  WordHeap myTest; //class heap to store words in
  int userAdding;  //size user enters, how many values will be added
  string userWord; //var to store temporarily values user inserts

  cout << "\nHow many values do you want to add to the heap? ";
  cin >> userAdding;
  cin.ignore();

  //test of insert
  for(int i = 0; i < userAdding; i++){
    cout << "Enter a word you want to add: ";
    getline(cin, userWord);
    myTest.insert(userWord);
  }
  cout << '\n';

  //test of printChildren
  for(int i = 0; i < 2; i++){
    cin.ignore();
    cout << "Enter a word you want to print the children of: ";
    getline(cin, userWord); 
    myTest.printChildren(userWord);
  }

  //test of copy constructor and copy assignment
  WordHeap myCopy(myTest);
  WordHeap myAssignment;
  myAssignment = myCopy; 

  //test of makeEmpty
  myAssignment.makeEmpty();
  
  return 0;
}

//bodies
