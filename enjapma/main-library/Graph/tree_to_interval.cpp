// par := その頂点から見た時の親
// tin := その頂点を親とする部分木の左端 (閉区間), その頂点の場所
// tout := その頂点を親とする部分木の右端 (閉区間)
// euler := 頂点番号を区間みたいに並べたもの



void dfs(int v, int p = -1) {
    par[v] = p;
    tin[v] = c;
    euler[c++] = v;

    for (int i : adj[v]) {
        if (i == p)
            continue;
        dfs(i, v);
        euler[c++] = v;
    }

    tout[v] = c - 1;
}