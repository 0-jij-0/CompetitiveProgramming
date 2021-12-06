#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    freopen("apples.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,x, y; cin >> n >> x >> y;
    int S = 0, M = 0, L = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ((a <= x) ? S : (a <= y ? M : L))++;
    }
    cout << S << ' ' << M << ' ' << L << '\n';
}