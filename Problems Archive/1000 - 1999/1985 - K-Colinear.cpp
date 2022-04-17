#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int>> points;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; points.resize(n);
	for (auto& x : points) cin >> x.first >> x.second;
	if (k == 1) { cout << "Infinity\n"; return 0; }

	int res = 0; set<pair<int, int>> vis;
	for (int i = 0; i < n; i++) {
		map<pair<int, int>, vector<int>> slopes;
		vector<int> vert, hori;
		for (int j = i + 1; j < n; j++) {
			if (vis.count({ i, j })) { continue; }

			int dx = points[j].first - points[i].first;
			int dy = points[j].second - points[i].second;
			if (dx == 0) { slopes[{1, 0}].push_back(j); continue; }
			if (dy == 0) { slopes[{0, 1}].push_back(j); continue; }

			bool neg = (dx < 0) ^ (dy < 0);
			int g = gcd(abs(dx), abs(dy));
			pair<int, int> s((neg ? -abs(dy) : abs(dy)) / g, abs(dx) / g);
			slopes[s].push_back(j);
		}

		for (auto& x : slopes) {
			if((int)x.second.size() >= k - 1) res++;
			for (int p1 = 0; p1 < x.second.size(); p1++)
				for (int p2 = p1 + 1; p2 < x.second.size(); p2++)
					vis.insert({ x.second[p1], x.second[p2] });
		}
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}