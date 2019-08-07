//Given a sorted (increasing order) array with unique integer elements, 
//write an algorithm to create a binary search tree with minimal height.

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node * left = nullptr;
	Node * right = nullptr;
	Node(int d){data = d;}
};


Node * createBST(int arr[], int start, int end){

	if (end < start)
		return nullptr;

	int mid = (start+end) / 2;

	Node * newNode = new Node(arr[mid]);
	newNode->left = createBST(arr, start, mid-1);
	newNode->right = createBST(arr, mid+1, end);

	return newNode;
}

void preorderTree(Node * current){
	if (current == nullptr)
		return;
	cout << current->data << " ";
	preorderTree(current->left);
	preorderTree(current->right);
}

int main(){
	// a unique sorted array
	int arr[7] = {1,2,3,4,5,6,7};
	int arr_size = sizeof(arr)/sizeof(*arr);
	//cout << arr_size;
	
	Node * root = createBST(arr, 0, arr_size-1);

	preorderTree(root);

	return 0;
}