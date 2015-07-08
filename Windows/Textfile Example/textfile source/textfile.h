/*
Textfile Library for C++
========================

Created by: Ijat
Website: Ijat.my
Version: 0.2.1 rev 1
Last modified: 13 Feb 2015
------------------------------------------------------------------------------
License:
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------
Contact: contact@ijat.my
Variables/Method:
	* variables
		thecontent : string		-> this variable will hold the text file contents.
		maxline : int			-> return the maximum line of the text
		arraycontent : string	-> array of strings after split whole content from any method ___split();
		fileok : boolean		-> if file exists, this variable will set to true.
			
	* method
		textfile anyvariable("textfile.txt")		-> Load textfile.txt into the library and return the contents to variable thecontent
		anyvariable.replace("search","replace")		-> Find all "search" occurence in the file and replace it with "replace"
		
		anyvariable.trysplit('delim')				-> Split whole content by the delim and save in in vector arraycontent
		anyvariable.trylinesplit('delim')			-> Same as trysplit() but this method split it line by line for the whole content
		anyvariable.linesplit(line_number,'delim')	-> Split at current line_number
		anyvariable.strsplit("string",'delim')		-> Split custom string
		
		anyvariable.regexfind("regular_expression")		-> Find string that match the regular expression and put the values in arraycontent
		anyvariable.replaceline(line_number,"string")	-> Replace current line_number with string
		anyvariable.lineread(line_number)				-> Read current line_number and return as string
		anyvariable.out("file_name.txt")				-> Save any modified content to a file
	
*/

#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <iterator>

using namespace std;

class textfile
{
	public:
		int maxline;
		string thecontent;
		vector<string> arraycontent;
		bool fileok;
		
		textfile(string f);
		void out(string f = "temp.txt");
		int replace(string f, string f2);
		void trysplit(char delim = '\n');
		void trylinesplit(char delim = '\n');
		void linesplit(int line_number, char delim = '\n');
		void strsplit(string str, char delim = '\n');
		void regexfind(string str = "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
		bool replaceline(int linenumber, string str);
		string lineread(int line = 0);
		
	private:
		void split(vector<string> &tokens, const string &text, char sep);
		void getmaxline();
		
};

#endif
