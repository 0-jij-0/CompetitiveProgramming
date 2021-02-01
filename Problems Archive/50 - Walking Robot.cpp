#include <iostream>
#include <vector>
using namespace std;

vector<int> sun;
int acc, batt;

int max_dist(int &n, int i, int a, int b) {
	if (i == n) { return n; }
	if (b == 0) { return ((i + a) < n) ? i + a : n; }
	
	if (sun[i] == 1) { 
		if(a != acc){ return max_dist(n, i + 1, a + 1, b - 1); }
		if (a != 0) { return max_dist(n, i + 1, a - 1, b); }
		return max_dist(n, i + 1, a, b - 1);
	}

	if (a != 0) { return max_dist(n, i + 1, a - 1, b); }

	return max_dist(n, i + 1, 0, b - 1);
}

int main() {
	int n; cin >> n >> batt >> acc;
	if (batt + acc >= n) { cout << n << endl; return 0; }
	sun.resize(n);
	for (int i = 0; i < n; i++) { cin >> sun[i]; }
	cout << max_dist(n, 0, acc, batt) << endl;
	return 0;
}