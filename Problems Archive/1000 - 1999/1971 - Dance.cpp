#include <iostream>
#include <vector>
using namespace std;

int res = 0, n;
vector<vector<int>> A;

void findMaxRes(int mask, int cur) {
	if (mask == 0) { res = max(res, cur); return; }

	int i = -1;
	for(int k = 0; k < n; k++)
		if (mask & (1 << k)) { i = k; break; }

	for (int j = i + 1; j < n; j++)
		if (mask & (1 << j)) findMaxRes(mask ^ (1 << i) ^ (1 << j), cur ^ A[i][j]);
}

int main() {
	cin >> n; n <<= 1; A.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cin >> A[i][j];

	findMaxRes((1 << n) - 1, 0);
	cout << res << '\n';
	cin.ignore(2); return 0;
}