#include <fstream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

vector<int> resp;
priority_queue<pair<int, int>> q;

int main() {
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int n, m, y, f, ideal; 
	ifs >> n >> m >> y;
	resp.resize(n);
	for(int i = 0; i < n; i++) {
		ifs >> f; ideal = f * m;
		q.push({ ideal, i });
	}
	pair<int, int> ok; 
	while (m--) {
		ok = q.top(); q.pop();
		ok.first -= y; resp[ok.second]++;
		q.push(ok);
	}
	for (auto &x : resp) ofs << x << ' '; ofs << '\n';
}