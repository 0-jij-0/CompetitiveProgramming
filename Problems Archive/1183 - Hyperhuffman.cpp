#include <fstream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ifstream ifs("huffman.in");
	ofstream ofs("huffman.out");

	int n; ifs >> n; ll res = 0;
	while (n--) { int x; ifs >> x; pq.push(x); }
	while (pq.size() != 1) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		res += x + y; pq.push(x + y);
	}
	ofs << res << endl; return 0;
}