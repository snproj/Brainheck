#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>



int main()
{

	//fstream starting

	std::ifstream input;
	std::string fileLocation;

	std::cout << "hello there now \n";

	//gets file location from the user
	std::cout << "Please enter the location of the file: ";
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

	char p = 112;
	char s = 32;

	const char* p_ptr = &p;
	const char* s_ptr = &s;


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
				output.write(p_ptr, 1);
				output << " personality";
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



	




	/*

	if (argc == 1) {} // Don't do anything if no arguments are passed

	else if (argc > 1)
	{
		/*
		Keeps track of previous character value. It is declared all the way back here because we want it
		to be initially set to zero before ALL arguments start being inputted. It is NOT reset between arguments.
		*
		int last_value = 0;

		// for each input argument
		for (int i = 2; i <= argc; i++)
		{
			// point at the first character in the argument
			ptr = &argv[i - 1][0];

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
						output << "p ";
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
	}

	*/

}