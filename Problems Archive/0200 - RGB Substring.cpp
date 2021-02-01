#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;
string s;

int find_min() {
	int min = k; int num[3] = { 0, 0, 0 };
	for (int i = 0; i < k; i++) { 
		num[v[i]]++;
	}
	min = max(num[0], num[1]); min = max(min, num[2]);
	for (int i = 0; i < n - k; i++) {
		num[v[i]]--; num[v[i + k]]++;
		int m = max(num[0], num[1]); m = max(m, num[2]);
		min = max(min, m);
	}
	return k - min;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> k >> s;
		v.clear(); v.resize(n);
		for (int j = 0; j < n; j++) {
			if (j % 3 == 0) {
				if (s[j] == 'R') { v[j] = 0; }
				else if (s[j] == 'G') { v[j] = 1; }
				else { v[j] = 2; }
			}
			else if (j % 3 == 1) {
				if (s[j] == 'R') { v[j] = 2; }
				else if (s[j] == 'G') { v[j] = 0; }
				else { v[j] = 1; }
			}
			else {
				if (s[j] == 'R') { v[j] = 1; }
				else if (s[j] == 'G') { v[j] = 2; }
				else { v[j] = 0; }
			}
		}
		cout << find_min() << endl;
	}
	cin.ignore(2); return 0;
}