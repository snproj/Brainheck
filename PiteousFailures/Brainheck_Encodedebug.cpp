#include <fstream>
#include <iostream>
#include <string>



int main()
{

	//fstream starting

	std::ifstream input;
	std::string fileLocation;

	std::cout << "With this version, you have to manually space out the 'p's. For whatever reason a bug is thrown specifically when printing 'p ' (with space following the 'p')." << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "In the .txt output file, do a find and replace from 'p' to 'p '. Also make sure that there are no newlines if any are generated for whatever reason." << std::endl;
	std::cout << "\n \n \n \n" << std::endl;
	//gets file location from the user
	std::cout << "Please enter the location of the .txt file to encode: ";
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

	char array[10000] = { 0 };
	input.getline(array, 10000);

	std::cout << array;

	std::cin.get();
	std::cin.get();

	std::ofstream output;
	output.open("output_file.txt");

	char* ptr = &array[0];

	int last_value = 0;

	// for each character
	for (; *ptr != 0; ptr++)
	{
		// get ASCII value of current character
		int value = int(*ptr);

		// if current value is more than the previous character
		if (value > last_value)
		{
			// calculate difference between the characters
			int difference = value - last_value;

			// INCREMENT Brainheck register until current value is reached
			for (int j = 0; j < difference; j++)
			{
				output << "p";
			}

			// trigger Brainheck output
			output << "o ";

			//pass current value to the last_value holder before next loop
			last_value = value;
		}

		// if current value is more than the previous character
		else if (value < last_value)
		{
			// calculate difference between the characters
			int difference = last_value - value;

			// DECREMENT Brainheck register until current value is reached
			for (int j = 0; j < difference; j++)
			{
				output << "m ";
			}

			// trigger Brainheck output
			output << "o ";

			//pass current value to the last_value holder before next loop
			last_value = value;
		}

		// if current value is the same as the previous character (i.e. repeated characters)
		else if (value == last_value)
		{
			// just trigger Brainheck output again since register already has the correct ASCII value
			output << "o ";
		}

		// this is for error handling
		else
		{
			// error message, not meant for running in Brainheck
			output << "ERROR!";
		}
	}
}