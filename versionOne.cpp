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


/*
Steps of main function
