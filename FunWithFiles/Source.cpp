#include <iostream>
#include <fstream>
#include <string>



int main()
{
	std::cout << "\n\n\n\t\tThe Ultimate File Construction\n\n";
	std::cout << "\nWhat would you like to recall?\n";
	std::string stuffToRemember;
	std::getline(std::cin, stuffToRemember);
	//create an object file handle to work with
	//opens your file 
	std::ofstream obj_file_handle;
	obj_file_handle.open("memory.txt");
	//using file stream here
	//notice arrows 
	std::cout << "About to write " << stuffToRemember << " to a file.\n";
	obj_file_handle << stuffToRemember;
	std::cout << "This file has been written to.\n";
	std::cout << "\nAttempting to close file!\n";
	obj_file_handle.close();
	std::cout << "\nThe file has been closed!\n\n\n";
		
	


	
}