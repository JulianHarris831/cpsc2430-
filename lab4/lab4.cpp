//Julian Harris
//lab4.cpp

//DESCRIPTION: Program creates a tree implemented with a linked list and fills
//             it with as many unique values as the user requests. Prints
//             only values smaller than the user's selection, and returns
//             the sum of the whole tree. Deallocatees tree at program end.

//ASSUMPTIONS: User does not provide negative integers for maxes. 

#include <iostream>

using namespace std;

//allows easy variance of tree data type, ex float
typedef int treeElement;

struct BNode{
  treeElement value;
  BNode* left;
  BNode* right; 
};

//preorder traversal to check if values already exist. helper to insert.
bool contains(BNode* n, treeElement k);

//inserts unique value to list in order. 
bool insert(BNode* &n, treeElement k);

//prints list recursively in pre order, only printing values less than k
void print(BNode* n, treeElement k);

//collects sum of tree, returns it
treeElement sumTree(BNode* n);

//deallocates tree
void deforestation(BNode* &n); 

int main(){
  
  BNode *testRoot = nullptr; //tree declaration
  int treeMax = 0; //maximum size of tree as set by user
  int treeSize = 0; //current size count to avoid overflow 
  treeElement userVal;  //user inputs
  treeElement userMax;
  treeElement sum = 0; //keep track of sum
  
  cout << "\nHow many keys do you want to add to the BST? ";
  cin >> treeMax;

  while(treeSize < treeMax){ //loading up tree with user inputs
    cout << "Enter the key you want to insert: ";
    cin >> userVal;
    if(insert(testRoot, userVal)) //only increments treeSize if valid input
      treeSize++;
  }
  
  cout << "\nEnter a key: ";
  cin >> userMax; //user sets values to print below
  cout << "Printing values smaller than " << userMax << "\n";
  print(testRoot, userMax); 
  cout << "\n\n";
  sum += sumTree(testRoot); //counting sum
  
  cout << "Sum of tree is " << sum << "\n\n";
  
  deforestation(testRoot);
  cout << "Timber! Exiting...\n\n";
  
  return 0; 
}

bool contains(BNode* n, treeElement k){

  if(!n){
    return false;
  }else if(n->value == k){
    return true;
  }else if(n->value > k){
    return contains(n->left, k);
  }else 
    return contains(n->right, k);
}

bool insert(BNode* &n, treeElement k){

  if(!contains(n, k)){ 
    
    if(!n){ 
      n = new BNode;
      n->value = k;
      n->left = nullptr;
      n->right = nullptr;
      return true;
    }
    else if(n->value > k)
      return insert(n->left, k);
    else
      return insert(n->right, k); 
  }
  return false; 
}

//prints all values in tree smaller than k, with preorder. CLR
void print(BNode* n, treeElement k){
  
  if(n == nullptr)
    return;
  else{
    if(n->value < k)
      cout << n->value << ' ';
    print(n->left, k);
    print(n->right, k);
  }
}

//sum of tree
treeElement sumTree(BNode* n){

  if(!n){
    return 0;
  }
  else{
    return n->value + sumTree(n->left) + sumTree(n->right); 
  }
}

//iterate in post order, deleting the friggin node
void deforestation(BNode* &n){
  
  if(n == nullptr)
    return;
  else{
    deforestation(n->left);
    deforestation(n->right);
    delete n;
  }
}
