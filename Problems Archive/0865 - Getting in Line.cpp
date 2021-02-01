#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
typedef pair<int, int> point;

vector<point> p; int n;
double dp[8][500];
int nextNode[8][500];
string line = "**********************************************************";

ostream &operator << (ostream &os, point &p) {
	os << '(' << p.first << ',' << p.second << ')';
	return os;
}

double dist(point &p1, point &p2) {
	int dx = p1.first - p2.first; dx *= dx;
	int dy = p1.second - p2.second; dy *= dy;
	return 16.0 + sqrt(dx + dy + 0.0);
}

double minDist(int i, int mask) {
	if (mask == (1 << n) - 1) { return 0.0; }
	if (dp[i][mask] > 0.0) { return dp[i][mask]; }

	int j = 0, lim = 1 << n;
	double res = 1e10;
	while (1 << j != lim) {
		int setBit = 1 << j;
		if ((mask & setBit) != 0) { j++; continue; }
		double ans = dist(p[i], p[j]) + minDist(j, mask | setBit);
		if (ans < res) { res = ans; nextNode[i][mask] = j; }
		j++;
	}
	return dp[i][mask] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; int t = 1;
	while (n != 0) {
		p.resize(n);
		for (auto &x : p) { cin >> x.first >> x.second; }
		fill(nextNode[0], nextNode[0] + 8 * 500, -1);
		fill(dp[0], dp[0] + 8 * 500, -1.0);

		double res = 1e10; int cur = -1;
		for (int i = 0; i < n; i++) {
			double ans = minDist(i, 1 << i);
			if (ans < res) { res = ans; cur = i; }
		}
		cout << line << '\n' << "Network #" << t++ << '\n'; int mask = 1 << cur;
		while (nextNode[cur][mask] != -1) {
			cout << "Cable requirement to connect ";
			cout << p[cur] << " to " << p[nextNode[cur][mask]];
			cout << " is " << fixed << setprecision(2) << dist(p[cur], p[nextNode[cur][mask]]) << " feet." << '\n';
			cur = nextNode[cur][mask]; mask = mask | (1 << cur);
		}
		cout << "Number of feet of cable required is " << res << '.' << '\n'; cin >> n;
	}
	cin.ignore(2); return 0;
}