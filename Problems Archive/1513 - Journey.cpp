#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

vector<vector<int>> L, R; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; L.clear(); R.clear();
		L.resize(n + 1, vector<int>(2, 0)); 
		R.resize(n + 1, vector<int>(2, 0));
		
		for (int i = n - 1; i >= 0; i--)
			R[i][s[i] == 'L'] = 1 + R[i + 1][s[i] == 'R'];
		for (int i = 1; i <= n; i++)
			L[i][s[i - 1] == 'R'] = 1 + L[i - 1][s[i - 1] == 'L'];

		for (int i = 0; i <= n; i++)
			cout << L[i][0] + R[i][0] + 1 << ' '; cout << '\n';
		
	}
	cin.ignore(2); return 0;
}