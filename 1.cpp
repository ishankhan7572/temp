#include <bits/stdc++.h>
using namespace std;
 
// YOU HAVEN'T COME THIS FAR TO , ONLY COME THIS FAR
 
typedef long long int lli;
typedef long long ll;
typedef vector< int > vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair< int,int > pii;

const ll inf = LLONG_MAX;
const ll modi=1e9+7;
 
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i,k,n) for(int i = k; i <n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
 
#define pb push_back
#define all(a) a.begin(),a.end()
#define  ff first 
#define  ss second
 
// __builtin_popcount -> count number of set bits
 
ll ceil_div(ll a,ll b){return (a%b==0)? a/b :a/b+1 ;}
void printvi(vector<int> &v){for(int &i:v)cout<<i<<" ";}
bool is_pow_of_2(int n){if(n&(n-1))return false;return true;}
bool isPlaindrome(string s){int n=s.length(),i=0,j=n-1;while(i<j){if(s[i]==s[j]){i++;j--;}else return false;}return true;}

// for directed weighted graph 
// source as '1'
void dikForWighDirec(){lli n,m;cin>>n>>m;vector<pii> adj[n+1];vector<bool> vis(n+1,false);vector<lli> dist(n+1,1e16);dist[1]=0;lli a,b,c;rep(i,m){cin>>a>>b>>c;adj[a].pb({b,c});}priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli> > > pq;pq.push({0,1});while(!pq.empty()){lli di=pq.top().ff;lli prev=pq.top().ss;pq.pop();if(vis[prev])continue;vis[prev]=1;for(auto it:adj[prev]){lli next=it.ff;lli next_dist=it.ss;if( dist[prev]+next_dist<dist[next]){dist[next]=dist[prev]+next_dist;pq.push({dist[next],next});}}}for(int i=1;i<=n;i++)cout<<dist[i]<<" ";} 
// for undirected weighted graph
// source as '1' 
void dikForWighUndirec(){lli n,m;cin>>n>>m;vector<pii> adj[n+1];vector<bool> vis(n+1,false);vector<lli> dist(n+1,1e16);dist[1]=0;lli a,b,c;rep(i,m){cin>>a>>b>>c;adj[a].pb({b,c});adj[b].pb({a,c});}priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli> > > pq;pq.push({0,1});while(!pq.empty()){lli di=pq.top().ff;lli prev=pq.top().ss;pq.pop();if(vis[prev])continue;vis[prev]=1;for(auto it:adj[prev]){lli next=it.ff;lli next_dist=it.ss;if( dist[prev]+next_dist<dist[next]){dist[next]=dist[prev]+next_dist;pq.push({dist[next],next});}}}for(int i=1;i<=n;i++)cout<<dist[i]<<" ";} 
 
// (x^y)%p  
ll  powerundermodp(ll x, ll y, ll  p){ll res = 1;x = x % p;if (x == 0) return 0; while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


/*----------------------------------------------------------------------------------------------------------------------------------*/

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int child = 0; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); 
	    child++; 
            if(low[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
    
    if(parent == -1 && child > 1) {
        isArticulation[node] = 1; 
    }
}

bool solve()
{
	int n, m;
    cin >> n >> m; 
       if(n==0 && m==0)
    return false;

	vector<int> adj[n]; 
	bool ok=true;
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    
	    u--,v--;
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	int count=0;
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) 
	    count++;

	}

	cout<<count;
	return (ok);
	// return true;


}


int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);

int  t=1e6;
 
// cin>>t;
 
while(t--)
{
    if(!solve())
    break;
    	// continue;
    // else
    // break;
    cout<<"\n";    
}
 
}