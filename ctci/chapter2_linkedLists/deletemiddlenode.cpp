#include <iostream>
//Implement an algorithm to delete a node in the middle 
//(i.e., any node but the first and last node, not necessarily the exact middle) 
//of a singly linked list, given only access to that node. 

//edge cases
//1. head with no data
//2. only one node
//3. only two nodes

using namespace std;

struct Node {
	int data=0;
	Node * next = nullptr;
};

void printList(Node * head){
	while(head){
		cout << head->data << "->";
		head = head->next;
	}
	cout << "null" << endl;
}

void insertList(Node * &head, int data){
	Node * newnode = new Node;
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

void deleteMiddleNode(Node * current){
	if(current == nullptr || current->next == nullptr){
		return;
	}

	//copy over and delte the next one
	current->data = current->next->data;
	Node * temp = current->next;
	current->next = current->next->next;
	temp->next = nullptr;
	delete temp;
}

int main(){

	srand(time(NULL));

	int size = rand()%50;
	int K =0;
	cout << "enter number between 1 and " << size-2 << "(inclusive): ";
	cin >> K; //K is the position of the node that is going to be deleted
	K = size - K;
	Node * head = nullptr;
	Node * nd = nullptr;
	for(int i=0;i<size;i++){
		insertList(head, rand()%10);
		if (i==K){
			nd = head;
		}
	}

	printList(head);

	cout << endl;

	deleteMiddleNode(nd);

	printList(head);


	return 0;
}