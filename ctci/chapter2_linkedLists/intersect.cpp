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

Node * intersection(Node * head1, Node * head2){
	int len1 = lengthOfList(head1);
	int len2 = lengthOfList(head2);
	
	if(len1 < len2){
		int diff = len2 - len1;
		for (int i=0;i<diff;i++){
			head2 = head2->next;
		}
	}
	else{
		int diff = len1 - len2;
		for (int i=0;i<diff;i++){
			head1 = head1->next;
		}
	}

	while(head1){
		if(head1 == head2){
			return head1;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	return nullptr;
}

int main(){// main function copied from ctci solution github
	Node * list1 = new Node(3);
	list1->next = new Node(6);
	list1->next->next = new Node(9);
	list1->next->next->next = new Node(12);
	list1->next->next->next->next = new Node(15);
	list1->next->next->next->next->next = new Node(18);

	Node * list2 = new Node(7);
	list2->next = new Node(10);
	list2->next->next = list1->next->next->next;
	printList(list1);
	printList(list2);

	Node * intersectingNode = intersection( list1 , list2 );
	if (intersectingNode) {
	  std::cout << "Intersecting Node of lists is :" << intersectingNode->data << std::endl;
	} else {
	  std::cout << "Lists do not interset" << std::endl;
	}
	return 0;
}