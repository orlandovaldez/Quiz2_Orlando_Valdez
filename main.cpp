#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


#include "Input_Validation_Extended.h"
using namespace std;

void printArray(double grade[]);

int main()
{
  //Accept user input size for the array
  int size;
  double grade;
  string firstName;
  cout << "\nEnter The Size Of The Array" << endl;
  size = validateInt(size);

  //Create an array from size with user input
  int *gradeArray = new int [size];

  //Populate the array with user input values 
  for(int i = 0; i < size; ++i)
  {
    gradeArray[i]=validateDouble(grade);
  }

  //sort the array from greatest to lowest using sort 
  sort(gradeArray, gradeArray+ size);

  //ask for user input of thier name
  cout << "What's your first name? " << endl;
  firstName = validateString(firstName);
  //Output thier naem to the screen
  cout << "Hello " << firstName << endl;

  //output the results with users name to GradeReport.txt
  
  ofstream myfile ("GradeReport.txt");
  if(myfile.is_open())
  {
     
    for(int i = 0; i < size; ++i)
      {
        cout << "Grade " << i + 1 << ": " << gradeArray[i] << endl;
      }
  }myfile.close();

//display out the array to the user

  return 0;
}