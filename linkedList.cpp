//Neel Madala
//1/3/2024
//Cited from Nathan Zou
//This program allows the user to input student information(name, Id, GPA) and print out all saved students and delete certain students based on id.
#include<iostream>
#include<vector>
#include<iomanip>
#include "node.h"
#include "student.h"
using namespace std;

//Intialize the functions to allow both to be used whenever
void DELETE(int id, vector<student*>* studentList);
void PRINT(vector<student*>* studentList);


student* ADD(node* &head, node* &newNode, node* &current, node* &next) {//Function to find the new nodes next node
  student* ns = new student();
  node* newNode = new node(stu);
  cout << "Enter first name: " << endl;
  cin >> ns -> first_name;
  cout << "Enter last name: " << endl;
  cin >> ns -> last_name;
  cout << "Enter ID number: " << endl;
  cin >> ns -> studentID;
  cout << "Enter GPA: " << endl;
  cin >> ns -> gpa;
  return ns;
}
void PRINT(vector<student*>* studentList) {//Prints out all the students
  vector<student*>::iterator print;
  for (print = studentList->begin(); print != studentList->end(); print++) {
    cout << (*print)->first_name << ", ";
    cout << (*print)->last_name << ", ";
    cout << (*print)->studentID << ", ";
    cout << fixed << setprecision(2) << (*print) ->gpa << endl;//Rounds GPA to 2 decimal places and prints(3.40 vs 3.4)
    cout << endl;
  }
}
void DELETE(int id, vector<student*>* studentList) {//Takes in a pointer to the list of student pointers and runs through the list of student pointers until you find the id inputted
  vector<student*> :: iterator del;
  for (del = studentList->begin(); del != studentList->end(); del++) {
    if ((*del)->studentID == id) {
      cout << "Deleted student ID #: " << id << endl;
      delete* del;
      studentList->erase(del);
      return;
    }
  }
  //If the ID doesn't exist
  cout << "Invalid ID." << endl;
}

int main() {
  char command[6];
  bool running = true;
  node* head = NULL; //first node
  int nodeCount = 0; //Necessary to know if node needs to be added to the end of the list
  //All to make sure you can edit both each student and the whole list
  cout << "Welcome to Student List." << endl;
  while (running == true) {
    cout << "ADD, PRINT, DELETE, QUIT" << endl;
    cin >> command;
    if (command[0] == 'A' && command[1] == 'D' && command[2] == 'D') {//Pushes the user to add a new student to the end of the list
      cout << "Adding a new student: " << endl;
      nodeCount++;
      student* ns = new student();
      node* newNode = new node(ns);
      node* current = head;
      node* next = head;
      add(head, newNode, current, next);
      
    }
    else if (command[0] == 'P' && command[1] == 'R' && command[2] == 'I' && command[3] == 'N' && command[4] == 'T') {//Prints out all the students stored in the list
      cout << "Printing the Student List: " << endl;
      PRINT(studentList);
    }
    else if (command[0] == 'D' && command[1] == 'E' && command[2] == 'L' && command[3] == 'E' && command[4] == 'T' && command[5] == 'E') { //Delete's a student after making sure and from the ID of that student
      char delCheck;
      cout << "You are about to delete a student. Are you sure? (y/n)";
      cin >> delCheck;
      bool deleteChecking = true;
      while (deleteChecking == true) {
	if (delCheck == 'y' || delCheck == 'Y') {//making sure you want to delete a student
	  cout << "Deleting Student." <<endl;
	  deleteChecking = false;
	  cout <<"Enter the student ID you want to delete: " << endl;
	  int IDdel;
	  cin >> IDdel;//Takes in a studentID
	  DELETE(IDdel, studentList);
	}
	else if (delCheck == 'n' || delCheck == 'N') {//goes back to main menu if you don't want to delete
	  cout << "Back to main menu " << endl;
	  deleteChecking = false;
	}
	else{//Invalid Input fail safe
	  cout << "Invalid input. Please input a 'y' or 'n'" << endl;
	}
      }
    }
    else if (command[0] == 'Q' && command[1] == 'U' && command[2] == 'I' && command[3] == 'T') { //Ends the program
      cout << "Quitting program" << endl;
      running = false;
    }
    else {//invalid input fail safe
      cout << "Invalid Input. Type a valid Command in Capitals." << endl;
    }

    
  
  }
}
