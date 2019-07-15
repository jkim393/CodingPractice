#include <iostream>

using namespace std;

string compression(string word){
	string result = "";
	int count = 0;
	if (word.length() == 1){
		return 
	}
	for (int i=0;i<word.length();i++){
		count++;
		if (word[i] != word[i+1] || i+1 >= word.length()) {
			result += word[i] + count;
			count = 0;
		}
	}
	return ( result.length() < word.length() ? result : word );
}

int main(){
	string word = "";
	getline(cin, word);
	
	cout << compression(word);

	return 0;
}
