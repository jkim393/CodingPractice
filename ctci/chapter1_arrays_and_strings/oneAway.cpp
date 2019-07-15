//2 strings given, check if replace/insert/remove one away
//look at each method
//replace -> same length
//insert -> not same length -> compare char by char
#include <iostream>

using namespace std;

bool replace(string word, string word2){
	int checker = 0;
	for (int i=0; i<word.length(); i++){
		if(word[i] != word2[i]){
			if (checker == 0){
				checker++;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

bool insert(string word, string word2){
	int j, checker = 0;
		for (int i=0; i<word.length(); i++){
			if(word[j] != word2[i]){
			
				if (checker == 0){
					checker++;
				}
				else {
					return false;
				}
			}
			else {
				j++;
			}
		}
	return true;
}

bool isOneaway(string word, string word2){
	if (word.length() == word2.length() ){
		return replace(word, word2);
	}
	else {
		if (word.length() < word2.length() ){
			return insert(word, word2);
		}
		else{
			return insert(word2, word);
		}
	}
	return true;
}


int main(){
	string word, word2 = "";
	getline(cin, word);
	getline(cin, word2);
	
	
	if ( isOneaway(word, word2) ){
		cout << "One away";
	}
	else {
		cout << "Not one away";
	}

	return 0;
}