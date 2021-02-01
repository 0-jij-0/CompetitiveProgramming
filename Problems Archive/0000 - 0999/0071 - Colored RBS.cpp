#include <iostream>
#include <string>
using namespace std;

int depth(string &rbs) {
	int d = 0, max_d = 0;
	for (unsigned int i = 0; i < rbs.size(); i++) {
		if (rbs[i] == '(') { 
			d++; if (d > max_d) { max_d = d; }
		}
		else { d--; }
	}
	return max_d;
}

void color_rbs(string &rbs) {
	int d = depth(rbs);
	int m = (d + 1) / 2;
	string res = "";
	int blue = 0, red = 0;
	for (unsigned int i = 0; i < rbs.size(); i++) {
		if (rbs[i] == '(' && blue < m) { res.push_back('0'); blue++; continue; }
		if (rbs[i] == '(') { res.push_back('1'); red++; continue; }
		if (rbs[i] == ')' && red != 0) { res.push_back('1'); red--; continue; }
		if (rbs[i] == ')') { res.push_back('0'); blue--; continue; }
	}
	cout << res << endl;
}

int main() {
	int n; string s; cin >> n >> s;
	color_rbs(s);
	return 0;
}

