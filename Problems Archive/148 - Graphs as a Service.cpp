#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n, m;
int graph[55][55];
int dp[55][55];
int req[55][55];

void floyd_warshal(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = 50000001;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = graph[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
}

void build(int n, ofstream &ofs) {
	floyd_warshal(n); bool b = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != req[i][j] && req[i][j] != -1) { b = false; break; }
		}
		if (b == false) { break; }
	}
	if (b == false) { ofs << "Impossible" << endl; return; }

	ofs << m << endl;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (graph[i][j] != 50000001)
				ofs << i << ' ' << j << ' ' << graph[i][j] << endl;
}

int main() {
	string fname_in = "graphsin.txt";
	string fname_out = "graphsout.txt";
	ifstream ifs(fname_in.c_str());
	ofstream ofs(fname_out.c_str());
	int t; ifs >> t;
	for (int i = 0; i < t; i++) {
		ifs >> n >> m;
		for (int j = 1; j < 51; j++) {
			for (int k = 1; k < 51; k++) {
				graph[j][k] = 50000001;
				req[j][k] = -1;
			}
		}
		for (int j = 0; j < m; j++) {
			int x, y, z; ifs >> x >> y >> z;
			req[x][y] = req[y][x] = z;
			graph[x][y] = graph[y][x] = z;
		}
		ofs << "Case #" << i + 1 << ": ";
		build(n, ofs);
	}
	ifs.close(); ofs.close();
	cin.ignore(2); return 0;
}