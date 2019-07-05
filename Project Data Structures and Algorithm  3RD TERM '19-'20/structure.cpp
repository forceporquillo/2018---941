// all structure algorithm here!

#include "stdafx.h"

void printPreTraversal(Node* root){ // PLR
	if(root == NULL)
    return;
  else
	   std::cout << root->data << " ";
	   printPreTraversal(root->left);
	   printPreTraversal(root->right);
}

void printInTraversal(Node* root){ // LPR
  if(root == NULL)
    return;
  else
	   printInTraversal(root->left);
       std::cout << root->data << " ";
	   printInTraversal(root->right);
}

void printPostTraversal(Node* root){ // LRP
  if(root == NULL)
    return;
  else
	   printPostTraversal(root->left);
	   printPostTraversal(root->right);
     std::cout << root->data << " ";
}

Node* insertData(Node* root, int key_value){ // insert
  if(root == NULL) {
    root = new Node();
    root->data = key_value;
    root->left = root->right = NULL;
  }
  else if(key_value <= root->data)
    root->left = insertData(root->left, key_value);
  else
    root->right = insertData(root->right, key_value);
  return root;
}

int getHeight(Node* root){
	if (root == NULL)  
        return 0;  
    else
    {  
        int left_Depth = getHeight(root->left);  
        int right_Depth = getHeight(root->right);  
      
        if (left_Depth > right_Depth)  
            return(left_Depth + 1);  
        else return(right_Depth + 1);  
    }  
    
}  

Node* minValNodeData(Node* root){
	Node *currData = root;
	
	while(currData && currData -> left != NULL)
		currData = currData -> left;
	
	return currData;
}

Node* delNodeData(Node* root, int delNum){
	if(root == NULL) 
		return root;
		
	if(delNum < root -> data)
		root -> left = delNodeData(root -> left, delNum);
		
	else if(delNum > root -> data)
		root -> right = delNodeData(root -> right, delNum);	
		
	else{
		if(root -> left == NULL){
			struct Node *tempVal = root -> right;
			free(root);
			return tempVal;
		}else if(root -> right == NULL){
			struct Node *tempVal = root -> left;
			free(root);
			return tempVal;
		}
		
		Node* temp = minValNodeData(root -> right);
		
		root -> data = temp -> data;
		
		root -> right = delNodeData(root -> right, temp -> data);
	}
	return root;
}

void createList(Node *&root){
  std::string x;
  int data;

  cout << "\nEnter a number: ";
  while(true){
    std::cin >> x;
    std::istringstream(x)>> data;

    if(x == "~"){
      cout << "\nList '~' ignored! ";
      system("pause");
      break;
	}
	
	cout << "\nList added!\n";
    root = insertData(root, data);
	}
	
	
	system("cls");
	
	menuList(root);
}

