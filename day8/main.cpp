#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

int scenery_score(vector<vector<int>> trees, int y, int x){
	int score = 1, i;

	// TOP
	i = y;
	do{
		i--;
		if(trees[i][x] >= trees[y][x])
			break;
	}
	while(i > 0);
	score *= (y - i);

	// BOTTOM
	i = y;
	do{
		i++;
		if(trees[i][x] >= trees[y][x])
			break;
	}
	while(i < trees.size() - 1);
	score *= (i - y);

	// LEFT
	i = x;
	do{
		i--;
		if(trees[y][i] >= trees[y][x])
			break;
	}
	while(i > 0);
	score *= (x - i);

	// RIGHT
	i = x;
	do{
		i++;
		if(trees[y][i] >= trees[y][x])
			break;
	}
	while(i < trees.size() - 1);
	score *= (i - x);

	return score;
}

int main(){

	string buffer;
	ifstream input_file("input.txt");
	int ct = 1, res = 0;

	getline(input_file, buffer, '\n');

	vector<vector<int>> trees(buffer.size(), vector<int>(buffer.size()));
	vector<vector<bool>> check(buffer.size(), vector<bool>(buffer.size()));

	for(int i = 0; i < buffer.size(); i++){
		trees[0][i] = buffer[i] - '0'; // char to int
		check[0][i] = false;
	}

	while(getline(input_file, buffer, '\n')){
		for(int i = 0; i < buffer.size(); i++){
			trees[ct][i] = buffer[i] - '0';
			check[ct][i] = false;
		}
		ct++;
	}

	/* PART 1
	// BORDERS
	for(int i = 0; i < trees.size(); i++){
		check[i][0] = true;
		check[i][trees.size() - 1] = true;
		check[0][i] = true;
		check[trees.size() - 1][i] = true;
	}

	// TOP
	for(int x = 1; x < trees.size() - 1; x++){
		int highest = trees[0][x];

		for(int y = 1; y < trees.size() - 1; y++){
			if(trees[y][x] > highest){
				highest = trees[y][x];
				check[y][x] = true;
			}
		}
	}

	// DOWN
	for(int x = 1; x < trees.size() - 1; x++){
		int highest = trees[trees.size() - 1][x];

		for(int y = trees.size() - 2; y > 0; y--){
			if(trees[y][x] > highest){
				highest = trees[y][x];
				check[y][x] = true;
			}
		}
	}

	// LEFT
	for(int y = 1; y < trees.size() - 1; y++){
		int highest = trees[y][0];

		for(int x = 1; x < trees.size() - 1; x++){
			if(trees[y][x] > highest){
				highest = trees[y][x];
				check[y][x] = true;
			}
		}
	}

	// RIGHT
	for(int y = 1; y < trees.size() - 1; y++){
		int highest = trees[y][trees.size() - 1];

		for(int x = trees.size() - 2; x > 0; x--){
			if(trees[y][x] > highest){
				highest = trees[y][x];
				check[y][x] = true;
			}
		}
	}

	for(int y = 0; y < check.size(); y++)
		for(int x = 0; x < check[y].size(); x++)
			if(check[y][x])
				res++;

	cout << res; */

	int max = 0;

	for(int y = 1; y < trees.size() - 1; y++){
		for(int x = 1; x < trees.size() - 1; x++){
			int score = scenery_score(trees, y, x);
			if(score > max)
				max = score;
		}
	}

	cout << max;

	return 0;
}
