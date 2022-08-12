#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<vector<int>> A(3, vector<int>(3)), B(3, vector<int>(3));
int R[3][3] = { {0, -1, 1}, {1, 0, -1}, {-1, 1, 0} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll k; int a, b; cin >> k >> a >> b; a--; b--;
	for (auto& x : A) for (auto& y : x) { cin >> y; --y; }
	for (auto& x : B) for (auto& y : x) { cin >> y; --y; }
	int idx = 0; map<pair<int, int>, int> m;
	vector<ll> aScore(9), bScore(9);

	ll rA = 0, rB = 0; while (!m.count({ a, b }) && idx < k) { 
		if (R[a][b] > 0) rA++; else if (R[a][b] < 0) rB++;
		aScore[idx] = rA; bScore[idx] = rB;

		int nextA = A[a][b], nextB = B[a][b];
		m[{a, b}] = idx++; a = nextA; b = nextB;
	}

	int prev = m[{a, b}], cycleLen = idx - prev;
	rA += ((k - idx) / cycleLen) * (aScore[idx - 1] - (prev ? aScore[prev - 1] : 0));
	rB += ((k - idx) / cycleLen) * (bScore[idx - 1] - (prev ? bScore[prev - 1] : 0));

	k = (k - idx) % cycleLen; while (k--) {
		if (R[a][b] > 0) rA++; else if (R[a][b] < 0) rB++;
		int nextA = A[a][b], nextB = B[a][b];
		a = nextA; b = nextB;
	}

	cout << rA << ' ' << rB << '\n';
}