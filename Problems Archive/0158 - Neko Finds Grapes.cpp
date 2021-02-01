#include <iostream>
#include <algorithm>
using namespace std;

int freqa[2], freqb[2];

int main() {
	freqa[0] = freqa[1] = freqb[0] = freqb[1] = 0;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; freqa[a % 2]++;
	}
	for (int i = 0; i < m; i++) {
		int b; cin >> b; freqb[b % 2]++;
	}
	cout << min(freqa[0], freqb[1]) + min(freqa[1], freqb[0]) << endl;
	cin.ignore(2); return 0;
}