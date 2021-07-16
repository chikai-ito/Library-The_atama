
const int MAX_V = 100000;

struct PrimalDual {
    struct edge {
        int to;
        ll cap;
        ll cost;
        int rev;
        bool isrev;
    };
    vector< vector< edge > > graph;
    vector< ll > potential, min_cost;
    vector< int > prevv, preve;

    PrimalDual(int V) : graph(V) {}

    void add_edge(int from, int to, ll cap, ll cost) {
        graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
        graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
    }

    ll min_cost_flow(int s, int t, ll f) {
        int V = (int) graph.size();
        ll ret = 0;
        using Pi = pair< ll, int >;
        priority_queue< Pi, vector< Pi >, greater< Pi > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while (!que.empty()) {
                Pi p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    ll nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if (min_cost[t] == INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            ll addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }
};

// PrimalDual< int, int > flow(N * M + 2);