//Julian Harris
//recursiveQueue.h

#include <iostream>

using namespace std;

class recursiveQueue
{
private:
  //vars and helper functions
  int *arr;
  int size = 0;
  int maxSize = 3;
  //helpers
  void doubleEven(int count);
  void print(int count);
  int sumBiggerX(int x, int sizeCopy);
  
public:
  //default consturctor
  recursiveQueue();
  
  //copy assignment overload operator, assigns values in one class to another
  recursiveQueue& operator=(const recursiveQueue copy);      
  
  bool isEmpty();
  
  //adds an element to the end of the list
  void enqueue(int newVal);

  //dequeue, removes an element from the front of the list, returns value
  int dequeue(); 

  //default destructor
  ~recursiveQueue();

  //recursive print
  void print();

  //recursive insert, in order gives digits of any int one at a time to queue
  void recInsert(int newVal);

  //recursively doubles the values at even indexes in the list
  void doubleEven();

  //recursive, adds all values in array bigger than x to sum, returns sum.
  int sumBiggerX(int x);
};
