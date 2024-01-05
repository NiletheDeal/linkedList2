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


student* ADD(node* &head, node* &newNode, node* &current, node* &prev) {//Function to find the new nodes next node
  if (head == null) {//if this is the first node in the list
    head = newNode;
    return;
  }
  else {

    int id1 = current->getStudent()->getID();
    int id2 = newNode->getStudent()->getID();
    int headID = head->getStudent()->getID();
    int prevID = prev->getStudent()->getID();
    
    if (id2 < headID) { //if input node is less than the lowest node(the head node)
      node tempNode = head;
      head = newNode;
      head->setNode(tempNode);
    }
    
    else if ((id2 > prevID) && (id2 < id1)) {//if input node falls in between two nodes
      prev->setNode(newNode);
      newNode->setNode(current);
    }
    else if (current->getNode() == NULL) {//if recursion reaches the end of the linkedList 
      cur->setNext(newNode);
    }
    else {//recursion with the next node being the current and the current node becomeing the previous
      add(head, newNode, current->getNode(), current);
    }
  }
}
void PRINT(node* head) {//Prints out all the students
  if (head == null) {//empty list
    cout << "List is Empty!" << endl;
  }
  else if (head != NULL && head->getNext() == NULL) {//if the list only has head
    head->getStudent()->printStudent();
  }
  else if (head->getNext() != NULL) {//print student and call print again with the node head connects to
    head->getStudent()->printStudent();
    print(head->getNext());
  }
}
void DELETE(node* &head, node* current, node* prev, int ID) {//
  if (head == NULL) {
    cout << "List is empty!" << endl;
  }
  else if (current == NULL) {
    cout << "This student isn't a part of the linked list
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
