#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
bool zi, zj;

long long find_min_area() {
	long long vpref = 0, hpref = 0;
	long long maxv = 0, maxh = 0;
	int firstmv = 0, firstmh = 0, lastmv = 0, lastmh = 0;
	int lastzv = 0, lastzh = 0;
	bool canv = true, canh = true;
	for (int i = 0; i < (int)s.size(); i++) {
		char &c = s[i];
		if (c == 'W') {
			vpref--; if (vpref == -1) { 
				lastzv = i; vpref++; maxv++;
			}
		}
		else if (c == 'S') {
			vpref++; if (vpref > maxv) { firstmv = i; maxv = vpref; }
		}
		else if (c == 'A') {
			hpref--; if (hpref == -1) { lastzh = i; hpref++; maxh++; }
		}
		else {
			hpref++; if (hpref > maxv) { firstmh = i; maxh = hpref; }
		}
	}
	long long area = (maxv + 1)*(maxh + 1);
	long long mi = min(maxv, maxh), ma = max(maxv, maxh);
	if (mi > 1) {
		if (ma == maxv) {
			if (lastzh < firstmh || hpref != maxh) { area -= maxv + 1; }
		}
		else {
			if (lastzv < firstmv || vpref != maxv) { area -= maxh + 1; }
		}
	}
	else if (ma > 1) {
		if (mi == maxv) {
			if (lastzh < firstmh || hpref != maxh) { area -= maxv + 1; }
		}
		else {
			if (lastzv < firstmv || vpref != maxv) { area -= maxh + 1; }
		}
	}
	return area;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;		
		cout << find_min_area() << endl;
	}
	cin.ignore(2); return 0;
}