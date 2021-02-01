#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

struct Car { string N; ll p, q, k; Car() {} };
struct Event { char T; ll c, d, s; Event() {} };

map<string, vector<Event>> M;
map<string, ll> res;
vector<Car> v; map<string, int> carId;

int main() {
	int t; cin >> t;
	while (t--) {
		res.clear(); M.clear(); carId.clear(); v.clear();
		int n, m; cin >> n >> m; v.resize(n); int id = 0;
		for (auto &x : v) { cin >> x.N >> x.p >> x.q >> x.k; carId[x.N] = id++; }
		for (int i = 0; i < m; i++) {
			int t; string spy; char T; cin >> t >> spy >> T;
			if (T == 'p') { 
				string C; cin >> C;	Event e; 
				e.T = T; e.c = carId[C];
				M[spy].push_back(e);
			}
			else if (T == 'r') {
				ll d; cin >> d; Event e;
				e.T = T; e.d = d;
				M[spy].push_back(e);
			}
			else if (T == 'a') {
				ll s; cin >> s; Event e;
				e.T = T; e.s = s;
				M[spy].push_back(e);
			}
		}
		for (auto &x : M) {
			int car = -1, ok = true; ll total = 0;
			for (auto &y : x.second) {
				if (y.T == 'p' && car != -1) { ok = false; break; }
				if (y.T == 'r' && car == -1) { ok = false; break; }
				if (y.T == 'a' && car == -1) { ok = false; break; }
				if (y.T == 'p') { car = y.c; total += v[car].q; continue; }
				if (y.T == 'r') { total += y.d * v[car].k; car = -1; continue; }
				if (y.T == 'a') { total += (y.s * v[car].p + 99) / 100; continue; }
			}
			if (!ok || car != -1) { res[x.first] = -1; }
			else { res[x.first] = total; }
		}
		for (auto &x : res) { cout << x.first << ' ' << (x.second == -1 ? "INCONSISTENT" : to_string(x.second)) << '\n'; }
	}
	cin.ignore(2); return 0;
}
