#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <exception>
using namespace std;

struct Node {
    string data;
    // True if this character is last character of one of the words
    int isEndOfString;
    vector<Node*> branches;
};

Node* newNode(string data) {
    Node* temp = new Node;
    temp->data = data;
    temp->isEndOfString = 1;
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    return temp;
}

struct word {
    int strength;
    string w;
};

struct Errormessage {
	string message;
};

class poo { //can't think of a class name. This is the class that takes words typed in a 1L format and returns a list of 10 predicted English words
public:
	poo() { //initialize the head treeNode
		head = new Node;
		head->data = "";
		head->isEndOfString = 1;
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
	}

	void insert(const string input) { //takes in word at 1L format
		for (int i = 0; i < input.length(); i++) {
	        columnize(input.at(i));
	    }
	    genCombos(head, "");
	    for (int i = 0; i < combinations.size(); i++) {
	        cout << combinations[i] << endl;
	    }
	}

	void columnize(char s) {
	    if (s == 'q') {
	        vector<string> n; n.push_back("q"); n.push_back("a"); n.push_back("z");
	        insert(head, n);
	    }
	    else if (s == 'w') {
	        vector<string> n; n.push_back("w"); n.push_back("s"); n.push_back("x");
	        insert(head, n);
	    }
	    else if (s == 'e') {
	        vector<string> n; n.push_back("e"); n.push_back("d"); n.push_back("c");
	        insert(head, n);
	    }
	    else if (s == 'r') {
	        vector<string> n; n.push_back("r"); n.push_back("f"); n.push_back("v");
	        insert(head, n);
	    }
	    else if (s == 't') {
	        vector<string> n; n.push_back("t"); n.push_back("g"); n.push_back("b");
	        insert(head, n);
	    }
	    else if (s == 'y') {
	        vector<string> n; n.push_back("y"); n.push_back("h"); n.push_back("n");
	        insert(head, n);
	    }
	    else if (s == 'u') {
	        vector<string> n; n.push_back("u"); n.push_back("j"); n.push_back("m");
	        insert(head, n);
	    }
	    else if (s == 'i') {
	        vector<string> n; n.push_back("i"); n.push_back("k");
	        insert(head, n);
	    }
	    else if (s == 'o') {
	        vector<string> n; n.push_back("o"); n.push_back("l");
	        insert(head, n);
	    }
	    else if (s == 'p') {
	        vector<string> n; n.push_back("p");
	        insert(head, n);
	    }
	}

    void insert(Node* root, vector<string> v) {
	    // Base Case: Last node
	    if (root->isEndOfString) {
	    	for (int i = 0; i < v.size(); i++) {
	    		root->branches[i] = newNode(v[i]);
	    	}
	    	root->isEndOfString = 0;
	    }
	    //Not last node
	    else {
	    	for (int i = 0; i < root->branches.size(); i++) {
	    		if (root->branches[i] != NULL)
	    			insert(root->branches[i], v);
	    	}
	    }
	}
	//arr(&begin, "", ans);
	void genCombos(Node* root, string seed) {
		// cout << seed << endl;
		if (root->branches[0] != NULL) {
		    combinations.push_back(seed+root->branches[0]->data);
		    genCombos(root->branches[0], seed + root->branches[0]->data);
		}
		if (root->branches[1] != NULL) {
		    combinations.push_back(seed+root->branches[1]->data);
		    genCombos(root->branches[1], seed + root->branches[1]->data);
		}
		if (root->branches[2] != NULL) {
		    combinations.push_back(seed+root->branches[2]->data);
		    genCombos(root->branches[2], seed + root->branches[2]->data);
		}
	}

private:
	Node* head;
	vector<string> combinations;
};

int main() {
	poo wordGuesser;
	string input;


	while (cin >> input) {
		// cout << input << endl;
		wordGuesser.insert(input);
		if (input == "EXIT") {
			cout << "Program ended" << endl;
			break;
		}
	}
	/*
	Steps of main functionu

	1)create initial head
	2)cin for word input
	3)grow dat tree

	*/
}
