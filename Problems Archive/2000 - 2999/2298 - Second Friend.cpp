#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

int main() {
	ifstream cin("second_friend_input.txt");
	ofstream cout("second_friend_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int R, C; cin >> R >> C; v.resize(R);
		for (auto& x : v) cin >> x;
		
		cout << "Case #" << t << ": ";
		if (min(R, C) > 1) {
			cout << "Possible\n";
			for (auto& x : v) cout << string(C, '^') << '\n';
		}
		else {
			bool tree = false; for (auto& x : v)
				tree = tree || count(x.begin(), x.end(), '^');

			if (tree) { cout << "Impossible\n"; continue; }
			cout << "Possible\n";
			for (auto& x : v) cout << x << '\n';
		}
	}
}