#include<iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,m,i,j,x,y;
  bool f;
  cin>>n>>m;
  int mas[101][101];
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      mas[i][j]=0;
    }
  }
  f=0;
  for (i=0;i<m;i++){
    cin>> x>>y;
    if((mas[x][y]==1)||(mas[y][x]==1)){
      f=1;
      break;
    }
    mas[x][y]=1;
  }
  if(f){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
}
