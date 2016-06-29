#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

#include "kNN.h"

using namespace std;

int main(int argc, char const *argv[])
{
	char* dict[3] = {"didntLike","smallDoses","largeDoses"};
	if (argc != 4)
	{
		cout << "Usage: ./kNN3 <dataSet> <testFile> <k>" << endl;
		return -1;
	}
	double count = 0;
	double error = 0;
	list<Point> datas = file2DataSet(argv[1]);
	normalize(datas);

	list<Point> tests = file2DataSet(argv[2]);
	normalize(tests);
	for (auto iter : tests)
	{
		cout << "x1 = " << iter.coordinates[0] << endl;
		cout << "x2 = " << iter.coordinates[1] << endl;
		cout << "x3 = " << iter.coordinates[2] << endl;
		string label = clarify(iter, datas, atoi(argv[3]));
		cout << "Should be : " << dict[atoi(iter.label.c_str()) - 1] << endl;
		cout << "Got label : " << label << endl;
		
		if (dict[atoi(iter.label.c_str()) - 1] != label)
		{
			error += 1.0;
			cout << "Wrong!" << endl;
		}
		cout << "-----------------------------------------------------------" << endl;
		count++;
	}
	cout << "Summary: " << endl;
	cout << "Global Error Rate = " << (error/count)*100 << "\%" << endl;
	return 0;
}