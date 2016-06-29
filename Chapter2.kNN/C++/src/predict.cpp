#include <iostream>
#include <cstdlib>
#include <list>
#include "kNN.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 1)
	{
		cout << "Usage: ./recommand" << endl;
		return -1;
	}
	char* dict[3] = {"didntLike","smallDoses","largeDoses"};

	list<Point> datas = file2DataSet("../test/datingTestSet.txt");
	normalize(datas);

	Point point;

	double flight, game, ice;
	system("clear");
	cout << "Flight = ";
	cin >> flight;
	system("clear");
	cout << "Game = ";
	cin >> game;
	system("clear");
	cout << "Ice = ";
	cin >> ice;
	system("clear");

	point.coordinates.push_back(flight);
	point.coordinates.push_back(game);
	point.coordinates.push_back(ice);

	list<Point> test = file2DataSet("../test/datingTestSet.txt");
	test.push_back(point);
	normalize(test);

	string label = clarify(test.back(), datas, 3);

	//cout << "x1 = " << test.front().coordinates[0] << endl;
	//cout << "x2 = " << test.front().coordinates[1] << endl;
	//cout << "x3 = " << test.front().coordinates[2] << endl;
	cout << "You should date with people of " << label << endl;

	return 0;
}