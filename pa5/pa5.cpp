//pa5.cpp
//Julian Harris
//11/16/20

//DESCRIPTION: Program loads in list of books into an array of linked lists.
//User is able to read and remove books, display the list, find books with
//the same author, and display detailed info about a given book, with the ISBN.

//ASSUMPTIONS: User does not attempt to load anything other than integers
//into the choices. 

#include <iostream>
#include "hash.h"
#include <fstream>
#include <sstream>

using namespace std;

const string FILENAME = "books-sample.csv";

//Takes the arr and fills it with books. Returns false if it fails. 
bool fileRead(HashTable &library);
//PRE: HashTable is declared in main and ready to be loaded.
//POST: None

int main()
{
  int choice = 0; //controls menu choices
  long ISBNChoice = 0; //allows the user to select specific books
  HashTable library; //declaration of arr of linked lists

  if(!fileRead(library)) //loading books into library
    return 0; 
  
  //start of menu loop
  cout << "\nWelcome! What would you like to do?\n\n";
  while(choice != 5){
    cout << "****************************\n";
    cout << "1. Browse for books\n2. Read a book\n3. View more info about a"
         << "book\n4. Get a recommendation\n5. Quit\nChoice: ";
    cin >> choice;
    cout << "\n";

    if(choice == 1){ //browsing for books, gives whole list of name and ISBN
      cout << "Displaying list...\n\n";
      library.displayAll();
    }
    if(choice == 2){ //show that book was read, then remove from list
      cout << "Enter the ISBN of the book you want to read: ";
      cin >> ISBNChoice;
      library.readBook(ISBNChoice); 
    }
    if(choice == 3){ //gives all info about selected book
      cout << "Enter the ISBN of the book: ";
      cin >> ISBNChoice;
      cout << "Displaying title info...\n\n";
      library.bookInfo(ISBNChoice);
    }
    if(choice == 4){ //get a recommendation (prints books w/same author)
      cout << "Enter the ISBN of the book that you liked: ";
      cin >> ISBNChoice; 
      cout << "Displaying books with same author...\n\n";
      library.recommend(ISBNChoice);
    }
  }
  
  cout << "Program finished. Exiting...\n\n";
  
  return 0;
}


bool fileRead(HashTable &library){
 
  string lineLoad;
  ifstream input;
  stringstream ss;
  string row[5];
  string load;
  int index; 

  input.open(FILENAME);

  if(input.fail()){
    cout << "File read failed. Exiting program...\n\n";
    return false;
  }
  else{  
    while(getline(input, lineLoad)){
      ss.str(lineLoad);
      index = 0;
      while(ss.good()){
        getline(ss, load, ',');
        row[index] = load;
        index++;
      }
      Book *newEntry = new Book(row[0], row[1], stof(row[2]),
                                stol(row[3]), stoi(row[4]));
      //cout << newEntry->getISBN() << " ISBN added...\n";
      library.addToBookshelf(stol(row[3]), newEntry);

      ss.clear();
    }
    input.close();
  }
  return true;
}
