#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){

	string buffer;
	ifstream input_file("input.txt");

	getline(input_file, buffer, '\n');

	// PART 1 -> i < buffer.size() - 4
	for(int i = 0; i < buffer.size() - 14; i++){
		unordered_map<char, int> m;

		for(int j = 0; j < 14; j++){
			m.try_emplace(buffer[i + j], 1);
		}

		// PART 1
		/* m.try_emplace(buffer[i], 1);
		m.try_emplace(buffer[i + 1], 1);
		m.try_emplace(buffer[i + 2], 1);
		m.try_emplace(buffer[i + 3], 1); */

		if(m.size() == 14){
			cout << i + 14;
			break;
		}
	}

	return 0;
}
