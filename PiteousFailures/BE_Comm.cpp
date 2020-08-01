#include <fstream>
#include <iostream>
#include <stdio.h>



int main(int argc, char** argv)
{
	std::ofstream output;
	output.open("output_file.txt");

	char* ptr;

	output << "working twice again bypass \n";


	if (argc == 1) {} // don't do anything

	else if (argc > 1)
	{
		for (int i = 2; i <= argc; i++)
		{
			ptr = &argv[i - 1][0];

			for (; *ptr != 0; ptr++)
			{
				// currently using exactly ASCII but beware to avoid the decoding program pointing to NULL
				int value = int(*ptr);

				for (int j = 0; j < value; j++)
				{
					output << "p ";

				}

				output << "o f ";
			}


		}
	}

	output << "\n finished";

}