#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ifstream ifs("en.txt");
	vector<string> hugo;
	string s;
	while (getline(ifs, s)) {
		hugo.push_back(s);
	}
	sort(hugo.begin(), hugo.end());
}