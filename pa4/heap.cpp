//heap.cpp
//Julian Harris

#include <iostream>
#include "heap.h"

using namespace std;

//functions

//default constructor  WORKING
WordHeap::WordHeap(){

  maxSize = MAX;
  size = 0;
  
  //make the array
  heap = new Item[MAX]; 
}

//default constructor for Item WORKING
WordHeap::Item::Item(){
  name = "nullptr"; 
}

//copy constructor
WordHeap::WordHeap(WordHeap &copy){

  heap = new Item[copy.maxSize]; 
  size = 0;
  for(int i = 1; i <= copy.size; i++)
    insert(copy.heap[i].name);
}

//copy assignment, thing already exists just insert a bunch of shit after delet
WordHeap& WordHeap::operator=(WordHeap& copy){

  for(int i = 1; i <= size; i++)
    deleteMax();
  for(int i = 1; i <= copy.size; i++)
    insert(copy.heap[i].name);
  
  return *this;
}

//desturctor
WordHeap::~WordHeap(){
  delete[] heap;
  size = 0; 
}

//insert  WORKING
void WordHeap::insert(string x){   

  size++; 
  int hole = size; 
  if(size > maxSize-1){ //checking resize
    cout << "Heap is full, resizing to ";
    resize();
    cout << maxSize << " elements\n";
  }
  //genuine insertion, index 0 holding new val temporarily
  heap[0].name = x;
  heap[0].key = x.length(); 
  
  //check if item is smaller, if so percolate up, cause maxHeap
  while(heap[0].key > heap[hole/2].key){
    heap[hole] = heap[hole/2];
    hole /= 2; 
  }
  //cout << "Inserting at index " << hole << ": " << heap[0].name << '\n';
  heap[hole] = heap[0];
}

//resize, set to user input first, then after that double //WORKING
void WordHeap::resize(){

  Item *tmp = new Item[maxSize*2];
  
  for(int i = 1; i < size; i++){
    tmp[i].key = heap[i].key;
    tmp[i].name = heap[i].name; 
  }
  delete[] heap;  //maybe swap
  heap = tmp;

  maxSize *= 2;
}

void WordHeap::percolateDown(){   //WORKING

  int hole = 1; 
  int child;
  Item tmp = heap[hole];
  bool bubbleDown = true; //not leaf
  
  //begin percolation, (DOESNT SWAP PROPERLY, DISORDER AT PRINT)
  while(bubbleDown && hole * 2 <= size){ //not at correct hole spot yet
    child = hole * 2;
    if(child != size && heap[child+1].key > heap[child].key)
      ++child;
    if(heap[child].key > tmp.key)
      heap[hole] = heap[child];
    else
      bubbleDown = false;
    if(bubbleDown)
      hole = child;
  }
  heap[hole] = tmp; 
}

//deletes the item with max key and returns the string   WORKING
string WordHeap::deleteMax(){

  string tmp = heap[1].name; 
  if(size == 0)
    cout << "The heap is empty...\n\n";
  
  heap[1] = heap[size--];
  percolateDown();
  
  return tmp;
}

//prints the left and right children of the word x in the heap WORKING
void WordHeap::printChildren(string x){

  Item tmp;
  tmp.name = x;
  tmp.key = x.length();
  int index = 1; 
  
  cout << "Printing children of " << x << "\n";
  
  //REMINDER: left child = 2*i, right child = 2*i +1, parent = i/2
  while(index <= size && heap[index].name != x)
    index++;
  
  //NOW do a print loop below x, OR say list doesn't contain it.
  if(index <= size && heap[index].name == x){
    cout << "Left child: " << heap[index*2].name << '\n'
         << "Right child: " << heap[(index*2)+1].name << "\n\n";
  }
  else
    cout << tmp.name  << " was not in heap\n\n";
}

//deletes all items and prints all the strings in the heap  WORKING
void WordHeap::makeEmpty(){ 

  cout << "Emptying the heap\n\n";

  int tmpSize = size;
  
  for(int i = 1; i <= tmpSize; i++){
    cout << deleteMax() << '\n';
  }
  size = 0;
  
  cout << "\nFinished deletion.\n\n";
}
