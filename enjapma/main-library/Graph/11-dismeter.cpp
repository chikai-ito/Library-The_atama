// 辺に重みがある場合
P dfs(int v, int p) {
    // (最も遠い頂点, 最も遠い距離)
    int r = v, dis = 0;
    for (auto [nv, length] : G[v]) {
        if (nv == p) continue;
        auto [fr, fdis] = dfs(nv, v);
        fdis += length;
        if (fdis > dis) {
            dis = fdis;
            r = fr;
        }
    }
    return P(r, dis);
}

// 辺に重みがない場合
P dfs(int v, int p) {
    int r = v, dis = 0;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        auto [fr, fdis] = dfs(nv, v);
        fdis++;
        if (fdis > dis) {
            dis = fdis;
            r = fr;
        }
    }
    return P(r, dis);
}
