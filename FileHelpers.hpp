#pragma once
#ifndef FILE_HELPERS_HPP
#define FILE_HELPERS_HPP

#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(const string& file_name);


#endif