#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GeometryShape.h"
#include "GeometryStatistic.h"

using namespace std;

class Reader {
private:
	ifstream reader;
	ofstream writer;
	GeometryStatistic *g;
public:
	Reader(string in_file, string out_file, GeometryStatistic *g);
	vector<Line> lines;
	vector<Circle> circles;
	void read();
	void write(int n);
};