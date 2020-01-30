#include <iostream>
#include <fstream>
#include <string>
//Author: Roberto Cordova
//Date: 1/30/20
//Purpose: transform data and then convert to a text file


int main()
{
	//************************File Reader***************************
	//
	//
	//var to hold user input
	std::string stuffToRemember;
	//intro
	std::cout << "\n\n\n\t\tThe Ultimate File Construction\n\n";
	std::cout << "\n\tThe ultimate remembering experience money can acquire\n";
	//init file object
	//create an object file handle to work around with
	std::ofstream obj_file_handle;
	//opening file
	obj_file_handle.open("memory.txt");
	//loop to write 5 statements
	for (int i = 0; i < 5; i++)
	{
		std::cout << "You have used " << i + 1 << " of blanks in memory to write to.\n";
		std::cout << "\nWhat would you like to recall?\n";
		//receive user input
		std::getline(std::cin, stuffToRemember);

		//check to see if open before writing
		if (obj_file_handle.is_open())
		{
			std::cout << "\nFile handle is open, currently writing to it!\n";
			//write to file
			obj_file_handle << stuffToRemember << std::endl;
		}
		else
		{
			std::cout << "\nError file handler is close, cannot write to file!\n";
		}
	}
	//close file
	obj_file_handle.close();
	std::cout << "\nThe file has been closed!\n\n\n";

	//***************************************************************
		
	//read the memory
	//filestream variable file
	std::fstream file;
	std::string word, filename;

	//filename of the file
	filename = "memory.txt";

	//opening file
	file.open(filename.c_str());

	//extracting words from the file
	while(file >> word)
	{
		//displayinf content
		std::cout << word << std::endl;
		
	}


	
}