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

void partition(Node * current, int K){
	Node * smallhead=nullptr;
	Node * largehead=nullptr;

	while(current){
		if(current->data < K){
			insertList(smallhead, current->data);
		}
		else{
			insertList(largehead, current->data);
		}
		current = current->next;
	}

	while(smallhead){
		insertList(largehead, smallhead->data);
		smallhead = smallhead->next;
	}
	printList(largehead);

}

//head and tail method
Node* partition2(Node * current, int x){
	Node* head = current;
	Node* tail = current;

	while(current){
		Node * next = current->next; //save the next here since it will get changed
		if(current->data < x){ //insert at head
			current->next = head;
			head = current;
		}
		else { //insert at tail
			tail->next = current;
			tail = current;
		}
		current = next;
	}
	tail->next = nullptr;
	return head;
}

int main(){
	srand(time(NULL));

	int size = rand()%50;
	int K;
	cout << "enter number between 0 and " << 9 << "(inclusive): ";
	cin >> K; //K is the position of the node that is going to be deleted
	
	Node * head = nullptr;
	
	for(int i=0;i<size;i++){
		insertList(head, rand()%10);
	}

	printList(head);

	cout << endl;

	//partition(head, K);
	head = partition2(head, K);
	printList(head);

	return 0;


}