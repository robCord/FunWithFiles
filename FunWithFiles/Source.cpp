#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//Author: Roberto Cordova
//Date: 1/30/20
//Purpose: transform data and then convert to a text file


int main()
{
	//sets array for CONST keywords 
	const std::string KEYWORDS[] = {
		"asm", "auto", "bool", "break", "case", "catch",
		"char", "class", "const", "const_cast", "continue",
		"default", "delete", "do", "double", "dynamic_cast",
		"else", "enum", "explicit", "export", "extern",
		"false", "float", "for", "friend", "goto", "if",
		"inline", "int", "long", "mutable", "namespace", "new",
		"operator", "private", "protected", "public", "register",
		"reinterpret_cast", "return", "short", "signed", "sizeof",
		"static", "static_cast", "struct", "switch", "template", 
		"this", "throw", "true", "try", "typedef", "typeid", "typename",
		"unison", "unsigned", "using", "virtual", "void", "volatile",
		"wchar_t", "while"
	};
	//sets array for reserve words 
	const std::string RESERVED_WORDS[] = {
		"and", "and_eq", "bitand", "bitor", "compl", "not",
		"not_eq", "or", "or_eq", "xor", "xor_eq"
	};

	//sets in file handler 
	std::ifstream in_file_handler;
	std::vector<std::string> file_text;

	//opens file 
	in_file_handler.open("CPP_Reference.txt");
	//checks if open
	if (in_file_handler.is_open()) 
	{
		//grabs string line
		std::string line;
		while (std::getline(in_file_handler, line)) 
		{//sets string to lowercase 
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
			file_text.push_back(line);
		}
	}
	//creating a output file handler for keywords
	std::ofstream out_file_handler("list.txt");
	//creating a vector for keywords using the const 
	std::vector<std::string> keywords;
	//loop through defined keywords
	for (std::string keyword : KEYWORDS)
	{
		//grabs each line of the input file
		for (std::string line : file_text)
		{
			//grabs the first word of each line 
			std::string word = line.substr(0, line.find(" "));
			//does word match current keyword
			if (word == keyword)
				//if it does it will be added to the list of keywords
				keywords.push_back(line);
		}
	}
	//outputs keywords to the output file
	out_file_handler << "C++ Keywords Defined = " << keywords.size() << ":\n";
	for (std::string line : keywords)
		out_file_handler << line << "\n";

	std::vector<std::string> reserved;

	for (std::string reserve : RESERVED_WORDS)
	{
		//grabs each line of the input file
		for (std::string line : file_text)
		{
			//grabs the first word of each line 
			std::string word = line.substr(0, line.find(" "));
			//does word match current keyword
			if (word == reserve)
				//if it does it will be added to the list of keywords
				reserved.push_back(line);
		}
	}
	// outputs the reserved to the output file
	out_file_handler << "\nC++ Reserved words Defined = " << reserved.size() << ":\n";
	for (std::string line : reserved)
		out_file_handler << line << "\n";


	//closes file 
	out_file_handler.close();
}