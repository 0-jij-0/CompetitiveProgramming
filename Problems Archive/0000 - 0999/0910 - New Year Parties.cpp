#include <iostream>
#include <vector>
using namespace std;

vector<int> freq;

int findMin() {
	int res = 0, n = (int)freq.size();
	for (int i = 0; i < n; i++) {
		if (!freq[i]) { continue; }
		res++; i += 2;
	}
	return res;
}

int findMax() {
	int res = 0, n = (int)freq.size() - 1;
	int i = 1, j = 1, sum = 0;
	while (j <= n) {
		if (!freq[i]) { i = j = j + 1; continue; }
		if (j != n && freq[j]) { sum += freq[j]; j++; continue; }
		if (sum == j - i) { res += j - i; i = j = j + 1; sum = 0; continue; }
		if (freq[i - 1]) { res += j - i + 1; freq[j] = 1; i = j = j + 1; sum = 0; continue; }
		if (sum == j - i + 1) { res += j - i + 1; i = j = j + 1; sum = 0; continue; }
		res += j - i + 2; freq[j] = 1; i = j = j + 1; sum = 0;
	}
	return res;
}

int main() {
	int n; cin >> n; freq.resize(n + 2, 0);
	for (int i = 0; i < n; i++) { int x; cin >> x; freq[x]++; }
	int min = findMin(), max = findMax();
	cout << min << ' ' << max << endl;
	cin.ignore(2); return 0;
}