#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> rotate(vector<string>& v) {
	int r = (int)v.size(), c = (int)v[0].size();
	vector<string> res(c, string(r, '0'));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			res[c - 1 - j][i] = v[i][j];
	return move(res);
}

vector<string> horizontalFlip(vector<string>& v) {
	int r = (int)v.size(), c = (int)v[0].size();
	vector<string> res = v;
	for (int i = 0; i < r; i++)
		for (int j = 0, k = c - 1; j < k; j++, k--)
			swap(res[i][j], res[i][k]);
	return move(res);
}

vector<string> verticalFlip(vector<string>& v) {
	int r = (int)v.size(), c = (int)v[0].size();
	vector<string> res = v;
	for (int j = 0; j < c; j++)
		for (int i = 0, k = r - 1; i < k; i++, k--)
			swap(res[i][j], res[k][j]);
	return move(res);
}

int findMatches(vector<string> a, vector<string> b) {
	int r1 = (int)a.size(), c1 = (int)a[0].size();
	int r2 = (int)b.size(), c2 = (int)b[0].size();

	int res = 0;
	for (int x = -r1 + 1; x < r2; x++) for (int y = -c1 + 1; y < c2; y++) {
		int cur = 0; for (int i = 0; i < r1; i++) for (int j = 0; j < c1; j++)
			if (x + i >= 0 && x + i < r2 && y + j >= 0 && y + j < c2)
				cur += (a[i][j] == '#') && (b[x + i][y + j] == '#');
		res = max(res, cur);
	}
	return res;
}

int solve(vector<string> a, vector<string> b) {
	int res = findMatches(a, b);
	res = max(res, findMatches(verticalFlip(a), b));
	res = max(res, findMatches(horizontalFlip(a), b));
	
	a = rotate(a); res = max(res, findMatches(a, b));
	res = max(res, findMatches(verticalFlip(a), b));
	res = max(res, findMatches(horizontalFlip(a), b));

	a = rotate(a); res = max(res, findMatches(a, b));
	res = max(res, findMatches(verticalFlip(a), b));
	res = max(res, findMatches(horizontalFlip(a), b));

	a = rotate(a); res = max(res, findMatches(a, b));
	res = max(res, findMatches(verticalFlip(a), b));
	res = max(res, findMatches(horizontalFlip(a), b));

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		vector<string> a, b;
		int r1, c1; cin >> r1 >> c1; a.resize(r1);
		for (auto& x : a) { cin >> x; }
		int r2, c2; cin >> r2 >> c2; b.resize(r2);
		for (auto& x : b) { cin >> x; }

		cout << solve(a, b) << '\n';
	}
	cin.ignore(2); return 0;
}