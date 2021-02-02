#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> sizes = { {"small", 0}, {"medium", 1}, {"large", 2} };
map<string, int> types;
vector<int> prices[3], res;
vector<string> names;

int main() {
	ifstream ifs("coffee.in");
	int t; ifs >> t;
	while (t--) {
		int c, p; ifs >> c >> p;
		prices[0].resize(c); prices[1].resize(c); prices[2].resize(c);
		names.resize(p); res.resize(p);
		for(int i = 0; i < c; i++) {
			string n; int s, m, l; ifs >> n >> s >> m >> l;
			prices[0][i] = s; prices[1][i] = m;
			prices[2][i] = l; types[n] = i;
		}
		for(int i = 0; i < p; i++) {
			string type, size; ifs >> names[i] >> size >> type;
			res[i] = prices[sizes[size]][types[type]] + 100 / p;
			if (res[i] % 5 == 1) { res[i]--; }
			if (res[i] % 5 == 4) { res[i]++; }
		}
		for (int i = 0; i < p; i++)
			cout << names[i] << ' ' << res[i] << endl;
	}
	cin.ignore(2); return 0;
}