//set of stacks

//using array as list of stacks
//array is also used for each stack

#include <iostream>

using namespace std;

//array implementation of stack
#define STACK_SIZE 5

class MyStack{
private:
	int top; //keep track of index of top
	int s[STACK_SIZE]; // actual stack

public:
	MyStack * next = nullptr;
	MyStack(){
		top = -1; // when first element added, ++
	}

	void push(int x){
		top++;
		s[top] = x;
		cout << x << " is added\n";
	}

	void pop(){
		cout << s[top] << " is popped\n";
		s[top] = 0;
		top--;
	}
	int peek(){
		if(!isEmpty())
			return s[top];
		else
			cout << "Stack Empty\n";
			return 0;;
	}
	bool isEmpty(){
		return (top==-1) ? true : false;
	}
	bool isFull(){
		return (top==STACK_SIZE-1) ? true : false;
	}
};

class SetOfStacks {
private:
	MyStack * root = new MyStack();
public:
	void push(int d){
		//if the root stack is full or no stack exists
		//create new stack
		//set root to the new stack
		if(root->isFull()){ 
			MyStack * newStack = new MyStack();
			newStack->next = root;
			root = newStack;
			cout << "new stack created\n";
		}
		//push into the current stack
		root->push(d);
	}
	void pop(){
		if(isEmpty()){
			cout << "Set of Stacks is empty\n";
			return;
		}
		if(root->isEmpty()){
			MyStack * temp = root;
			root = root->next;
			delete[] temp;
			cout << "stack removed\n";
		}
		root->pop();
	}
	int top(){
		if(!isEmpty())
			return root->peek();
		else
			cout << "Set of Stacks is empty\n";
			return 0;;
	}
	bool isEmpty(){
		if (root->next == nullptr && root->isEmpty())
			return true;
		else
			return false;
	}
};

int main(){

	SetOfStacks s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);

	s.pop(1);
	s.pop(2);
	s.pop(0);
	s.pop(1);


	return 0;
}