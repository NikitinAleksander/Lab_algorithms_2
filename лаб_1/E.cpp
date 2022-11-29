#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;


int main(){
  freopen("pathbge1.in", "r", stdin);
  freopen("pathbge1.out", "w", stdout);
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
  q.push(1);
  while(!q.empty()){
    x=q.front();
    q.pop();
    for(i=0;i<graf[x].size();i++){
      y=graf[x][i];
      if (!used[y]){
        used[y]=true;
        q.push(y);
        d[y]=d[x]+1;
      }
    }
  }
  for(i=1;i<=n;i++){
    cout<<d[i]<<" ";
  }

}
