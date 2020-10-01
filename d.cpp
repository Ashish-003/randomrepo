																//  SMOKE SHISHA PLAY FIFA  // 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define mod 1000000007
#define lp(i,start,end) for(ll i=start;i<=end;i++) 
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
	ll t;
	cin >> t;
	while(t--)
	{
		//binary search 
		ll n,x;
		cin>>n>>x;
		ll a[n];
		lp(i,0,n-1)
		cin>>a[i];
		sort(a,a+n);
		ll mi=0, ma=n,m;
		while(mi<=ma){
			m=(mi+ma)/2;
			if(a[m]<x)
				mi=m+1;
			else
				ma=m-1;
		}
		cout<<a[m]<<endl;

	}
	return 0;	
}
