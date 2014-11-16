#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

struct word {
	int strength;
	string w;
};

bool two_less(word const & a, word const & b)
{
    return a.strength > b.strength;
}

int main(int argc, char** argv) {
	string input;
	cin >> input;
	ifstream ifs("new.txt");
	vector<word> hugo;
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
	sort(hugo.begin(), hugo.end(), two_less);
	for (int a = 0; a < 10; a++) {
    	cout << hugo[a].w << endl;
	}
}