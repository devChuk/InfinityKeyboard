#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Node {
    string data;
    // True if this character is last character of one of the words
    int isEndOfString;
    vector<Node*> branches;
};

struct word {
    int strength;
    string w;
};

class poo { //can't think of a class name. This is the class that takes words typed in a 1L format and returns a list of 10 predicted English words
public:
	poo() { //initialize the head treeNode
		head.data = "";
		head.isEndOfString = 1;
		head.branches.push_back(NULL);
	}
private:
	Node head;
};

int main() {
	poo wordGuess;
}
/*
Steps of main functionu

1)create initial head
2)cin for word input
3)grow dat tree

*/