#include <iostream>
#include <iomanip>
#include <cstring>
#include "student.h"

using namespace std;

//Constructor
student::student() {
  firstName = new char[20];
  lastName = new char[20];
  cout << "First Name of the Student: " << endl;
  cin.getline(firstName, 20);
  cout << endl << "Last Name of the Student: " << endl;
  cin.getline(lastName,20);
  cout << endl << "ID of the Student: " << endl;
  cin >> ID;
  cin.ignore(256, '\n');
  cout << endl << "GPA of the Student: " << endl;
  cin >> GPA;
  cin.ignore(256, '\n');
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
