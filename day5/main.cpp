#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main(){

	string buffer, result;
	ifstream input_file("input.txt");
	vector<stack<char>> stacks;

	for(int i = 0; i < 9; i++){
		getline(input_file, buffer, ' ');
		int ct = stoi(buffer);
		stacks.push_back(stack<char>());

		for(int j = 0; j < ct; j++){
			getline(input_file, buffer, (j == ct - 1) ? '\n' : ' ');

			stacks[i].push(buffer[0]);
		}
	}

	while(getline(input_file, buffer, ' ')){
		int amount = stoi(buffer), from, to;

		getline(input_file, buffer, ' ');
		getline(input_file, buffer, ' ');
		from = stoi(buffer) - 1;

		getline(input_file, buffer, ' ');
		getline(input_file, buffer, '\n');
		to = stoi(buffer) - 1;

		// PART 1
		/* for(int i = 0; i < amount; i++){
			stacks[to].push(stacks[from].top());
			stacks[from].pop();
		} */

		stack<char> tmp;
		for(int i = 0; i < amount; i++){
			tmp.push(stacks[from].top());
			stacks[from].pop();
		}

		for(int i = 0; i < amount; i++){
			stacks[to].push(tmp.top());
			tmp.pop();
		}
	}

	for(int i = 0; i < stacks.size(); i++){
		result += stacks[i].top();
	}

	cout << result;

	return 0;
}
