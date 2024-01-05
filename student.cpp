#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//Constructor
student::student() {
  cout << "First Name of the Student: " << endl;
  cin >> firstName;
  cout << endl << "Last Name of the Student: " << endl;
  cin >> lastName;
  cout << endl << "ID of the Student: " << endl;
  cin >> ID;
  cout << endl << "GPA of the Student: " << endl;
  cin >> GPA;
}
//Destructor
student::~student() {
  delete firstName;
  delete lastName;
}

//Getters
char* student::getFirstName() {
  return firstName;
}
char* student::getLastName() {
  return lastName;
}
int student::getID() {
  return ID;
}
float student::getGPA() {
  return GPA;
}
void student::printStudent() {
  cout << endl << firstName << " " << lastName << " " << ID << " " << fixed << setprecision(2) << GPA << endl;
}
