#include <iostream>
using namespace std;

int freq[1001];

int main() {
	for (int i = 0; i < 1001; i++) { freq[i] = 0; }
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; freq[a]++;
	}
	int s = 0; bool extra = false;
	for (int i = 1; i <= k; i++) {
		if (freq[i] % 2 == 0) { s += freq[i]; continue; }
		if (extra) { s += freq[i] - 1; extra = false; continue; }
		s += freq[i]; extra = true; continue;
	}
	cout << s << endl;
	cin.ignore(2); return 0;
}