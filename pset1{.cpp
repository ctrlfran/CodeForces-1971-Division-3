#include  <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long total = 0;
        for (int i = 0; i + 1 < n; i++) {
            total += abs(a[i] - a[i + 1]);
        }

        long long bestReduction = 0;
        for (int i = 1; i + 1 < n; i++) {
            long long before =
                abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
            long long after =
                abs(a[i - 1] - a[i + 1]);
            bestReduction = max(bestReduction, before - after);
        }

        cout << total - bestReduction << '\n';
    }
    return 0;
}