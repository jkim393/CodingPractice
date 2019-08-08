//Implement a function to check if a binary tree is balanaced.
//For the purposes of this question, a balanced tree is defined to be a 
//tree such that the heights of the 2 subtrees of any node never differ by more than one.

#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	Node * left = nullptr;
	Node * right = nullptr;
	Node(int d){
		this->data = d;
	}
};

int balancedCheck(Node * current){
	if (current == nullptr)
		return 0;

	int leftHeight = balancedCheck(current->left);
	int rightHeight = balancedCheck(current->right);
	if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
		return -1;

	return max(leftHeight, rightHeight) + 1;

}

int main(){

	Node * root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(7);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	root->left->left->left = new Node(1);
	root->right->left = new Node(6);
	root->right->right = new Node(8);
	root->right->right->right = new Node(9);

	if (balancedCheck(root) == -1)
		cout << "not balanced";
	else
		cout << "balanced";

	return 0;
}