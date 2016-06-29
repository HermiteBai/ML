#ifndef _KNN_
#define _KNN_
#include <vector>
#include <list>

typedef struct Point
{
	std::vector<double> coordinates;
	std::string label;
	double distance = 0.0;
}Point;

std::string clarify(Point point, std::list<Point> dataSet, unsigned int k);
void updateDistance(Point subject, Point& data);
bool cmp(const Point &point1, const Point &point2);
std::list<Point> file2DataSet(const char* filename);
void normalize(std::list<Point>& dataSet);

#endif