#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
using namespace std;
typedef double ld;
const ld EPS = 1e-10;

vector<int> v; int n, d;

pair<int, int> check(ld M) {
	vector<ld> p; 
	for (auto& x : v) p.push_back(x - M);
	partial_sum(p.begin(), p.end(), p.begin());

	auto ma = max_element(p.begin() + d - 1, p.end());
	if (*ma > -EPS) return { 0, ma - p.begin() };

	vector<int> prefMin(n, 0); for (int i = 1; i < n; i++)
		prefMin[i] = p[i] < p[prefMin[i - 1]] ? i : prefMin[i - 1];

	for(int i = d; i < n; i++)
		if (p[i] - p[prefMin[i - d]] > -EPS)
			return { prefMin[i - d] + 1, i };

	return { -1, -1 };
}

pair<int, int> maxAverageSegment() {
	ld L = 0.0, R = 101.0;
	for(int i = 0; i < 100; i++) {
		ld M = (L + R) / 2.0;
		check(M).first == -1 ? R = M : L = M;
	}
	return check(L);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> d; v.resize(n);
	for (auto& x : v) cin >> x;

	int L, R; tie(L, R) = maxAverageSegment();
	cout << L + 1 << ' ' << R + 1 << '\n';
}