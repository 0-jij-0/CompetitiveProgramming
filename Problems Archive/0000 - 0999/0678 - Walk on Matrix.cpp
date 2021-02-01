#include <iostream>
using namespace std;

int main() {
	int k; cin >> k; int fillOnes = (1 << 18) - 1, notK = fillOnes ^ k;
	int res[3][3] = { { fillOnes, k, k }, { notK, fillOnes, fillOnes }, { notK, fillOnes, k } };
	cout << 3 << ' ' << 3 << endl;
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) { cout << res[i][j] << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}