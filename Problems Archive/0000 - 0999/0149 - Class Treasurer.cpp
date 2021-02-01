#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<int> votes;
int a[1000001];
const int mod = 1000000007;

void fill_a() {
	a[0] = 1;
	for (int i = 1; i < 1000001; i++)
		a[i] = (a[i - 1] * 2) % mod;
}

int min_cost(int n, int k) {
	int cost = 0, cur_sum = 0;
	for (int i = n; i > 0; i--) {
		cur_sum += votes[i];
		if (cur_sum < 0) { cur_sum = 0; continue; }
		if (cur_sum > k) {
			cost += a[i]; cost %= mod; cur_sum -= 2; 
			if (cur_sum < 0) { cur_sum = 0; }
			continue;
		}
	}
	return cost;
}

int main() {
	string fname_in = "class_treasurerin.txt";
	string fname_out = "class_treasurerout.txt";
	ifstream ifs(fname_in.c_str());
	ofstream ofs(fname_out.c_str());
	fill_a(); int t; ifs >> t;

	for (int i = 0; i < t; i++) {
		int n, k; ifs >> n >> k;
		votes.clear(); votes.resize(n + 1);
		for (int j = 1; j <= n; j++) {
			char c; ifs >> c;
			votes[j] = (c == 'A') ? -1 : 1;
		}
		ofs << "Case #" << i + 1 << ": " << min_cost(n, k) << endl;
	}
	ifs.close(); ofs.close();
	cin.ignore(2); return 0;
}