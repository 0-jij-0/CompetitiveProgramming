#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

map<int, int> DP;
vector<int> v;

void LCIS() {
	for (unsigned int i = 0; i < v.size(); i++) {
		int n = v[i];
		int a = DP[n], b = 1 + DP[n - 1];
		DP[n] = (a > b) ? a : b;
	}

	int num = 0, max = 0;
	map<int, int>::iterator it = DP.begin();
	for (; it != DP.end(); it++) {
		if (it->second > max) {
			max = it->second; num = it->first;
		}
	}
	cout << max << endl;
	stack<int> s;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == num) { s.push(i); num--; }
	}
	while (true) {
		int a = s.top(); s.pop();
		cout << a + 1;
		if (!s.empty()) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	LCIS();
	cin.ignore(2); return 0;
}