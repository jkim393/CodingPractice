//2 strings, see if the other is permutation of the other

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//sort method
bool isPermutation(string word, string word2){
	if (word.length() != word2.length() ){
		return false;
	}

	sort(word.begin(), word.end());
	sort(word2.begin(), word2.end());
	for (int i =0; i < word.length(); i++){
		if(word[i] != word2[i]){
			return false;
		}
	}
	return true;
}

//hash table method
bool isPermutation2(string word, string word2){
	vector<int> perm(128);
	int value = 0;
	for (int i =0; i < word.length(); i++){
		value = word[i];
		perm[value]++;
	}
	for (int i =0; i < word.length(); i++){
		value = word[i];
		perm[value]--;
		if (perm[value] < 0){
			return false;
		}
	}
	return true;
}


int main(){
	string word = "";
	string word2 = "";
	getline(cin, word);
	getline(cin, word2);

	if ( isPermutation2(word, word2) ){
		cout << "Permutation";
	}
	else {
		cout << "Not Permutation";
	}

	return 0;
}