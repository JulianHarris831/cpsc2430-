//Julian Harris
//activity.h

#include <iostream>

using namespace std;

//class to store relevant list data and perform operations
class ActivityList
{
private:
  //list data members, exclusively the list itself and its head. 
  class ActivityNode
  {
  public:
    //elements of node
    string name;
    float price;
    float rating; 
    int priority; 
    ActivityNode *next;

    //node constructor 
    ActivityNode(string newName, float newPrice, float newRating,
                 int newPriority); 
  };
  ActivityNode *head = nullptr; 
  int size = 0;
  
public:
  //list operations

  //default constructor
  ActivityList(); 
  
  //copy constructor, initializes a new list
  ActivityList(ActivityList& copy);

  //default destructor
  ~ActivityList();
  
  //copy assignment of a created list to another created list
  ActivityList& operator=(const ActivityList& copy);  

  //adds elements of current class list to s2 of given priority
  void createList(ActivityList& s2, int priority);
  
  bool isEmpty();
  
  //insert function 
  void enqueue(string newName, float newPrice, float newRating,
               int newPriority);

  //removes given list elements with targetName
  void dequeue(string targetName);
  
  int getSize();

  //returns the rating of element with target name
  float getRating(string name);
  
  void printList();
};
