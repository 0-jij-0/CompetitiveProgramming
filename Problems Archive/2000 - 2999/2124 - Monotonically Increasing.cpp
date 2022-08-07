#include <iostream>
#include <vector>
using namespace std;

int n, m; vector<int> v;

void generate(int i, int prev) {
	if (i == n) { 
		for (auto& x : v) cout << x << ' '; 
		cout << '\n'; return;
	}

	for (int j = prev + 1; j + (n - 1 - i) <= m; j++) {
		v.push_back(j); 
		generate(i + 1, j);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	generate(0, 0);
}