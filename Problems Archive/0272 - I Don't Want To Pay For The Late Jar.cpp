#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> r;;
int n, s;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return min(p1.first, p1.first - (p1.second - s)) < min(p2.first, p2.first - (p2.second - s));
}

int main() {
	int d; cin >> d;
	for (int i = 0; i < d; i++) {
		cin >> n >> s; r.clear(); r.resize(n);
		for (auto &x : r) { cin >> x.first >> x.second; }
		auto it = max_element(r.begin(), r.end(), compare);
		cout << "Case #" << i + 1 << ": ";
		cout << min(it->first, it->first - (it->second - s)) << endl;
	}
	cin.ignore(2); return 0;
}