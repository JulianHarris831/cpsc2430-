//hash.h
//Julian Harris
//11/16/20

#include <iostream>
#include "book.h" 

using namespace std;

const int SHELF_SIZE = 11;  //max size of array

class HashTable
{
 private:
  //arr of BookNodes
  class BookNode
  {
  public:
    Book *value;
    long ISBN; 
    BookNode *next;
    BookNode();  //default constructor
    BookNode(Book *newValue, long newKey); //paramaterized constructor
  };
  BookNode **bookshelf;
    
public:
  //constructor default
  HashTable(); 

    //destructor
  ~HashTable();
  
  //hash function
  int hash(long key); //return key % SHELF_SIZE

  //contains function
  int contains(long key);
  
  //insert function
  void addToBookshelf(long newKey, Book *newValue);
  
  //if book is not on bookshelf, return false. else print read and return.
  bool readBook(long key); 

  //If the key exists, display info about the book. Else, print not found.
  //Separate authors with a comma. 
  void bookInfo(long key);

  //displays the title and ISBN of all books on the shelf
  void displayAll();

  //displays title and ISBN of all books with same author as given book.
  void recommend(long key);
};
