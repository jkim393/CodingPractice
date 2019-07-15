#include <iostream>

using namespace std;

int main(){
	string word = "";
	getline(cin, word);
	
	if ( isPermutation2(word) ){
		cout << "Permutation";
	}
	else {
		cout << "Not Permutation";
	}

	return 0;
}