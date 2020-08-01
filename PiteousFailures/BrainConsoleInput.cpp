#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	//init brainheck

	char str[10000];

	char* main_array = new char[3000];

	for (int x = 0; x < 2999; x++)
	{
		main_array[x] = 0;
	}

	char* ptr = new char;
	ptr = main_array;



	//std::ifstream input;
	//input.open("input_file.txt");



	char* char_ptr = str;

	for (int i = 1; i < argc; i++)
	{
		if (*(argv[i]) == 'p') *ptr += 1;
		else if (*(argv[i]) == 'm') *ptr -= 1;
		else if (*(argv[i]) == 'f') ptr += 1;
		else if (*(argv[i]) == 'b') ptr -= 1;
		else if (*(argv[i]) == 'o') { std::cout << *ptr; }
		else {}
	}

	std::cin.get();
	std::cin.get();

}