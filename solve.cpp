#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,x,y,out[N],d[N],v[N];
vector<int>rg[N];
priority_queue<pair<int,int> >q;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),out[x]++,rg[y].push_back(x);
	memset(d,0x3f,sizeof(d)),d[n]=0,q.push({0,n});
	while(q.size()){
		int y=q.top().second;q.pop();
		if(v[y]) continue;
		v[y]=1;
		for(int x:rg[y]){
			if(d[x]>d[y]+out[x]) d[x]=d[y]+out[x],q.push({-d[x],x});
			out[x]--;
		}
	}
	printf("%d\n",d[1]);
	return 0;
}