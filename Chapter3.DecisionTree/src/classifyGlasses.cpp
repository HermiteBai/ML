#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <map>
#include "decisionTree.h"

using namespace std;

list<Data> file2DataSet(char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		cerr << "Fail to open file" << endl;
		return list<Data>();
	}

	list<Data> ret;
	char* buffer = NULL;
	size_t length = 0;

	while (getline(&buffer, &length, file) != -1)
	{
		Data data;
		buffer[strlen(buffer) - 2] = '\0';
		char* token = strtok(buffer, "\t");
		data.features["Age"] = token;
		token = strtok(NULL, "\t");
		data.features["Prescript"] = token;
		token = strtok(NULL, "\t");
		data.features["Astigmatic"] = token;
		token = strtok(NULL, "\t");
		data.features["Tearate"] = token;
		token = strtok(NULL, "\t");
		data.label = token;
		ret.push_back(data);
	}
	free(buffer);
	buffer = NULL;
	fclose(file);
	return ret;
}

void printDataSet(list<Data> dataSet)
{
	for (auto iter : dataSet)
	{
		for (auto feature : iter.features)
		{
			cout << "Key : " << feature.first << ", Value : " << feature.second << endl;
		}
		cout << "Label : "  << iter.label << endl;
		cout << "------------------------------------" << endl;
	}
}

string classify(Data data, TreeNode root)
{
	if (root.label.empty() != true)
		return root.label;
	else
		return classify(data, root.children[data.features[root.axis]]);
}


int main(int argc, char const *argv[])
{
	list<Data> dataSet = file2DataSet("../test/lenses.txt");
	//printDataSet(dataSet);
	cout << "Generating Decision Tree..." << endl;
	TreeNode root = createTree(dataSet);
	printTree(root, 0, "");
	std::ofstream fout;
	fout.open("../data/trainedData.json");
	serialize(root, 0, fout);
	fout.close();
	cout << "Start testing decision tree generated..." << endl;
	cout << "--------------------------------------------" << endl;
	double total = 0.0;
	double error = 0.0;
	for (auto data : dataSet)
	{
		cout << "Processing data : " << endl;
		cout << "\t Age : " << data.features["Age"] << endl;
		cout << "\t Prescript : " << data.features["Prescript"] << endl;
		cout << "\t Astigmatic : " << data.features["Astigmatic"] << endl;
		cout << "\t Tearate : " << data.features["Tearate"] << endl;
		cout << "Should be : " << data.label << endl; 
		string result = classify(data, root);

		cout << "Result : " << result << endl;
		cout << "--------------------------------------------" << endl;
		if (result != data.label)
			error += 1.0;
		total += 1.0;
	}
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Summary : \n" << endl;
	cout << "Global Error Rate = " << 100*error/total << "\%" << endl;
	return 0;
}

