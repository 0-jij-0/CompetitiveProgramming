#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> pos;

bool check(int m) {
	int x = pos[m].first, y = pos[m].second;
	return abs(x) + abs(y) <= m;
}

int findMin() {
	int l = 0, r = pos.size();
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int x, y; string m; cin >> x >> y >> m;
		pos.clear(); pos.push_back({ x, y });
		for (char &c : m) {
			if (c == 'N') { y++; }
			if (c == 'S') { y--; }
			if (c == 'E') { x++; }
			if (c == 'W') { x--; }
			pos.push_back({ x, y });
		}
		int minTime = findMin();
		cout << "Case #" << t << ": ";
		if (minTime == pos.size()) { cout << "IMPOSSIBLE" << endl; continue; }
		cout << minTime << endl;
	}
	cin.ignore(2); return 0;
}