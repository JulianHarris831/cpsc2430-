//Julian Harris
//activity.cpp

#include "activity.h"
#include <iostream>

using namespace std;

//class default constructor 
ActivityList::ActivityList(){
  head = nullptr; 
}

//class copy constructor (deep copy)
ActivityList::ActivityList(ActivityList& copy){ 

  head = nullptr;
  
  ActivityNode* nodePtr = copy.head;
  
  while(nodePtr){ //be concerned about edge cases so there are no errors
    //such as 1 item, etc. enqueue will fix most though. 
    enqueue(nodePtr->name, nodePtr->price, nodePtr->rating, nodePtr->priority);
    nodePtr = nodePtr->next;
  }
}

//class descructor (yeet)
ActivityList::~ActivityList(){

  ActivityNode* nodePtr = head;
  ActivityNode* prePtr = head;
  
  while(nodePtr){
    prePtr = nodePtr;
    nodePtr = nodePtr->next;
    delete prePtr;
  }
}

//class copy assignment (assignment copy) 
ActivityList& ActivityList::operator=(const ActivityList& copy){

  //if same, return here

  //THIS IS YOUR LAST THING TO DO BEFORE FILE READ IN MAIN AND DEQUEUE
  ActivityNode* nodePtr = copy.head;
  ActivityNode* voidPtr = head; 
  ActivityNode* prePtr = voidPtr;
  
  //removing list 
  while(voidPtr){
    prePtr = voidPtr;
    voidPtr = prePtr->next;
    delete prePtr; 
  }
  head = nullptr; 
  
  //building the list
  while(nodePtr){
    enqueue(nodePtr->name, nodePtr->price, nodePtr->rating,
            nodePtr->priority);
    nodePtr = nodePtr->next; 
  }
  
  return *this;
}

//node parameterized constructor
ActivityList::ActivityNode::ActivityNode(string newName, float newPrice,
                                         float newRating, int newPriority){
  next = nullptr;
  name = newName;
  price = newPrice;
  rating = newRating;
  priority = newPriority;
}

void ActivityList::createList(ActivityList& s2, int priority){

  ActivityNode* nodePtr = head;
  
  //adds all items of given priority in current list to s2.
  if(isEmpty())
    cout << "The list is empty\n";
  else{
    while(nodePtr){
      if(nodePtr->priority == priority)
        s2.enqueue(nodePtr->name, nodePtr->price, nodePtr->rating, priority);
      nodePtr = nodePtr->next;
    }
  }
}

bool ActivityList::isEmpty(){
  return(!head);
}

void ActivityList::enqueue(string newName, float newPrice, float newRating,
                           int newPriority){
    
  ActivityNode* newPtr = new ActivityNode(newName, newPrice, newRating,
                                          newPriority);
  
  if(head == nullptr){ //first node
    head = newPtr;
    size++;
  }
  else{ //standard insert 
    ActivityNode* nodePtr = head;
    ActivityNode* prePtr = nullptr; 
    while(nodePtr->next && nodePtr->priority < newPriority){//new node for 2+
      prePtr = nodePtr; 
      nodePtr = nodePtr->next;
    }
    if(nodePtr->priority < newPriority){//new node lower priority 
      nodePtr->next = newPtr;
    }
    else if(prePtr == nullptr){ //new node is higher priority and replacing h 
      head = newPtr;
      newPtr->next = nodePtr;
    } 
    else{ //new node is higher higher priority and replacing non head element
      newPtr->next = nodePtr;
      prePtr->next = newPtr;
    }
    size++;
  }
}

void ActivityList::dequeue(string targetName){

  ActivityNode* nodePtr; 
  ActivityNode* prePtr; 
  
  if(!isEmpty()){
    nodePtr = head->next;
    prePtr = head;     
    if(head->name == targetName){ //if head is target value
      cout << "Removed " << head->name << '\n';
      head = head->next;
      delete prePtr;
    }
    else{
      //standard loop to check
      while(nodePtr->next && nodePtr->name != targetName){       
        prePtr = nodePtr;
        nodePtr = nodePtr->next;
      }
      if(nodePtr && nodePtr->name == targetName){ //patching target
        prePtr->next = nodePtr->next;
        cout << "Removed " << nodePtr->name << '\n';            
        delete nodePtr;
      }
      else{
        cout << "Target not found\n";
      }
    }
  }
  else
    cout << "List is empty\n";
}

void ActivityList::printList(){

  ActivityNode* nodePtr = head;
  int count = 1;
  
  if(isEmpty())
    cout << "Cannot print empty list.\n";
  else{
    if(head->next == nullptr){  //if list contains one element
      cout << count << ". [P" << nodePtr->priority << "] " << nodePtr->name
           << " - $" << nodePtr->price << " - " << nodePtr->rating
           << " stars\n";
    }
    else{
      while(nodePtr){  //normal execution
        cout << count << ". [P" << nodePtr->priority << "] " 
             << nodePtr->name << " - $" << nodePtr->price << " - "
             << nodePtr->rating << " stars\n";
        nodePtr = nodePtr->next;        
        count++; 
      }
    }
  }
  cout << '\n';
}

float ActivityList::getRating(string name){

  ActivityNode* nodePtr = head;

  if(isEmpty()){
    cout << "The list is empty\n";
    return 0;
  }
  
  while(nodePtr && nodePtr->name != name){
    nodePtr = nodePtr->next;
  }
  if(nodePtr->name == name)
    return nodePtr->rating;
  else{
    cout << "Value not found\n";
    return 0;
  }
}

int ActivityList::getSize(){
  return size;
}
