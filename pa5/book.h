//book.h
//Julian Harris

#include <iostream>

using namespace std;

//book class is meant to hold the data of each node. hash will have hash
//functions and such but its method of storing will be books

class Book
{
 private:
  //class vars/helpers
  string title, authors;
  float rating;
  long ISBN;
  int pages; 
 public:
  //class functions
  Book(); 
  Book(string newTitle, string newAuthors, float newRating, //parameterized 
       long newISBN, int newPages);                         //constructor
  long getISBN();
  string getTitle();
  string getAuthors(); 
  void printBook(); //prints title and ISBN
  void printBookInfo(); //prints all data relevant to book
};
