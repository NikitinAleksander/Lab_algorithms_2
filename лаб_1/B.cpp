#include<iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,i,j,x,y;
  bool f;
  cin>>n;
  int mas[101][101];
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      cin>>mas[i][j];
    }
  }
  f=1;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(((i==j)&&(mas[i][j]==1))||((mas[i][j]!=mas[j][i])&&(mas[i][j]==1))){
        f=0;
      }
    }
  }
  if(f){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
}
