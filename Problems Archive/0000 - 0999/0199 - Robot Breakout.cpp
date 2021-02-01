#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> moves;
vector<pair<int, int>> pos;

void find_point() {
	int xmax = 100000, ymax = 100000;
	int xmin = -100000, ymin = -100000;
	for (unsigned int i = 0; i < moves.size(); i++) {
		if (!moves[i][0]) {
			xmin = max(pos[i].first, xmin);
		}
		if (!moves[i][1]) {
			ymax = min(pos[i].second, ymax);
		}
		if (!moves[i][2]) {
			xmax = min(pos[i].first, xmax);
		}
		if (!moves[i][3]) {
			ymin = max(pos[i].second, ymin);
		}
	}
	if (xmin > xmax || ymin > ymax) { cout << 0 << endl; return; }
	else { 
		cout << 1 << ' ';
		cout << (xmin + xmax) / 2 << ' ';
		cout << (ymin + ymax) / 2 << endl;
	}
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n; cin >> n; 
		moves.clear(); pos.clear();
		moves.resize(n); pos.resize(n);
		for (int j = 0; j < n; j++) { moves[j].resize(4); }
		for (int j = 0; j < n; j++) {
			int x, y; cin >> x >> y;
			pair<int, int> p(x, y); pos[j] = p;
			cin >> moves[j][0] >> moves[j][1];
			cin >> moves[j][2] >> moves[j][3];
		}
		find_point();
	}
	cin.ignore(2); return 0;
}