#include <iostream>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "word2vec.h"

#define WORD_BAG 0
#define WORD_SET 1

using namespace std;

Data word2vec(char* filename, set<char*> vocabulary, Data (*generator)(char*))
{
	FILE* open = fopen(filename, "r");

	if (!file)
	{
		std::cerr << "Cannot open file" << filename << std::endl;
		return Data(); 
	}
	return generate(filename);
}


Data word2vecSet(char* filename, set<char*> vocabulary)
{
	char* buffer = NULL;
	map<string, double> vec;
	Data ret;
	std::size_t length = 0;
	while (getline(&buffer, &length, file) != -1)
	{
		int i = 0;
		while (buffer[i] != '\0')
		{
			if (ispunct(buffer[i]) || !isprint(buffer[i]))
				buffer[i] = ' ';
		}

		char* token = strtok(buffer, " ");
		while (token)
		{
			if (vocabulary.find(token) != vocabulary.end())
			{
				map[token] = 1.0;
			}
			token = strtok(NULL, " ");	
		}
	}
	ret.features = vec;
	return ret;
}

Data word2vecBag(char* filename, set<char*> vocabulary)
{
	char* buffer = NULL;
	map<string, double> vec;
	Data ret;
	std::size_t length = 0;
	while (getline(&buffer, &length, file) != -1)
	{
		int i = 0;
		while (buffer[i] != '\0')
		{
			if (ispunct(buffer[i]) || !isprint(buffer[i]))
				buffer[i] = ' ';
		}

		char* token = strtok(buffer, " ");
		while (token)
		{
			if (vocabulary.find(token) != vocabulary.end())
			{
				map[token] += 1.0;;
			}
			token = strtok(NULL, " ");	
		}
	}
	ret.features = vec;
	return ret;
}









