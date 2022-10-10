#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n, t; cin >> n >> t; v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first; v[i].second = i;
	}
	sort(v.begin(), v.end()); 
	int i = 0, j = n - 1; while (i < j) {
		if (v[i].first + v[j].first < t) { i++; continue; }
		if (v[i].first + v[j].first > t) { j--; continue; }
		cout << v[i].second + 1 << ' ' << v[j].second + 1 << '\n'; 
		cin.ignore(2); return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	cin.ignore(2); return 0;
}