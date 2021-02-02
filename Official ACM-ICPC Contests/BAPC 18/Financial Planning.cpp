#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, pair<long long, long long>>> v;
int n; long long m;

bool check_day(long long k) {
	long long prof = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first > k) { break; }
		prof += v[i].second.first + (k - v[i].first)*v[i].second.second;
		if (prof >= m) { return true; }
	}
	return false;
}

long long find_min() {
	long long l = 1, r = 2000000000;
	while (l != r) {
		long long mid = (l + r) >> 1;
		bool b = check_day(mid);
		if (b) { r = mid; }
		else { l = mid + 1; }
	}
	return l;
}

int main() {
	cin >> n >> m; v.resize(n);
	for (int i = 0; i < n; i++) {
		long long p, c; cin >> p >> c;
		long long d = (c + p - 1) / p;
		c = (p - (c % p)) % p;
		v[i] = { d, {c, p} };
	}
	sort(v.begin(), v.end());
	cout << find_min() << endl;
	cin.ignore(2); return 0;
}

