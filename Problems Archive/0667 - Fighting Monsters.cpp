#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

map<int, int> m; set<int> s;
vector<int> ones;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; m[a] = i; s.insert(a);
		if (a == 1) { ones.push_back(i); }
	}

	if (ones.size() > 1) {
		cout << ones.front() + 1 << ' ' << ones.back() + 1 << endl;
		cin.ignore(2); return 0;
	}

	int f1 = 1, f2 = 2;
	while (f2 <= *s.rbegin()) {
		if (!s.count(f1) || !s.count(f2)) {
			int temp = f1 + f2; f1 = f2; f2 = temp; continue;
		}
		cout << m[f1] + 1 << ' ' << m[f2] + 1 << endl;
		cin.ignore(2); return 0;
	}
	cout << "impossible" << endl;
	cin.ignore(2); return 0;
}