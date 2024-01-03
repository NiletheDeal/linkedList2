#include "node.h"
#include <iostream>
#include "student.h"
using namespace std;

node::node(student* s){
  this-> s = s;
  n = NULL;
}

node::~node(){
  delete s;
  n = NULL;
}

node* node::getNode(){
  return this->n;
}

void node::setNode(node* n){
  this->n = n;
}

student* node::getStudent(){
  return this->s;
}

void node::setStudent(student* s){
  this->s = s;
}
