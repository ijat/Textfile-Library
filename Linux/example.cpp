// Compile with 'g++ -std=C++11 example.cpp'
// Make sure g++ version is 4.9.x

#include <iostream>
#include "src/textfile.h"

using namespace std;

int main() {
	textfile haha("Somuchequals.txt");

if (haha.fileok) {	// If file exists then proceed...
		cout << "Replace? " << haha.replace("hohoho", "marsupilami") << '\n';
		cout << "lineread: " << haha.lineread(3) << '\n';
		cout << "Maxline: " << haha.maxline << '\n';
		cout << "\nText content:\n" << haha.thecontent << "\n";	// print out text contents of text file

		haha.trysplit('=');		// split every new line and store to arraycontent
		cout << "\nSplitted whole string:\n";
		for (unsigned int i = 0; i < haha.arraycontent.size(); i++) {
			cout << "arraycontent[" << i << "] = " << haha.arraycontent[i] << '\n';
		}
		
		haha.replaceline(14,"Noooooooooooooooo");
		cout << "New line: " << haha.lineread(14) << '\n';

		haha.linesplit(7, '=');		// split at current line by delim '='
		cout << "\nSplitted line:\n";
		for (unsigned int i = 0; i < haha.arraycontent.size(); i++) {
			cout << "arraycontent[" << i << "] = " << haha.arraycontent[i] << '\n';
		}

		haha.trylinesplit('=');		// split at current line by delim '='
		cout << "\nSplitted line by line:\n";
		for (unsigned int i = 0; i < haha.arraycontent.size(); i++) {
			cout << "arraycontent[" << i << "] = " << haha.arraycontent[i] << '\n';
		}

		haha.strsplit("pokemon+digimon", '+');		// custom split
		cout << "\nSplitted custom string:\n";
		for (unsigned int i = 0; i < haha.arraycontent.size(); i++) {
			cout << "arraycontent[" << i << "] = " << haha.arraycontent[i] << '\n';
		}

		haha.regexfind();							// default value find float number in thecontent
		cout << "\nRegex matches:\n";
		for (unsigned int i = 0; i < haha.arraycontent.size(); i++) {
			cout << "arraycontent[" << i << "] = " << haha.arraycontent[i] << '\n';
		}

	}
	else {
		cout << "File not exists. Run this program from IDE or put this file in the same folder with main-example.cpp";
	}
	getchar();
	return 0;	
}