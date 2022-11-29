#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

struct node{
  char x;
  short int prev;
  char y;
};

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,m,i,S,T;

  cin>>n>>m;

  node a[n*m];
  vector<bool> used(n*m);
  bool flag=0;
  queue<int> q;

  for(i=0;i<n*m;i++){
      cin>>a[i].x;

      if(a[i].x=='S'){
        S=i;
      }

      if(a[i].x=='T'){
        T=i;
      }
  }

  q.push(S);

  while((!q.empty())&&(!flag)){
    i=q.front();
    q.pop();

    if(i==T){
      flag=1;
      break;
    }

    if(!used[i]){
      if((i>=m)&&(a[i-m].x!='#')){
        q.push(i-m);
        if(!used[i-m]){
          a[i-m].prev=i;
          a[i-m].y='U';
        }
      }

      if((i<(n-1)*m)&&(a[i+m].x!='#')){
        q.push(i+m);
        if(!used[i+m]){
          a[i+m].prev=i;
          a[i+m].y='D';
        }
      }

      if((i%m>0)&&(a[i-1].x!='#')){
        q.push(i-1);
        if(!used[i-1]){
          a[i-1].prev=i;
          a[i-1].y='L';
        }
      }

      if((i%m<m-1)&&(a[i+1].x!='#')){
        q.push(i+1);
        if(!used[i+1]){
          a[i+1].prev=i;
          a[i+1].y='R';
        }
      }
    }
    used[i]=1;
  }

  if(flag){
    string s="";

    while(T!=S){
      s=a[T].y+s;
      T=a[T].prev;
    }

    cout<<s.length()<<endl<<s;
  }else{
    cout<<"-1";
  }
}
