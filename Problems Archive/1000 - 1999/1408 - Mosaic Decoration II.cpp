#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll w, h, a, b, m, c;
	cin >> w >> h >> a >> b >> m >> c;
	ll hor = (w + a - 1) / a, ver = (h + b - 1) / b;
	ll buy = (hor * ver + 9) / 10; buy *= m;
	ll cutW = (w % a != 0) * c * h;
	ll cutH = (h % b != 0) * c * w;
	cout << buy + cutW + cutH << '\n';
	cin.ignore(2); return 0;
}