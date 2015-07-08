/*	This file is part of Textfile Library for C++.

    Textfile library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Textfile library.  If not, see <http://www.gnu.org/licenses/>.*/
    
#include "textfile.h"

#ifndef TEXTFILE_CPP
#define TEXTFILE_CPP

#include "textfile.h"

using namespace std;

textfile::textfile(string f) {
	maxline = 0;
	thecontent = "";
	fileok = false;
	
	fileok = false;
	ifstream checkfile(f.c_str());
	if (checkfile.good()) {
		ifstream thefile;
		thefile.open(f.c_str());					// open file (no error checking implemented yet)
		stringstream thebuffer;
		thebuffer << thefile.rdbuf();				// convert ifstream to stringstream
		thefile.close();
		thecontent = thebuffer.str();				// convert stringstream to normal string
		thebuffer.str("");
		getmaxline();								// calculate max line in the textfile
		fileok = true;
	}
	else thecontent = f;
}

int textfile::replace(string f,string f2) {
	string::size_type nval;
	nval = thecontent.find(f);
	if (nval != string::npos) {
		thecontent.replace(nval,f.length(),f2);
		return true;
	}
	else return false;
}

void textfile::split(vector<string> &tokens, const string &text, char sep) {
  int start = 0, end = 0;
  while ((end = text.find(sep, start)) != string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
}

void textfile::trysplit(char delim) {
	arraycontent.clear();
	split(arraycontent,thecontent,delim);
}

void textfile::trylinesplit(char delim) {
	vector<std::string> temp;
	textfile::trysplit();
	for (unsigned int i=0;i<arraycontent.size();i++) {
		split(temp,arraycontent[i],delim);
	}
	arraycontent.clear();
	arraycontent = temp;
	temp.clear();
}

void textfile::linesplit(int line_number, char delim) {
	arraycontent.clear();
	split(arraycontent,lineread(line_number),delim);
}

void textfile::strsplit(string str, char delim) {
	arraycontent.clear();
	split(arraycontent,str,delim);
}

string textfile::lineread(int line) {
	if (line > maxline || line <= 0) return "Invalid line number";
	int start = 0, end = 0;
	
	for (int i = 0; i < line; i++) {
		end = thecontent.find('\n',start);
		if (i == line - 1) {
			return thecontent.substr(start,end-start);
		} else {
			start = end + 1;
		}
	}
	return "";
}

void textfile::getmaxline() {
	int start = 0, end = 0;
	while ((end = thecontent.find('\n', start)) != string::npos) {
		maxline++;
	    start = end + 1;
	}
	maxline++;
}

void textfile::regexfind(string str) {
	std::regex r(str);
	std::regex_iterator<std::string::iterator> rstart(thecontent.begin(), thecontent.end(), r);
	std::regex_iterator<std::string::iterator> rend;
	vector<string> temp;

	for (rstart; rstart != rend; rstart++) {
		temp.push_back(rstart->str());
	}

	arraycontent.clear();
	arraycontent = temp;
}

bool textfile::replaceline(int linenumber, string str) {
	if (textfile::lineread(linenumber).compare("Invalid line number") != 0) {
		textfile::replace(lineread(linenumber),str);
		return true;
	}
	else return false;
}

void textfile::out(string f) {
	ofstream thefile(f.c_str(),ios_base::trunc);
	thefile << thecontent;
	thefile.close();
	thecontent = "";
	return;
}

#endif
