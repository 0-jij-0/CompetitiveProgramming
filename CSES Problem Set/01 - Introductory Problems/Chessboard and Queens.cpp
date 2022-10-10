#include <bits/stdc++.h>
using namespace std;

vector<int> column(8), diag1(16), diag2(16);
vector<string> v(8); int res = 0;

void placeQueens(int i) {
	if (i == 8) { res++; return; }
	for (int j = 0; j < 8; j++) 
		if (!column[j] && !diag1[i + j] && !diag2[i - j + 8] && v[i][j] == '.'){
			column[j] = diag1[i + j] = diag2[i - j + 8] = 1; placeQueens(i + 1);
			column[j] = diag1[i + j] = diag2[i - j + 8] = 0;
		}
}

int main() {
	for (auto &x : v) { cin >> x; }
	placeQueens(0); cout << res << endl;
}