
#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 5000000;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";

#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 

// how to use
//
// write simple code which solve problem and print answer

ll n, m, k, num, sum, ans, a, b, c, d, e, g, h, l, q, r;
ll x[300000], y[500005], z[500005], w[500005];
ll dp[1005][10];

int main(){
	cin >> n >> m;
    for(ll i=0;i<n;i++){
        cin >> x[i];
    }
    for(ll i=0;i<m;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a)
    }
	return 0;
}
 
 









