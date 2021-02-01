#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; int n; cin >> n >> s;
	int max = s[0] - 'a', cur = s[0] - 'a'; bool b = false;
	unsigned int i = 0, max_idx = 0;
	for (; i < s.size(); i++) {
		cur = s[i] - 'a';
		if (cur > max) { max = cur; max_idx = i; continue; }
		else if (cur == max) { continue; }
		else { b = true; break; }
	}
	if (b) {
		cout << "YES" << endl;
		cout << max_idx + 1 << " " << i + 1 << endl;
	}
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}