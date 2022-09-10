#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p, freq;

int dist(int i, int j, int n) {
	return (j - i + n) % n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; p.resize(n); freq.resize(n);
	for (auto& x : p) cin >> x;

	for (int i = 0; i < n; i++) {
		int d = dist(i, p[i] - 1, n);
		freq[d]++; freq[(d + 1) % n]++; freq[(d + 2) % n]++;
	}

	cout << *max_element(freq.begin(), freq.end()) << '\n';
}