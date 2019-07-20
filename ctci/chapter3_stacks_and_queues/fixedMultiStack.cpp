#include "fixedMultiStack.h"

using namespace std;

fixedMultiStack::fixedMultiStack(int stackCapacity){
	this->stackCapacity = stackCapacity; //defining the size of the array
	this->stackArray = new int[numOfStack * stackCapacity];
	this->stackCapacityUsed = new int[numOfStack]; //keeps track of the capacity used for each stack
}

fixedMultiStack::~fixedMultiStack(){
	delete [] stackArray;
	delete [] stackCapacityUsed;
}

void fixedMultiStack::push(int stackNum, int value){
	if(isFull(stackNum))
		cout << "Stack " << stackNum << " is full.\n";
	else{
		stackCapacityUsed[stackNum]++;
		stackArray[indexOfTop(stackNum)] = value;
	} 
}

void fixedMultiStack::pop(int stackNum){
	if(isEmpty(stackNum))
		cout << "Stack " << stackNum << " is empty.\n";
	else{
		int topIndex = indexOfTop(stackNum);
		stackArray[topIndex] = 0;
		stackCapacityUsed[stackNum]--;
	}
}

int fixedMultiStack::top(int stackNum) const {
	if(isEmpty(stackNum)){
		cout << "Stack " << stackNum << " is empty.\n";
		exit(1);
	}
	else {
		return stackArray[indexOfTop(stackNum)];
	}
}

bool fixedMultiStack::isEmpty(int stackNum) const {
	return (stackCapacityUsed[stackNum] == 0);
}
bool fixedMultiStack::isFull(int stackNum) const {
	return (stackCapacityUsed[stackNum] == stackCapacity);
}

int fixedMultiStack::indexOfTop(int stackNum) const{
	int startIndex = stackNum * stackCapacity;
	int position = stackCapacityUsed[stackNum];
	return (startIndex+position-1);
}