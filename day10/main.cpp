#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// It kinda works, it's missing the first column and really needs some refactoring...

void update_display(bool display[6][41], int *d_y, int *d_x, int b_x){
	if(b_x + 1 >= *d_x && *d_x >= b_x - 1)
		display[*d_y][*d_x] = true;
	else
		display[*d_y][*d_x] = false;

	(*d_x)++;
	if(*d_x > 40){
		*d_x = 1;
		(*d_y)++;
	}
}

int main(){

	string buffer;
	ifstream input_file("input.txt");
	int ct = 1, x = 1, pending_value = 0, timer = 0, result = 0;
	bool display[6][41]; // Offset of 1 on the x axis

	// PART 1
	/* while(true){
		if((ct - 20) % 40 == 0)
			// cout << x * ct << "\n";
			result += x * ct;

		if(timer > 0){
			timer--;
		}
		else{
			if(pending_value != 0){
				x += pending_value;
				pending_value = 0;
			}
			
			if(getline(input_file, buffer, '\n')){
				if(buffer != "noop"){
					string token;
					istringstream ss(buffer);

					while(getline(ss, token, ' '));

					pending_value = stoi(token);
					timer = 1;
				}
			}
			else
				break;
		}

		ct++;
	}

	cout << result; */

	int d_y = 0, d_x = 1;

	while(ct < 40 * 6){
		getline(input_file, buffer, '\n');

		// addx
		if(buffer != "noop"){
			string token;
			istringstream ss(buffer);

			while(getline(ss, token, ' '));

			pending_value = stoi(token);

			// Update display during addx
			update_display(display, &d_y, &d_x, x);
			
			// Update value register x
			x += pending_value;

			// Update display after addx
			update_display(display, &d_y, &d_x, x);

			ct += 2;
		}
		// noop
		else{
			update_display(display, &d_y, &d_x, x);
			
			ct++;
		}
	}

	// Print display
	for(int d_y = 0; d_y < 6; d_y++){
		for(int d_x = 1; d_x < 40; d_x++){
			if(display[d_y][d_x])
				cout << "#";
			else
				cout << ".";
		}
		cout << "\n";
	}

	return 0;
}
