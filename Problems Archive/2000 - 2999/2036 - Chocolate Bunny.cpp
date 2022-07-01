#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> res;

int query(int i = -1, int j = -1) {
	if (i == -1) {
		string s = "!";	for (auto& x : res)
			s += " " + to_string(x);
		cout << s << endl; return 0;
	}

	cout << "? " + to_string(i) + " " + to_string(j) << endl;
	int mod; cin >> mod; return mod;
}

int main() {
	int n; cin >> n; res.resize(n);

	int cur = 0; 
	for (int i = 1; i < n; i++) {
		int x = query(cur + 1, i + 1);
		int y = query(i + 1, cur + 1);
		if (y > x) { res[i] = y; continue; }
		res[cur] = x; cur = i;
	}
	res[cur] = n; query();
}