#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long double ld;
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-10;

vector<pair<ld, int>> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.clear();
		for (int i = 0; i < n; i++) {
			ld px, py; int yi; cin >> px >> py >> yi;
			if (abs(px) < 0.001 && abs(py) < 0.001) { continue; }
			if (abs(px) < 0.001) { v.push_back({ (py < 0.00 ? -PI / 2.0 : PI / 2.0), yi }); continue;	}
			v.push_back({ atan2(py, px), yi });
		}
		sort(v.begin(), v.end());
		n = (int)v.size(); int ones = 0;
		for (auto& x : v) { ones += (x.second == 1); }
		if (n < 3) { cout << "YES" << '\n'; continue; }

		int idx = 0; bool colinear = (v[0].second != v[n - 1].second) && (abs(2 * PI + v[0].first - v[n - 1].first) < EPS);
		for (int i = 1; i < n && !colinear; i++) {
			if (v[i].second != v[i - 1].second)
				if ((abs(v[i].first - v[i - 1].first)) < EPS) { idx = i; colinear = true; }
		}

		if (!colinear) {
			if (ones == n || ones == 0) {
				ld sep = 2 * PI + v[0].first - v[n - 1].first;
				for (int i = 1; i < n; i++)
					sep = max(sep, v[i].first - v[i - 1].first);
				cout << ((sep - PI > -EPS) ? "YES" : "NO") << '\n';
				continue;
			}

			if (v[0].second == 1 && v[n - 1].second == 1) {
				int i = 0, j = n - 1;
				while (v[i].second == 1) { i++; }
				while (v[j].second == 1) { j--; }
				if (i + (n - 1 - j) < ones) { cout << "NO" << '\n'; continue; }
				if (v[j].first - v[i].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
				if (PI + v[i - 1].first - v[j + 1].first >= -EPS) { cout << "NO" << '\n'; continue; }
				cout << "YES" << '\n'; continue;
			}
			if (v[0].second == 1) {
				int i = 0; while (v[i].second == 1) { i++; }
				if (i < ones) { cout << "NO" << '\n'; continue; }
				if (v[i - 1].first - v[0].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
				if (v[n - 1].first - v[i].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
				cout << "YES" << '\n'; continue;
			}
			if (v[n - 1].second == 1) {
				int j = n - 1; while (v[j].second == 1) { j--; }
				if (n - 1 - j < ones) { cout << "NO" << '\n'; continue; }
				if (v[n - 1].first - v[j + 1].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
				if (v[j].first - v[0].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
				cout << "YES" << '\n'; continue;
			}
			int i = 0, j = n - 1;
			while (v[i].second != 1) { i++; }
			while (v[j].second != 1) { j--; }
			if (j - i + 1 > ones) { cout << "NO" << '\n'; continue; }
			if (v[j].first - v[i].first - PI >= -EPS) { cout << "NO" << '\n'; continue; }
			if (PI + v[i - 1].first - v[j + 1].first >= -EPS) { cout << "NO" << '\n'; continue; }
			cout << "YES" << '\n'; continue;
		}

		ld start = v[idx].first, end = (start < EPS) ? PI + start : -PI + start;
		if (start > end) { swap(start, end); }
		set<int> pos, neg;

		for (int i = 0; i < n; i++) {
			if (abs(v[i].first - start) < EPS) { continue; }
			if (abs(v[i].first - end) < EPS) { continue; }
			if (v[i].first > start && v[i].first < end) { pos.insert(v[i].second); }
			else { neg.insert(v[i].second); }
		}

		if (pos.size() == 2) { cout << "NO" << '\n'; continue; }
		if (neg.size() == 2) { cout << "NO" << '\n'; continue; }
		if (pos.size() == 0) { cout << "YES" << '\n'; continue; }
		if (neg.size() == 0) { cout << "YES" << '\n'; continue; }
		cout << (*pos.begin() != *neg.begin() ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}