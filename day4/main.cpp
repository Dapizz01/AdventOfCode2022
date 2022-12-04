#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

	string buffer;
	ifstream input_file("input.txt");
	int ct = 0;

	while(getline(input_file, buffer, '-')){
		int l1, r1, l2, r2;

		l1 = stoi(buffer);
		getline(input_file, buffer, ',');
		r1 = stoi(buffer);
		getline(input_file, buffer, '-');
		l2 = stoi(buffer);
		getline(input_file, buffer, '\n');
		r2 = stoi(buffer);

		// PART 1
		/* if(l1 <= l2 && r1 >= r2)
			ct++;
		else
			if(l2 <= l1 && r2 >= r1)
				ct++; */

		if(l1 <= r2 && l2 <= r1)
			ct++;
	}

	cout << ct;

	return 0;
}
