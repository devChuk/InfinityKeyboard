/*
HOW CAN OPTIMIZE
    kill off node combos that don't exist
    binary search
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <cstring>
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

bool two_less(word const & a, word const & b)
{
    return a.strength > b.strength;
}

Node* newNode(string data) {
    Node* temp = new Node;
    temp->data = data;
    temp->isEndOfString = 1;
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    temp->branches.push_back(NULL);
    return temp;
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

void prnt(Node* root, int depth) {
    string tab = ".    .";
    for (int i = 0; i < depth; i++)
        tab += tab;
    if (root->branches[0] != NULL) {
        cout << tab << root->branches[0]->data << endl;
        prnt(root->branches[0],1+depth);
    }
    if (root->branches[1] != NULL) {
        cout << tab << root->branches[1]->data << endl;
        prnt(root->branches[1],1+depth);
    }
    if (root->branches[2] != NULL) {
        cout << tab << root->branches[2]->data << endl;
        prnt(root->branches[2],1+depth);
    }
}

void arr(Node* root, string bb, vector<string>& ans) {
    if (root->branches[0] != NULL) {
        ans.push_back(bb+root->branches[0]->data);
        //cout << bb << root->branches[0]->data << endl;
        arr(root->branches[0], bb + root->branches[0]->data, ans);
    }
    if (root->branches[1] != NULL) {
        ans.push_back(bb+root->branches[1]->data);
        //cout << bb << root->branches[1]->data << endl;
        arr(root->branches[1], bb + root->branches[1]->data, ans);
    }
    if (root->branches[2] != NULL) {
        ans.push_back(bb+root->branches[2]->data);
        //cout << bb << root->branches[2]->data << endl;
        arr(root->branches[2], bb + root->branches[2]->data, ans);
    }
}

void attach(Node* root, char i) {
    if (i == 'q') {
        vector<string> n; n.push_back("q"); n.push_back("a"); n.push_back("z");
        insert(root, n);
    }
    if (i == 'w') {
        vector<string> n; n.push_back("w"); n.push_back("s"); n.push_back("x");
        insert(root, n);
    }
    if (i == 'e') {
        vector<string> n; n.push_back("e"); n.push_back("d"); n.push_back("c");
        insert(root, n);
    }
    if (i == 'r') {
        vector<string> n; n.push_back("r"); n.push_back("f"); n.push_back("v");
        insert(root, n);
    }
    if (i == 't') {
        vector<string> n; n.push_back("t"); n.push_back("g"); n.push_back("b");
        insert(root, n);
    }
    if (i == 'y') {
        vector<string> n; n.push_back("y"); n.push_back("h"); n.push_back("n");
        insert(root, n);
    }
    if (i == 'u') {
        vector<string> n; n.push_back("u"); n.push_back("j"); n.push_back("m");
        insert(root, n);
    }
    if (i == 'i') {
        vector<string> n; n.push_back("i"); n.push_back("k");
        insert(root, n);
    }
    if (i == 'o') {
        vector<string> n; n.push_back("o"); n.push_back("l");
        insert(root, n);
    }
    if (i == 'p') {
        vector<string> n; n.push_back("p");
        insert(root, n);
    }
}

int countDepth(Node* root) {
    int depth = 0;
    while (!(root->isEndOfString)) {
        root = root->branches[0];
        depth++;
    }
    // cout << depth << endl;
    return depth;

}

int main() {
    Node begin;
    begin.data = ""; begin.isEndOfString = 1; begin.branches.push_back(NULL); begin.branches.push_back(NULL); begin.branches.push_back(NULL);

    string swagger;
    cin >> swagger;
    for (int i = 0; i < swagger.length(); i++) {
        // cout << swagger.at(i) << endl;
        attach(&begin, swagger.at(i));
    }


    vector<string> ans;

    //prnt(&begin, 0);
    arr(&begin, "", ans);
    int su = countDepth(&begin);
    vector<string> fin;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].length() == su) {
            fin.push_back(ans[i]);
            // cout << ans[i] << endl;
        }
    }

    vector<word> hugo;
    for (int i = 0; i < fin.size(); i++) {
        string input = fin[i];
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