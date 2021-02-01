#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq, v;

int main() {
	int n; cin >> n; v.resize(n);
	freq.resize(200001, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; freq[v[i]]++;
	}
	int max = max_element(freq.begin(), freq.end()) - freq.begin();
	int idx = find(v.begin(), v.end(), max) - v.begin();
	cout << n - freq[max] << endl;

	for (int i = idx + 1; i < n; i++) {
		if (v[i] == max) { continue; }
		int t = (v[i] < max) ? 1 : 2;
		cout << t << ' ' << i + 1 << ' ' << i << endl;
	}
	for (int i = idx - 1; i >= 0; i--) {
		if (v[i] == max) { continue; }
		int t = (v[i] < max) ? 1 : 2;
		cout << t << ' ' << i + 1 << ' ' << i + 2 << endl;
	}
	cin.ignore(2); return 0;
}