#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n, a = 0, b = 0; string s; ifs >> n >> s;
		for (char &c : s) { (c == 'A' ? a : b)++; }
		ofs << "Case #" << t << ": ";
		ofs << (abs(a - b) == 1 ? 'Y' : 'N') << '\n';
	}
	cin.ignore(2); return 0;
}