#include "stdafx.h"

void menuList(Node* root){
	int choice;
	
	cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		 << "\n\n\t\t | MAIN MENU |"
		 << "\n\t\t  -- TREES -- \n\n"
		 << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"
		 << "\n[1] Create List\n";
		 
	if(root != NULL){	 
 	
	cout << "\n[2] Tree Traversals\n"
		 << "\n[3] Height\n"
		 << "\n[4] BST\n";
	}
	
	cout << "\n[0] Exit\n";
	
		 cout << "\n\n> ";
	
	cin >> choice;
	
	switch(choice){
		
		case 1: 
			system("cls");
			cout << "	ADD NODE\n";
			
			if(root != NULL){
				cout << "\nList exist! do you want to replace this list? Y/N:";
				char y;
				
				cin >> y;
				
				if('y' || 'Y' == y){
					root = NULL;
					cout << "Succesfully replaced list!\n";
		
				}
			}else{
			
			createList(root);
		}
			break;
	
		case 2:
			system("cls");
			
			if(root == NULL){
				cout << "Tree is empty! cannot display Traversals!\n";
				
			}else{ 
			
				cout << "TREE TRAVERSALS\n";
			
				cout << "\nPreorder: ";
				printPreTraversal(root);
				cout << "\n\n";
			
				cout << "Inorder: ";
				printInTraversal(root);
				cout << "\n\n";
			
				cout << "Postorder: ";
				printPostTraversal(root);
				cout << "\n\n";
				break;
			}
		
		case 3:
			system("cls");
			cout << "	BINARY SEARCH TREE\n";
			cout << "Height: ";
			cout << getHeight(root);
			cout << "\n\n";
			break;
		case 4:
			system("cls");
			cout << "	BINARY SEARCH TREE\n"
			     << "\n[A] Insertion\n"
		 		 << "\n[B] Deletion\n"
		         << "\n\n> ";
	
		char c;
		int del;
		cin >> c;
	

		switch(c){
			case 'A':
			case 'a':
				createList(root);	
				break;
				
			case 'B':
			case 'b':
				int delNum;
				cout << "Enter number to be deleted: ";
				cin >> delNum;
				
				delNodeData(root, delNum);
				break;
		}
		break;
		
		case 0:
			system("cls");
			cout << "	PROJECT: BINARY SEARCH TREE\n"
				 << "\nSubmitted by: \n"
				 << "\n	Porquillo, Aljan  [201811941]\n"
				 << "\n	Reyes, Angel Troy [201811619]\n"
				 << "\n	(BSCSSE - N01)\n\n";
			break;
	}
	
	if(choice != 0){
		system("pause");
		system("cls");
		menuList(root);
	}
}
