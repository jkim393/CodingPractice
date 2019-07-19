#include <iostream>

using namespace std;

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void printList(Node * head){
	while(head){
		cout << head->data << "->";
		head = head->next;
	}
	cout << "null" << endl;
}

int lengthOfList(Node * head){
	int length = 0;
	if (head==nullptr){
		return 0;
	}
	else {
		while(head){
			length++;
			head = head->next;
		}
		return length;
	}

}

Node * loopBeginNode(Node * head){
	Node * turtle = head;
	Node * rabbit = head;

	//collision
	while(rabbit && rabbit->next){ //standard turtle and rabbit while loop condition
		rabbit = rabbit->next->next;
		turtle = turtle->next;
		if (rabbit == turtle){
			break;
		}
	}
	turtle = head; //reset to head

	//error cheching
	if(rabbit == nullptr || rabbit->next == nullptr)
		return nullptr;

	while(turtle!=rabbit){
		turtle = turtle->next;
		rabbit = rabbit->next;
	}
	return turtle; // or rabbit. doesn't matter

}

int main(){// main function copied from ctci solution github
	Node * list1 = new Node(3);
	list1->next = new Node(6);
	list1->next->next = new Node(9);
	list1->next->next->next = new Node(12);
	list1->next->next->next->next = new Node(15);
	list1->next->next->next->next->next = new Node(18);
	list1->next->next->next->next->next->next = list1->next->next;

	//printList(list1);

	Node * beginNode = loopBeginNode(list1);

	cout << "Beginning Node of the loop is :" << beginNode->data << endl;
	
	return 0;
}