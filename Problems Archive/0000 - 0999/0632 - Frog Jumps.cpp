#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

vector<int> v;
string s;

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> s; v.clear();
		int n = (int)s.size();
		for (int i = 0; i < n; i++)
			if (s[i] == 'R') v.push_back(i);
		if (v.empty()) { cout << n + 1 << endl; continue; }
		int a = max(v.front() + 1, n - v.back());
		adjacent_difference(v.begin(), v.end(), v.begin());
		cout << max(a, *max_element(v.begin(), v.end())) << endl;
	}
	cin.ignore(2); return 0;
}