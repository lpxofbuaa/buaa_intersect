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
		GeometryStatistic *statistic = new GeometryStatistic();
		Reader read(in_file, out_file, statistic);
		
		read.read();
		read.write(statistic->getPointCount());
		//cout << statistic->getPointCount() << endl;
		//cout << statistic->rational_points->size() << endl;
		//cout << statistic->unrational_points->size() << endl;
	}
	//cout << argc << endl;
}




