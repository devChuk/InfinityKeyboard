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

bool two_less(word const & a, word const & b)
{
    return a.strength > b.strength;
}

struct Errormessage {
	string message;
};

class poo { //can't think of a class name. I asked Lucy to think of one for me haha
//Takes words typed in a 1L format and returns 10 predicted English words
public:
	poo() { //initialize the head treeNode
		head = new Node;
		head->data = "";
		head->isEndOfString = 1;
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
	}
	~poo() {
		deleteNode(head);
	}
	void insert(const string input) { //takes in word at 1L format
		for (int i = 0; i < input.length(); i++) {
	        columnize(input.at(i));
	    }
	    genCombos(head, "");
	    cleanCombos();
	    search();
	}

	void columnize(char s) {//converts single keypresses into the keypresses of the column
	    if (s == 'q') {
	        vector<string> n; n.push_back("q"); n.push_back("a"); n.push_back("z");
	        grow(head, n);
	    }
	    else if (s == 'w') {
	        vector<string> n; n.push_back("w"); n.push_back("s"); n.push_back("x");
	        grow(head, n);
	    }
	    else if (s == 'e') {
	        vector<string> n; n.push_back("e"); n.push_back("d"); n.push_back("c");
	        grow(head, n);
	    }
	    else if (s == 'r') {
	        vector<string> n; n.push_back("r"); n.push_back("f"); n.push_back("v");
	        grow(head, n);
	    }
	    else if (s == 't') {
	        vector<string> n; n.push_back("t"); n.push_back("g"); n.push_back("b");
	        grow(head, n);
	    }
	    else if (s == 'y') {
	        vector<string> n; n.push_back("y"); n.push_back("h"); n.push_back("n");
	        grow(head, n);
	    }
	    else if (s == 'u') {
	        vector<string> n; n.push_back("u"); n.push_back("j"); n.push_back("m");
	        grow(head, n);
	    }
	    else if (s == 'i') {
	        vector<string> n; n.push_back("i"); n.push_back("k");
	        grow(head, n);
	    }
	    else if (s == 'o') {
	        vector<string> n; n.push_back("o"); n.push_back("l");
	        grow(head, n);
	    }
	    else if (s == 'p') {
	        vector<string> n; n.push_back("p");
	        grow(head, n);
	    }
	}

    void grow(Node* root, vector<string> v) {//adds possible next chars to a tree
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
	    			grow(root->branches[i], v);
	    	}
	    }
	}

	void genCombos(Node* root, string seed) {//converts the tree into possible words
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

	void cleanCombos() {//removes words that are not as long as the input
	//remove the word combos that are smaller than the input 4 optimization
		int cutoff = getTreeDepth();
		vector<string> temp;
		for (int i = 0; i < combinations.size(); i++) {
	        if (combinations[i].length() == cutoff) {
	            temp.push_back(combinations[i]);
	        }
		}
		combinations = temp;
	}

	int getTreeDepth() {//returns the depth of the tree
		int depth = 0;
		Node* p = head;
		while (!(p->isEndOfString)) {
	        p = p->branches[0];
	        depth++;
	    }
	    return depth;
	}

	void reset() {
		combinations.clear();
		deleteNode(head->branches[0]);
		deleteNode(head->branches[1]);
		deleteNode(head->branches[2]);
		head = new Node;
		head->data = "";
		head->isEndOfString = 1;
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
		head->branches.push_back(NULL);
	}

	void deleteNode(Node* root) {
		if (root->branches[0] != NULL)
			deleteNode(root->branches[0]);
		if (root->branches[1] != NULL)
			deleteNode(root->branches[1]);
		if (root->branches[2] != NULL)
			deleteNode(root->branches[2]);
		delete root;

	}

	void search() { //finds words that contain combinations and returns top ten strongest words
		vector<word> hugo;
		for (int i = 0; i < combinations.size(); i++) {
		    string input = combinations[i];
		    ifstream ifs("new.txt");
		    string s;
		    string first;
		    int last;
		    while (ifs >> first >> last) {
		        if (first.find(input) == 0) {
		            word durr;
		            durr.strength = last;
		            durr.w = first;
		            hugo.push_back(durr);
		        }
		    }        
		}
		sort(hugo.begin(), hugo.end(), two_less);
		for (int a = 0; a < 10; a++) {
		    cout << hugo[a].w << " " << hugo[a].strength << endl;
		}
	}

private:
	Node* head;
	vector<string> combinations;
};

int main() {
	string input;
	poo wordGuesser;

	while (cin >> input) {
		if (input == "EXIT") {
			cout << "Program ended" << endl;
			break;
		}
		wordGuesser.insert(input);
		wordGuesser.reset();
	}
}
/*
TODO
================
Optimize
	kill off nasty nonexistant treeNode combos that don't exist
	binary search will be more hygenic
		perhaps we can move new.txt into an array.
		perhaps we can mark firstletterlocations
*/