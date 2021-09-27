#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> G;
vector<int> above, below;

int main() {
	ifstream cin("C1.in.txt");
	ofstream cout("C1.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		above.clear(); below.clear(); G.clear();
		int r, c, k; cin >> r >> c >> k; G.resize(r); 
		above.resize(c, 0); below.resize(c, 0);
		k--; for (auto& x : G) { cin >> x; }

		int res = 1 << 30;
		for (int i = 0; i < r; i++) if(i != k)
			for (int j = 0; j < c; j++)
				(i < k ? above : below)[j] += G[i][j] == 'X';

		int cur = 0;
		for (int i = k; i < r; i++) {
			cur = 0; for (int j = 0; j < c; j++) {
				cur += (G[i][j] == 'X') || (above[j] > k);
				above[j] += G[i][j] == 'X';
			}
			res = min(res, cur + i - k);
		}
		
		cur = 0; for(int j = 0; j < c; j++){
			cur += (above[j] > k);
		} res = min(res, cur + r - k);

		for (int i = k; i >= 0; i--) {
			int cur = 0; for (int j = 0; j < c; j++) {
				cur += (G[i][j] == 'X') || (below[j] >= (r - k));
				below[j] += G[i][j] == 'X';
			}
			res = min(res, cur + k - i);
		}

		cur = 0; for (int j = 0; j < c; j++) {
			cur += (below[j] >= (r - k));
		} res = min(res, cur + k + 1);

		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}