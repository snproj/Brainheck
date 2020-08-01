#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//init brainheck

	char* main_array = new char[3000];

	for (int x = 0; x < 2999; x++)
	{
		main_array[x] = 0;
	}

	char* ptr = new char;
	ptr = main_array;


	//fstream starting

	std::ifstream input;
	std::string fileLocation;

	//gets file location from the user
	std::cout << "Please enter the location of the .txt file to decode: ";
	getline(std::cin, fileLocation);

	//opens the file
	input.open(fileLocation);

	//makes sure that the file opened properly
	while (input.fail())
	{
		std::cout << "The file at location " << fileLocation << " failed to open" << std::endl;
		std::cout << "Please enter the location of the file: ";
		getline(std::cin, fileLocation);
		input.open(fileLocation);
	}

	//std::ifstream input;
	//input.open("input_file.txt");

	std::ofstream output;
	output.open("decoded.txt");

	char array[10000] = { 0 };


	input.getline(array, 10000);

	char* char_ptr = array;
	
	for (; *char_ptr != 0; char_ptr++)
	{
		if (*char_ptr == 'p') *ptr += 1;
		else if (*char_ptr == 'm') *ptr -= 1;
		else if (*char_ptr == 'f') ptr += 1;
		else if (*char_ptr == 'b') ptr -= 1;
		else if (*char_ptr == 'o') { output.write(ptr, 1); }
		else {}
	}
	

}