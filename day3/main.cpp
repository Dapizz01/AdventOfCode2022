#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

	// string buffer;
	string s1, s2, s3;
	ifstream input_file("input.txt");
	int priority = 0;
	
	// PART 1
	/* while(getline(input_file, buffer, '\n')){
		unordered_map<char, int> freq;

		string left = buffer.substr(0, buffer.size() / 2);
		string right = buffer.substr(buffer.size() / 2, buffer.size());

		for(int i = 0; i < left.size(); i++){
			freq.try_emplace(left[i], 1);
		}

		for(int i = 0; i < right.size(); i++){
			if(freq.contains(right[i])){
				priority += isupper(right[i]) ? right[i] - 'A' + 27 : right[i] - 'a' + 1;
				// priority += right[i] - 'a' + 1; // Errato conteggio, la tab ascii va da A a Z e poi da 'a' a 'z'
				break;
			}
		}
		
	} */

	while(getline(input_file, s1, '\n')){
		unordered_map<char, int> freq;

		getline(input_file, s2, '\n');
		getline(input_file, s3, '\n');

		for(int i = 0; i < s1.size(); i++)
			freq.try_emplace(s1[i], 1);

		for(int i = 0; i < s2.size(); i++){
			if(freq.contains(s2[i]))
				if(freq[s2[i]] == 1)
					freq[s2[i]] = 2;
		}

		for(int i = 0; i < s3.size(); i++){
			if(freq.contains(s3[i]))
				if(freq[s3[i]] == 2)
					freq[s3[i]] = 3;
		}

		for(auto element : freq){
			if(element.second == 3){
				priority += isupper(element.first) ? element.first - 'A' + 27 : element.first - 'a' + 1;
				break;
			}
		}
	}

	cout << priority;

	return 0;
}
