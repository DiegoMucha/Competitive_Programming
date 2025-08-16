#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define emset(arr, val) memset(arr, val, sizeof(arr))
#define fora(it, ini, cns) for(int it = ini; it < cns; it++)
#define ford(it, ini, cns) for(int it = ini; it > cns; it--)
#define forai(it, ini, cns, aug) for(int it = ini; it < cns; it+= aug)
#define fordi(it, ini, cns, dec) for(int it = ini; it > cns; it-=dec)

const int MAXN = 200001;
 
void solve() {
    
}
 
int32_t main() {FIN;
    int n; cin >> n;
    vector<int> potions(n);
    int max_eli = 0;
    for (int i = 0; i < n; i++) {
       cin >> potions[i];
    } 
    int health = 0;
    int ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (potions[i] >= 0) {
            health += potions[i];
            ans++;
        }   
        else {
            if (potions[i] + health >= 0) {
                health += potions[i];
                ans++;
                pq.push(abs(potions[i]));           
            }
            else {
                if (pq.size() && pq.top() >= abs(potions[i])) {
                    health += pq.top();
                    health += potions[i];
                    pq.pop();
                    pq.push(abs(potions[i]));
                }
            }
        }
    }
    cout << ans;
}