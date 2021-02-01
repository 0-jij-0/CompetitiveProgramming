#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	int h, w; cin >> h >> w; v.resize(h);
	for (auto &x : v) { cin >> x; }
	int res = 0;
	for(int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (v[i][j] == '.') {
				res += (i != h - 1 && v[i + 1][j] == '.');
				res += (j != w - 1 && v[i][j + 1] == '.');
			}
	cout << res << '\n';
	cin.ignore(2); return 0;
}