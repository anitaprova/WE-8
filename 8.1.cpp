#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

bool has_repeated_words(string line){
	istringstream stream;
	stream.str(line);
	string previous = "";
	string word;
	while(stream >> word){
		if (word == previous){
			return true;
		}
		else{
			previous = word;
		}
	}
	return false;
}

int main(){
	string filename;
	cin >> filename;
	ifstream in_file;
	in_file.open(filename);

	string line;
	int line_number = 0;
	while (getline(in_file, line)){
		line_number++;
		if (has_repeated_words(line)){
			cout << setw(7) << line_number << ":" << line << endl;
		}
	}

	return 0;
}
