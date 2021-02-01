#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> res; int n;

bool checkCar(int i) {
	for (int j = 0; j < n; j++)
		if (v[i][j] == 1 || v[i][j] == 3) { return false; }
	return true;
}

int main() {
	cin >> n; v.resize(n, vector<int>(n));
	for (auto &x : v) for (auto &y : x) { cin >> y; }
	for(int i = 0; i < n; i++)
		if (checkCar(i)) { res.push_back(i); }

	cout << res.size() << endl;
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << endl; cin.ignore(2); return 0;
}