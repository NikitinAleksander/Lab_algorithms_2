#include<iostream>

using namespace std;

int main(){
  freopen("components.in", "r", stdin);
  freopen("components.out", "w", stdout);
  int n,m,i,max,x,y;
  cin>>n>>m;
  int mas[100001];
  for(i=1;i<=n;i++){
    mas[i]=0;
  }
  max=0;
  for(i=0;i<m;i++){
    cin>>x>>y;
    if((mas[x]==0)||(mas[y]==0)){
      if ((mas[x]==0)&&(mas[y]>0)){
        mas[x]=mas[y];
      }
      if ((mas[x]>0)&&(mas[y]==0)){
        mas[y]=mas[x];
      }
      if((mas[x]==0)&&(mas[y]==0)){
        max++;
        mas[x]=max;
        mas[y]=max;
      }
    }
  }
  for(i=1;i<=n;i++){
    if ((mas[i]==0)){
      max++;
      mas[i]=max;
    }
  }
  cout<<max<<endl;
  for(i=1;i<=n;i++){
    cout<<mas[i]<<" ";
  }
}
