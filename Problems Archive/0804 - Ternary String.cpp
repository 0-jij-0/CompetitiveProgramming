#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s; int n = (int)s.size();
		vector<int> freq(3, 0); int i = 0, j = 0, res = n + 1;
		while (j < n) {
			freq[s[j] - '1']++;
			if (!freq[0] || !freq[1] || !freq[2]) { j++; continue; }
			while (freq[s[i] - '1'] != 1) { freq[s[i] - '1']--; i++; }
			res = min(res, j - i + 1); freq[s[i] - '1']--; i++; j++;
		}
		cout << (res == n + 1 ? 0 : res) << endl;
	}
	cin.ignore(2); return 0;
}