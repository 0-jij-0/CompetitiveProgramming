#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<set<int>> v;

int firstQuery(int n) { //Finds Max of Array
	string query = "? " + to_string(n);
	for (int i = 1; i <= n; i++) { query += " " + to_string(i); }
	cout << query << endl; int res; cin >> res; return res;
}

int lastQuery(int n, int idx) { //Finds Max among all indices except v[idx]
	string query = "? " + to_string(n - v[idx].size());
	for (int i = 1; i <= n; i++) if (!v[idx].count(i)) query += " " + to_string(i);
	cout << query << endl; int res; cin >> res; return res;
}

void printRes(int k, int idx, int max, int other) { //Prints the result of the problem
	string res = "!";
	for (int i = 0; i < k; i++) res += " " + to_string(i == idx ? other: max);
	cout << res << endl;
}

int intermQuery(int l, int r) { //Finds max of indices in {v[l], ..., v[r]}
	string query = "? ", queryNums = ""; int qS = 0;
	for (int i = l; i <= r; i++) {
		qS += v[i].size();
		for (auto &x : v[i]) queryNums += " " + to_string(x);
	}
	query += to_string(qS) + queryNums;
	cout << query << endl; int res; cin >> res; return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		v.clear(); v.resize(k);
		for (auto &x : v) {
			int c; cin >> c; 
			while (c--) { int a; cin >> a; x.insert(a); }
		}
		int max = firstQuery(n), l = 0, r = k - 1;
		while (l != r) {
			int mid = (l + r) >> 1;
			bool b = intermQuery(l, mid) == max;
			b ? r = mid : l = mid + 1;
		}
		int other = lastQuery(n, l); printRes(k, l, max, other);
		string str; cin >> str;
	}
	return 0;
}