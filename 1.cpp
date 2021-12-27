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

// (x^y)%p  
ll  powerundermodp(ll x, ll y, ll  p){ll res = 1;x = x % p;if (x == 0) return 0; while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

/*----------------------------------------------------------------------------------------------------------------------------------*/

//give the limit for prime number
const int szOfSeieve=1e6;
vector<bool > vis(szOfSeieve,true);

void seive()
{
	for(int i=2;i<=szOfSeieve;i++)
	{

		if(vis[i])
		{
			for(ll j=(ll)i*i;j<=szOfSeieve;j+=i)
			vis[j]=false;
			
		}
	}
}

void  solve()
{
	int n;
	cin>>n;
    int ind=2;
	for(int i=0;i<n;i++)
	{
		while(ind<szOfSeieve &&  vis[ind]==false)
		{
			ind++;
		}
		cout<<ind<<" ";
		ind++;

	}

}


int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);

seive();
int  t=1;
 
// cin>>t;
 
while(t--)
{
    solve();
    cout<<"\n";    
}
 

}