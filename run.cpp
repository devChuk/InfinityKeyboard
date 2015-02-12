#include "textPredict.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
	using namespace std;

int main() {
	string input;
	predictor wordGuesser;

	while (cin >> input) {
		if (input == "EXIT") {
			cout << "Program ended" << endl;
			break;
		}
		wordGuesser.insert(input);
		wordGuesser.reset();
	}
	return 0;
}