#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s; cin >> n >> s;
	int maxTime = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		maxTime = max(maxTime, t);
	}
	maxTime *= s; maxTime = (maxTime + 999) / 1000;
	cout << maxTime << endl;
}