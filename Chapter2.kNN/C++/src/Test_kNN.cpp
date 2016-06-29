#include <iostream>
#include <vector>
#include <list>
#include "kNN.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		cout << "Usage: ./kNN <x> <y> <k>" << endl;
		return -1;
	}
	Point point;
	point.coordinates.push_back(atoi(argv[1]));
	point.coordinates.push_back(atoi(argv[2]));

	list<Point> dataSet;
	Point data1, data2, data3, data4;

	data1.coordinates.push_back(1);
	data1.coordinates.push_back(1.1);
	data1.label = "A";

	data2.coordinates.push_back(1);
	data2.coordinates.push_back(1);
	data2.label = "A";

	data3.coordinates.push_back(0);
	data3.coordinates.push_back(0);
	data3.label = "B";

	data4.coordinates.push_back(0);
	data4.coordinates.push_back(0.1);
	data4.label = "B";

	dataSet.push_back(data1);
	dataSet.push_back(data2);
	dataSet.push_back(data3);
	dataSet.push_back(data4);

	cout << "Label should be: " << clarify(point, dataSet, atoi(argv[3])) << endl;

	return 0;
}