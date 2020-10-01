																//  SMOKE SHISHA PLAY FIFA  // 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
#define lp(start,end) for(ll i=start;i<=end;i++) 
#define deb1(a) cout<<#a<<" = "<<(a)<<endl;
#define deb2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define deb3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;


ll modu(ll a, ll b)
{
	ll ans =1;
	while(b>0)
	{
		if(b&1)
		ans = (ans*a)%mod;
		b/=2;
		a = (a*a)%mod;
	}
	return ans;
}

int main()
{
	fastio
	ll tt;
	cin >> tt;
	while(tt--)
	{
		
			// a^b%m for large values of a and b
			ll a,b;
			cin>>a>>b;
			ll res;
			res=modu(a,b);
			cout<<res<<endl;
	
	}
	return 0;	
}
