#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

class node{
 public:
  node(student* s);
  ~node();
  node* getNode();
  void setNode(node* n);
  student* getStudent();
  void setStudent(student* s);
  

 private:
  student* s;
  node* n;
  

};
#endif
