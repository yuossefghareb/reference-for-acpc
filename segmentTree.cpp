#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N];

struct {
    int seg[4 * N];
    void build(int l, int r, int x) {
        if (l == r) {
            seg[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * x + 1);
        build(m + 1, r, 2 * x + 2);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2]; 
    }
    void update(int l, int r, int x, int i, int v) {
        if (l == r) {
            seg[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            update(l, m, 2 * x + 1, i, v);
        } else {
            update(m + 1, r, 2 * x + 2, i, v);
        }
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    int query(int l, int r, int x, int ql, int qr) {
        if (qr < l or r < ql)
            return 0;  //  0 or IntMax or INTMIN
        if (ql <= l and r <= qr)
            return seg[x];
        int m = (l + r) / 2;
        int ans1 = query(l, m, 2 * x + 1, ql, qr);
        int ans2 = query(m + 1, r, 2 * x + 2, ql, qr);
        return ans1 + ans2;
    }
} seg;

int main() {
  
    return 0;
}
