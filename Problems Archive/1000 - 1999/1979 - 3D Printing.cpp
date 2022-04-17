#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> printers(3, vector<int>(4, 0));

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {

		for (auto& x : printers) 
			for (auto& y : x) cin >> y;

		vector<int> maxFeasible(4);	
		for (int i = 0; i < 4; i++) {
			maxFeasible[i] = printers[0][i];
			for (int j = 0; j < 3; j++) 
				maxFeasible[i] = min(maxFeasible[i], printers[j][i]);
		}

		int maxTotal = accumulate(maxFeasible.begin(), maxFeasible.end(), 0);
		cout << "Case #" << t << ": ";
		if (maxTotal < 1000 * 1000) cout << "IMPOSSIBLE\n";
		else {
			maxTotal = 1000 * 1000;
			for (int i = 0; i < 4; i++) {
				if (maxFeasible[i] < maxTotal) {
					maxTotal -= maxFeasible[i];
					cout << maxFeasible[i];
				}
				else {
					cout << maxTotal;
					maxTotal = 0;
				}
				cout << " \n"[i == 3];
			}
		}
	}
	cin.ignore(2); return 0;
}