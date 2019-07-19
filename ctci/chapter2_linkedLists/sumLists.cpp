#include <iostream>
//forward order
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

int length(Node * current){
	int len=0;
	while(current){
		len++;
		current = current->next;
	}
	return len;
}

int recursiveAddList(Node * head1, Node * head2, Node * &head3){
	if(head1 == nullptr){
		return 0;
	}
	else{
		int carry = recursiveAddList(head1->next, head2->next, head3);
		int sum = head1->data + head2->data + carry;
		int value = sum % 10; 
		if(sum>=10){
			carry=1;
		}
		else {
			carry=0;
		}
		insertList(head3, value);
		return carry;
	}
}

Node* sumList(Node * head1, Node* head2){
	int len1 = length(head1);
	int len2 = length(head2);
	//cout << len1 << len2;
	//padding zeros
	if (len1 < len2){
		int countZero = len2-len1;
		for (int i=0; i<countZero;i++){
			insertList(head1,0);
		}
	}
	else {
		int countZero = len1-len2;
		for (int i=0; i<countZero;i++){
			insertList(head2,0);
		}
	}

	Node* head3 = nullptr;
	
	//sum part
	int carry = recursiveAddList(head1, head2, head3);

	if(carry) 
		insertList(head3, 1);

	return head3;

}

int main(){

	srand(time(NULL));
	
	Node * head1 = nullptr;
	Node * head2 = nullptr;
	
	// cout << "Enter digits for the first number one by one, q to quit\n";
	// int digit1;
	// while(cin >> digit1) {
	// 	if (digit1 > 9){
	// 		break;
	// 	}
	// 	insertList(head1, digit1);
	// }
	// cout << "Enter digits for the second number one by one, q to quit\n";
	// int digit2;
	// cout << digit1 << " " << digit2 << endl;
	// while(cin >> digit2) {
	// 	if (digit2 > 9){
	// 		break;
	// 	}
	// 	insertList(head2, digit2);
	// }

	insertList(head1, 7);
	insertList(head1, 6);
	insertList(head1, 5);

	insertList(head2, 4);
	insertList(head2, 3);
	insertList(head2, 2);
	insertList(head2, 1);

	printList(head1);
	printList(head2);

	Node * head3 = sumList(head1, head2);

	printList(head3);


	return 0;
}