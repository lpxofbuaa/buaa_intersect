#include "stdafx.h"
#include "Reader.h"

Reader::Reader(string in_file, string out_file, GeometryStatistic *gg) {
	reader = ifstream(in_file);
	writer = ofstream(out_file);
	g = gg;
}

void Reader::read() {
	int n;
	reader >> n;
	for (int i = 0; i < n; ++i) {
		char type;
		reader >> type;
		if (type == 'L') {
			int x1, y1, x2, y2;
			reader >> x1 >> y1 >> x2 >> y2;
			Line l(x1, y1, x2, y2);
			g->feed(l);
			//lines.push_back(Line(x1, y1, x2, y2));
		}
		else if (type == 'C') {
			int a, b, r;
			reader >> a >> b >> r;
			Circle c(a, b, r);
			g->feed(c);
			//circles.push_back(Circle(a, b, r));
		}
	}
}

void Reader::write(int m) {
	writer << to_string(m) << endl;
}