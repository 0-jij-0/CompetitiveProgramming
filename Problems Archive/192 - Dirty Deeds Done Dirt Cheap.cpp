#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v1, v2;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		pair<int, int> p(a, i);
		if (a < b) { v1.push_back(p); }
		else { v2.push_back(p); }
	}
	sort(v1.rbegin(), v1.rend());
	sort(v2.begin(), v2.end());
	vector<pair<int, int>> &v = (v1.size() < v2.size()) ? v2 : v1;
	cout << v.size() << endl;
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v[i].second + 1;
		if (i + 1 != v.size()) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}