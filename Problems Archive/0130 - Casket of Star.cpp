#include <iostream>
#include <vector>
using namespace std;

vector<int> stars;
int DP[51][51];

int max_energy(int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (i + 1 == j) { return 0; }
	int sum = stars[i] * stars[j];
	int max = 0;
	for (int x = i + 1; x < j; x++) {
		int a = max_energy(i, x) + max_energy(x, j);
		if (a > max) { max = a; }
	}
	DP[i][j] = sum + max; return DP[i][j];
}

int main() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) { DP[i][j] = -1; }
	}
	char c; cin >> c;
	while (c != '}') {
		int a; cin >> a >> c; stars.push_back(a);
	}
	cout << max_energy(0, stars.size() - 1) << endl;
	cin.ignore(2); return 0;
}