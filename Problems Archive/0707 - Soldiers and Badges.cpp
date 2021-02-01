#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq;

int main() {
	int n; cin >> n; freq.resize(2 * n + 2, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; freq[x]++;
	}

	int res = 0;
	for (int i = 0; i < 2 * n + 1; i++) {
		int x = max(0, freq[i] - 1);
		res += x; freq[i + 1] += x;
	}
	cout << res << endl; cin.ignore(2); return 0;
}