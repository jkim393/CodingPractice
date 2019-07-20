#include <iostream>
#include <stack>
using namespace std;

//1 variable method: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/


struct MinStack 
{ 
    stack<int> s; 
    int minEle; 

    void getMin(){
    	if(s.empty()){
    		cout << "stack is empty\n";
    	}
    	else{
    		cout << minEle << endl;
    	}

    }

    void push(int d){
    	if(s.empty()){
    		s.push(d);
    		minEle = d;
    	}
    	else{
   			if(d < minEle){
   				int current = 2*d - minEle;
   				s.push(current);
   				minEle = d;
   			}
   			else{
   				s.push(d);
   			}
    	}
    }

    void pop(){
    	if(s.empty()){
    		cout << "stack is empty\n";
    	}
    	else{
   			if(s.top() < minEle){
   				int prevMin = 2*minEle - s.top();
   				s.pop();
   				minEle = prevMin;
   			}
   			else{
   				s.pop();
   			}
    	}
    }
    void peek(){
    	if(s.empty())
    		cout << "stack is empty\n";
    	else{
    		int t = s.top();
    		(t < minEle)? cout << minEle: cout << t;
    		cout << endl;
    	}
    }

}; 

struct MaxStack 
{ 
    stack<int> s; 
    int maxEle; 

    void getMax(){
    	if(s.empty()){
    		cout << "stack is empty\n";
    	}
    	else{
    		cout << maxEle << endl;
    	}
    }
    void push(int d){
    	if(s.empty()){
    		s.push(d);
    		maxEle = d;
    	}
    	else{
   			if(d > maxEle){
   				int current = 2*d - maxEle;
   				s.push(current);
   				maxEle = d;
   			}
   			else{
   				s.push(d);
   			}
    	}
    }
    void pop(){
    	if(s.empty()){
    		cout << "stack is empty\n";
    	}
    	else{
   			if(s.top() > maxEle){
   				int prevMax = 2*maxEle - s.top();
   				s.pop();
   				maxEle = prevMax;
   			}
   			else{
   				s.pop();
   			}
    	}
    }
    void peek(){
    	if(s.empty())
    		cout << "stack is empty\n";
    	else{
    		int t = s.top();
    		(t > maxEle)? cout << maxEle : cout << t;
    	}
    }

}; 
  
// Driver Code 
int main() 
{ 
    MinStack s; 
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop(); 
    s.peek(); 
  	
    cout << endl;

    MaxStack m; 
    m.push(3); 
    m.push(5); 
    m.getMax(); 
    m.push(2); 
    m.push(1); 
    m.getMax(); 
    m.pop(); 
    m.getMax(); 
    m.pop(); 
    m.peek(); 

    return 0; 
} 

// class MyStack {
// private:
// 	stack<int> minstack;
// 	stack<int> normalstack;

// public:
// 	void push(int d){
// 		if(minstack.empty()){
// 			minstack.push(d);
// 		}
// 		else {
// 			if(d < minstack.top()){
// 				minstack.push(d);
// 			}
// 		}
// 		normalstack.push(d);
// 	}

// 	void pop(){
// 		if(normalstack.empty()){
// 			cout << "stack is empty\n"; 
// 			return;
// 		}
// 		else{
// 			if(normalstack.top() == minstack.top()){
// 				minstack.pop();
// 			}
// 		}
// 		normalstack.pop();

// 	}
// 	void getMin(){
// 		cout << minstack.top() << endl;
// 	}
// 	bool isEmpty(){
// 		return (normalstack.empty());
// 	}
// };

// int main(){
// 	MyStack s;
// 	s.push(3);
// 	s.push(7);
// 	s.push(2);
// 	s.push(1);
// 	s.push(6);

// 	while(!s.isEmpty()){
// 		s.getMin();
// 		s.pop();
// 	}

// 	return 0;
// }

