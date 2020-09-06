void bfs(ll v, vec& costTable) {
    queue<ll> que;
    for (int i = 1; i <= n; i++) {
        costTable[i] = INF;
    }
    costTable[v] = 0;
    que.push(v);
    while (que.size()) {
        ll v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            ll nv = G[v][i];
            if (costTable[nv] > costTable[v] + 1) {
                costTable[nv] = costTable[v] + 1;
                que.push(nv);
            }
        }
    }
}

ll diameter() {
    // グローバルに配置されているグラフ G の直径を求める
    vec x(n);
    bfs(1, x);
    ll res = -INF, v = -1;
    for (int i = 1; i <= n; i++) {
        if (x[i] >= res) {
            res = x[i];
            v = i;
        }
    }
    bfs(v, x);
    res = -INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] >= res) {
            res = x[i];
        }
    }
    return res;
}