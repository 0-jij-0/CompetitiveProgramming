#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

stack<int> st;
vector<bool> p;
string s;

int main() {
	int n, k; cin >> n >> k >> s; 
	p.resize(n, 1); int r = n - k;
	for (int i = 0; i < n; i++) {
		if (r == 0) { break; }
		if (s[i] == '(') { st.push(i); continue; }
		p[i] = 0; p[st.top()] = 0; st.pop(); r -= 2;
	}

	for (int i = 0; i < n; i++)
		if (p[i]) cout << s[i];

	cout << endl; cin.ignore(2); return 0;
}