/*
 *  kNN Algorithm in C++
 *  Author: Lanxiao Hermite Bai
 */

#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include "kNN.h"

using std::vector;
using std::map;
using std::string;
using std::list;
using std::size_t;

string clarify(Point point, list<Point> dataSet, unsigned int k)
{
	//1. Calculate the distances between each point in DataSet to the Point that we want to classify
	for (Point& data : dataSet)
	{
		updateDistance(point, data);
	}
	//2. Sort the points based on the distances
	dataSet.sort(cmp);
	//3. Take the smallest k points to calculate the frequency of label
	vector<Point> points_k;
	map<string, unsigned int> stat;

	for (auto iter : dataSet)
	{
		points_k.push_back(iter);
	}
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		stat[points_k[i].label]++;
	}
	//4. Return the prediction
	int max = 0;
	for (auto iter = stat.begin(); iter != stat.end(); iter++)
	{
		if (iter->second > max)
		{
			max = iter->second;
			point.label = iter->first;
		}
	}
	return point.label;
}

void updateDistance(Point subject, Point& data)
{
	double raw_distance = 0.0;
	for (int i = 0; i < subject.coordinates.size(); i++)
	{
		raw_distance += (subject.coordinates[i] - data.coordinates[i]) * (subject.coordinates[i] - data.coordinates[i]);
	}
	data.distance = sqrt(raw_distance);
}

bool cmp(const Point &point1, const Point &point2)
{
	if (point1.distance < point2.distance)
		return true;
	else
		return false;
}

list<Point> file2DataSet(const char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		std::cerr << "Could not open file: " << filename << std::endl;
		return list<Point>();
	}
	list<Point> ret;
	char* buffer = NULL;
	size_t length = 0;
	while (getline(&buffer, &length, file) != -1)
	{
		Point temp;
		buffer[strlen(buffer) - 2] = '\0';
		char* token = strtok(buffer, "\t");
		temp.coordinates.push_back(atof(token));
		token = strtok(NULL, "\t");
		temp.coordinates.push_back(atof(token));
		token = strtok(NULL, "\t");
		temp.coordinates.push_back(atof(token));
		token = strtok(NULL, "\t");
		temp.label = token;
		ret.push_back(temp);
	}
	fclose(file);
	return ret;
}

void normalize(list<Point>& dataSet)
{
	unsigned int size = dataSet.front().coordinates.size();
	double* max = new double[size];
	double* min = new double[size];
	for (int i = 0; i < size; i++)
	{
		max[i] = dataSet.front().coordinates[i];
		min[i] = dataSet.front().coordinates[i];
	}
	for (auto iter : dataSet)
	{
		for (int i = 0; i < size; i++)
		{
			if (iter.coordinates[i] > max[i])
				max[i] = iter.coordinates[i];
			if (iter.coordinates[i] < min[i])
				min[i] = iter.coordinates[i];
		}
	}
	for (auto& iter : dataSet)
	{
		for (int i = 0; i < size; i++)
		{
			iter.coordinates[i] = (iter.coordinates[i] - min[i]) / (max[i] - min[i]);
		}
	}
	delete[] max;
	delete[] min;
}













