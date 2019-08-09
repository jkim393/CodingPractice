//Write an algorithm to find the "next" node (i.e., in-order successor)
//of a given node in a binary search tree. You may assume that each node has a link to its parent.

 Node * successor(Node * current){
 	if(current == nullptr)
 		return nullptr;

 	if (current->right){
 		Node next = current->right;
 		while(next->left){
 			next = next->left;
 		}
 	}
 	else{
 		Node next = current->parent;
 		while(next->parent->left != next){
 			next = next->parent;
 		}
 	}
 	return next;
 }