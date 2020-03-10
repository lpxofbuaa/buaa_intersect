#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GeometryShape.h"

using namespace std;

class Reader {
private:
	ifstream reader;
	ofstream writer;
public:
	Reader(string in_file, string out_file);
	vector<Line> lines;
	void read();
	void write(int n);
};