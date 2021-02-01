#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
string s;
vector<int> idx[2];

int main() {
	int q; cin >> q;
	while (q--) {
		int n; ll k; cin >> n >> k >> s;
		idx[0].clear(); idx[1].clear();
		for (int i = 0; i < n; i++)
			idx[s[i] - '0'].push_back(i);
		int m = idx[0].size(), d = 0, i = 0;
		while (i < m && k > idx[0][i] - d) {
			k -= idx[0][i] - d; d++; i++;
		}
		if (i == m) {
			int j = 0; 
			while (j < m) { cout << '0'; j++; }
			while (j < n) { cout << '1'; j++; }
			cout << endl;
		}
		else {
			int y = idx[0][i] - d, j = 0; y -= k;
			while (j < i) { cout << '0'; j++; }
			while (y != 0) { cout << '1'; j++; y--; }
			cout << '0';
			while (j < idx[0][i]) { cout << '1'; j++; }
			while (j < n - 1) { cout << s[j + 1]; j++; }
			cout << endl;
		}
	}
	cin.ignore(2); return 0;
}