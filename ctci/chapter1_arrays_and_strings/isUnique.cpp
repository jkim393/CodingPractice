//check if a string has all unique characters
//if I have an ascii table 
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bool isUnique(string word){
	vector<bool> unique(128, true); //if it gets set to false, return false
	int charValue = 0;
	for (unsigned int i =0; i <word.length(); i++){
		charValue = word[i];
		if(unique[charValue]){
			unique[charValue] = false;
		}
		else {
			return false;
		}
	}
	return true;
}

//using bitset
bool isUnique2(string word){
	bitset<128> unique; //if it gets set to false, return false
	int charValue = 0;
	for (unsigned int i =0; i <word.length(); i++){
		charValue = word[i];
		if(!unique.test(charValue) ){
			unique.set(charValue,1);
		}
		else {
			return false;
		}
	}
	return true;
}

//#2 without using additional data structures by sorting first and then checking
bool isUnique3(string word){
	sort(word.begin(), word.end());

	if(word.length() == 1){
		return true;
	}

	for (int i = 1; i < word.length(); i++){
		if (word[i] == word[i-1]){
			return false;
		}
	}

	return true;
}

int main(){
	string word = "";
	getline(cin, word);

	if ( isUnique3(word) ){
		cout << "Unique";
	}
	else {
		cout << "Not unique";
	}

	return 0;
}