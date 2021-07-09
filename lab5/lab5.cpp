//lab5.cpp
//Julian Harris
//10/16/2020

//DESCRIPTION: Program creates a heap with 14 integers of random size, then
//             allows the user to remove them in inputted increments. Largest
//             value is always removed. 

//ASSUMPTIONS: None

#include <iostream>
#include <ctime>  //included to generate random numbers

using namespace std;

const int SIZE = 15; //size of the array
const int MIN = 1;  //range of random numbers
const int MAX = 25; 

//functions
void insert(int arrHeap[], int& currentSize, int newVal);
//Given array, size, and a random value, inserts something into the heap.
//PRE: Array has space for a value to be inserted.
//POST: None

int deleteMax(int arrHeap[], int& currentSize);
//Given array and size, deletes largest value in array, arr[1]. 
//PRE: Array has values to be deleted
//POST: None

void percolateDown(int arrHeap[], int hole, int size);
//Helper function for deleteMax

void print(int arrHeap[], int size);
//Outputs in order of array the contents of the heap

int main()
{
  int currentSize = 0;
  int arrHeap[SIZE];  //array implementation of heap
  int userVal = 0;   //used to store user selection of deleting

  srand(time(0)); //to generate random numbers
  
  cout << "\nFilling queue with random integers\n\n";  
  for(int i = 1; i < 15; i++)   //heap loaded with 14 random ints
    insert(arrHeap, currentSize, rand() % ((MAX - MIN) + 1) + MIN);

  print(arrHeap, currentSize); //printed stuff 

  while(currentSize != 0){  //while array still has stuff to delete
    cout << "Enter a positive integer: ";
    cin >> userVal; 

    if(userVal <= currentSize){  //ensures userVal is valid
      for(int i = 1; i <= userVal; i++){  //removes values as requested
        cout << "Removing biggest value " << i << "...\n"
             << deleteMax(arrHeap, currentSize) << '\n';
      }
      print(arrHeap, currentSize);
    }
    else
      cout << "Invalid input, try again.\n";
  }
  cout << "Program finished. Exiting...\n";
}


//bodies
void insert(int arrHeap[], int& currentSize, int newVal){
  
  if(currentSize == SIZE-1)
    cout << "Queue is already full.\n\n";
  else{
    int hole = ++currentSize;  
    arrHeap[0] = newVal; //first index holds temp values
    
    //percolate up
    while(newVal > arrHeap[hole/2]){
      arrHeap[hole] = arrHeap[hole/2];
      hole /= 2;
    }
    arrHeap[hole] = arrHeap[0]; //:0
  }
}

int deleteMax(int arrHeap[], int& currentSize){
  
  int tempVal = arrHeap[1];
  
  arrHeap[1] = arrHeap[currentSize--];
  percolateDown(arrHeap, 1, currentSize);
  
  return tempVal;
}

void percolateDown(int arrHeap[], int hole, int size){

  int child;
  int tmp = arrHeap[hole];
  bool bubbleDown = true; //not leaf

  while(bubbleDown && hole * 2 <= size){
    child = hole * 2;
    if(child != size && arrHeap[child+1] > arrHeap[child])
      ++child;
    if(arrHeap[child] > tmp)
      arrHeap[hole] = arrHeap[child];
    else
      bubbleDown = false;
    if(bubbleDown)
      hole = child;
  }
  arrHeap[hole] = tmp;
}

void print(int arrHeap[], int size){

  cout << "Printing heap\n\n";

  for(int i = 1; i <= size; i++)
    cout << i << ": " << arrHeap[i] << '\n';
  cout << '\n';
}
