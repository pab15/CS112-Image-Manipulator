#pragma once
#ifndef FILE_HELPERS_H
#define FILE_HELPERS_H

#include <vector>
#include <string>
#include <fstream>
#include "PpmClass.hpp"
using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(const string& file_name);
bool countinueFuction(char c);
void menuSwitch(char c, string input_file, string output_file, PpmClass doc);

#endif