#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> 
#include <vector> 
#include <iomanip> 
#include "FileHelpers.hpp"
#include "PpmDocument.hpp"

int main(int argc, char* argv[])
{
	string input_file;
	string output_file;
	char continues;
	string switchchar;
	bool quit = false;
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
		cout << "8. Random Noise" << endl;
		cout << "9. High Contrast" << endl;
		cout << "10. Horizontal Flip" << endl;
		cout << "11. Vertical Flip" << endl;
		cout << "12. Blur" << endl;
		cout << "13. Pixelate" << endl;
		cout << "14. Rotate 90" << endl;
		cout << "q. Quit" << endl;
		cout << endl;
		cout << "Selection: ";
		cin >> switchchar;
		cout << endl;

		if (switchchar == "q" || switchchar == "Q")
		{
			cout << "Quitting....." << endl;
		}
		else
		{
			PpmDocument doc{};
			string new_switch;
			bool quit = false;

			switch (stoi(switchchar))
			{
			case 1:
				doc.removeRed(input_file, output_file);
				break;

			case 2:
				doc.removeGreen(input_file, output_file);
				break;

			case 3:
				doc.removeBlue(input_file, output_file);
				break;

			case 4:
				doc.negateRed(input_file, output_file);
				break;

			case 5:
				doc.negateGreen(input_file, output_file);
				break;

			case 6:
				doc.negateBlue(input_file, output_file);
				break;

			case 7:
				doc.grayScale(input_file, output_file);
				break;

			case 8:
				doc.randomNoise(input_file, output_file);
				break;

			case 9:
				doc.highContrast(input_file, output_file);
				break;

			case 10:
				doc.horizontalFlip(input_file, output_file);
				break;

			case 11:
				doc.verticalFlip(input_file, output_file);
				break;

			case 12:
				break;

			case 13:
				break;

			case 14:
				break;

			default:
				cout << "Error! Invalid Selection." << endl;
				cout << endl;
				break;
			}

			do
			{
				PpmDocument newdoc{};
				input_file = output_file;
				cout << "Selection: ";
				cin >> new_switch;
				cout << endl;
				if (new_switch == "q" || new_switch == "Q")
				{
					cout << "Quitting....." << endl;
					quit = true;
				}
				else
				{
					switch (stoi(new_switch))
					{
					case 1:
						newdoc.removeRed(input_file, output_file);
						break;

					case 2:
						newdoc.removeGreen(input_file, output_file);
						break;

					case 3:
						newdoc.removeBlue(input_file, output_file);
						break;

					case 4:
						newdoc.negateRed(input_file, output_file);
						break;

					case 5:
						newdoc.negateGreen(input_file, output_file);
						break;

					case 6:
						newdoc.negateBlue(input_file, output_file);
						break;

					case 7:
						newdoc.grayScale(input_file, output_file);
						break;

					case 8:
						newdoc.randomNoise(input_file, output_file);
						break;

					case 9:
						newdoc.highContrast(input_file, output_file);
						break;

					case 10:
						newdoc.horizontalFlip(input_file, output_file);
						break;

					case 11:
						newdoc.verticalFlip(input_file, output_file);
						break;

					case 12:
						break;

					case 13:
						break;

					case 14:
						break;

					default:
						cout << "Error! Invalid Selection." << endl;
						cout << endl;
						break;
					}
				}
			} while (quit == false);
		}

		cout << "------------------------------------" << endl;
		cout << endl;

		cout << "Would you like to continue? (Y/n)" << endl;
		cin >> continues;
		cout << endl;
		cout << "------------------------------------" << endl;
		cout << endl;

		switch (continues)
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