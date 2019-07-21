//a queue using 2 stacks
//lazy approach only works when the oldStack becomes empty first and then gets transferred
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
	stack<int> newStack;
	stack<int> oldStack;

public:
	void enqueue(int d){
		newStack.push(d);
		cout << d << " is pushed\n";
	}
	void dequeue(){
		shift();
		cout << oldStack.top() << " is popped\n";
		oldStack.pop();
	}
	int peek(){
		shift();
		cout << oldStack.top() << "\n";
	}
	void shift(){
		while(oldStack.empty()){
			while(!newStack.empty()){
				oldStack.push(newStack.top());
				newStack.pop();
			}
		}
	}
};



int main(){

	MyQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.dequeue();
	q.dequeue();

	return 0;
}