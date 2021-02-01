#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string I, O;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ofstream ofs("out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, i; cin >> n >> I >> O;
		vector<string> res(n, string(n, 'N'));
		i = 0; while (i < n) {
			int j = i + 1;
			while (j < n && O[j - 1] == 'Y' && I[j] == 'Y') { j++; }
			for (int a = i; a < j; a++)
				for (int b = a; b < j; b++)
					res[a][b] = 'Y';
			i = j;
		}
		i = n - 1; while (i >= 0) {
			int j = i - 1;
			while (j >= 0 && O[j + 1] == 'Y' && I[j] == 'Y') { j--; }
			for (int a = i; a > j; a--)
				for (int b = a; b > j; b--)
					res[a][b] = 'Y';
			i = j;
		}
		ofs << "Case #" << t << ":" << '\n';
		for (auto &x : res) ofs << x << '\n';
	}
	cin.ignore(2); return 0;
}