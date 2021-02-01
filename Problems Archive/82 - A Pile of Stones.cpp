#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n; cin >> n;
	stack<char> st;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '-' && st.empty()) { continue; }
		if (c == '-') { st.pop(); continue; }
		st.push(c);
	}
	cout << st.size() << endl;
	cin.ignore(2); return 0;
}