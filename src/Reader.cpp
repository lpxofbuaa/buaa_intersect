#include "stdafx.h"
#include "Reader.h"

Reader::Reader(string in_file, string out_file) {
	reader = ifstream(in_file);
	writer = ofstream(out_file);
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
			lines.push_back(Line(x1, y1, x2, y2));
		}
	}
}

void Reader::write(int m) {
	writer << to_string(m) << endl;
}