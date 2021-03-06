//Julian Harris
//lab6.cpp 

//DESCRIPTION: Program loads a given list of books (class) into an array,
//             using hashed ISBN codes as indexes to sort. Prints any collision
//             and displays full shelf at the end. 

//ASSUMPTIONS: None, program is automated with no user input

#include <iostream>
using namespace std;

int const SIZE = 13; //size of shelf

class Book{
private:
  string title; //book data
  long ISBN;
  
public:
  //default constructor
  Book(){
    title = "";
    ISBN = -1; 
  }

  //parameterized constructor
  Book(string newTitle, long newKey){
    title = newTitle;
    ISBN = newKey; 
  }

  //getter function for ISBN 
  long getISBN(){
    return ISBN;
  }

  //basic print function to display shelf, only prints titles if there is
  //a book at the current index. index must be passed in
  void print(int i){ 
    cout << "Bookshelf[" << i << "]-----------";
    if(ISBN != -1)
      cout << "\nTitle: " << title << "\nISBN: " << ISBN;
    cout << "\n\n";
  }
};

//main functions

//basic hash function, modding table size to find index
int hashFunc(long longKey){
  return longKey % SIZE;
}

//inserts book into shelf, hasing is done here
bool addBook(string newTitle, long newKey , Book bookshelf[]){

  //make the book
  Book newBook(newTitle, newKey); 
  
  int index = hashFunc(newBook.getISBN());
  if(bookshelf[index].getISBN() != -1){
    cout << "Collission at index " << index << '\n';
    return false;
  }
  bookshelf[index] = newBook;
  return true; 
}


int main()
{
  int collisions = 0; //keeping count # of collisions
  Book bookshelf[SIZE]; 
  
  string titleArr [] = {"Sherlock Holmes: The Complete Novels and Stories",
  "The Very Hungry Caterpillar","Goodnight Moon","On the Night You Were Born",
  "The Kissing Hand","The Monster at the End of this Book",
  "The Story of Ruby Bridges","The Road Not Taken and Other Poems",
  "The Cat in the Hat and Other Dr. Seuss Favorites","Green Eggs and Ham",
  "One Morning in Maine","The Glass Castle","A Child's Garden of Verses",
  "Twenty Love Poems and a Song of Despair","The Lorax",
  "Letters to a Young Poet","The Body","The Missing Piece Meets the Big O",
  "Matilda","Harry Potter and the Sorcerer's Stone"};
  long isbnArr [] = {9780553212419,9780241003008,9780060775858,9780312346065,
    9781933718002,9780375829130,9780439598446,9780486275505,9780807218730,
    9780394800165,9780140501742,9780743247542,9780689823824,9780143039969,
    9780679889106,9780486422459,9780582418172,9780060256579,9780141301068,
    9780439554930};

  //loading books into shelf
  cout << '\n';
  for(int i = 0; i < 20; i++){
    if(!addBook(titleArr[i], isbnArr[i], bookshelf))
      collisions++;
  }
  cout << "There were " << collisions << " collisions.\n\n";

  //printing list of books...
  for(int i = 0; i < SIZE; i++)
    bookshelf[i].print(i);
  
  return 0;
}
