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
int powerundermodp(int x, ll y, ll  p){int res = 1;x = x % p;if (x == 0) return 0; while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


/*----------------------------------------------------------------------------------------------------------------------------------*/

struct node 
{
	int u,v,wt;
	node(int u_,int v_,int wt_)
	{
		u=u_;
		v=v_;
		wt=wt_;
	}
};

void solve()
{
	int n,m,q;
	int a,b,c;
	cin>>n>>m;
    vector<node> edge;
    vector<lli> dist(n+1,INT_MAX);
    vi par(n+1,0);
    // par[1]=1;
    dist[1]=0;
  rep(i,m)
  {
  	cin>>a>>b>>c;
  	edge.pb(node(a,b,c));
  }

 // ll ans=0;
  int till=1;
  for(int k=1;k<=n;k++)
  {
     for(auto it:edge)
     {     		
     	if(dist[it.v]>dist[it.u]+it.wt)
     	{	
     		dist[it.v]=dist[it.u]+it.wt;
     		par[it.v]=it.u;
     	}
     }
  }


    bool ok=true;
   for(auto it:edge)
    {

     	if(dist[it.v]>dist[it.u]+it.wt)
     	{
     		ok=false;
     		till=it.v;
     		break;
     	}
     	
    }
 
 // cout<<till;

// printvi(par);
// cout<<"\n";


    if(ok==false)
    {
    	cout<<"YES\n";
    	int x=till;
    	int y=x;
    	// cout<<till<<'\n';
    	for(int i=1;i<=n;i++)
    		y=par[y];

    	// cout<<y<<"\n";

    	 vector<int> path;
        for (int cur=y;; cur=par[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
            break;
        }
         reverse (path.begin(), path.end());
         printvi(path);
    }
    else
    cout<<"NO";
}


int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
 
int  t=1;
 
// cin>>t;
 
while(t--)
{
    solve();
    cout<<"\n";    
}
 
}