#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

map<int, int> m;
vector<int> v;
int n, I;

long long num_bits(int n) {
	return (long long)ceil(log2(n + 0.0));
}

int max_sub(int k) {
	int m = 0, max = 0;
	for (int i = 0; i < k; i++) {
		m += v[i];
	}
	max = m;
	for (unsigned int i = 0; i < v.size() - k; i++) {
		m -= v[i]; m += v[i + k];
		if (m > max) { max = m; }
	}
	return max;
}

int main() {
	cin >> n >> I; I *= 8;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; m[a]++;
	}
	for (auto x : m) { v.push_back(x.second); }
	int k = I / n; int N = (int)v.size();
	if (k >= num_bits(N)) { cout << 0 << endl; }
	else {
		k = 1 << k;
		cout << n - max_sub(k) << endl;
	}
	cin.ignore(2); return 0;
}
