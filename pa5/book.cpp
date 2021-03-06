//book.cpp
//Julian Harris

#include <iostream>
#include "book.h"

using namespace std;

//constants

Book::Book(){
  ISBN = -1; 
}

Book::Book(string newTitle, string newAuthors, float newRating,
           long newISBN, int newPages){
  
  title = newTitle;
  authors = newAuthors;
  rating = newRating;
  ISBN = newISBN;
  pages = newPages; 
}

long Book::getISBN(){
  return ISBN;
}

string Book::getTitle(){
  return title;
}

string Book::getAuthors(){
  return authors; 
}

void Book::printBook(){

  //to avoid getters, print basic book info in loop to show all
  cout << "Title: " << title << "\nISBN: " << ISBN << "\n\n";
}

void Book::printBookInfo(){

  //print all book info in targeted print
  cout << "Title: " << title << "\nAuthors: " << authors << "\nISBN: "
       << ISBN << "\nPages: " << pages << "\nRating: " << rating << "\n\n";
}
