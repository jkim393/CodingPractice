#include <iostream>
#include <stack>

using namespace std;


void printStack(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

//O(n^2) implementation
void sortStack(stack<int> &s){
	if(s.empty()){
		return;
	}

	stack<int> temp;
	int size = s.size();

	for (int x=0;x<size;x++){
		int min = s.top();
		int count = 0;
		int minIndex = 0;
		//find min
		while(!s.empty()){
			if(s.top() <= min){
				min = s.top();
				minIndex = count;
			}
			temp.push(s.top());
			s.pop();
			count++;
		}
		// cout << min << endl;
		//repopulate the original stack except the minimum
		for(int i=0;i<count;i++){
			if(i != count - minIndex - 1)
				s.push(temp.top());
			temp.pop();
		}
		//push the minimum to the temp stack
		temp.push(min);
		//printStack(temp);
	}
	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}

}

//better implementation
void sortStack2(stack<int> &s){
	stack<int> temp;
	while(!s.empty()){
		int value = s.top();
		s.pop();
		if(temp.empty()){
			temp.push(value);
		}
		else{
			while(value > temp.top()){
				s.push(temp.top());
				temp.pop();
			}
			temp.push(value);
		}
	}
	s = temp;
}

int main(){
	stack<int> s;
	s.push(3);
	s.push(7);
	s.push(1);
	s.push(5);
	s.push(8);

	sortStack2(s);

	printStack(s);

	return 0;
}