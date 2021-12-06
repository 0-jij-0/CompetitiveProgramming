#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    freopen("fouad.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x, y; cin >> x >> y;
    cout << min(x, y) << '\n';
}
