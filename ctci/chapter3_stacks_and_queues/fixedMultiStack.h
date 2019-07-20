//copied from careercup repo
#include <iostream>
#include <cstdlib>

class fixedMultiStack {
private:
	int numOfStack = 3;
	int stackCapacity;
	int *stackArray;
	int *stackCapacityUsed;

	//const member function to prevent modifying the stack
	int indexOfTop(int stackNum) const; //returns the index of top of the chosen stack

public:
	fixedMultiStack(int stackCapacity);
	virtual ~fixedMultiStack();
	void push(int stackNum, int value);
	void pop(int stackNum);
	int top(int stackNum) const;

	bool isEmpty(int stackNum) const;
	bool isFull(int stackNum) const;
};