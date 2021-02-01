#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b; int n;
vector<int> v;

bool check() {
	if (a.size() != b.size()) { return false; }
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) v.push_back(i);
	if (v.size() != 2) { return false; }
	return a[v[0]] == b[v[1]] && a[v[1]] == b[v[0]];
}

int main() {
	cin >> a >> b; n = (int)a.size();
	cout << (check() ? "YES" : "NO")<< endl;
	cin.ignore(2); return 0;
}