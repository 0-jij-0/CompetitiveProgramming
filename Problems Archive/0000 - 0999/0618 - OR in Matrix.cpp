#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n, m;

vector<vector<int>> OrMatrix(vector<vector<int>> &v) {
	vector<int> vert(m, 0), horiz(n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			horiz[i] = horiz[i] || v[i][j];
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			vert[j] = vert[j] || v[i][j];

	vector<vector<int>> res(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = horiz[i] || vert[j];

	return move(res);
}

vector<vector<int>> invOrMatrix(vector<vector<int>> &v) {
	vector<vector<int>> res(n, vector<int>(m, 1));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (!v[i][j]) {
				for (int k = 0; k < m; k++) res[i][k] = 0;
				for (int k = 0; k < n; k++) res[k][j] = 0;
			}
	return move(res);
}

bool equalMatrix(vector<vector<int>> &v1, vector<vector<int>> &v2) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v1[i][j] != v2[i][j])
				return false;
	return true;
}

int main() {
	cin >> n >> m; v.resize(n, vector<int>(m));
	for (auto &x : v) for (auto &y : x) cin >> y;
	vector<vector<int>> v1 = invOrMatrix(v);
	vector<vector<int>> v2 = OrMatrix(v1);
	if (!equalMatrix(v2, v)) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		for (auto &x : v1) {
			for (auto &y : x) { cout << y << ' '; }
			cout << endl;
		}
	}
	cin.ignore(2); return 0;
}