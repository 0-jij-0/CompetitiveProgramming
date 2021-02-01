#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int c, v; cin >> c >> v;
		vector<int> freq(c + 1, 0);
		vector<vector<int>> votes(v, vector<int>(c + 1, 0));
		for (int i = 0; i < v; i++) {
			for (int j = 1; j <= c; j++) {
				int a; cin >> a;
				if (j == 1) { freq[a]++; }
				votes[i][j] = a;
			}
		}
		auto x = max_element(freq.begin(), freq.end());
		int idx1 = x - freq.begin();
		if (*x > v / 2) { cout << idx1 << ' ' << 1 << endl; continue; }
		*x = 0; x = max_element(freq.begin(), freq.end());
		int idx2 = x - freq.begin();
		int a = 0, b = 0;
		for(int i = 0; i < v; i++)
			for(int j = 1; j <= c; j++)
				if (votes[i][j] != idx1 && votes[i][j] != idx2) { continue; }
				else if (votes[i][j] == idx1) { a++; break; }
				else { b++; break; }
		cout << (a < b ? idx2 : idx1) << ' ' << 2 << endl;
	}
	cin.ignore(2); return 0;
}