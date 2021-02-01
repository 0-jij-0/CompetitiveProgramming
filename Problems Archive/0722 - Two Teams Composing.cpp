#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int> freq(n + 1, 0);
		for (int i = 0; i < n; i++) { int x; cin >> x; freq[x]++; }
		int sec = max_element(freq.begin(), freq.end()) - freq.begin();
		int others = 0; for (int i = 1; i <= n; i++) { others += (freq[i] && (i != sec)); }
		if (others >= freq[sec]) { cout << freq[sec] << endl; continue; }
		if (others + 1 == freq[sec]) { cout << others << endl; continue; }
		cout << others + 1 << endl;
	}
	cin.ignore(2); return 0;
}