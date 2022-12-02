#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	string buffer;
	ifstream input_file("input.txt");
	int score = 0;

	// PART 1
	/* while(getline(input_file, buffer, ' ')){
		char enemy_move = buffer[0];
		getline(input_file, buffer, '\n');
		char my_move = buffer[0];

		if(enemy_move == 'A'){
			if(my_move == 'X')
				score += 4;
			else if(my_move == 'Y')
				score += 8;
			else
				score += 3;
		}
		else if(enemy_move == 'B'){
			if(my_move == 'X')
				score += 1;
			else if(my_move == 'Y')
				score += 5;
			else
				score += 9;
		}
		else{
			if(my_move == 'X')
				score += 7;
			else if(my_move == 'Y')
				score += 2;
			else
				score += 6;
		}
	} */

	while(getline(input_file, buffer, ' ')){
		char enemy_move = buffer[0];
		getline(input_file, buffer, '\n');
		char my_move = buffer[0];

		if(enemy_move == 'A'){
			if(my_move == 'X')
				score += 3;
			else if(my_move == 'Y')
				score += 1;
			else
				score += 2;
		}
		else if(enemy_move == 'B'){
			if(my_move == 'X')
				score += 1;
			else if(my_move == 'Y')
				score += 2;
			else
				score += 3;
		}
		else{
			if(my_move == 'X')
				score += 2;
			else if(my_move == 'Y')
				score += 3;
			else
				score += 1;
		}

		score += (my_move - 'X') * 3;
	} 

	cout << score;

	return 0;
}
