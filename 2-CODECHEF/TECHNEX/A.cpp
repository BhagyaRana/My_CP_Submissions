#include <bits/stdc++.h>
using namespace std;

double Convert(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

int main() {
  int t;
  cin>>t;
  while(t--){
      double n;
      cin>>n;
      double p = Convert(180/n);
      cout<<setprecision(8)<<(1/(1-cos(p)*cos(p)))<<endl;
  }
  return 0;
}