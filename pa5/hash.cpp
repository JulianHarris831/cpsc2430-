//hash.cpp
//Julian Harris

#include <iostream>
#include "hash.h"

using namespace std;

//class functions

//default constructor for list
HashTable::HashTable(){

  bookshelf = new BookNode*[SHELF_SIZE];
  //must fill with empty books
  for(int i = 0; i < SHELF_SIZE; i++)
    bookshelf[i] = new BookNode(); 
}

//deconstructor for list
HashTable::~HashTable(){

  BookNode *nodePtr;
  BookNode *prePtr; 
  
  for(int i = 0; i < SHELF_SIZE; i++){
    nodePtr = bookshelf[i]->next;
    while(nodePtr){
      prePtr = nodePtr;
      nodePtr = nodePtr->next;
      delete prePtr; 
    }
  }  
  delete bookshelf;
}

//default constructor for book node
HashTable::BookNode::BookNode(){
  ISBN = -1;
  value = nullptr;
  next = nullptr; 
}

//parameterized constructor for book node
HashTable::BookNode::BookNode(Book *newValue, long newKey){

  value = newValue;
  ISBN = newKey;
  next = nullptr; 
}

//hash function
int HashTable::hash(long key){
  
  return key % SHELF_SIZE;
}

//contains function
int HashTable::contains(long key){

  BookNode *nodePtr;
  bool found = false;
  int count = 0;
  
  while(!found && count < SHELF_SIZE){
    nodePtr = bookshelf[count]->next; 
    while(!found && nodePtr){
      if(key == nodePtr->value->getISBN())
        found = true;
      nodePtr = nodePtr->next; 
    }
    count++; 
  }

  if(found)
    return count-1;
  
  return -1;
}

//insert function
void HashTable::addToBookshelf(long newKey, Book *newValue){

  BookNode* newNode = new BookNode(newValue, newKey); 
  int index = hash(newKey);
  
  //if first in list
  if(bookshelf[index]->next == nullptr)
    bookshelf[index]->next = newNode;
  else{ //classic traversal
    BookNode* nodePtr = bookshelf[index]->next;
    while(nodePtr->next){
      nodePtr = nodePtr->next; 
    }
    nodePtr->next = newNode;  //issue: var nodePtr is not replacing 
  }
}

//if book is not on bookshelf, return false. else print read and return
bool HashTable::readBook(long key){

  int index = contains(key);
  
  if(index == -1) //not in bookshelf
    return false;

  //remove book here, also print. need nodePtr and prePtr
  BookNode *nodePtr = bookshelf[index]->next;
  BookNode *prePtr = bookshelf[index];

  while(nodePtr->next && key != nodePtr->value->getISBN()){ //seg fault
    prePtr = nodePtr;
    nodePtr = nodePtr->next;
  }
  cout << "Reading the book " << nodePtr->value->getTitle() << ". "
       << "Removed it from the bookshelf!\n\n";
  delete nodePtr; 
  prePtr->next = nodePtr->next; 
  
  return true; 
}

//if the key exists, display info about the book. else, print not found.
//separate authors with a comma.
void HashTable::bookInfo(long key){

  int index = contains(key);
  
  if(index == -1)
    cout << "Book is not in list...\n\n";
  else{
    BookNode *nodePtr = bookshelf[index]->next;
    if(key == nodePtr->value->getISBN())
      nodePtr->value->printBookInfo();
  }  
}

//display the title and ISBN of all books on the shelf
void HashTable::displayAll(){

  BookNode *nodePtr;
  
  for(int i = 0; i < SHELF_SIZE; i++){
    nodePtr = bookshelf[i]->next;  
    
    while(nodePtr != nullptr){
      nodePtr->value->printBook();  //nodePtr is NOT an arr
      nodePtr = nodePtr->next; 
    }
  }
}

//final function, runs through list and prints books that have same author
//as given book
void HashTable::recommend(long key){
  
  if(contains(key) == -1)
    cout << "Book is not in list...\n\n";
  else{
    string authors;
    int index = hash(key);
    BookNode *nodePtr = bookshelf[index]; 
    
    while(nodePtr->next && key != bookshelf[index]->ISBN)
      nodePtr = nodePtr->next;
    authors = nodePtr->value->getAuthors();

    //print loop
    for(int i = 0; i < SHELF_SIZE; i++){
      nodePtr = bookshelf[i]->next;
      while(nodePtr != nullptr){
        if(authors == nodePtr->value->getAuthors())
          nodePtr->value->printBook();
        nodePtr = nodePtr->next;
      }
    }
  }
}
