//Neel Madala
//1/6/2024
//Cited from Roger Lee
//This program allows the user add student information which is stored in a linked list of nodes that can be printed, have certain students deleted and average the GPAs of the students in the list
#include<iostream>
#include<vector>
#include<iomanip>
#include "node.h"
#include "student.h"
using namespace std;

//Intialize the functions to be able to use whenever
void AVERAGE (node* head, float sumGPA, int totalNode);
void ADD(node* &head, node* newNode, node* current, node* prev);
void PRINT(node* head);
void DELETE(node* &head, node* current, node* prev, int ID);


void ADD(node* &head, node* newNode, node* current, node* prev) {//Function to find the new nodes next node
  cout << "Placing NOde" << endl;
  if (head == NULL) {//if this is the first node in the list
    cout << "test2" << endl;
    head = newNode;
    return;
  }
  else {
    cout << "test1" << endl;
    int id1 = current->getStudent()->getID();
    int id2 = newNode->getStudent()->getID();
    int headID = head->getStudent()->getID();
    int prevID = prev->getStudent()->getID();
    
    if (id2 < headID) { //if input node is less than the lowest node(the head node)
      node* tempNode = head;
      head = newNode;
      head->setNode(tempNode);
    }
    
    else if ((id2 > prevID) && (id2 < id1)) {//if input node falls in between two nodes
      prev->setNode(newNode);
      newNode->setNode(current);
    }
    else if (current->getNode() == NULL) {//if recursion reaches the end of the linkedList 
      current->setNode(newNode);
    }
    else {//recursion with the next node being the current and the current node becomeing the previous
      
      ADD(head, newNode, current->getNode(), current);
    }
  }
}
void PRINT(node* head) {//Prints out all the students
  if (head == NULL) {//empty list
    cout << "List is Empty!" << endl;
  }
  else if (head != NULL && head->getNode() == NULL) {//if the list only has head
    head->getStudent()->printStudent();
  }
  else if (head->getNode() != NULL) {//print student and call print again with the node head connects to
    head->getStudent()->printStudent();
    PRINT(head->getNode());
  }
}
void DELETE(node* &head, node* current, node* prev, int ID) {//Deletes the student if they match the ID given by the user
  if (head == NULL) {//if no nodes at all
    cout << "List is empty!" << endl;
  }
  else if (current == NULL) {// if no matching ID is found
    cout << "This student isn't a part of the linked list" << endl;
  }
  else if (current->getStudent()->getID() == ID) { //finds a matching ID
    //matched node is the head and head is the only node
    if (current == head && head->getNode() == NULL) {//delete the student/node and reset back to default head value
      head->~node();
      head = NULL;
    }
    //if the matched node is the head node, but the list isn't only the head node
    else if (current == head) {//deletes current head node and replaces it with the node it pointed to
      node* tempNode = head->getNode();
      head->~node();
      head = tempNode;
    }
    //if the node has a node it points to than the previous node points to the node current points to
    else if (current->getNode() != NULL && current != head) {
      prev->setNode(current->getNode());
      current->~node();
    }
    //if the node has nothing it points to than the node that points to it now points to nothing
    else if (current->getNode() == NULL && current != head) {
      prev->setNode(NULL);
      current->~node();
    }
  }
  else {//recursion
    DELETE(head, current->getNode(), current, ID);
  }
}

void AVERAGE (node* head, float sumGPA, int totalNode) {//Average the GPAs of all the students in the list
  //if the starting node is empty and you haven't go through any iterations of average
  if (head == NULL && totalNode == 0) {
    cout << "List is Empty" << endl;
  }
  else if (head != NULL) {
    sumGPA += head->getStudent()->getGPA();
    totalNode++;
    AVERAGE(head->getNode(), sumGPA, totalNode);
  }
  else {
    cout << fixed << setprecision(2) << (sumGPA/totalNode) << endl;
  }
}

int main() {
  char command[20];
  bool running = true;
  node* head = NULL; //first node
  //place holders that are used when calling add or delete
  cout << "Welcome to LinkList List." << endl;
  while (running == true) {
    cout << "Enter one of the following: ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl;
    cin.getline(command, 20);
    
    if (strcmp(command, "ADD") == 0) {//Pushes the user to add a new student to the end of the list
      cout << "Adding a new student: " << endl;
      student* ns = new student();
      node* newNode = new node(ns);
      ADD(head, newNode, head, head);
      
    }
    
    else if (strcmp(command, "PRINT") == 0) {//Prints out all the students stored in the list
      cout << "Printing the Student List: " << endl;
      PRINT(head);
    }
    
    else if (strcmp(command, "DELETE") == 0) { //Delete's a student after making sure and from the ID of that student
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
	  cin >> IDdel;
	  DELETE(head, head, head, IDdel);
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
    
    else if (strcmp(command, "AVERAGE") == 0) {//Average the GPAs of the students
      cout << "Averaging the GPAs of all students in the list:" << endl;
      //Variables required for average function
      float sumGPA = 0;
      int totalNode = 0;
      AVERAGE(head, sumGPA, totalNode);
    }
    
    else if (strcmp(command, "QUIT") == 0) { //Ends the program
      cout << "Quitting program" << endl;
      running = false;
    }
    
    else {//invalid input fail safe
      cout << "Invalid Input. Type a valid command in capital letters." << endl;
    }
  }
}
