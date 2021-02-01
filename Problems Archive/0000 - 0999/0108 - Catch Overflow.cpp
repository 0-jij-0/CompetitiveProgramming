#include <iostream>
#include <stack>
#include <climits>
#include <string>
using namespace std;

unsigned long long inf = UINT32_MAX;

int main() {
	int n; cin >> n;
	stack<int> st;
	unsigned long long prod = 1, res = 0; 
	bool overflow = false;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "end") { prod /= st.top(); st.pop(); continue; }
		if (s == "for") {
			unsigned int a; cin >> a;
			st.push(a); prod *= a;
			if (prod > inf) {
				int end_c = 1;
				while (i < n && end_c != 0) {
					string s1; cin >> s1;
					if (s1 == "add") { overflow = true; }
					else if (s1 == "for") { int a; cin >> a; end_c++; }
					else if (s1 == "end") {
						if (end_c != 1) { end_c--; continue; }
						prod /= st.top(); st.pop(); end_c--;
					}
					i++;
				}
			}
			continue;
		}
		if (s == "add") {
			res += prod; inf -= prod;
			if (res > UINT32_MAX) { overflow = true; }
			continue;
		}
	}
	if (overflow) { cout << "OVERFLOW!!!" << endl; }
	else { cout << res << endl; }
	cin.ignore(2); return 0;
}