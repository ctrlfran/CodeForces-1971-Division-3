#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define ii pair<int, int>
#define pb push_back
#define INF INT_MAX
#define se second
#define fi first
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define str string
#define yes cout << "YES\n";
#define no cout << "NO\n";

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;

const int MOD = 1000000007;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxx(v) *max_element(v.begin(), v.end())
#define minn(v) *min_element(v.begin(), v.end())

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    str s;
    cin >> s;
    vec<int> p(n);
    int sp = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sp += p[i];
    }
    
    int t = x + y;
    if (t < sp) {
        no
        return;
    }
    
    int n0 = 0;
    for (char c : s) n0 += (c == '0');
    int n1 = n - n0;
    
    if (n0 && n1) {
        int amin = 0, bmin = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (s[i] == '0') amin += c;
            else bmin += c;
        }
        
        int maxa = t - bmin;
        if (x >= amin && x <= maxa) yes else no
        return;
    }
    
    if (n1 == 0) {
        int base = 0, k = 0;
        for (int i = 0; i < n; i++) {
            base += p[i] / 2 + 1;
            if ((p[i] & 1) == 0) k++;
        }
        
        int e = t - sp;
        int r = e - k;
        int add = 0;
        if (r > 0) add = (r + 1) / 2;
        int mina = base + add;
        if (x >= mina && x <= t) yes else no
        return;
    }
    
    int base = 0, k = 0;
    for (int i = 0; i < n; i++) {
        base += (p[i] - 1) / 2;
        if ((p[i] & 1) == 0) k++;
    }
    
    int e = t - sp;
    int m = min(e, k);
    if ((m & 1) != (e & 1)) m--;
    int inc = (e + m) / 2;
    int maxa = base + inc;
    if (x <= maxa) yes else no
}

signed main() {
    #ifdef LOCAL
    freopen("a2.txt","r", stdin);
    freopen("a2.txt","w", stdout);
    #endif LOCAL
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}