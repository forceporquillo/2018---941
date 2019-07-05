// all function prototypes as well as struct declaration

#include <iostream>
#include <string>
#include <sstream>
#include<stdlib.h>

using namespace std; // still uses sstd:: on some of functions 

struct Node{
  int data;

  Node *left, *right;
};

Node* delNodeData(Node* root, int delNum);
Node* insertData(Node* root, int key_value);
void createList(Node *&root);
void menuList(Node* root);
int getHeight(Node* root);

void printPreTraversal(Node* root);
void printInTraversal(Node* root);
void printPostTraversal(Node* root);
