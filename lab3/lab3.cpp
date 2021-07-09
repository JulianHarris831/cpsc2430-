//Julian Harris
//lab3.cpp
//9/25/2020

//DESCRIPTION: This program takes the input of the user to create a linked
//list of size X, and then reverse it up to Y and return the sum.

//ASSUMPTIONS: User gives positive numbers, and user does not give a number
//for the reversal size larger 

#include <iostream>

using namespace std;

//Setting typedef in case floating point is required.
typedef int valueType; 

//basic structure for linked list
struct ListNode
{
  valueType value;
  ListNode* next;
};
  
ListNode* append(valueType newVal, ListNode* head);
//Adds new node with a value to the linked list, returns the head
//PRE: User passes a value greater than zero.

valueType recursivePrint(int reverseSize, ListNode* head, valueType sum);
//Prints the linked list in reverse order and returns the sum of numbers
//printed.
//PRE: User has added values to the list and passes a reverSize smaller than
//the overall list size.

int main()
{
  //initialization of linked list
  ListNode* head = nullptr;
  //controls how many values will be added/printed
  int size = 0;
  int reverseSize = 0;
  //values to be loaded into the linked list
  valueType load;
  valueType sumLoad = 0;
  valueType sum = 0;
  
  //User selects list size
  cout << "\nHow many elements do you wish to add? ";
  cin >> size;
  cout << "\n";
  
  //Loading values into list
  for(int i = 0; i < size; i++){ 
    cout << "Enter list value: ";
    cin >> load;
    head = append(load, head);
  }
  
  cout << "\nHow many values do you wish to reverse? ";
  cin >> reverseSize;

  //recursion process
  sum += recursivePrint(reverseSize, head, sumLoad);
  cout << "\nThe sum of these values is " << sum << "\n\n";
  
  return 0;
}

ListNode* append(valueType newVal, ListNode* head){

  ListNode* newPtr = new ListNode;
  newPtr->value = newVal;
  ListNode* nodePtr = head; 

  if(head == nullptr)
    head = newPtr; 
  else{
    while(nodePtr->next){
      nodePtr = nodePtr->next;
    }
    nodePtr->next = newPtr; 
  }
  return head; 
}

valueType recursivePrint(int reverseSize, ListNode* head, valueType sum){

  ListNode* nodePtr = head;
  
  if(reverseSize == 1){
    cout << head->value << ' ';
    return sum + head->value;
  }
  else{
    for(int i = 1; i < reverseSize; i++)
      nodePtr = nodePtr->next; 
    cout << nodePtr->value << ' ';
    sum += nodePtr->value;
    return recursivePrint(--reverseSize, head, sum);
  }
}
