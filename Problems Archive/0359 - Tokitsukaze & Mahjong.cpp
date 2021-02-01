#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[3]; int a; char c;

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> a >> c;
		if (c == 'm') { v[0].push_back(a); }
		else if (c == 'p') { v[1].push_back(a); }
		else { v[2].push_back(a); }
	}
	for (int i = 0; i < 3; i++)
		sort(v[i].begin(), v[i].end());

	int res = 2;
	for (int i = 0; i < 3; i++) {
		if (v[i].size() < 2) { continue; }
		if (v[i].size() == 2 && v[i][1] - v[i][0] <= 2) { res = min(res, 1); }
		else if (v[i].size() == 3 && v[i][2] == v[i][0]) { res = min(res, 0); }
		else if (v[i].size() == 3 && v[i][2] - v[i][1] == 1 && v[i][1] - v[i][0] == 1) { res = min(res, 0); }
		else if (v[i].size() == 3 && (v[i][2] - v[i][1] <= 2 || v[i][1] - v[i][0] <= 2)) { res = min(res, 1); }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}