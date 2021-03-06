#include <iostream>
#include <string>
using namespace std;

int h, m;
string mirror = "015aa2aa8a";

bool valid(string H, string M) {
	if (H.size() == 1) { H.insert(H.begin(), '0'); }
	if (M.size() == 1) { M.insert(M.begin(), '0'); }
	swap(H[0], H[1]); swap(M[0], M[1]);
	if (mirror[H[0] - '0'] == 'a') { return false; }
	else { H[0] = mirror[H[0] - '0']; }
	if (mirror[H[1] - '0'] == 'a') { return false; }
	else { H[1] = mirror[H[1] - '0']; }
	if (mirror[M[0] - '0'] == 'a') { return false; }
	else { M[0] = mirror[M[0] - '0']; }
	if (mirror[M[1] - '0'] == 'a') { return false; }
	else { M[1] = mirror[M[1] - '0']; }
	return stoi(H) < m && stoi(M) < h;
}

int main() {
	int t; cin >> t; while (t--) {
		cin >> h >> m; string H(2, '0'), M(2, '0'); char c;
		cin >> H[0] >> H[1] >> c >> M[0] >> M[1];
		int a = stoi(H), b = stoi(M);
		while (!valid(to_string(a), to_string(b))) {
			a = (a + (b + 1) / m) % h;
			b = (b + 1) % m;
		}
		H = to_string(a); M = to_string(b);
		if (H.size() == 1) { H.insert(H.begin(), '0'); }
		if (M.size() == 1) { M.insert(M.begin(), '0'); }
		cout << H << ':' << M << '\n';
	}
	cin.ignore(2); return 0;
}