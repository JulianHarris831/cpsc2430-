//Harris, Julian
//lab1.cpp
//09/11/20

#include <iostream>

using namespace std;

const int SIZE = 10; 

void getInput(int maxVal, int list[]);
int getMin(int maxVal, int list[]);

int main()
{
  int list[SIZE];
  int max = 0;
  
  cout << "\nGathering ints to 50!\n\n";
  
  cout << "Max: ";
  cin >> max;
  cout << "Max set to " << max << "\n\n";
  
  getInput(max, list);
  
  cout << "\nInput gathered!\n\nDisplaying list...\n\n";

  for(int i = 0; i < 10; i++){

    cout << '#' << i+1 << " = " << list[i] << '\n';  
  }
  cout << "\n";

  cout << "The minimum value is " << getMin(max, list) << "\n\n";
  
  return 0;
}

void getInput(int maxVal, int list[]){

  int input = 0;
  
  for(int i = 0; i < 10; i++){
    while(input < 1 || input > maxVal){
      cout << "Input: ";
      cin >> input;
    }
    list[i] = input; 
    cout << "Added...\n";
    input = 0;
  }
}

int getMin(int maxVal, int list[]){
  int min = maxVal;

  for(int i = 0; i < 10; i++){
    
    if(list[i] < min)
      min = list[i];
  }
  return min;
}
