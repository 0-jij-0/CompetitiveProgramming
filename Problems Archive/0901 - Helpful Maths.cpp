#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

vector<int> v;

int main() {
	string s; cin >> s; stringstream ss(s);
	int x; while (ss >> x) { v.push_back(x); char c; ss >> c; }
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size() - 1; i++) { cout << v[i] << '+'; }
	cout << v.back() << '\n'; cin.ignore(2); return 0;
}