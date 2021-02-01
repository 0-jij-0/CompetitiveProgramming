#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
bool operator <  (const pair<long long, int> &p1, const pair<long long, int> &p2) {
	return p1.first < p2.first;
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) { int a; cin >> a; v.push_back(a); }
	vector<pair<long long, int>> sums; long long sum = 0; long long res = 0;
	for (int i = 0; i < n; i++) {
		sum += (long long) v[i];
		if (i == n - 1) { res = sum; }
		pair<long long, int> p(sum, i);
		sums.push_back(p);
	}
	sort(sums.begin(), sums.end()); res *= k;
	vector<pair<long long, int>>::iterator it = sums.begin();
	for (int i = 0; i < k - 1; i++) {
		if (it->second == n - 1) { it++; }
		res -= (long long) it->first; it++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}