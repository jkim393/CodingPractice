//check if the characters in a string input can form a palindrome
//all characters must be even number (except one character can be odd number if odd length string)
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

// longer solution
// bool isPalindrome(string word){
// 	int oddCount = 0;
// 	vector<int> pal (128);
// 	int value = 0;
	
// 	for (int i=0; i < word.length(); i++){
// 		value = word[i];
// 		pal[value]++;
// 	}

// 	for (int i=0; i<pal.size(); i++){
// 		if (pal[i] % 2) { //if odd
// 			oddCount++;
// 		}
// 	}
// 	if (oddCount > 1){
// 		return false;
// 	}
// 	return true;
// }

bool isPalindrome(string word){
	bitset<128> pal;
	int value = 0;
	
	for (int i=0; i < word.length(); i++){
		value = word[i];
		pal.flip(value);
	}

	if (pal.count() > 1){
		return false;
	}
	return true;
}

int main(){
	string word = "";
	getline(cin, word);
	
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	word.erase(remove(word.begin(), word.end(), ' '), word.end());

	if ( isPalindrome(word) ){
		cout << "palindrome";
	}
	else {
		cout << "Not palindrome";
	}

	return 0;
}