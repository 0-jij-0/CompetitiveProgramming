#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
bool operator < (const pair<int, int> p1, const pair<int, int> p2) {
	return p1.first < p2.first;
}

int exp_coeff() {
	sort(v.begin(), v.end());
	int min = 1000000000;
	int left = 0, right = v.size() - 1;
	for (unsigned int i = 0; i < v.size() - 1; i++) {
		int dist = (v[i].second - left > right - v[i].second) ? v[i].second - left : right - v[i].second;
		int k = v[i].first / dist;
		if (k < min) { min = k; }
		if (v[i].second == left) { left++; }
		else if (v[i].second == right) { right--; }
	}
	return min;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; pair<int, int> p(a, i); v.push_back(p);
	}
	cout << exp_coeff() << endl;
	return 0;
}