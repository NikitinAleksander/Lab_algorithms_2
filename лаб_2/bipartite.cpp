#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
  freopen("bipartite.in", "r", stdin);
  freopen("bipartite.out", "w", stdout);
  int n,m,i,j,x,y;
  cin>>n>>m;
  vector<int> graf[n+1];
  for(i=0;i<m;i++){
    cin>>x>>y;
    graf[x].push_back(y);
    graf[y].push_back(x);
  }
  vector<bool> used(n+1);
  vector<int> d(n+1);
  queue<int> q;
  for (i=0;i<=n;i++){
    used[i]=false;
    d[i]=0;
  }
  used[1]=true;
  bool flag=1;
  q.push(1);
  d[1]=1;
  j=n+1;
  while((!q.empty())||(j<=n)){
    /*if(q.empty()){

      while((j<=n)){
        j++;
        if(!used[j]){
          break;
        }
        if(j==n+1){
          break;
        }
      }
      x=j;
      if(j==n+1){
        x=-1;
      }
    }else{*/
    x=q.front();
    q.pop();
//  }
  if(x==-1){
    break;
  }
  //cout<<x<<endl;
    for(i=0;i<graf[x].size();i++){

      y=graf[x][i];
      //cout<<" "<<y<<endl;
      if(d[x]==0){
        d[x]=1;
      }
      if(d[y]==0){
        if(d[x]==1){
          d[y]=2;
        }
        if(d[x]==2){
          d[y]=1;
        }
      }
        if(d[y]==d[x]){
          flag=0;
      }
      if (!used[y]){
        used[y]=true;
        q.push(y);

      }
    }
  }
/*  if(flag){
  for(i=1;i<=n;i++){
    if (d[i]==0){
      flag=0;
    }
  }
}*/
  if(flag){
    /*for(i=0;i<=n;i++){
      cout<<d[i]<<" ";
    }*/
    cout<<"YES";
  }else{
    cout<<"NO";
  }
}
