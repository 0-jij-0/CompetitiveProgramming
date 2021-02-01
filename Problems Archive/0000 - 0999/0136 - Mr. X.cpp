#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

struct tuples {
	int zero, one, x, notx;

	tuples() {}
	tuples(int _zero, int _one, int _x, int _notx) :
		zero(_zero), one(_one), x(_x), notx(_notx) {}
};

string f;
vector<int> formula;

void fill_formula() {
	formula.resize(f.size(), -1);
	stack<int> s;
	for (unsigned int i = 0; i < f.size(); i++) {
		if (f[i] == '(') { s.push(i); continue; }
		if (f[i] == '^' || f[i] == '|' || f[i] == '&') {
			formula[s.top()] = i; s.pop(); continue;
		}
	}
}

tuples min_op(int i, int j) {
	if (i == j) {
		if (f[i] == '0') { tuples t(0, 1, 1, 1); return t; }
		else if (f[i] == '1') { tuples t(1, 0, 1, 1); return t; }
		else if (f[i] == 'x') { tuples t(1, 1, 0, 1); return t; }
		else { tuples t(1, 1, 1, 0); return t; }
	}
	int idx = formula[i]; char c = f[idx];
	tuples t1 = min_op(i + 1, idx - 1), t2 = min_op(idx + 1, j - 1);
	int zero, one, x, notx;
	if (c == '|') {
		zero = t1.zero + t2.zero;
		int one1 = min(t1.one, t2.one);
		int one2 = min(t1.x + t2.notx, t1.notx + t2.x);
		one = min(one1, one2);
		int x1 = min(t1.zero + t2.x, t1.x + t2.zero);
		x = min(x1, t1.x + t2.x);
		int notx1 = min(t1.zero + t2.notx, t1.notx + t2.zero);
		notx = min(notx1, t1.notx + t2.notx);
		tuples t(zero, one, x, notx); return t;
	}
	if (c == '&') {
		int zero1 = min(t1.zero, t2.zero);
		int zero2 = min(t1.x + t2.notx, t1.notx + t2.x);
		zero = min(zero1, zero2);
		one = t1.one + t2.one;
		int x1 = min(t1.one + t2.x, t1.x + t2.one);
		x = min(x1, t1.x + t2.x);
		int notx1 = min(t1.one + t2.notx, t1.notx + t2.one);
		notx = min(notx1, t1.notx + t2.notx);
		tuples t(zero, one, x, notx); return t;
	}
	int zero1 = min(t1.one + t2.one, t1.zero + t2.zero);
	int zero2 = min(t1.x + t2.x, t1.notx + t2.notx);
	zero = min(zero1, zero2);
	int one1 = min(t1.one + t2.zero, t1.zero + t2.one);
	int one2 = min(t1.x + t2.notx, t1.notx + t2.x);
	one = min(one1, one2);
	int x1 = min(t1.zero + t2.x, t1.x + t2.zero);
	int x2 = min(t1.one + t2.notx, t1.notx + t2.one);
	x = min(x1, x2);
	int notx1 = min(t1.zero + t2.notx, t1.notx + t2.zero);
	int notx2 = min(t1.one + t2.x, t1.x + t2.one);
	notx = min(notx1, notx2);
	tuples t(zero, one, x, notx); return t;
}

int main() {
	string fname1 = "mr_xin.txt";
	string fname2 = "mr_xout.txt";
	ifstream ifs(fname1.c_str());
	ofstream ofs(fname2.c_str());
	int t; ifs >> t;
	for (int i = 0; i < t; i++) {
		ifs >> f; fill_formula();
		tuples t = min_op(0, f.size() - 1);
		int m = (t.zero < t.one) ? t.zero : t.one;
		ofs << "Case #" << i + 1 << ": " << (m >= 1) << endl;
	}
	ifs.close(); ofs.close();
	cin.ignore(2); return 0;
}