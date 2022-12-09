#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

int main(){

	ifstream input_file("input.txt");
	string buffer;

	// PART 1
	/* unordered_set<pair<int, int>, SimpleHash> history;
	pair<int, int> head(4, 0);
	pair<int, int> tail(4, 0);

	while(getline(input_file, buffer, ' ')){
		char move = buffer[0];

		getline(input_file, buffer, '\n');
		int amount = stoi(buffer);

		for(int i = 0; i < amount; i++){
			switch(move){
				case 'U':
					head.first -= 1;
					break;
				case 'R':
					head.second += 1;
					break;
				case 'D':
					head.first += 1;
					break;
				case 'L':
					head.second -= 1;
					break;
				default:
					break;
			}

			// Too far from head
			if(abs(head.first - tail.first) > 1 || abs(head.second - tail.second) > 1){
				// The tail is diagonal to the head
				if((abs(head.first - tail.first) > 1 && abs(head.second - tail.second) == 1) || (abs(head.first - tail.first) == 1 && abs(head.second - tail.second) > 1)) {
					// Left down diagonal
					if(tail.first > head.first && tail.second < head.second){
						tail.first -= 1;
						tail.second += 1;
					}
					// Right down diagonal
					else if(tail.first > head.first && tail.second > head.second){
						tail.first -= 1;
						tail.second -= 1;
					}
					// Left up diagonal
					else if(tail.first < head.first && tail.second < head.second){
						tail.first += 1;
						tail.second += 1;
					}
					// Right up diagonal
					else{
						tail.first += 1;
						tail.second -= 1;
					}
				}
				// The tail is on the same x or y axis as the head
				else{
					if(head.first - tail.first > 1)
						tail.first++;
					else if(tail.first - head.first > 1)
						tail.first--;
					else if(head.second - tail.second > 1)
						tail.second++;
					else
						tail.second--;
				}
			}

			// cout << "Head: (y: " << head.first << ", x: " << head.second << ")\n";
			// cout << "Tail: (y: " << tail.first << ", x: " << tail.second << ")\n\n";

			history.insert(tail);
		}
	} */


	unordered_set<pair<int, int>, SimpleHash> history;
	vector<pair<int, int>> knots(10);

	for(int i = 0; i < knots.size(); i++){
		knots[i].first = 0;
		knots[i].second = 0;
	}

	while(getline(input_file, buffer, ' ')){
		char move = buffer[0];

		getline(input_file, buffer, '\n');
		int amount = stoi(buffer);

		for(int i = 0; i < amount; i++){
			switch(move){
				case 'U':
					knots[0].first -= 1;
					break;
				case 'R':
					knots[0].second += 1;
					break;
				case 'D':
					knots[0].first += 1;
					break;
				case 'L':
					knots[0].second -= 1;
					break;
				default:
					break;
			}

			for(int i = 1; i < knots.size(); i++){
				pair<int, int> *head = &knots[i - 1];
				pair<int, int> *tail = &knots[i];

				if(abs(head->first - tail->first) > 1 || abs(head->second - tail->second) > 1){
					if(head->first != tail->first && head->second != tail->second){
						// Left down diagonal
						if(tail->first > head->first && tail->second < head->second){
							tail->first -= 1;
							tail->second += 1;
						}
						// Right down diagonal
						else if(tail->first > head->first && tail->second > head->second){
							tail->first -= 1;
							tail->second -= 1;
						}
						// Left up diagonal
						else if(tail->first < head->first && tail->second < head->second){
							tail->first += 1;
							tail->second += 1;
						}
						// Right up diagonal
						else{
							tail->first += 1;
							tail->second -= 1;
						}
					}
					else{
						if(head->first - tail->first > 1)
							tail->first++;
						else if(tail->first - head->first > 1)
							tail->first--;
						else if(head->second - tail->second > 1)
							tail->second++;
						else
							tail->second--;
					}
				}
			}

			history.insert(knots[knots.size() - 1]);
		}
	}

	cout << history.size();

	return 0;
}
