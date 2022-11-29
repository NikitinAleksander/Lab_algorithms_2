#include<iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,m,i,j,x,y;
  cin>>n>>m;
  int mas[101][101];
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      mas[i][j]=0;
    }
  }
  for (i=0;i<m;i++){
    cin>> x>>y;
    mas[x][y]=1;
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      cout<<mas[i][j]<<" ";
    }
    cout<<endl;
  }
}
