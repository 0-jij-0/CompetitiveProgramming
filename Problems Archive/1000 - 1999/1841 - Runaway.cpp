#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> S, F;
vector<multiset<int>> P;

int main() {
	ifstream cin("A.in.txt");
	ofstream cout("A.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m; cin >> n >> m; 
		P.clear(); F.clear(); S.clear();
		S.resize(m); F.resize(m, 0); P.resize(n);

		for (auto& x : S) cin >> x;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				int x; cin >> x; P[i].insert(x);
			}

		int res = 0; for (int i = 0; i < n; i++) {
			vector<int> took(m, 0);
			for (int j = 0; j < m; j++) if (F[j]) {
				multiset<int>::iterator it = P[i].find(S[j]);
				if (it != P[i].end()) { P[i].erase(it); took[j] = 1; }
			}
			for (int j = 0; j < m; j++) if (!F[j]) {
				multiset<int>::iterator it = P[i].find(S[j]);
				if (it != P[i].end()) { P[i].erase(it); took[j] = 1; }
			}

			for (int j = 0; j < m; j++) if (took[j] == 0) {
				res += F[j]; if (F[j] == 0) { F[j] = 1; }
				S[j] = *P[i].begin(); P[i].erase(P[i].begin());
			}
		}

		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}