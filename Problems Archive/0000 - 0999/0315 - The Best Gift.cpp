#include <iostream>
#include <vector>
using namespace std;

vector<long long> freq;

int main() {
	int n, m; cin >> n >> m; freq.resize(m + 1, 0);
	for (int i = 0; i < n; i++) { int a; cin >> a; freq[a]++; }
	long long res = (long long) n * (n - 1) / 2;
	for (auto &x : freq) { res -= x * (x - 1) / 2; }
	cout << res << endl;
	cin.ignore(2); return 0;
}