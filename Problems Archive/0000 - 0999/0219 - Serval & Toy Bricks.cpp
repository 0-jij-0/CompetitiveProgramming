#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> f, l;
vector<vector<int>> top;
int n, m, h;

int main() {
	cin >> n >> m >> h;
	f.resize(m); l.resize(n); top.resize(n);
	for (int i = 0; i < n; i++) { top[i].resize(m); }
	for (int i = 0; i < m; i++) { cin >> f[i]; }
	for (int i = 0; i < n; i++) { cin >> l[i]; }

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> top[i][j]; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << top[i][j] * min(l[i], f[j]);
			if (j + 1 != m) { cout << ' '; }
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}