//Julian Harris
//pa2.cpp

//DESCRIPTION: Program builds a queue with linked list implementation to be
//             filled with values the user inserts. Allows doubling of even
//             indexes, printing, and selective summation. 

//ASSUMPTIONS: User does not provide non integer elements. 

#include <iostream>
#include "recursiveQueue.h"

using namespace std; 

int main(){

  //vals
  recursiveQueue myRecursion; 
  recursiveQueue myCopy;
  int userInput = 0;
  int sum;
  int sumCounter;
  
  cout << "\nBeginning of tests for recursiveQueue.\n\n"
       << "Please enter a positive integer: ";
  cin >> userInput;
  
  // TEST OF recInsert and doubleEven
  myRecursion.recInsert(userInput);
  myRecursion.print();
  myRecursion.doubleEven();
  myRecursion.print();
  cout << "Insert an int: ";
  cin >> sumCounter; 
  cout << "Sum of elements bigger than that is ";
  sum = myRecursion.sumBiggerX(sumCounter); //test of sum 
  cout << sum << "\n";

  cout << "Testing copy assignment...\n"; //test of copy
  cout << "Inserting 54321\n";
  myCopy.recInsert(54321);
  myCopy.print();
  cout << "Copying 1st queue to second\n";
  myRecursion = myCopy;
  myRecursion.print();

  cout << "Dequeued value is " << myRecursion.dequeue();
  
  cout << "\nSuccessful run. Exiting...\n\n";

  return 0;
}
