 //Julian Harris
//recursiveQueue.cpp

#include <iostream>
#include "recursiveQueue.h"

using namespace std;


//Initial construction of class.
recursiveQueue::recursiveQueue(){
  arr = new int[maxSize];
  size = 0;

  for(int i = 0; i < maxSize; i++)
    arr[i] = 0;
}

//Checks if arr has no values
bool recursiveQueue::isEmpty(){
  return size == 0;
}

//assigns this everything in the copy. 
recursiveQueue& recursiveQueue::operator=(const recursiveQueue copy){
  //starts by resetting array
  delete[] arr;
  maxSize = 3;
  size = 0;
  arr = new int[maxSize];
  
  //go through copy and give all of it to this with enqueue
  for(int i = 0; i < copy.size; i++)
    enqueue(copy.arr[i]);
  size = copy.size;
  
  return *this;
}

//adding new values to end of queue, resizes if necessary
void recursiveQueue::enqueue(int newVal){

  size++;
  //if resize
  if(size > maxSize){
    maxSize = maxSize * 2;
    int *temp = new int[maxSize];
    for(int i = 0; i < size-1; i++)
      temp[i] = arr[i];
    temp[size-1] = newVal;
    delete[] arr; 
    arr = temp;
  }
  else
    arr[size-1] = newVal;
}

int recursiveQueue::dequeue(){
  if(isEmpty()){
    cout << "Queue is empty, cannot dequeue.\n";
    return 0;
  }
  
  size--;
  int temp = arr[0];

  //might ree if size starts at 1 here, maybe fill arr with zeros to start?
  for(int i = 0; i < size; i++)
    arr[i] = arr[i+1];
  
  return temp;
}

//destructor, not deleting here to avoid a double free space and core dump
recursiveQueue::~recursiveQueue(){
  //delete[] arr;
  //arr = nullptr; 
}

//recursive print function
void recursiveQueue::print(){

  cout << "\nPrinting array...\n";
  print(0);
}

//helper for recursive print
void recursiveQueue::print(int count){
  
  if(count+1 == size) //base case
    cout << arr[count] << "\n\n"; 
  else{
    cout << arr[count] << ", "; //standard print
    print(count+1);
  } 
}

void recursiveQueue::recInsert(int newVal){

  if(newVal >= 10){
    recInsert(newVal / 10);
    enqueue(newVal % 10);
  }
  else
  enqueue(newVal);
}

//takes array and doubles
void recursiveQueue::doubleEven(){

  cout << "Doubling even indexes\n";

  int count = 0;
  doubleEven(count);
}

//helper function for above
void recursiveQueue::doubleEven(int count){
  
  if(count < size){
    if(count % 2 == 0) //doubles point if even
      arr[count] = arr[count] * 2;
    doubleEven(count+1);
  }
}

int recursiveQueue::sumBiggerX(int x){

  int sum = 0;
  sum += sumBiggerX(x, size);
  return sum;
}

//helper
int recursiveQueue::sumBiggerX(int x, int sizeCopy){
  
  if(sizeCopy == 1){
    if(arr[0] > x)
      return arr[0];
  }
  else{
    if(arr[sizeCopy-1] > x)
      return arr[sizeCopy-1] + sumBiggerX(x, sizeCopy-1);
    return sumBiggerX(x, sizeCopy-1);
  }
  return 0;
}
