#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class student{
 public:
  //Constructor will ask for all the data on the students
  student();
  //destructor
  ~student();
  //Getters
  //Get first name
  char* getFirstName();
  //get last name
  char* getLastName();
  //Get ID
  int getID();
  //get GPA
  float getGPA();
  //print student
  void printStudent();
 private:
  //Variables
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};
#endif
