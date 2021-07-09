//gamebst.cpp
//Julian Harris

#include <iostream>
#include "gamebst.h"

using namespace std;

//default constructor
GameBST::GameBST(){
  
  root = nullptr;
}

//copy constructor 
GameBST::GameBST(GameBST &copy){

  root = nullptr;
  
  //for sure use inorder traversal. has to be recursive too no? if so helper
  TreeNode* copyPtr = copy.root;
  copyTree(copyPtr);
}

//copy helper      
void GameBST::copyTree(TreeNode* copyPtr){
  
  if(copyPtr){
    insert(copyPtr->key, copyPtr->maxPlayers, copyPtr->playtime);
    copyTree(copyPtr->left);
    copyTree(copyPtr->right);
  }
}

//deconstructor, postOrder traversal deletes data at all nodes in tree
GameBST::~GameBST(){
  
  clearTree(root);
  root = nullptr;
}

//deconstructor helper    
void GameBST::clearTree(TreeNode* nodePtr){
  
  if(nodePtr){
    if(nodePtr->left)
      clearTree(nodePtr->left);
    else
      clearTree(nodePtr->right);
    delete nodePtr;
    nodePtr = nullptr; 
  }  
}
    
//copy assignment
GameBST& GameBST::operator=(GameBST& copy){   

  //ensure our copy is empty. 
  clearTree(root);  
  root = nullptr; 
  
  //reuse copy constructor helper
  copyTree(copy.root);
  
  return *this; 
}

//insert 
void GameBST::insert(string newKey, int newMax, int newTime){
  
  TreeNode* newPtr = new TreeNode;
  newPtr->key = newKey;
  newPtr->maxPlayers = newMax;
  newPtr->playtime = newTime;
  newPtr->left = nullptr;
  newPtr->right = nullptr;
  
  if(root == nullptr)
    root = newPtr;
  else{
    TreeNode* nodePtr = root; 
    insert(nodePtr, newPtr);
  }

}
//insert helper
void GameBST::insert(TreeNode* &nodePtr, TreeNode* &newPtr){
  
  if(nodePtr == nullptr)
    nodePtr = newPtr;
  else{
    if(nodePtr->key > newPtr->key)
      insert(nodePtr->left, newPtr);
    else
      insert(nodePtr->right, newPtr);
  }
}

//remove selection
bool GameBST::remove(string name){  //having seg fault after removal.
  
  if(!contains(name, root))
    return false;
  
  remove(name, root);
  
  return true;
}

//helper for remove
void GameBST::remove(string name, TreeNode* &nodePtr){

  cout << "Entered remove loop\n";
  
  if(!nodePtr)
    return;
  if(name < nodePtr->key)
    remove(name, nodePtr->left);
  else if(name > nodePtr->key)
    remove(name, nodePtr->right);
  else if(nodePtr->left != nullptr && nodePtr->right != nullptr){ //2 children
    nodePtr->key = findMin(nodePtr->right)->key;
    remove(nodePtr->key, nodePtr->right);
  }else{
    cout << "Entered actual deletion\n";
    TreeNode* oldNode = nodePtr;
    nodePtr = (nodePtr->left != nullptr) ? nodePtr->left : nodePtr->right; 
    cout << oldNode->key;
    delete oldNode;
    oldNode = nullptr;
  }
}

GameBST::TreeNode* GameBST::findMin(TreeNode* nodePtr){

  cout << "Entered findmin\n";
  if(nodePtr == nullptr)
    return nullptr;
  if(nodePtr->left == nullptr)
    return nodePtr;
  cout << "End of findmin\n";
  return findMin(nodePtr->left);
}

bool GameBST::contains(string name, TreeNode* nodePtr){
  
  if(!nodePtr)
    return false; 
  else{
    if(nodePtr->key == name)
      return true;
    else{
      if(nodePtr->key > name)
        return contains(name, nodePtr->left);
      else
        return contains(name, nodePtr->right);
    }
  }
  return false;
}

//returns height
int GameBST::getHeight(){

  int height = 0;
  int count = 0;
  TreeNode* nodePtr = root;

  //get height call
  
  height = getHeight(height, count, nodePtr);
  
  return height-1;
}

//height helper
int GameBST::getHeight(int& height, int count, TreeNode* nodePtr){
  
  if(nodePtr){
    getHeight(height, count+1, nodePtr->left);
    getHeight(height, count+1, nodePtr->right);
  }
  else if(count > height){ //if current is deeper than anything already seen
    height = count;
  }
  return height; 
}

//prints whole list of games inorder LCR (PRINTING) MAKE THIS ONE SECOND
void GameBST::print(){
  
  //if empty throw exception

  cout << "Printing list...\n\n";
  TreeNode* nodePtr = root;
  print(nodePtr);
}

//helper for main print
void GameBST::print(TreeNode* nodePtr){

  //left, current, right
  if(nodePtr){
    print(nodePtr->left);
    cout << nodePtr->key << '\n';
    print(nodePtr->right);
  }
}

//prints specific selected game
void GameBST::printGame(string name){

  if(!contains(name, root))
    cout << "Game is not in list\n";
  else{
    TreeNode* nodePtr = root;
    
    while(nodePtr && nodePtr->key != name){ //seg fault this line
      if(nodePtr->key > name)
        nodePtr = nodePtr->left;
      else
        nodePtr = nodePtr->right; 
    }
    //print boi
    cout << "Game: " << nodePtr->key << '\n'
         << "Maximum # of players: " << nodePtr->maxPlayers << '\n'
         << "Minimum playtime: " << nodePtr->playtime << " mins\n";
  }
}

//prints all games that user has time to play
void GameBST::printPlayable(int timeLeft){
  
  //if empty throw exception

  cout << "Printing playables...\n\n";

  printPlayable(timeLeft, root);
}

void GameBST::printPlayable(int timeLeft, TreeNode* nodePtr){

  if(nodePtr){
    print(nodePtr->left);
    print(nodePtr->right);
    if(nodePtr->playtime <= timeLeft)
      cout << nodePtr->key << '\n';
  }
}
