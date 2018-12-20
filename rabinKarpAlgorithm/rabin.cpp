#include <iostream>
#include <cstring>

#define PRIME 101
#define INPUTS 26

using namespace std;

	/*
	//naive algorithm
	int counter = 0;
	for (int i = 0; i < texLen-patLen+1; i++) {
		bool found = true;
		for (int j = 0; j < texLen; j++) {
			if (text[j] != text[i+j]) {
				found = false;
				break;
			}
		}
		if (found == true) 
			counter++;
	}
	if (counter == 0)
		cout << "Not found" << endl;
	else
		cout << "Found" << endl;
	*/

int main(int argc, const char *argv[]) {
	
	char text[] = "redqwertreddasw";
	char pattern[] = "red";

	int textLen = strlen(text);
	int pattLen = strlen(pattern);
	int textHash = 0;
	int pattHash = 0;
	int hash = 1;
	int i, j;
	
	for (i = 0; i < pattLen; i++) {
		hash = (hash*INPUTS) % PRIME;
		cout << i << " Hash: " << hash << endl;
	}

	for (i = 0; i < pattLen; i++) {
		pattHash = (INPUTS * pattHash + pattern[i]) % PRIME;	
		printf("PattHash[%d]: %d\n", i, pattHash);
		textHash = (INPUTS * textHash + text[i]) % PRIME;	
		printf("TextHash[%d]: %d\n", i, textHash);
	}

	for (i = 0; i < textLen-pattLen+1; i++) {
	//pattern bolon text-n hash utga tentsii bol char-uudiig shalgana
		if (pattHash == textHash) {
			for (j = 0; j < pattLen; j++) {
				if (pattern[j] != text[i+j])
					break;
			}
			if (j == pattLen) {
				cout << "found at: " << i << endl;
			}
		}
		else if (i < textLen-pattLen) {
			textHash = (INPUTS * (textHash - (int)text[i]*hash) + (int)text[i+pattLen]) % PRIME;
			if (textHash < 0)
				textHash = textHash + PRIME;
		}
	}

	return 0;

}
//https://riptutorial.com/algorithm/example/24653/introduction-to-rabin-karp-algorithm
