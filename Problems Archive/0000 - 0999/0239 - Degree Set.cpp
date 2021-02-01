#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<int> dq;

void print_graph() {
	vector<pair<int, int>> res;
	int first = 1, dec = 0;
	while (!dq.empty()) {
		int max = dq.back() - dec, min = dq.front() - dec;
		for (int i = 0; i < min; i++) {
			for (int j = 1; j <= max; j++) {
				res.push_back({ first, first + j });
			}
			first++; max--;
		}
		dec += min;
		if (dq.size() < 3) { break; }
		dq.pop_back(); dq.pop_front();
	}
	cout << res.size() << endl;
	for (auto &x : res) { cout << x.first << ' ' << x.second << endl; }
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; dq.push_back(a);
	}
	print_graph();
	cin.ignore(2); return 0;
}