#include <iostream>
#include <string>
using namespace std;

pair<int, int> moveSouth(int x, int y) { return { x / 2, (y + 1) / 2 }; }
pair<int, int> moveNorth(int x, int y) { return { x / 2, (y - 1) / 2 }; }
pair<int, int> moveEast(int x, int y) { return { (x - 1) / 2, y / 2 }; }
pair<int, int> moveWest(int x, int y) { return { (x + 1) / 2, y / 2 }; }

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int x, y; cin >> x >> y; cout << "Case #" << t << ": ";
		if (abs(x + y) % 2 == 0) { cout << "IMPOSSIBLE" << endl; continue; }
		string res = "";
		while (x != 0 || y != 0) {
			if (abs(x) % 2) {
				pair<int, int> p1 = moveWest(x, y), p2 = moveEast(x, y);
				if (!p1.first && !p1.second) { res.push_back('W'); break; }
				if (!p2.first && !p2.second) { res.push_back('E'); break; }
				if (abs(p1.first + p1.second) % 2) {
					x = p1.first; y = p1.second; res.push_back('W'); continue;
				}
				x = p2.first; y = p2.second; 
				res.push_back('E'); continue;
			}
			pair<int, int> p1 = moveNorth(x, y), p2 = moveSouth(x, y);
			if (!p1.first && !p1.second) { res.push_back('N'); break; }
			if (!p2.first && !p2.second) { res.push_back('S'); break; }
			if (abs(p1.first + p1.second) % 2) {
				x = p1.first; y = p1.second; res.push_back('N'); continue;
			}
			x = p2.first; y = p2.second; 
			res.push_back('S'); continue;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}