//Given a binary tree, design an algorithm which creates a linked list of all the nodes
//at each depth (e.g. if you have a tree with depth D, you'll have D linked lists)

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

struct Node{
	int data;
	Node * left = nullptr;
	Node * right = nullptr;
	Node(int d){
		this->data = d;
	}
};

void traverseTree(Node * current, int height, vector<list<int>> & hashTable){
	if(current == nullptr)
		return;
	//cout << hashTable.size();
	if(hashTable.size() <= height){
		list<int> newList;
		hashTable.push_back(newList);
	}

	hashTable[height].push_back(current->data);
	traverseTree(current->left, height+1, hashTable);
	traverseTree(current->right, height+1, hashTable);

}

void printHash(vector<list<int>> hashTable){
	for (int i=0;i<hashTable.size();i++){
		list <int>::iterator it;
		for (it = hashTable[i].begin(); it != hashTable[i].end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}
}

int main(){

	//create Tree
	Node * root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(7);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	root->left->left->left = new Node(1);
	root->right->left = new Node(6);
	root->right->right = new Node(8);
	root->right->right->right = new Node(9);

	//int D = 4; //depth of the tree but what if Depth is unknown
	vector<list<int>> hashTable;

	traverseTree(root, 0, hashTable);
	printHash(hashTable);
 
	return 0;
}
