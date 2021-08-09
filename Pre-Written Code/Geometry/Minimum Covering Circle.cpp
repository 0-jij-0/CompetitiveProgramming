#include <algorithm> 
#include <assert.h> 
#include <iostream> 
#include <cmath> 
#include <vector> 
#include <iomanip>
using namespace std;
typedef double ld; 

struct Point { ld X, Y; };
struct Circle { Point C; ld R2; };

ld dist2(const Point& a, const Point& b) {
    ld dx = a.X - b.X, dy = a.Y - b.Y;
    return (dx * dx + dy * dy);
}

bool isInsideCircle(const Circle& c, const Point& p) {
    return dist2(c.C, p) <= c.R2;
} 

Point getCircleCenter(ld bx, ld by, ld cx, ld cy) {
    ld B = bx * bx + by * by;
    ld C = cx * cx + cy * cy;
    ld D = bx * cy - by * cx;
    return { (cy * B - by * C) / (2 * D),
             (bx * C - cx * B) / (2 * D) };
}

Circle circleFrom3Points(const Point& A, const Point& B, const Point& C) {
    Point I = getCircleCenter(B.X - A.X, B.Y - A.Y, C.X - A.X, C.Y - A.Y);
    I.X += A.X; I.Y += A.Y; return { I, dist2(I, A) };
}

Circle smallestCircleFrom2Points(const Point& A, const Point& B) {
    Point C = { (A.X + B.X) / 2.0, (A.Y + B.Y) / 2.0 };
    return { C, dist2(A, B) / 4.0 };
}
 
bool isValidCircle(const Circle& c, const vector<Point>& P) {
    for (const Point& p : P)
        if (!isInsideCircle(c, p))
            return false;
    return true;
}

Circle minEnclosingCircleTrivial(vector<Point>& P) {
    assert(P.size() <= 3);
    if (P.empty()) { return { { 0, 0 }, 0 }; }
    else if (P.size() == 1) { return { P[0], 0 }; }
    else if (P.size() == 2) { return smallestCircleFrom2Points(P[0], P[1]); }

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            Circle c = smallestCircleFrom2Points(P[i], P[j]);
            if (isValidCircle(c, P)) return c;
        }

    return circleFrom3Points(P[0], P[1], P[2]);
}

// Returns the MEC using Welzl's algorithm 
// Takes a set of input points P and a set R 
// points on the circle boundary. 
// n represents the number of points in P 
// that are not yet processed. 
Circle welzlHelper(vector<Point>& P, vector<Point> R, int n) {
    // Base case when all points processed or |R| = 3 
    if (n == 0 || R.size() == 3) { return minEnclosingCircleTrivial(R); }

    // Pick a random point randomly 
    int idx = rand() % n; Point p = P[idx];
    swap(P[idx], P[n - 1]);

    // Get the MEC circle d from the 
    // set of points P - {p} 
    Circle d = welzlHelper(P, R, n - 1);

    // If d contains p, return d 
    if (isInsideCircle(d, p)) { return d; }

    // Otherwise, must be on the boundary of the MEC 
    R.push_back(p);

    // Return the MEC for P - {p} and R U {p} 
    return welzlHelper(P, R, n - 1);
}

Circle minEnclosingCircle(const vector<Point>& P) {
    vector<Point> P_copy = P;
    random_shuffle(P_copy.begin(), P_copy.end());
    return welzlHelper(P_copy, {}, P_copy.size());
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin.ignore(2); return 0;
}