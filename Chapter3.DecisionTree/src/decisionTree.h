#ifndef _DECTREE_
#define _DECTREE_

#include <list>
#include <map>
#include <fstream>

typedef struct Data
{
	std::map<std::string, std::string> features;
	std::string label;
} Data;

typedef struct TreeNode
{
	std::string axis;
	std::string label;
	std::map<std::string, TreeNode> children;
} TreeNode;

double entropy(std::list<Data> dataSet);
double log2(double n);
std::list<Data> split(std::list<Data> dataSet, std::string axis, std::string value);
TreeNode createTree(std::list<Data> dataSet);
void printTree(TreeNode root, int deepth, std::string value);
void storeTree(TreeNode root, int deepth, std::string value, std::ofstream& fout);
//TreeNode getTree(std::filename);

#endif