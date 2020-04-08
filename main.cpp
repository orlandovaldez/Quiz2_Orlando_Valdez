#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


#include "Input_Validation_Extended.h"
using namespace std;

void printArray();

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
  
  ofstream gradeArrayData ("GradeReport.txt");     
    for(int i = 0; i < size; ++i)
      {
        gradeArrayData << "Grade " << i + 1.0 << ": " << gradeArray[i] << endl;
      }
 

//display out the array to the user
printArray();
  return 0;
}
void printArray()
{
  string file;
  ifstream myfile("GradeReport.txt");
  if(myfile.is_open())
  {
    while (getline(myfile, file))
    {
      cout << file << "\n";
    }
  myfile.close();
  }

}