#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	// PART 1
	/* string buffer;
	ifstream input_file("input1.txt");
	int max = 0;
	int tmp = 0;

	while(getline(input_file, buffer, '\n')){
		if(buffer == ""){
			if(tmp > max)
				max = tmp;
			tmp = 0;
		}
		else{
			int val = stoi(buffer);
			tmp += val;
		}
	}

	cout << max; */

	// PART 2
	string buffer;
	ifstream input_file("input1.txt");
	vector<int> max{0, 0, 0};
	int tmp = 0;

	while(getline(input_file, buffer, '\n')){
		if(buffer == ""){
			int min = max[0], min_index = 0;
			for(int i = 0; i < 3; i++){
				if(max[i] < min){
					min = max[i];
					min_index = i;
				}
			}
			if(tmp > min)
				max[min_index] = tmp;
			tmp = 0;
		}
		else{
			int val = stoi(buffer);
			tmp += val;
		}
	}

	cout << (max[0] + max[1] + max[2]); 
	return 0;
}
