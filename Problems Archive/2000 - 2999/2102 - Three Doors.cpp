#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(3);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int x; cin >> x; x--;
		cin >> v[0] >> v[1] >> v[2];
		if (v[x] == 0) { cout << "NO\n"; continue; }
		if (v[v[x] - 1] == 0) { cout << "NO\n"; continue; }
		cout << "YES\n";
	}
}