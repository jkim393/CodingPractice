//Implement a function to check if a linked list is a palindrome
#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
};

//insert at head
void insertNode(Node * &head, int d){
	Node * newnode = new Node;
	newnode->data = d;
	newnode->next = head;
	head = newnode;
}
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

bool checkPalindrome(Node * current){
	int len = lengthOfList(current);
	bool isodd = false;
	stack<int> s;

	if(len==0){
		return false;
	}
	else if(len==1){
		return true;
	}
	else if(len%2){//odd; since it won't be 0
		isodd = true;
	}


	for(int i=0;i<len/2;i++){
		s.push(current->data);
		current = current->next;
	}

	if(isodd){
		current = current->next;
	}

	for(int i=0;i<len/2;i++){
		if (s.top() == current->data)
			s.pop();
		else
			return false;
		current = current->next;
	}
	return true;
}

//using two pointers(running technique); no need to know the size(better)
bool checkPalindrome2(Node * head){
	Node * p1 = head;
	Node * p2 = head;

	//case of no node
	if(!head)
		return false;
	//case of only one node
	if(!(head->next))
		return true;

	stack<int> s;

	while(p2 != nullptr && p2->next != nullptr){
		s.push(p1->data);

		p1 = p1->next;
		p2 = p2->next->next;
	}

	if(p2){
		p1 = p1->next;
	}

	while(p1){
		if (s.top() != p1->data)
			return false;
		s.pop();
		p1 = p1->next;
	}
	return true;
}


//recursive method
bool checkPalindrome2(Node * head){
	return true;
}

int main(){

	//odd case
	Node * head1 = nullptr;
	insertNode(head1, 1);
	insertNode(head1, 2);
	insertNode(head1, 1);
	if(checkPalindrome2(head1))
		cout << "121 is palindrome\n";
	else
		cout << "121 is not palindrome\n";

	//even
	Node * head2 = nullptr;
	insertNode(head2, 1);
	insertNode(head2, 2);
	insertNode(head2, 2);
	insertNode(head2, 1);
	if(checkPalindrome2(head2))
		cout << "1221 is palindrome\n";
	else
		cout << "1221 is not palindrome\n";

	//single node
	Node * head3 = nullptr;
	insertNode(head3, 1);
	if(checkPalindrome2(head3))
		cout << "1 is palindrome\n";
	else
		cout << "1 is not palindrome\n";

	//no node
	Node * head4 = nullptr;
	if(checkPalindrome2(head4))
		cout << "no node is palindrome\n";
	else
		cout << "no node is not palindrome\n";

	Node * head5 = nullptr;
	insertNode(head5, 1);
	insertNode(head5, 2);
	insertNode(head5, 2);
	if(checkPalindrome2(head5))
		cout << "122 is palindrome\n";
	else
		cout << "122 is not palindrome\n";

	Node * head6 = nullptr;
	insertNode(head6, 1);
	insertNode(head6, 2);
	if(checkPalindrome2(head6))
		cout << "12 is palindrome\n";
	else
		cout << "12 is not palindrome\n";

	return 0;
}