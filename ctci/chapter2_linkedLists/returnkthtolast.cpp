//Implement an algorithm to find the kth to last element of a singly linked list
#include <iostream>

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
//trivial solution
//void returnkthtolast(Node * current, int K){
	// //1. find the size of the list
	// Node * head = current;
	// int count = 0;
	// while(current){
	// 	count++;
	// 	current = current->next;
	// }
	// //cout << "count: " << count << endl;
	// //2. iterate through
	// current = head;
	// for (int i=0;i<count-(K+1);i++){
	// 	current = current->next;
	// }
	// cout << "Kth to the last value: " << current->data;
//}
//recursive solution
// Node* returnkthtolast(Node * current, int K, int & i){
// 	if (current == nullptr){
// 		return nullptr;
// 	}
// 	node * kth = returnkthtolast(current->next, K, i);
// 	i++;
// 	if (i==K){
// 		return current;
// 	}
// 	return kth;
// }
//iterative solution THIS IS GENIOUS
Node* returnkthtolast(Node * current, int K){
	//space two pointers K distance apart
	Node * p1 = current;
	Node * p2 = current;

	//set p1 K distance in front, also check boundary
	for(int i=0; i<K; i++){
		if (p1 == nullptr)
			return nullptr;
		p1 = p1->next;
	}
	while(p1){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}



int main(){

	srand(time(NULL));

	int K = 0;
	int size = rand()%50;
	cout << "enter number between 0 and " << size << "(inclusive): ";
	cin >> K;

	Node * head = nullptr;
	for(int i=0;i<size;i++){
		insertList(head, rand()%10);
	}

	printList(head);

	cout << endl;
	
	int i = 0;

	Node* kth = returnkthtolast(head, K);
	cout << kth->data;

	return 0;
}