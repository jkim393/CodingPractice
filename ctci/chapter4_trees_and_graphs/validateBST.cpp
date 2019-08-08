//Implement a function to check if a binary tree is a binary search tree
//1. use inorder
//2. use range check

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node * left = nullptr;
	Node * right = nullptr;
	Node(int d){
		this->data = d;
	}
};

void inorder(Node * current, vector<int> &v){
	if (current == nullptr)
		return;

	inorder(current->left, v);
	v.push_back(current);
	inorder(current->right, v);

}

//prev is the value right before the current.
//it has to be set by the leftmost value first
bool inorder(Node * current, int* prev){
	if (current == nullptr )
		return true;

	if (!inorder(current->left, prev)) // if left child is wrong
		return false;

	if (!prev && current->data <= *prev)
		return false;
	*prev = current->data;
	
	if (!inorder(current->right, *prev))
		return false;

	return true;
}
//case of duplicates
//from the solution
bool validateBST(TreeNode* root, int min, int max) {
	if (root == nullptr)
		return true;

	if (root->data < min || root->data >= max)
		return false;

	if ( !validateBST(root->left, min, root->data) || !validateBST(root->right, root->data, max) )
		return false;
	return true;
}

bool validateBST(TreeNode* root) {
	return validateBST(root, -2e9, 2e9);
}

int main(){

//check if v is sorted
//is_sorted(v.begin(), v.end());


	return 0;
}