#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> st = { "ABC", "ARC", "AGC", "AHC" };

int main() {
	for (int i = 0; i < 3; i++) {
		string s; cin >> s; st.erase(s);
	}
	cout << *st.begin() << '\n';
	cin.ignore(2); return 0;
}