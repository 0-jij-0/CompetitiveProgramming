#include <iostream>
#include <vector>
using namespace std;

vector<int> v, freq;

bool check() {
	freq.clear(); freq.resize(10001, 0);
	for (auto &x : v) {	freq[x]++; }
	int i = 1, j = 10000; int area = 0;
	while (i <= j) {
		if (freq[i] == 0) { i++; continue; }
		if (freq[j] == 0) { j--; continue; }
		if (freq[i] % 2 || freq[j] % 2 || freq[i] != freq[j]) { return false; }
		if (area == 0) { area = i * j; i++; j--; continue; }
		else if (i * j != area) { return false; }
		i++; j--;
	}
	return true;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n; cin >> n;
		v.clear(); v.resize(4*n);
		for (auto &x : v) { cin >> x; }
		bool b = check();
		if (b) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}