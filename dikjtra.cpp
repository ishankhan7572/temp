#include <bits/stdc++.h>
using namespace std;
 
// YOU HAVEN'T COME THIS FAR TO , ONLY COME THIS FAR
 
typedef long long int lli;
typedef long long ll;
typedef vector< int > vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
 
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
 
int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};
 
bool dfs(int node,int par,vector<int> adj[],vector<bool> &vis,vi &tmp,int &till)
{
	vis[node]=1;
	tmp.pb(node);
	for(int i:adj[node])
	{
		if(!vis[i])
		{
			if(dfs(i,node,adj,vis,tmp,till))
				return true;
		}
		else if(i!=par)
		{
            till =i;
			// cout<< i<<" "<<par;
			return true;
		}
	}
 
     tmp.pop_back();
	return false;
 
 
 
}
 
void solve()
{
	lli n,m;
	cin>>n>>m;
	vector<pii> adj[n+1];
 
	vector<bool> vis(n+1,false);
	vector<lli> dist(n+1,1e16);
	dist[1]=0;
 
    lli a,b,c;
	rep(i,m)
	{
		cin>>a>>b>>c;
		adj[a].pb({b,c});
 
	}
  priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli> > > pq;
  pq.push({0,1});
  
  // vis[1]=1;
 
  while(!pq.empty())
  {
  	lli di=pq.top().ff;
  	lli prev=pq.top().ss;
  	pq.pop();
  	if(vis[prev])
  	continue;
 
  	vis[prev]=1;
 
  	 for(auto it:adj[prev])
  	 {
  	 	lli next=it.ff;
  	 	lli next_dist=it.ss;
  	 	if( dist[prev]+next_dist<dist[next])
  	 	{
  	 		
         dist[next]=dist[prev]+next_dist;
         pq.push({dist[next],next});
       
  	 	}
  	 }
  }
 
for(int i=1;i<=n;i++)
cout<<dist[i]<<" ";
 
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
