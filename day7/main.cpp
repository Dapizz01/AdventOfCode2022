#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

#define TOTAL_SIZE 70000000
#define FREE_NEEDED 30000000

using namespace std;

struct file{
	file *parent;
	int bytes;
	string name;
	bool is_dir;
	vector<file> sub_files;
};

int fix_fs_dir_size(file *root){
	if(root->is_dir == false){
		return root->bytes;
	}
	else{
		root->bytes = 0;
		for(int i = 0; i < root->sub_files.size(); i++){
			root->bytes += fix_fs_dir_size(&(root->sub_files[i]));
		}
		return root->bytes;
	}
}

int get_max_100000(file root){
	if(root.is_dir == false)
		return 0;
	else{
		int tot = 0;
		
		for(int i = 0; i < root.sub_files.size(); i++){
			tot += get_max_100000(root.sub_files[i]);
		}

		return (root.bytes <= 100000) ? tot += root.bytes : tot;
	}
}

int free_space(file root, int needed){
	if(root.is_dir == false)
		return 0;
	else{
		int most_fit = TOTAL_SIZE;

		for(int i = 0; i < root.sub_files.size(); i++){
			int sub_space = free_space(root.sub_files[i], needed);
			if(sub_space < most_fit && sub_space >= needed)
				most_fit = sub_space;
		}

		return (root.bytes < most_fit && root.bytes >= needed) ? root.bytes : most_fit;
	}
}

int main(){

	ifstream input_file("input.txt");
	string buffer;
	file root = {.is_dir=true};

	file *travers = &root;

	getline(input_file, buffer, '\n');

	while(getline(input_file, buffer, ' ')){
		if(buffer == "$"){
			getline(input_file, buffer, '\n');

			if(buffer != "ls"){
				istringstream iss(buffer);
				string token;
				vector<string> command;

				while(getline(iss, token, ' ')){
					command.push_back(token);
				}

				if(command[0] == "cd"){
					if(command[1] == ".."){
						travers = travers->parent;
					}
					else{
						for(int i = 0; i < travers->sub_files.size(); i++){
							if(travers->sub_files[i].name == command[1])
								travers = &(travers->sub_files[i]);
						}
					}
				}
			}	

		}
		else if(buffer == "dir"){
			string name;
			file curr;

			getline(input_file, buffer, '\n');

			curr.name = buffer;
			curr.is_dir = true;
			curr.bytes = 0;
			curr.parent = travers;

			(*travers).sub_files.push_back(curr);
		}
		else{
			int size;
			string name;
			file curr;

			size = stoi(buffer);

			getline(input_file, buffer, '\n');
			name = buffer;

			curr.parent = travers;
			curr.bytes = size;
			curr.name = name;
			curr.is_dir = false;

			(*travers).sub_files.push_back(curr);

		}
	}

	fix_fs_dir_size(&root);

	// PART 1
	// cout << get_max_100000(root);
	
	cout << free_space(root, FREE_NEEDED - (TOTAL_SIZE - root.bytes));

	return 0;
}
