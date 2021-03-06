//Julian Harris
//lab2.cpp
//9/18/2020

//DESCRIPTION: Program sets a dynamic array based on user input then
//             allows user to add or remove values until array is full
//             or the user quits. 

//ASSUMPTIONS: User uses lower case letters, user enters a nonzero size for
//             array.

#include <iostream>

using namespace std;

//Setting typedef in case floating point is required for ease of change
typedef int valueType; 

void push(valueType *reverseStack, valueType newVal, int& arrSize);
//Adds a value to the array.
//PRE: User passes a value greater than current top of stack, stack is not full

valueType pop(valueType *reverseStack, int& arrSize);
//Removes a value from the array, returns it to main.
//PRE: User does not attempt to remove a value from an empty array. 

void print(valueType *reverseStack, int& arrSize);

int main()
{
  //vars for controlling array size and loops to add more data 
  int arrMax = 0;
  char choice = 'z';
  int arrSize = 0; 
  valueType newValue; 
  
  cout << "\nStack size: ";
  cin >> arrMax;
  cout << '\n';

  valueType *reverseStack = new valueType[arrMax];  

  //loop to allow user to add as many values as desired until full
  while(choice != 's' && arrSize < arrMax){
    cout << "Do you want to push (p), pop(o), or stop (s)?\n"
         << "Choice: ";
    cin >> choice;
    
    //if statements for push and pop 
    if(choice == 'p'){
      cout << "Input: ";
      cin >> newValue;
      push(reverseStack, newValue, arrSize);
    }
    if(choice == 'o'){
      if(arrSize == 0)
        cout << "Stack is empty.\n"; 
      else{
        cout << "Removed " << pop(reverseStack, arrSize) << '\n';
      }
    }
    cout << "\n";
  }

  //printing final product
  print(reverseStack, arrSize);
  
  return 0;
}

void push(valueType *reverseStack, valueType newVal, int& arrSize){

  if(newVal > reverseStack[arrSize] || arrSize == 0){
    reverseStack[arrSize] = newVal;
    arrSize++;
  } else
    cout << "Input is too small.\n";
}

valueType pop(valueType *reverseStack, int& arrSize){

  arrSize--;
  valueType temp = reverseStack[arrSize];
  reverseStack[arrSize] = 0;
  
  return temp; 
}

void print(valueType *reverseStack, int& arrSize){

  for(int i = 0; i < arrSize; i++)
    cout << "Reverse Stack: " << reverseStack[i] << ' ';
  cout << "\n\n";
}
