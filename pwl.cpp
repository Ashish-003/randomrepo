#include<bits/stdc++.h>
using namespace std;
//#define ll long long int
#define inf 1e16+9
long long int ans = inf,edges,n;
pair<long long int,pair<long long int,long long int >> adj[10005];
long long int pt[100005];
long long int roota(long long int root[],long long int i){
if(root[i] != i)
		return root[i] = roota(root,root[i]);
	return i;
}
int onion(long long int root[],long long int a,long long int b){
	long long int x,y;
	x = roota(root,a);
	y = roota(root,b);
	root[x] = root[y];
	return 0;
}
long long int kruskal(long long int root[],pair<long long int,pair<long long int,long long int>>p[]){
	long long int x,y,mini,cost,i,j,h;
	mini = 0;
	h= 0;
	
	for(j = 0;j<n;j++){
			root[j] = j;
		}
	for(i = 0;i<edges;i++){
		y = p[i].second.second;
		cost = p[i].first;
		x = p[i].second.first;
		if(roota(root,x) != roota(root,y)){
			mini += cost;
			onion(root,x,y);
			h++;
		}

	}
	if(h==n-1)
	return mini;
	else{
		return inf;
	}
}
long long int loga(long long int x){
	return 64 - __builtin_clzll(x);
}
int main(){
	pair<long long int,pair<long long int,long long int>>p[100005];
	long long int m,x,i,j,k,l,pot,cost,curr,total,flag,xi,newe;
	scanf("%lld %lld %lld",&n,&m,&x);
	long long int root[n+2];
	total = 0;
	xi = loga(x);
	//printf("%lld\n",xi);
	for(i = 0;i<m;i++){

		scanf("%lld %lld %lld %lld",&k,&l,&pot,&cost);
		if(pot>x){
			adj[total] = make_pair(cost,make_pair(k,l));
			pt[total] = pot;
			total++;
		}
		//adj[l].push_back(make_pair(k,make_pair(pot,cost)));
	}
	sort(adj,adj+total);
	edges = 0;
	flag= 0;
	newe = 0;

	for(i = 20;i>=xi;i--){
		edges = 0;
		for(j = 0;j<total;j++){
			if(pt[j]&(1<<i)){
				p[edges] = make_pair(adj[j].first,make_pair(adj[j].second.first,adj[j].second.second));
				edges++;
				
			}
			//printf("j%lld  %lld\n",j,pt[j]);
		}
		
		//printf("i %lld\n",i);
		///for(j = 0;j<edges;j++){
			//printf("cost %lld k %lld l%lld\n",adj[j].first,adj[j].second.first,adj[j].second.second);		}
		curr = kruskal(root,p);
		ans = min(curr,ans);
	}
	for(i = xi -1;i>=0;i--){
		if((1<<i)&x){

			for(j = 0;j<total;j++){
				if((1<<i)&pt[j]){
					adj[newe] = make_pair(adj[j].first,make_pair(adj[j].second.first,adj[j].second.second));
					pt[newe] = pt[j];
					newe++;
					//printf("%lld\n",adj[j].second.second);
				}
			}
			total = newe;
			newe = 0;
		}
		else{
			edges  = 0;
			for(j=0;j<total;j++){
				if((1<<i)&pt[j]){
					p[edges] = make_pair(adj[j].first,make_pair(adj[j].second.first,adj[j].second.second));
					edges++;
				}
			}
			curr = kruskal(root,p);
			ans = min(curr,ans);
		}
	}
	/*for(i = 0;i<= n;i++){
	  for(j = 0;j<adj[i].size();j++){
	  printf("%lld --> %lld pot %lld cost %lld\n",i,adj[i][j].first,adj[i][j].second.first,adj[i][j].second.second);
	  }
	  printf("\n");
	  }*/
	if(ans == inf){
		printf("-1");
	}
	else{
		printf("%lld",ans);
	}
	return 0;
}
