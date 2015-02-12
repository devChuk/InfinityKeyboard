#ifndef TEXTPREDICT_H
#define TEXTPREDICT_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

struct Node {
    std::string data;
    // True if this character is last character of one of the words
    int isEndOfString;
    std::vector<Node*> branches;
};

Node* newNode(std::string data);

struct word {
    int strength;
    std::string w;
};

bool two_less(word const& a, word const& b);

class predictor {										//Takes words typed in a 1L format and returns 10 predicted English words
public:
	predictor();										 //initialize the head treeNode
	~predictor();
	void insert(const std::string input);				//takes in word at 1L format
	void columnize(char s);								//converts single keypresses into the keypresses of the column
	void grow(Node* root, std::vector<std::string> v);	//adds possible next chars to a tree
	void genCombos(Node* root, std::string seed);		//converts the tree into possible words
	void cleanCombos();									//removes words that are not as long as the input
	int getTreeDepth();
	void reset();
	void deleteNode(Node* root);
	void search();										//finds words that contain combinations and returns top ten strongest words
private:
	Node* head;
	std::vector<std::string> combinations;
};

#endif