#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll INF = 3e18;
ll cost[500005];
vector<P> G[500005];
priority_queue<P, vector<P>, greater<P>> pqps;
ll n, m, k;
ll a, b, c;
ll i;

int main() {
    cin >> n >> m >> k;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back(P(b, c));
    }
    for (i = 0; i < n; i++) {
        cost[i] = INF;
    }
    pqps.push(P(0, k));
    cost[k] = 0;
    while (!pqps.empty()) {
        auto [nowcost, v] = pqps.top();
        pqps.pop();
        if (nowcost > cost[v]) continue;
        for (auto [nv, edgecost] : G[v]) {
            ll newcost = edgecost + cost[v];
            if (cost[nv] > newcost) {
                cost[nv] = newcost;
                pqps.push(P(newcost, nv));
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (cost[i] == INF) {
            cout << "INF"
                 << "\n";
        } else {
            cout << cost[i] << "\n";
        }
    }
    return 0;
}