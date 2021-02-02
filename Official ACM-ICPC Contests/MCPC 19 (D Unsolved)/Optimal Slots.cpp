#include <iostream>
#include <vector>
using namespace std;

int DP[102][52], choice[102][52];
vector<int> hours; int T, N;

int maxNums(int available, int i) {
	if (DP[available][i] != -1) { return DP[available][i]; }
	if (i >= N) { return 0; }

	int c1 = maxNums(available, i + 1), c2 = 0;
	if (hours[i] <= available) { c2 = hours[i] + maxNums(available - hours[i], i + 1); }

	if (c2 >= c1 && c2 != 0) {
		choice[available][i] = 1;
		DP[available][i] = c2;
	}
	else {
		choice[available][i] = 0;
		DP[available][i] = c1;
	}
	return DP[available][i];
}

void resetDP() {
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 52; j++) 
			DP[i][j] = choice[i][j] = -1;
}

int main() {
	cin >> T;
	while (T != 0) {
		resetDP(); cin >> N; hours.resize(N);
		for (int i = 0; i < N; i++) { cin >> hours[i]; }
		int res = maxNums(T, 0);

		int i = T, j = 0;
		while (choice[i][j] != -1) {
			if (choice[i][j]) {
				cout << hours[j] << ' ';
				i -= hours[j];
			}
			j++;
		}
		cout << res << endl; cin >> T;
	}
	cin.ignore(2); return 0;
}