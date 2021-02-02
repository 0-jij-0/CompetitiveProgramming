#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { 
		string s; cin >> s; 
		v[i] = (s == "mumble") ? -1 : atoi(s.c_str());
	}

	n = (int)v.size(); vector<int> a(n); bool b = true;
	iota(a.begin(), a.end(), 1);
	for(int i = 0; i < n; i++)
		if (v[i] != -1 && v[i] != a[i]) { b = false; break; }

	cout << (b ? "makes sense" : "something is fishy") << endl;
	cin.ignore(2); return 0;
}