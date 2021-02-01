#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair {
	int x;
	int y;
	int idx;

	Pair() {}
	Pair(int a, int b, int i) :
		x(a), y(b), idx(i) {}

	bool operator < (const Pair &rhs) const {
		return (x + 0.0) / (y + 0.0) < (rhs.x + 0.0) / (rhs.y + 0.0);
	}
};

int main() {
	int n; cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		int size; cin >> size;
		vector<Pair> tasks;
		for (int j = 0; j < size; j++) {
			int a, b;
			cin >> a >> b;
			Pair p(a, b, j+1);
			tasks.push_back(p);
		}
		sort(tasks.begin(), tasks.end());
		for (int j = 0; j < size; j++) {
			cout << tasks[j].idx << " ";
		}
		cout << endl;
		if (i + 1 != n) { cout << endl; }
	}

	cout << endl; cin.ignore(2); return 0;
}