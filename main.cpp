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
	char switchchar;
	bool stop_loop = false;

	while (stop_loop == false)
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
		cout << "v. View PPM file contents" << endl;
		cout << "t. test all" << endl;
		cout << endl;
		cin >> switchchar;
		cout << endl;

		cout << "------------------------------------" << endl;
		cout << endl;

		PpmClass remove_red{};
		PpmClass remove_green{};
		PpmClass remove_blue{};
		PpmClass negate_red{};
		PpmClass negate_blue{};
		PpmClass grayscale{};
		PpmClass view_file{};
		PpmClass test{};
		PpmClass test2{};
		PpmClass test3{};
		PpmClass test4{};
		PpmClass test5{};
		PpmClass test6{};
		PpmClass test7{};

		switch (switchchar)
		{
		case '1':
			remove_red.removeRed(input_file, output_file);
			break;

		case '2':
			remove_green.removeGreen(input_file, output_file);
			break;

		case '3':
			remove_blue.removeBlue(input_file, output_file);
			break;

		case '4':
			negate_red.negateRed(input_file, output_file);
			break;

		case '5':
			negate_red.negateGreen(input_file, output_file);
			break;

		case '6':
			negate_blue.negateBlue(input_file, output_file);
			break;

		case '7':
			grayscale.grayScale(input_file, output_file);
			break;

		case 'v':
		case 'V':
			view_file.viewPpmContents(input_file);
			break;
		
		case 't':
		case 'T':
			test.removeRed("tinypix.ppm", "testRR.ppm");
			cout << endl;
			test2.removeGreen("tinypix.ppm", "testRG.ppm");
			cout << endl;
			test3.removeBlue("tinypix.ppm", "testRB.ppm");
			cout << endl;
			test4.negateRed("tinypix.ppm", "testNR.ppm");
			cout << endl;
			test5.negateGreen("tinypix.ppm", "testNG.ppm");
			cout << endl;
			test6.negateBlue("tinypix.ppm", "testNB.ppm");
			cout << endl;
			test7.grayScale("tinypix.ppm", "testGS.ppm");
			break;

		default:
			cout << "Error! Invalid Selection." << endl;
			cout << endl;
			break;
		}

		cout << "------------------------------------" << endl;
		cout << endl;

		cout << "Would you like to continue? (Y/n)" << endl;
		cin >> continues;
		cout << endl;

		switch(continues)
		{
			case 'n':
			case 'N':
				stop_loop = true;
				cout << "Ending Program....." << endl;
				break;

			case 'y':
			case 'Y':
				stop_loop = false;
				break;

			default:
				stop_loop = true;
				cout << "Error! Invalid Input." << endl;
				cout << "Ending Program....." << endl;
				break;
		}
	}

	cout << "------------------------------------" << endl;
	cout << endl;

	return 0;
}