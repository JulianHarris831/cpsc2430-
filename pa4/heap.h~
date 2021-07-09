//WordHeap.h
//Julian Harris

#include <iostream>

using namespace std;

//size of heap, (4)
const int MAX = 5; 

class WordHeap
{
private:
  class Item 
  {
  public:
    string name; 
    int key;  //key is # of characters in the string
    Item(); 
  };
  Item *heap;   //initialize empty arr
  int size;
  int maxSize; 
  //helper functions
  void resize();
  void percolateDown();
  
public:
  //default constructor
  WordHeap();
  
  //copy constructor
  WordHeap(WordHeap &copy);
  
  //copy assignment
  WordHeap& operator=(WordHeap& copy);
  
  //destructor
  ~WordHeap();
  
  //inserts an item in the heap based on the string passed in. heap grows
  //if it needs to
  void  insert(string x);

  //deletes the Item with max key and returns the string
  string deleteMax();

  //prints the left and right children of the word x in the heap
  void printChildren(string x);

  //deletes all items and prints all the strings in the heap
  void makeEmpty();
  
};
