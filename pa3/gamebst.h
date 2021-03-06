//gamebst.h
//Julian Harris

#include <iostream>

using namespace std;

class GameBST
{
private:
  //private variables and helper function
  struct TreeNode{ //linked list storage for data
    string key;
    int maxPlayers;
    int playtime;
    TreeNode* left;
    TreeNode* right; 
  };
  TreeNode* root; 
  //helpers
  void print(TreeNode* nodePtr); 
  void insert(TreeNode* &nodePtr, TreeNode* &newPtr);
  void clearTree(TreeNode* nodePtr);
  bool contains(string name, TreeNode* nodePtr);
  void remove(string name, TreeNode* &nodePtr);
  TreeNode* findMin(TreeNode* nodePtr);
  void printPlayable(int timeLeft, TreeNode* nodeptr);
  int getHeight(int& height, int count, TreeNode* nodePtr);
  void copyTree(TreeNode* copyPtr);
  
public:
  
  //default constructor, sets root nullptr
  GameBST();
  
  //copy constructor, creates a new GameBST identical to copy passed in. 
  GameBST(GameBST &copy);
  //PRE: Must have a copy class to pass in
  
  //deconstructor, deallocates all data in list, sets root nullptr
  ~GameBST();
  
  //copy assignment, copies data in current class to already declared copy
  GameBST& operator=(GameBST& copy);
  //PRE: Must have two already created classes, one to copy to and one original
  
  //insert adds a boardgame with name, # of players, and duration
  void insert(string newKey, int newMax, int newTime);
  //PRE:
  
  //removes selection if in the tree
  bool remove(string name);
  //PRE:Needs values to be removed
  
  //returns the height of the tree
  int getHeight();
  //PRE: Must have a tree to analyze. 
  
  //prints list of games in alphabetical order.
  void print();
  //PRE: Must have a tree list with values to print
  
  //printGame prints a specific selected game and relevant data
  void printGame(string name);
  //PRE: Requires value to be passed in by user. 

  //printPlayable prints all games that user has time to play. uses postorder
  void printPlayable(int timeLeft);
  //PRE: Must have a tree to check, value passed in by user to compare to.
};
