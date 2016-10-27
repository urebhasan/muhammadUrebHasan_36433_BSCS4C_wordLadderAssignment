/*
Muhammad Ureb Hasan 36433
AP Assignment 1 
Word Ladder Problem
Code file
*/

#include "headerFile_muhammadUrebHasan_36433_BSCS4C.h"

//*********************************************************************************************
int main(){
	
	string prevWord, nWord;

	char againChoice;

	while (true){
		int count = 0;
		hashTable ABC;
		string word1, word2;
		cout << "Enter first word: ";
		cin >> word1;
		cout << "Enter second word: ";
		cin >> word2;

		if (word1.length() != word2.length()){
			cout << "Words should be same length. Enter them again: \n";
		}
		else {

			if (word1 > word2)
				swap(word1, word2);

			int wordLen = word1.length();
			cout << "\nPlease wait, file is loading ....." << endl;

			ifstream ifs;
			ifs.open("test.txt", ifstream::in);
			for (int i = 0; ifs.good(); i++){

				getline(ifs, nWord);
				cout << "\r" << count++ << "/88670 Words";
				if (nWord.length() == wordLen){
					ABC.insertIntoHash(nWord);
				}

			}
			ifs.close();
			cout << "File is loaded \n\n";


			ABC.twoWords(word1, word2);
		}

		cout << "Do you want to find another chain?: (Y/N) ";
		cin >> againChoice;
		if (againChoice != 'y' && againChoice != 'Y')
			break;
		system("CLS");

	}
	cout << "\nBYE\n" << endl;
	

	return 0;
}