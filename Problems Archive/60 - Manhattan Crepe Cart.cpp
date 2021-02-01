#include <iostream>
#include <vector>
using namespace std;

struct person {
	int x, y; 
	char c;
	person() {}
	person(int _x, int _y, char _c) :
		x(_x), y(_y), c(_c) {}
};

vector<int> north, south, east, west;
vector<person> people;

int max(vector<int> &v) {
	int m = 0, idx = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] > m) { m = v[i]; idx = i; }
	}
	return idx;
}

void cart(int &q) {
	north.clear(); south.clear(); east.clear(); west.clear();
	north.resize(q + 1, 0); south.resize(q + 1, 0); east.resize(q + 1, 0); west.resize(q + 1, 0);
	vector<int> x, y; x.resize(q + 1, 0); y.resize(q + 1, 0);

	for (unsigned int i = 0; i < people.size(); i++) {
		person p = people[i];
		if (p.c == 'N') { north[p.y]++; continue; }
		if (p.c == 'S') { south[p.y]++; continue; }
		if (p.c == 'E') { east[p.x]++; continue; }
		if (p.c == 'W') { west[p.x]++; continue; }
	}

	int count1 = 0, count2 = 0;
	for (int i = 0; i < q; i++) {
		count1 += east[i]; count2 += north[i];
		x[i + 1] += count1; y[i + 1] += count2;
	}
	count1 = 0; count2 = 0;
	for (int i = q; i > 0; i--) {
		count1 += west[i]; count2 += south[i];
		x[i - 1] += count1; y[i - 1] += count2;
	}

	int X = max(x), Y = max(y);
	cout << X << " " << Y << endl;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		people.clear();
		int p, q; cin >> p >> q;
		people.resize(p);
		for (int j = 0; j < p; j++) {
			int x, y; char c; cin >> x >> y >> c;
			person p(x, y, c);
			people[j] = p;
		}
		cout << "Case #" << i + 1 << ": ";
		cart(q);
	}
	cin.ignore(2); return 0;
}
