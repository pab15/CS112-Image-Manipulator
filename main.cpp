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
	PpmClass doc{};
	doc.removeRed("tinypix.ppm");

	return 0;
}