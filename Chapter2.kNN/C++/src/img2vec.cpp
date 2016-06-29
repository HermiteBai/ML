#include <iostream>
#include <cstring>
#include <cctype>
#include <regex>
#include "kNN.h"
#include "img2vec.h"

using namespace std;

Point img2vec(char* filename)
{
	Point ret;
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		cerr << "Fail to open file" << endl;
		return Point();
	}
	char *pLastSlash = strrchr(filename, '/');
	char *pszBaseName = pLastSlash ? pLastSlash + 1 : filename;
	char* token = strtok(pszBaseName, "_");
	ret.label = (string)token;

	int letter;
	while ((letter = fgetc(file)) != EOF)
	{
		if (isdigit(letter))
			ret.coordinates.push_back((double)letter);
	}
	fclose(file);
	return ret;
}