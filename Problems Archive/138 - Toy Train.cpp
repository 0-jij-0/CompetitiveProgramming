#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[5001];
vector<pair<int, int>> v;
int n, m;

int dist(int a, int b) {
	if (b >= a) { return b - a; }
	return n + (b - a);
}

void toy_train() {
	vector<int> time; time.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		time[i] = (v[i].first - 1) * n + v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		int max = time[i];
		for (int j = 1; j < n; j++) {
			int idx = ((i + j) % (n + 1));
			if (idx < i) { idx++; }
			int m = j + time[idx];
			max = (max < m) ? m : max;
		}
		cout << max;
		if (i != n) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	cin >> n >> m; pair<int, int> z(0, -1); v.resize(n + 1, z);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int d = dist(a, b);
		v[a].first++; 
		if (v[a].second == -1 || d < v[a].second) { v[a].second = d; }
	}
	toy_train();
	cin.ignore(2); return 0;
}