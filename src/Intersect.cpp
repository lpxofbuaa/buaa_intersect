#include "stdafx.h"
#include <iostream>
#include "GeometryStatistic.h"
#include "Point.h"
#include "Reader.h"


using namespace std;

int main(int argc, char* argv[])
{

	if (argc == 5) {
		string in_file;
		string out_file;
		if (argv[1][0] == '-' && argv[1][1] == 'i') {
			in_file = argv[2];
		}
		if (argv[3][0] == '-' && argv[3][1] == 'o') {
			out_file = argv[4];
		}
		Reader read(in_file, out_file);
		GeometryStatistic *statistic = new GeometryStatistic();
		read.read();
		for (vector<Line>::iterator i = read.lines.begin(); i != read.lines.end(); ++i) {
			statistic->feed(*i);
		}
		for (vector<Circle>::iterator i = read.circles.begin(); i != read.circles.end(); ++i) {
			statistic->feed(*i);
		}
		read.write(statistic->getPointCount());
		//cout << statistic->getPointCount() << endl;
		//cout << statistic->rational_points->size() << endl;
		//cout << statistic->unrational_points->size() << endl;
	}
	//cout << argc << endl;
}




