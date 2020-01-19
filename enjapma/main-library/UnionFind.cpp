#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll parent[500005], sizes[500005];

void init(ll n){
	for(ll i=0;i<=n;i++){
		parent[i] = i;
	}
}
ll find(ll x){
	if(parent[x] == x){
		return x;
	}else{
		return parent[x] = find(parent[x]);
	}
}

void unite(ll x,ll y){
	x = find(x);
	y = find(y);
	if(x == y)return;
	if(sizes[x] < sizes[y])swap(x, y);

	parent[y] = x;
	sizes[x] += sizes[y];
}

bool same(ll x,ll y){
	return find(x) == find(y);
}

ll size(ll x){
	return sizes[find(x)];
}

int main(){
	ll n, q;
	cin >> n >> q;
	init(n);
	for(ll i=0;i<q;i++){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a == 0){
			unite(b, c);
		}else{
			if(same(b, c)){
				cout << 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}