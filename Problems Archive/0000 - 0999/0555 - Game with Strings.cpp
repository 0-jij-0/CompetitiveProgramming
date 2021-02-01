#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> st;
string s;

int main() {
	cin >> s;  
	int n = (int)s.size();
	int res = 0, i = 0;

	for (int i = 0; i < n; i++) {
		if (st.empty()) { st.push(s[i]); continue; }
		if (st.top() == s[i]) { res++; st.pop(); }
		else { st.push(s[i]); }
	}

	cout << (res % 2 ? "Yes" : "No") << endl;
	cin.ignore(2); return 0;
}