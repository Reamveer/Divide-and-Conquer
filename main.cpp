#include <iostream>
#include <math.h>
using namespace std;

double P(int i, int j) {
    //Or anything else
    return 30-sqrt((i-5)*(i-5)+(j-5)*(j-5));
};

int n, m;

double f(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return -1;
    return P(i, j);
}

int find(int a, int b, int p, int q) {
    int r = (a + b) / 2, s = (p + q) / 2;

    if (f(r, s) < f(r + 1, s))
        return find(r + 1, b, p, q);
    if (f(r, s) < f(r - 1, s))
        return find(a, r - 1, p, q);
    if (f(r, s) < f(r, s + 1))
        return find(a, b, s + 1, q);
    if (f(r, s) < f(r, s - 1))
        return find(a, b, p, s - 1);

    return f(r, s);
}

int main() {
    cin >> n >> m;
    cout << find(0, n, 0, m) << std::endl;
}
