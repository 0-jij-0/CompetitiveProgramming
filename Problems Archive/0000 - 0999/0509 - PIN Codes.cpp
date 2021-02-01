#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;

set<int> s;
vector<string> v;

int main() {
	int t; cin >> t;
	while (t--) {
		s.clear(); v.clear();
		int n; cin >> n; v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		for (int i = 0; i < n; i++) { s.insert(v[i][0] - '0'); }
		int res = 0;
		for (int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if (v[i] == v[j]) {
					res++;
					for(int k = 0; k < 10; k++)
						if (!s.count(k)) {
							s.insert(k);
							v[j][0] = k + '0';
							break;
						}
				}
		

		cout << res << endl;
		for (auto &x : v) {
			for (auto &y : x)
				cout << y;
			cout << endl;
		}
	}
	cin.ignore(2); return 0;
}