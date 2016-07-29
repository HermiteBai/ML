#include <iostream>
#include <cstring>
#include <list>
#include <dirent.h>
#include <regex>
#include "kNN.h"
#include "img2vec.h"

using namespace std;

list<Point> learn()
{
	cout << "*********************************************" << endl;
	cout << "Start training with provided data set" << endl;
	DIR* dir = opendir("../test/digits/trainingDigits/");
	struct dirent* ptr;
	list<Point> trainingDatas;
	while ((ptr = readdir(dir)) != NULL)
	{
		//printf("%s\n", ptr->d_name);
		char path[128] = "../test/digits/trainingDigits/";
		regex txt_regex("[0-9]+_[0-9]+\\.txt");
		if (regex_match(ptr->d_name, txt_regex))
		{
			strcat(path, ptr->d_name);
			cout << "Processing: " << path << endl;
			trainingDatas.push_back(img2vec(path));
		}
		else
		{
			cout << "Not .txt file" << endl;
		}
	}
	closedir(dir);
	cout << "Training complete" << endl;
	cout << "*********************************************" << endl;
	return trainingDatas;
}

int main(int argc, char const *argv[])
{
	double count = 0.0, error = 0.0;
	DIR* dir = opendir("../test/digits/testDigits");
	struct dirent* ptr;
	list<Point> trainingDatas = learn();

	while ((ptr = readdir(dir)) != NULL)
	{
		char path[128] = "../test/digits/testDigits/";
		strcat(path, ptr->d_name);
		cout << "Processing: " << path << endl;
		Point temp = img2vec(path);
		string label = clarify(temp, trainingDatas, 3);
		cout << "Got: " << label << endl;
		cout << endl;

		if (label != temp.label)
		{
			error += 1.0;
		}
		count += 1.0;
	}
	closedir(dir);
	cout << "*********************************************" << endl;
	cout << "Summary: " << endl;
	cout << "Global Error Rate = " << 100 * error/count << "\%" << endl;
	return 0;
}