#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

class my_node{
	public:
		char value;
		int distance;
		pair<int, int> prev;
		my_node();
		my_node(char v, int d, pair<int, int> p);
};

my_node::my_node(){
	value = 'a';
	distance = -1;
	prev = make_pair(0, 0);
}

my_node::my_node(char v, int d, pair<int, int> p){
	value = v;
	distance = d;
	prev = p;
}

int main(){

	string buffer;
	ifstream input_file("input.txt");
	int rows = 0;

	getline(input_file, buffer);

	int cols = buffer.size();
	
	queue<pair<int, int>> q;
	// PART 1
	// pair<int, int> start;
	vector<pair<int, int>> starts;
	vector<vector<my_node>> mat(cols, vector<my_node>(cols));

	do{
		for(int i = 0; i < cols; i++){
			if(buffer[i] == 'E')
				mat[rows][i] = my_node('{', -1, make_pair(-1, -1));
			else if(buffer[i] == 'S' || buffer[i] == 'a'){
				mat[rows][i] = my_node('a', -1, make_pair(-1, -1));
				starts.push_back(make_pair(rows, i));
			}
			else
				mat[rows][i] = my_node(buffer[i], -1, make_pair(-1, -1));
		}
		rows++;
	}
	while(getline(input_file, buffer));

	for(int i = 0; i < starts.size(); i++){
		q.push(starts[i]);
		mat[starts[i].first][starts[i].second].distance = 0;
	}
	
	// PART 1
	// q.push(start);
	// mat[start.first][start.second].distance = 0;

	while(!q.empty()){
		pair<int, int> curr = q.front();

		if(curr.first > 0){
			if(mat[curr.first - 1][curr.second].distance == -1){
				if(mat[curr.first - 1][curr.second].value - mat[curr.first][curr.second].value <= 1){
					q.push(make_pair(curr.first - 1, curr.second));
					mat[curr.first - 1][curr.second].prev.first = curr.first;
					mat[curr.first - 1][curr.second].prev.second = curr.second;
					mat[curr.first - 1][curr.second].distance = mat[curr.first][curr.second].distance + 1;

					if(mat[curr.first - 1][curr.second].value == '{')
						cout << mat[curr.first - 1][curr.second].distance;
				}
			}
		}


		if(curr.first < rows - 1){
			if(mat[curr.first + 1][curr.second].distance == -1){
				if(mat[curr.first + 1][curr.second].value - mat[curr.first][curr.second].value <= 1){
					q.push(make_pair(curr.first + 1, curr.second));
					mat[curr.first + 1][curr.second].prev.first = curr.first;
					mat[curr.first + 1][curr.second].prev.second = curr.second;
					mat[curr.first + 1][curr.second].distance = mat[curr.first][curr.second].distance + 1;

					if(mat[curr.first + 1][curr.second].value == '{')
						cout << mat[curr.first + 1][curr.second].distance;
				}
			}
		}


		if(curr.second > 0){
			if(mat[curr.first][curr.second - 1].distance == -1){
				if(mat[curr.first][curr.second - 1].value - mat[curr.first][curr.second].value <= 1){
					q.push(make_pair(curr.first, curr.second - 1));
					mat[curr.first][curr.second - 1].prev.first = curr.first;
					mat[curr.first][curr.second - 1].prev.second = curr.second;
					mat[curr.first][curr.second - 1].distance = mat[curr.first][curr.second].distance + 1;

					if(mat[curr.first][curr.second - 1].value == '{')
						cout << mat[curr.first][curr.second - 1].distance;
				}
			}
		}


		if(curr.second < cols - 1){
			if(mat[curr.first][curr.second + 1].distance == -1){
				if(mat[curr.first][curr.second + 1].value - mat[curr.first][curr.second].value <= 1){
					q.push(make_pair(curr.first, curr.second + 1));
					mat[curr.first][curr.second + 1].prev.first = curr.first;
					mat[curr.first][curr.second + 1].prev.second = curr.second;
					mat[curr.first][curr.second + 1].distance = mat[curr.first][curr.second].distance + 1;

					if(mat[curr.first][curr.second + 1].value == '{')
						cout << mat[curr.first][curr.second + 1].distance;
				}
			}
		}

		q.pop();
	}

	return 0;
}
