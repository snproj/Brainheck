#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//init brainheck

	std::cout << "copy-paste in the encoded text... capacity for translation however is limited.";

	char str[10000];

	char* main_array = new char[3000];

	for (int x = 0; x < 2999; x++)
	{
		main_array[x] = 0;
	}

	char* ptr = new char;
	ptr = main_array;


	std::cin.getline(str, 10000);

	//std::ifstream input;
	//input.open("input_file.txt");

	

	char* char_ptr = str;

	for (; *char_ptr != 0; char_ptr++)
	{
		if (*char_ptr == 'p') *ptr += 1;
		else if (*char_ptr == 'm') *ptr -= 1;
		else if (*char_ptr == 'f') ptr += 1;
		else if (*char_ptr == 'b') ptr -= 1;
		else if (*char_ptr == 'o') { std::cout << *ptr; }
		else {}
	}


}