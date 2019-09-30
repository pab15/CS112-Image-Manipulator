#pragma once
#ifndef PPM_CLASS_HPP
#define PPM_CLASS_HPP

#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include "FileHelpers.h"
using namespace std;

class PpmClass
{
private:
	string file_name;
	string _image_format;
	int _width = 0;
	int _height = 0;
	int _max_pixel_value = 0;
	vector<int> _rgb_data{};

public:
	void removeRed(string file_name)
	{
		vector<string> data = readFile("samples/" + file_name);

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
};

#endif // !PPM_CLASS_HPP
