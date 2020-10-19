#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
ll h;
unordered_map<ll,pair<ll,pair<ll,ll>>>adj;
#define ho 1000000007
long long int roota(long long int i){
	ll x;
	if(adj[i].second.first != i){
		x = adj[i].second.first;
		adj[i].second.first = roota(x);
		adj[i].first = adj[i].first^adj[x].first;
		return adj[i].second.first;;
		}
	return i;
}
int onion(long long int a,long long int b,ll wt){
	long long int x,y;
	x = roota(a);
	y = roota(b);
	if(adj[x].second.second<adj[y].second.second){
		adj[x].second.first = adj[y].second.first;
		adj[y].second.second += adj[x].second.second;
		adj[x].first  = (adj[a].first)^wt^(adj[b].first);
	}
	else{
		adj[y].second.first = adj[x].second.first;
		adj[x].second.second += adj[y].second.second;
		adj[y].first  = (adj[a].first)^wt^(adj[b].first);
	}
	return 0;
}
ll moda(ll y){
	ll ans = 1 ,x;
	x = 2;
	//printf("y %lld\n",y );
	while(y>0){
		if(y&1){
			ans = (ans*x)%(ho-1);
		}
			y = y>>1;
			x = (x*x)%(ho-1);
	}
	ans  = ans%(ho-1);
	//printf(" %llddfg\n",ans );
	return ans;
}
ll mods(ll y){
	ll ans = 1 , x;
	x = h;
	y = y%(ho-1);
	while(y>0){
		if(y&1){
			ans = (ans*x)%ho;
		}
			y = y>>1;
			x = (x*x)%ho;
	}
	ans  = ans%ho;
	return ans;

}
int main(){
	ll n,m,k,x,a,b,wt,i,j,flag = 0, count,ans,ans2;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&h);
	ans  = 1;
	ll aaya;
	count = n+m-1;
	for(i = 0;i<k;i++){
		scanf("%lld %lld %lld",&a,&b,&wt);
		if(flag)
			continue;
		b = b+n;
		if(adj.count(a) == 0)
			adj[a] = make_pair(0,make_pair(a,1));
		if(adj.count(b) == 0)
			adj[b] = make_pair(0,make_pair(b,1));
		if(roota(a)!=roota(b)){
			onion(a,b,wt);
			count--;
		}
		else{
			if(wt != (ll)(adj[a].first^adj[b].first) ){
				flag = 1;
			   //printf("wt %lld xor%lld %lld %lld %lld %lld \n ",wt,xora[a]^xora[b],a,b,xora[a],xora[b]);
			}
		}
		if(flag)
			continue;
		if(count >= 0){
		
			aaya  = moda(count * 30);
			//printf(" d %lld %lld\n",count,aaya);
			ans = (ans*mods(aaya))%ho;
			// cout << aaya << endl;
		}
	}
		/*ans = moda(count);
		printf("jaa %lld\n",ans);*/
	printf("%lld\n",ans);
	return 0;
}