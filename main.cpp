#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "PpmClass.hpp"
#include "FileHelpers.h"
using namespace std;


int main(int argc, char* argv[])
{
	string input_file;
	string output_file;
	char continues;
	char switch_char;
	bool cont_loop = false;

	while (cont_loop == true)
	{
		cout << "Enter a File Name to Input: ";
		cin >> input_file;
		cout << endl;

		cout << "Enter A File Name to Output: ";
		cin >> output_file;
		cout << endl;

		cout << "------------------------------------" << endl;
		cout << endl;

		cout << "*******Select an Image Effect*******" << endl;
		cout << "1. Remove Red" << endl;
		cout << "2. Remove Green" << endl;
		cout << "3. Remove Blue" << endl;
		cout << "4. Negate Red" << endl;
		cout << "5. Negate Green" << endl;
		cout << "6. Negate Blue" << endl;
		cout << "7. Grayscale" << endl;
		cout << "8. Random Noise" << endl;
		cout << "9. High Contrast" << endl;
		cout << "v. View PPM file contents" << endl;
		cout << "t. test all" << endl;
		cout << "q. Quit Program" << endl;
		cout << endl;
		cout << endl;

		cout << "------------------------------------" << endl;
		cout << endl;

		PpmClass doc{};
		do
		{
			int count = 1;
			if (count == 1)
			{
				cout << "Selection: ";
				cin >> switch_char;
				cout << endl;
				menuSwitch(switch_char, input_file, output_file, doc);
			}
			else 
			{
				cout << "Selection: ";
				cin >> switch_char;
				cout << endl;
				menuSwitch(switch_char, output_file, output_file, doc);
			}
			
		}while(switch_char != 'q' || switch_char != 'Q');
		

		cout << "------------------------------------" << endl;
		cout << endl;

		cout << "Would you like to continue with a New File? (Y/n)" << endl;
		cin >> continues;
		cout << endl;
		cout << "------------------------------------" << endl;
		cout << endl;

		cont_loop = countinueFuction(continues);
	}

	cout << "------------------------------------" << endl;
	cout << endl;

	return 0;
}