#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> sums;

int find_dorm(long long n) {
	return lower_bound(sums.begin(), sums.end(), n) - sums.begin();
}

int main() {
	int n, m; cin >> n >> m;
	long long a; cin >> a; sums.push_back(a);
	for (int i = 1; i < n; i++) {
		cin >> a; sums.push_back(sums.back() + a);
	}
	for (int i = 0; i < m; i++) {
		cin >> a; int dorm = find_dorm(a);
		long long room = (dorm == 0) ? a : a - sums[dorm - 1];
		cout << dorm + 1 << " " << room << endl;
	}
	cin.ignore(2); return 0;
}