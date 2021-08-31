#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> RX, RO, CX, CO, R, C;
vector<string> grid;

int main() {
	ifstream cin("B.in.txt");
	ofstream cout("B.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		RX.clear(); RO.clear(); CX.clear(); 
		CO.clear(); R.clear(); C.clear();

		int n; cin >> n; grid.resize(n);
		RX.resize(n, 0); RO.resize(n, 0);
		CX.resize(n, 0); CO.resize(n, 0);

		for (auto& x : grid) { cin >> x; }
		for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
			if(grid[i][j] != '.') {
				(grid[i][j] == 'O' ? RO : RX)[i]++;
				(grid[i][j] == 'O' ? CO : CX)[j]++;
			}

		R.resize(n, 1 << 30); C.resize(n, 1 << 30);
		for (int i = 0; i < n; i++) {
			if (RO[i] == 0) { R[i] = n - RX[i]; }
			if (CO[i] == 0) { C[i] = n - CX[i]; }
		}

		int mi = *min_element(R.begin(), R.end());
		mi = min(mi, *min_element(C.begin(), C.end()));
		int res = count(R.begin(), R.end(), mi) + count(C.begin(), C.end(), mi);

		if (mi == 1) {
			res = 0; for(int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) if(grid[i][j] == '.')
					res += R[i] == 1 || C[j] == 1;
		}

		cout << "Case #" << t << ": ";
		if (mi == 1 << 30) { cout << "Impossible\n"; }
		else { cout << mi << ' ' << res << '\n'; }
	}
	return 0;
}