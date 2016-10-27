/*
Muhammad Ureb Hasan 36433
AP Assignment 1
Word Ladder Problem
Header file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

//*********************************************************************************************
bool checkDiff(string w1, string w2);
int sameLetters(string w1, string w2);

struct graphNode{
	string str;
	vector < graphNode* > neighbors;
	graphNode *next = NULL;
};


//*********************************************************************************************
class graph{
private:
	graphNode* head;
	string **timetable;
	int noOfSlots = 4;
	int totalSlots = 7200;

public:


	graph(){
		head = NULL;
	}

	~graph(void){}

	void insertWord(string newWord){
		graphNode* newNode = new graphNode;
		newNode->str = newWord;


		if (head == NULL){
			head = newNode;
		}
		else {
			graphNode *temp = head;

			while (temp->next && temp->str != newWord){

				if (checkDiff(temp->str, newWord)){
					temp->neighbors.push_back(newNode);
					newNode->neighbors.push_back(temp);
				}

				temp = temp->next;
			}

			if (temp->str == newWord){
				return;	//do nothing if words are the same 
			}

			if (temp == head && checkDiff(temp->str, newWord)){
				temp->neighbors.push_back(newNode);
				newNode->neighbors.push_back(temp);
			}
			temp->next = newNode;
		}
	}

	void wordChain(string str1, string str2){
		cout << "word chain\n";
		int replaceCount = sameLetters(str1, str2);
		string chainWord = str1;
		cout << chainWord;

		graphNode *temp;
		temp = head;
		while (temp->str != str1)
			temp = temp->next;

		while (chainWord != str2){
			for (vector<graphNode*>::iterator it = temp->neighbors.begin(); it != temp->neighbors.end(); ++it){
				graphNode* t = *it;
				int sameL = sameLetters(t->str, str2);
				if (sameL > replaceCount){
					chainWord = t->str;
					temp = t;
					replaceCount = sameL;
					cout << " --> " << chainWord;
					break;
				}
				if (*it == temp->neighbors.back()){
					cout << "\r Sorry no chain found from " << str1 << " to " << str2 << endl;
					return;
				}
			}
		}
		cout << endl;
	}

	void printGraph(){
		graphNode *temp = head;
		while (temp){
			cout << temp->str << endl;
			for (vector<graphNode*>::iterator it = temp->neighbors.begin(); it != temp->neighbors.end(); ++it){
				graphNode* t = *it;
				cout << "neig: " << t->str << ' ';
			}
			cout << endl;
			temp = temp->next;
		}
	}

};

//*********************************************************************************************
struct indexNode{
	string str;
	int len;
	indexNode *next = NULL;
	graph words;
};

//*********************************************************************************************
class hashTable{
private:
	indexNode *head;

public:
	hashTable(){
		head = NULL;
	}

	void insertIntoHash(string newWord){

		if (head == NULL){
			indexNode *newNode = new indexNode;
			head = newNode;
			head->len = newWord.length();
			head->words.insertWord(newWord);
		}
		else{
			indexNode *temp = head;
			int l = newWord.length();

			while (temp->next && temp->len != l){
				temp = temp->next;
			}

			if (temp->len == l){
				temp->words.insertWord(newWord);
			}
			else{
				indexNode *newNode = new indexNode;
				temp->next = newNode;
				newNode->len = l;
				newNode->words.insertWord(newWord);
			}
		}
	}

	void twoWords(string a, string b){
		if (a.length() != b.length()){
			cout << "Words should be same length beta! \n";
			return;
		}
		else{
			indexNode* temp;
			temp = head;
			while (temp->next && temp->len != a.length())
				temp = temp->next;

			temp->words.wordChain(a, b);
		}
	}

	void printHash(){
		if (head == NULL){
			cout << "nothin to print \n";
		}
		else {
			indexNode *temp = head;
			while (temp){
				cout << "\n****************************************************************\n";
				cout << temp->len << " WORDS \n";
				temp->words.printGraph();
				temp = temp->next;
			}
		}
	}

};

//*********************************************************************************************
int sameLetters(string w1, string w2){
	int count = 0;

	for (int i = 0; i < w1.length(); i++){
		if (w1[i] == w2[i])
			count += 1;
	}

	return count;
}

//*********************************************************************************************
bool checkDiff(string w1, string w2){
	int count = 0;

	if (w1.length() != w2.length()){
		cout << "SOMETHIGN WENT WRONG ! ! \n\n\n";
		return false;

	}

	for (int i = 0; i < w1.length(); i++){
		if (w1[i] != w2[i])
			count += 1;
	}

	if (count == 1){
		return true;
	}
	else{
		return false;
	}
}
