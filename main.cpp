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
	bool quit = false;

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
		cout << "8. Random Noise" << endl;
		cout << "9. High Contrast" << endl;
		cout << "v. View PPM file contents" << endl;
		cout << "t. Test All" << endl;
		cout << "q. Quit" << endl;
		cout << endl;
		cout << "Selection: ";
		cin >> switchchar;
		cout << endl;

		PpmClass doc{};
		PpmClass test{};
		PpmClass test2{};
		PpmClass test3{};
		PpmClass test4{};
		PpmClass test5{};
		PpmClass test6{};
		PpmClass test7{};
		PpmClass test8{};
		PpmClass test9{};

		switch (switchchar)
		{
		case '1':
			doc.removeRed(input_file, output_file);
			break;

		case '2':
			doc.removeGreen(input_file, output_file);
			break;

		case '3':
			doc.removeBlue(input_file, output_file);
			break;

		case '4':
			doc.negateRed(input_file, output_file);
			break;

		case '5':
			doc.negateGreen(input_file, output_file);
			break;

		case '6':
			doc.negateBlue(input_file, output_file);
			break;

		case '7':
			doc.grayScale(input_file, output_file);
			break;

		case '8':
			doc.randomNoise(input_file, output_file);
			break;

		case '9':
			doc.highContrast(input_file, output_file);
			break;

		case 'v':
		case 'V':
			doc.viewPpmContents(input_file);
			break;

		case 't':
		case 'T':
			test.removeRed(input_file, "testRR.ppm");
			cout << endl;
			test2.removeGreen(input_file, "testRG.ppm");
			cout << endl;
			test3.removeBlue(input_file, "testRB.ppm");
			cout << endl;
			test4.negateRed(input_file, "testNR.ppm");
			cout << endl;
			test5.negateGreen(input_file, "testNG.ppm");
			cout << endl;
			test6.negateBlue(input_file, "testNB.ppm");
			cout << endl;
			test7.grayScale(input_file, "testGS.ppm");
			cout << endl;
			test8.randomNoise(input_file, "testGS.ppm");
			cout << endl;
			test9.highContrast(input_file, "testGS.ppm");
			cout << endl;
			break;

		case 'q':
		case 'Q':
			cout << "Ending Effect Chain....." << endl;
			cout << endl;
			break;
		default:
			cout << "Error! Invalid Selection." << endl;
			cout << endl;
			break;
		}

		do
		{
			PpmClass newdoc{};
			input_file = output_file;
			cout << "Selection: ";
			cin >> switchchar;
			cout << endl;
			switch (switchchar)
			{
			case '1':
				newdoc.removeRed(input_file, output_file);
				break;

			case '2':
				newdoc.removeGreen(input_file, output_file);
				break;

			case '3':
				newdoc.removeBlue(input_file, output_file);
				break;

			case '4':
				newdoc.negateRed(input_file, output_file);
				break;

			case '5':
				newdoc.negateGreen(input_file, output_file);
				break;

			case '6':
				newdoc.negateBlue(input_file, output_file);
				break;

			case '7':
				newdoc.grayScale(input_file, output_file);
				break;

			case '8':
				newdoc.randomNoise(input_file, output_file);
				break;

			case '9':
				newdoc.highContrast(input_file, output_file);
				break;

			case 'v':
			case 'V':
				newdoc.viewPpmContents(input_file);
				break;

			case 't':
			case 'T':
				test.removeRed(input_file, "testRR.ppm");
				cout << endl;
				test2.removeGreen(input_file, "testRG.ppm");
				cout << endl;
				test3.removeBlue(input_file, "testRB.ppm");
				cout << endl;
				test4.negateRed(input_file, "testNR.ppm");
				cout << endl;
				test5.negateGreen(input_file, "testNG.ppm");
				cout << endl;
				test6.negateBlue(input_file, "testNB.ppm");
				cout << endl;
				test7.grayScale(input_file, "testGS.ppm");
				cout << endl;
				test8.randomNoise(input_file, "testGS.ppm");
				cout << endl;
				test9.highContrast(input_file, "testGS.ppm");
				cout << endl;
				break;

			case 'q':
			case 'Q':
				cout << "Ending Effect Chain....." << endl;
				cout << endl;
				quit = true;
				break;

			default:
				cout << "Error! Invalid Selection." << endl;
				cout << endl;
				break;
			}
		} while (quit != true);
		

		cout << "------------------------------------" << endl;
		cout << endl;

		cout << "Would you like to continue? (Y/n)" << endl;
		cin >> continues;
		cout << endl;
		cout << "------------------------------------" << endl;
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
				cout << "------------------------------------" << endl;
				cout << endl;

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