#include "FileHelpers.h"
#include "PpmClass.hpp"

// Used From Lecture 8:

vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};

	//make sure file is open
	if (some_file.is_open() == true)
	{
		string line;

		//loop while file is good (not EOF, not error, etc.)
		while (some_file.good() == true)
		{
			getline(some_file, line);

			//add to end of vector
			result.push_back(line);
		}
	}
	return result;
}

vector<string> readFile(const string& file_name)
{
	ifstream input{ file_name };
	vector<string> result = readFile(input);
	input.close();
	return result;
}

void menuSwitch(char c, string input_file, string output_file, PpmClass doc)
{
	PpmClass test{};
	PpmClass test2{};
	PpmClass test3{};
	PpmClass test4{};
	PpmClass test5{};
	PpmClass test6{};
	PpmClass test7{};
	PpmClass test8{};
	PpmClass test9{};
	switch (c)
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
			test8.randomNoise(input_file, "testRN.ppm");
			cout << endl;
			test9.highContrast(input_file, "testHC.ppm");
			cout << endl;
			break;

		default:
			cout << "Error! Invalid Selection." << endl;
			cout << endl;
			break;
	}
}

bool countinueFunction(char c)
{
	switch(c)
	{
		case 'n':
		case 'N':
			cout << "Ending Program....." << endl;
			return false;
			break;

		case 'y':
		case 'Y':
			cout << "------------------------------------" << endl;
			cout << endl;
			return true;
			break;

		default:
			cout << "Error! Invalid Input." << endl;
			cout << "Ending Program....." << endl;
			return false;
			break;
	}
}