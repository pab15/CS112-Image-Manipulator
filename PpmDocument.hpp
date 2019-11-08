#pragma once
#ifndef PPM_DOCUMENT_HPP
#define PPM_DOCUMENT_HPP
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <algorithm>
#include "FileHelpers.hpp"
#include "Pixel.hpp"
#include <time.h>
using namespace std;

class PpmDocument
{
private:
	//underscore means that the variable belongs
	//to the object
	string _format;
	int _width = 0;
	int _height = 0;
	int _color_depth = 0;
	string _file_name;
	vector<vector<Pixel>> _rgb_data;
	vector<unsigned char> _raw_bytes;

	void checkDocumentValidity(istream& stream)
	{
		if (stream.good() == false && stream.eof() == false)
		{
			throw exception{ "Invalid PPM spec" };
		}
	}

public:

	//constructor method gets called automatically
	//whenever we create a new PpmDocument
	PpmDocument(string file_name)
	{
		open(file_name);
	}

	//do nothing constructor for when we don't
	//have a file name
	PpmDocument()
	{
	}


	void open(string file_name)
	{
		_file_name = file_name;
		vector<string> raw_data = readFile(_file_name);

		//make sure file was read successfully
		if (raw_data.size() == 0)
		{
			//TODO: throw error
		}
		else
		{
			//set object properties
			_format = raw_data[0];

			//grab width and height using istringstream
			istringstream line{ raw_data[1] };
			line >> _width;
			line >> _height;
			checkDocumentValidity(line);

			//color depth
			line = istringstream{ raw_data[2] };
			line >> _color_depth;
			checkDocumentValidity(line);
			
			_rgb_data.resize(_height);
			for (int i = 0; i < _height; i++)
			{
				_rgb_data[i].resize(_width);
			}

			int cur_x = 0;
			int cur_y = 0;
			//process data
			for (int i = 3; i < raw_data.size(); i++)
			{
				istringstream numbers_str{ raw_data[i] };
				while (numbers_str.eof() == false)
				{
					Pixel pix;
					numbers_str >> pix;
					checkDocumentValidity(numbers_str);
					if (pix.getRed() >= 0)
					{
						_rgb_data[cur_y][cur_x] = pix;
						cur_x++;
					}
					if (cur_x >= _width)
					{
						cur_y++;
						cur_x = 0;
					}
				}
			}
		}
	}

	int getColorDepth() const
	{
		return _color_depth;
	}

	string getFileName() const
	{
		return _file_name;
	}

	void setFileName(const string& file_name)
	{
		_file_name = file_name;
	}

	int getHeight() const
	{
		return _height;
	}

	int getWidth() const
	{
		return _width;
	}

	string getImageFormat() const
	{
		return _format;
	}

	void setImageFormat(string format)
	{
		//error checking
		if (format == "P3" || format == "P6")
		{
			_format = format;
		}
		else
		{
			//TODO: throw error 
		}
	}

	void viewFile(string input_file)
	{
		open(input_file);
		cout << _format << endl;
		cout << _width << " " << _height << endl;
		cout << _color_depth << endl;
		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				cout << _rgb_data[i][j] << " ";
			}
			cout << endl;
		}
	}

	void removeRed(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setRed(0);
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Removing All Red....." << endl << endl;
		destination.close();
	}

	void removeGreen(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setGreen(0);
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Removing All Green....." << endl << endl;
		destination.close();
	}

	void removeBlue(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setBlue(0);
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Removing All Blue....." << endl << endl;
		destination.close();
	}

	void negateRed(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setRed(255 - _rgb_data[i][j].getRed());
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Negating All Red....." << endl << endl;
		destination.close();
	}

	void negateGreen(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setGreen(255 - _rgb_data[i][j].getGreen());
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Negating All Green....." << endl << endl;
		destination.close();
	}

	void negateBlue(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				_rgb_data[i][j].setBlue(255 - _rgb_data[i][j].getBlue());
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Negating All Blue....." << endl << endl;
		destination.close();
	}

	void grayScale(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		int avg_triplet = 0;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				avg_triplet = ((_rgb_data[i][j].getRed() + _rgb_data[i][j].getGreen() + _rgb_data[i][j].getBlue()) / 3);
				destination << avg_triplet << " " << avg_triplet << " " << avg_triplet << " ";
			}
			destination << endl;
		}

		cout << "Grayscaling All Pixels....." << endl << endl;
		destination.close();
	}

	void randomNoise(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;
		srand(time(NULL));
		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				int random = (rand() % 20);
				int random_number = random - 10;
				if ((_rgb_data[i][j].getRed() + random_number) >= 255)
				{
					_rgb_data[i][j].setRed(255);
				}
				else if ((_rgb_data[i][j].getRed() - random_number) <= 0)
				{
					_rgb_data[i][j].setRed(0);
				}
				else
				{
					_rgb_data[i][j].setRed((_rgb_data[i][j].getRed() + random_number));
				}
				random = (rand() % 20);
				random_number = random - 10;
				if ((_rgb_data[i][j].getGreen() + random_number) >= 255)
				{
					_rgb_data[i][j].setGreen(255);
				}
				else if ((_rgb_data[i][j].getGreen() - random_number) <= 0)
				{
					_rgb_data[i][j].setGreen(0);
				}
				else
				{
					_rgb_data[i][j].setGreen((_rgb_data[i][j].getGreen() + random_number));
				}
				random = (rand() % 20);
				random_number = random - 10;
				if ((_rgb_data[i][j].getBlue() + random_number) >= 255)
				{
					_rgb_data[i][j].setBlue(255);
				}
				else if ((_rgb_data[i][j].getBlue() - random_number) <= 0)
				{
					_rgb_data[i][j].setBlue(0);
				}
				else
				{
					_rgb_data[i][j].setRed((_rgb_data[i][j].getBlue() + random_number));
				}
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}
		cout << "Applying Random Noise....." << endl << endl;
		destination.close();
	}

	void highContrast(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				if (_rgb_data[i][j].getRed() >= 128)
				{
					_rgb_data[i][j].setRed(255);
				}
				else
				{
					_rgb_data[i][j].setRed(0);
				}
				if (_rgb_data[i][j].getGreen() >= 128)
				{
					_rgb_data[i][j].setGreen(255);
				}
				else
				{
					_rgb_data[i][j].setGreen(0);
				}
				if (_rgb_data[i][j].getBlue() >= 128)
				{
					_rgb_data[i][j].setBlue(255);
				}
				else
				{
					_rgb_data[i][j].setBlue(0);
				}
				destination << _rgb_data[i][j] << " ";
			}

			destination << endl;
		}

		cout << "Applying High Contrast....." << endl << endl;
		destination.close();
	}

	void horizontalFlip(string input_file, string output_file)
	{
		open(input_file);
		ofstream destination;
		destination.open(output_file);

		destination << _format << endl;
		destination << _width << " " << _height << endl;
		destination << _color_depth << endl;

		for (int i = 0; i < _rgb_data.size(); i++)
		{
			reverse(_rgb_data[i].begin(), _rgb_data[i].end());
		}
		for (int i = 0; i < _rgb_data.size(); i++)
		{
			for (int j = 0; j < _rgb_data[i].size(); j++)
			{
				destination << _rgb_data[i][j] << " ";
			}
			destination << endl;
		}

		cout << "Flipping Horizontally....." << endl << endl;
		destination.close();
	}
};


#endif // !PPM_DOCUMENT_HPP
