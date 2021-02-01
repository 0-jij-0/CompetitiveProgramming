#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<pair<int, int>> v;

int main() {
	string fname = "powers.in"; ifstream ifs(fname.c_str());
	int t; ifs >> t;
	for (int i = 0; i < t; i++) {
		int g; ifs >> g;
		v.clear(); v.resize(g);
		for (auto &x : v) { ifs >> x.first >> x.second; }
		int res = 0;
		for (auto &x : v) {
			if (x.first % 2) { res ^= x.second % 2; }
			else if ((x.second % (x.first + 1)) % 2) { res ^= 1; }
			else if ((x.second % (x.first + 1)) == x.first) { res ^= 2; }
		}
		int win = 2 - (res != 0); cout << win << endl;
	}
	ifs.close(); cin.ignore(2); return 0;
}