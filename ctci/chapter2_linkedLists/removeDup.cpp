//create a hash table
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <iterator>
#include <unordered_set>

using namespace std;

struct Node {
	int data;
	Node * next = nullptr;
};

//insert into head of the linked list
void insertList(Node* & head, int d){
	Node * newnode = new Node;
	newnode->data = d;
	newnode->next = head;
	head = newnode;
}

void deleteList(Node* &head, int d){

	Node * current = head;
	Node* next;  
  
	while (current != NULL)  
	{  
	    next = current->next;  
	    free(current);  
	    current = next;  
	}  

	head = NULL;
}

//print linked list
void printList(Node * head){
	while(head){
		cout << head->data << "->";
		head = head->next;
	}
	cout << "null\n";
}

//STL List version
void removeDup(list<int> & l){
	unordered_set<int> hash;
	list<int>::iterator it;
	it = l.begin();
	while(it != l.end()){
		if(hash.find(*it) != hash.end()){
			it = l.erase(it);
			cout << "removed " << *it << endl;
		}
		else{
			hash.insert(*it);
			cout << "inserted " << *it << endl;
			it++;
		}
	}

}

//my own Linked List version
void removeDup1(Node* current){
	unordered_set<int> hash;
	Node * previous = current;
	while(current){
		if(hash.find(current->data) != hash.end()){ //found a duplicate cuz it exists in the hashtable
			previous->next = current->next;
			current->next = nullptr;
			delete current;
			current = previous->next;
		}
		else { //no duplicate, no delete
			hash.insert(current->data);
			previous = current;
			current = current->next;
		}
	}
}

//no buffer method, use a runner pointer
//can be done without previous by using runner->next->next
void removeDup2(Node* current){
	while(current){
		Node* runner = current;
		while(runner->next){
			if(current->data == runner->next->data){
				Node * temp = runner->next;
				runner->next = runner->next->next;
				temp->next = nullptr;
				delete temp;
			}
			else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}


int main(){
	srand(time(NULL));

	// list<int> l;

	// for(int i=0;i<10;i++){
	// 	l.push_back(rand()%5);
	// }

	// list<int>::iterator it;
	// cout << "Before: " << endl;
	// for(it=l.begin(); it != l.end(); it++){
	// 	cout << *it << " ";
	// }

	// removeDup(l);
	// cout << "After: " << endl;
	// for(it=l.begin(); it != l.end(); it++){
	// 	cout << *it << " ";
	// }

	Node * head = nullptr;
	for(int i=0;i<20;i++){
		insertList(head, rand()%10);
	}

	printList(head);

	cout << endl;

	removeDup2(head);

	printList(head);


	return 0;
}