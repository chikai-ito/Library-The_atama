
struct edge {ll to, cap, rev; };
vector<edge> G[500005];

void add_edge(ll from,ll to, ll cap){
    // fromからtoへの辺を貼る
    // 容量はcap
    G[from].pb((edge){to,cap,(ll)G[to].size()});
    G[to].pb((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(int v,int t,ll f){
    if(v == t)return f;
    used[v] = true;
    for(int i=0;i<G[v].size();i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(ll s,ll t){
    ll flow = 0;
    for(;;){
        memset(used,0,sizeof(used));
        ll f = dfs(s,t,INF);
        if(f == 0)return flow;
        flow += f;
    }
}