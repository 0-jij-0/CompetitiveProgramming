#include <bits/stdc++.h>
using namespace std;

vector<string> v; int H, W;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool check(int i, int j, int k) {
	string res = "snuke";
	for (int x = 0; x < 5; x++, i += dx[k], j += dy[k]) 
		if (i < 0 || i >= H || j < 0 || j >= W || v[i][j] != res[x]) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> H >> W; v.resize(H);
	for (auto& x : v) cin >> x;

	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			for(int k = 0; k < 8; k++)
				if (check(i, j, k)) {
					for (int x = 0; x < 5; x++) {
						cout << i + 1 << ' ' << j + 1 << '\n';
						i += dx[k]; j += dy[k];
					}
					return 0;
				}
}