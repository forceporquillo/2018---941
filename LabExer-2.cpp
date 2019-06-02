#include <iostream>
#include <sstream>
#include <cstdlib> // system libraries
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;
Node* node = NULL;

// prototypes
int main();
void replaceList();

void menuList(){
	cout << "  SELECT FOR CORESPONDING NUMBER.\n"
	     << "[Press (.) to stop inserting list]\n"
			 << "[1] Create List\n"
		   << "[2] Bubble Sort\n"
		   << "[3] Selection Sort\n"
			 << "[4] Insertion Sort\n"
			 << "[5] Exit\n";
}

void createList(){
	char choice;
	string number;
	int x;

	if(head != NULL){
		cout << "List exist! do you want to replace list? [Y/N]: ";
		cin >> choice;

		switch(choice){
			case 'Y':
			case 'y':
				replaceList(); // delete list
				break;
			case 'N':
			case 'n':
				main();
				break;
		}
	}

		cout << "Enter number you wish to sort: ";
		while(true){
			cin >> number;
			istringstream(number) >> x;

			if(number == "."){
				cout << "List succesfully created!\n";
				break;
			}
			node = new Node;
			node -> data = x;
			node -> next = NULL;

			if(head == NULL){
				head = node;
				tail = node;
			}else{
				tail -> next = node;
				tail = node;
				node = NULL;
			}

		/*	while(node != NULL){
				arr[counter] = node -> data;
				node = node -> next;
				counter++;
			} */
		}

	main();
}


void bubbleSort(){ // sorting implementation : Linked List
	Node* tempSort = head;

	Node *i , *j;
	int swapNode;

	if(head == NULL){
		cout << "Empty!\n";
	}else{
		for(i = tempSort; i -> next != NULL; i = i -> next){
			for(j = i -> next; j != NULL; j = j-> next){
				if(i -> data > j -> data){
					swapNode = i -> data;
					i -> data = j -> data;
					j -> data = swapNode;
			}
		}
	}

	cout << "Sorted number in bubble sort: ";
	while(tempSort != NULL){
		cout << tempSort -> data << " ";
		tempSort = tempSort -> next;
	}
	}
	cout << "\n";
	system("pause");
	main();
}

void selectionSort(){ // sorting implementation : Linked List
	Node* selectedNode = head;

	if(head == NULL){
		cout << "Empty!\n";
	}else{
		while(selectedNode -> next != NULL){
			Node* currentNode = selectedNode;
			Node* minimumNode = currentNode;

			int minimumData = currentNode -> data;

			while(currentNode != NULL){
				if(minimumData > currentNode -> data){
					minimumData = currentNode -> data;
					minimumNode = currentNode;
				}
				currentNode = currentNode -> next;
			}
			int tempSwap = minimumNode -> data;
			minimumNode -> data = selectedNode -> data;
			selectedNode -> data = tempSwap;
			selectedNode = selectedNode -> next;
		}
	}

	Node* tempDis = head;

	if(head != NULL){
		cout << "Sorted number in selection sort: ";
	}

	while(tempDis != NULL){
		cout << tempDis -> data << " ";
		 tempDis = tempDis -> next;
	}
	cout << "\n";
	system("pause");
	main();
}

void insertionSort(){ // sorting implementation : Array
	Node* inserSort = head;

	/* this algorithm will convert linked list to array, since I only used singly linked list
		therefore i can't previously traverse list to reverse that the insertion sort was suppose to be used to, so
		by that i need to convert first linked list into an array.*/

	if(head == NULL){
		cout << "Empty!\n";
	}else{
		int *arr;
		static int counter = 0;
		arr = new int[counter];
		int j;

		while(inserSort != NULL){
			arr[counter] = inserSort -> data;
			inserSort = inserSort -> next;
			counter++;
		}

		delete inserSort;
		inserSort = NULL;

		/*test output
		for(int i = 0; i < counter; i++){
			cout << arr[i] << " ";
		}*/

		//	delete inserSort;
		//	inserSort = NULL;

			for(int i = 1; i < counter; i++){
				int temp = arr[i];
					for(j = i - 1; j >=0 && temp < arr[j]; j--){
						arr[j+1] = arr[j];
					}
					arr[j+1] = temp;
			}

			cout << "Sorted number in insertion sort: ";
			for(int i = 0; i < counter; i++){
				cout << arr[i] << " ";
			}

			cout << endl;

			delete [] arr;
			arr = NULL;

		}

		/*
		cout << "Sorted number in insertion sort: ";
		while(insertSort != NULL){
			cout << insertSort -> data << " ";
			insertSort = insertSort -> next;
		}
		system("pause");
		main();
		*/

	system("pause");
	main();
}


void replaceList(){
	Node *clear = new Node;

	if(clear != NULL){
		clear = NULL;
	}

	clear = head;

	while(head != NULL){
		clear = new Node;
		clear = head;
		while(clear -> next != tail){
			clear = clear -> next;
		}

		tail = clear;

		cout << "Element list cleared! \n";
		delete clear;

		if(head == tail){
			head = NULL;
			tail = NULL;
			break;
		}
	}
}

void display(){
	Node* display_node = new Node;

	display_node = head;

	if(display_node == NULL){
		cout << "Empty!\n";
	}else{
	cout << "Current list: ";
	while(display_node != NULL){
		cout << display_node -> data << " ";
		display_node = display_node -> next;
	}
	}
	cout << "\n";
	system("pause");
	main();
}

void exitDisplay(){
	system("cls");
	cout << "201811941\n"
			 << "Aljan A. Porquillo\n"
			 << "BSCSSE - N01\n"
			 << "Lab Exer 3\n";
}

int main(void){
	int x;

	system("cls");
	menuList(); // menu
	cout << "=> ";
	cin >> x;

	switch(x){
		case 1:
			createList();
			break;
		case 2:
			bubbleSort();
			break;
		case 3:
			selectionSort();
			break;
		case 4:
			insertionSort();
			break;
		case 5:
			exitDisplay();
			break;
		case 0: // hidden command to display linked list
			display();
			break;
		default:
			cout << "Wrong input! please try again. . ." << endl;
			system("pause");
			main();
	}
}
