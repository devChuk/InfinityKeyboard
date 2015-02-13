#include "textPredict.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
	using namespace std;

Node* newNode(string data) {
    Node* temp = new Node;
    temp->data = data;
    temp->isEndOfString = 1;
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    return temp;
}

bool two_less(word const& a, word const& b) {
    return a.strength > b.strength;
}

predictor::predictor() {
	head = new Node;
	head->data = "";
	head->isEndOfString = 1;
	head->branches.push_back(NULL);
	head->branches.push_back(NULL);
	head->branches.push_back(NULL);
}

predictor::~predictor() {
	deleteNode(head);
}
void predictor::insert(const string input) {
	for (int i = 0; i < input.length(); i++) {
        columnize(input.at(i));
    }
    genCombos(head, "");
    cleanCombos();
    search();
}

void predictor::columnize(char s) {
	vector<string> n;
    switch(s) {
    	case 'q':
    		n.push_back("q"); n.push_back("a"); n.push_back("z");
    	break;
    	case 'w':
    		n.push_back("w"); n.push_back("s"); n.push_back("x");
    	break;
    	case 'e':
    		n.push_back("e"); n.push_back("d"); n.push_back("c");
    	break;
    	case 'r':
    		n.push_back("r"); n.push_back("f"); n.push_back("v");
    	break;
    	case 't':
    		n.push_back("t"); n.push_back("g"); n.push_back("b");
    	break;
    	case 'y':
    		n.push_back("y"); n.push_back("h"); n.push_back("n");
    	break;
    	case 'u':

    	break;
    	case 'i':

    	break;
    	case 'o':
    	break;
    	case 'p':
    	break;

    }

    // if (s == 'q') {
    //     n.push_back("q"); n.push_back("a"); n.push_back("z");
    // }
    // else if (s == 'w') {
    //     n.push_back("w"); n.push_back("s"); n.push_back("x");
    // }
    // else if (s == 'e') {
    //     n.push_back("e"); n.push_back("d"); n.push_back("c");
    // }
    // else if (s == 'r') {
    //     n.push_back("r"); n.push_back("f"); n.push_back("v");
    // }
    // else if (s == 't') {
    //     n.push_back("t"); n.push_back("g"); n.push_back("b");
    // }
    // else if (s == 'y') {
    //     n.push_back("y"); n.push_back("h"); n.push_back("n");
    // }
    // else if (s == 'u') {
    //     n.push_back("u"); n.push_back("j"); n.push_back("m");
    // }
    // else if (s == 'i') {
    //     n.push_back("i"); n.push_back("k");
    // }
    // else if (s == 'o') {
    //     n.push_back("o"); n.push_back("l");
    // }
    // else if (s == 'p') {
    //     n.push_back("p");
    // }
    grow(head, n);
}

void predictor::grow(Node* root, vector<string> v) {
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

void predictor::genCombos(Node* root, string seed) {
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

void predictor::cleanCombos() {
	int cutoff = getTreeDepth();
	vector<string> temp;
	for (int i = 0; i < combinations.size(); i++) {
        if (combinations[i].length() == cutoff) {
            temp.push_back(combinations[i]);
        }
	}
	combinations = temp;
}

int predictor::getTreeDepth() {
	int depth = 0;
	Node* p = head;
	while (!(p->isEndOfString)) {
        p = p->branches[0];
        depth++;
    }
    return depth;
}

void predictor::reset() {
	combinations.clear();
	if (head->branches[0]) {
		deleteNode(head->branches[0]);
		if (head->branches[1]) {
			deleteNode(head->branches[1]);
			if (head->branches[2])
				deleteNode(head->branches[2]);
		}
	}
	head = new Node;
	head->data = "";
	head->isEndOfString = 1;
	head->branches.push_back(NULL);
	head->branches.push_back(NULL);
	head->branches.push_back(NULL);
}

void predictor::deleteNode(Node* root) {
	if (root->branches[0] != NULL)
		deleteNode(root->branches[0]);
	if (root->branches[1] != NULL)
		deleteNode(root->branches[1]);
	if (root->branches[2] != NULL)
		deleteNode(root->branches[2]);
	delete root;

}

void predictor::search() {
	vector<word> hugo;
	for (int i = 0; i < combinations.size(); i++) {
	    string input = combinations[i];
	    string txt = ".txt";
	    string folder = "./words/";
	    ifstream ifs(folder + input[0] + txt); //access the file with the corresponding first letter of the word to search
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
	if (hugo.size())
		for (int a = 0; (a < 10 && a < hugo.size()); a++) {
		    cout << hugo[a].w << " " << hugo[a].strength << endl;
		}
	else
		cout << "not found" << endl;
}