#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool graph[7][7];
int s[7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	for (int i = 0; i < 7; i++) {
		s[i] = 0;
		for (int j = 0; j < 7; j++)
			graph[i][j] = false;
	}
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		graph[a][b] = graph[b][a] = true;
		s[a]++; s[b]++;
	}
	if (n < 7) { cout << m << endl; }
	else {
		int dec = 10;
		for(int i = 0; i < 7; i++)
			for (int j = i + 1; j < 7; j++) {
				int c = 0;
				for (int k = 0; k < 7; k++) { if (graph[i][k] && graph[j][k]) { c++; } }
				int e = s[i] + s[j] - c - graph[i][j], dis = max(e - 5 - graph[i][j], 0);
				dec = min(dec, dis + c);
			}
		cout << m - dec << endl;
	}
	cin.ignore(2); return 0;
}