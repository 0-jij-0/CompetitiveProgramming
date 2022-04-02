#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n + 1, 4);
	for (int i = 0; i < 4 * n - 1; i++) {
		int x; cin >> x; v[x]--;
	}

	cout << (find(v.begin(), v.end(), 1) - v.begin()) << '\n';
}