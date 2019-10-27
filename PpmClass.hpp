#pragma once
#ifndef PPM_CLASS_HPP
#define PPM_CLASS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "FileHelpers.h"
using namespace std;

class PpmClass
{
private:
	string _file_name;
	string _image_format;
	int _width = 0;
	int _height = 0;
	int _max_pixel_value = 0;
	vector<int> _rgb_data{};

public:
	void openPpmDoc(string file_name)
	{
		vector<string> data = readFile(file_name);

		_file_name = file_name;

		_image_format = data[0];

		istringstream width_height{ data[1] };
		width_height >> _width;
		width_height >> _height;

		_max_pixel_value = stoi(data[2]);

		for (int i = 3; i < data.size(); i++)
		{
			istringstream numbers_str{ data[i] };
			while (numbers_str.good() == true)
			{
				string temp;
				getline(numbers_str, temp, ' ');
				if (temp.length() > 0 && temp != " ")
				{
					_rgb_data.push_back(stoi(temp));
				}
			}
		}
	}

	string getImageFormat() const
	{
		return _image_format;
	}

	int getWidth() const
	{
		return _width;
	}

	int getHeight() const
	{
		return _height;
	}

	int getMaxPix() const
	{
		return _max_pixel_value;
	}

	void setImageFormat(string image_format)
	{
		_image_format = image_format;
	}

	void setFileName(const string& file_name)
	{
		_file_name = file_name;
	}

	void viewPpmContents(string input_file)
	{
		openPpmDoc(input_file);
		cout << "------------------------------------" << endl;
		cout << input_file + " contents:" << endl;
		cout << "------------------------------------" << endl;
		cout << endl;
		cout << _image_format << endl;
		cout << _width << " " << _height << endl;
		cout << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (i % (3 * _width) == 0)
			{
				cout << endl;
			}
			cout << _rgb_data[i] << " ";
			
		}

		cout << endl;
		cout << "------------------------------------" << endl;
		cout << endl;
	}

	void removeRed(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			
			if (i == 0 || i % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 0 << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Removing All Red....." << endl << endl;
		destination.close();
	}

	void removeGreen(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (i == 1 || (i - 1) % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 0 << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Removing All Green....." << endl << endl;
		destination.close();
	}

	void removeBlue(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (i == 2 || (i - 2) % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 0 << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Removing All Blue....." << endl << endl;
		destination.close();
	}

	void negateRed(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{

			if (i == 0 || i % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 255 - _rgb_data[i] << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Negating All Red....." << endl << endl;
		destination.close();
	}

	void negateGreen(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (i == 1 || (i - 1) % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 255 - _rgb_data[i] << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Negating All Green....." << endl << endl;
		destination.close();
	}

	void negateBlue(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (i == 2 || (i - 2) % 3 == 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 255 - _rgb_data[i] << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] << " ";
			}
		}

		cout << "Negating All Blue....." << endl << endl;
		destination.close();
	}

	void grayScale(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		int avg_triplet = 0;
		int count = 0;

		for (int i = 2; i < _rgb_data.size(); i += 3)
		{
			avg_triplet = ((_rgb_data[i] + _rgb_data[(i - 1)] + _rgb_data[(i - 2)]) / 3);
			destination << avg_triplet << " " << avg_triplet << " " << avg_triplet << " ";
			count++;
			if (count % 4 == 0)
			{
				destination << endl;
			}
		}

		cout << "Grayscaling All Pixels....." << endl << endl;
		destination.close();
	}

	void randomNoise(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;
		srand(time(NULL));
		for (int i = 0; i < _rgb_data.size(); i++)
		{
			
			int random = (rand() % 20);
			int random_number = random - 10;
			if ((int)_rgb_data[i] + random_number > 255)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 255 << " ";
			}
			else if ((int)_rgb_data[i] - random_number < 0)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 0 << " ";
			}
			else
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << _rgb_data[i] + random_number << " ";
			}

		}
		cout << "Applying Random Noise....." << endl << endl;
		destination.close();
	}

	void highContrast(string input_file, string output_file)
	{
		openPpmDoc(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _image_format << endl;
		destination << _width << " " << _height << endl;
		destination << _max_pixel_value << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			if (_rgb_data[i] >= 128)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 255 << " ";
			}
			if (_rgb_data[i] <= 127)
			{
				if (i % (3 * _width) == 0)
				{
					destination << endl;
				}
				destination << 0 << " ";
			}
		}

		cout << "Applying High Contrast....." << endl << endl;
		destination.close();
	}
};

#endif // !PPM_CLASS_HPP
