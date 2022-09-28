#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pqObj {
	int i, C; pqObj() {}
	pqObj(int _i, int _c) : i(_i), C(_c) {}
	bool operator < (const pqObj& rhs) const { return C > rhs.C; }
};

vector<int> v[4]; int n[4];

void updateMinDiff(vector<int> &i, int &minDiff, vector<int> &res) {
	int ma = max({ v[0][i[0]], v[1][i[1]], v[2][i[2]], v[3][i[3]] });
	int mi = min({ v[0][i[0]], v[1][i[1]], v[2][i[2]], v[3][i[3]] });
	if (ma - mi < minDiff) { minDiff = ma - mi; res = i; }
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> n[i]; v[i].resize(n[i]);
		for (auto& x : v[i]) cin >> x;
		sort(v[i].begin(), v[i].end());
	}

	vector<int> i = { 0, 0, 0, 0 };
	priority_queue<pqObj> pq;
	for (int j = 0; j < 4; j++)
		if (n[j] != 1) pq.push(pqObj(j, v[j][1]));

	int minDiff = 1 << 30; vector<int> res;
	while (!pq.empty()) {
		updateMinDiff(i, minDiff, res);
		pqObj cur = pq.top(); pq.pop(); i[cur.i]++;
		if (i[cur.i] + 1 != n[cur.i]) { pq.push(pqObj(cur.i, v[cur.i][i[cur.i] + 1])); }
	}

	updateMinDiff(i, minDiff, res);
	for (int j = 0; j < 4; j++)
		cout << v[j][res[j]] << ' '; cout << '\n';
}