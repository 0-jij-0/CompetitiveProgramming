#include <iostream>
#include <vector>
using namespace std;

vector<int> freq;

int main() {
	int n; cin >> n; freq.resize(n + 2, 0);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		freq[a]++; freq[b + 1]--;
	}
	int pref = 0;
	for (int i = 0; i < n + 2; i++) {
		pref += freq[i]; freq[i] = pref;
	}
	int res = -1;
	for (int i = n; i >= 0; i--) {
		if (freq[i] == i) { res = i; break; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}