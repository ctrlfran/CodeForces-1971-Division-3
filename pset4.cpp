#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define pb push_back

void solve() {
    int n;
    cin >> n;
    
    static bool ready = false;
    static vec<vec<int>> store(17);
    
    if (!ready) {
        for (int i = 0; i < 17; i++) store[i].clear();
        store[0] = {0};
        
        for (int lvl = 1; lvl <= 16; lvl++) {
            vec<int> temp;
            temp.reserve(store[lvl - 1].size() + (1 << lvl));
            
            for (int val : store[lvl - 1]) {
                temp.pb(val * 2 + 1);
            }
            
            for (int x = 0; x < (1 << lvl); x += 2) {
                temp.pb(x);
            }
            
            store[lvl] = temp;
        }
        ready = true;
    }
    
    for (int v : store[n])
        cout << v << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}