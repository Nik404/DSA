#include <iostream>
using namespace std;
const int INT_MAX = 10000;
struct cord{
  int x, y;
};

bool vis[12] = {false};

int abs(int x){
  return (x < 0) ? -1*x : x;
}
int  min(int x, int y){
  return (x <= y) ? x : y;
}
int solve(int x, int y, int hx, int hy,cord customers[],int cnt, int n){
  if(cnt == n){
    return abs(x-hx) + abs(y-hy);
  }
  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    cord curr = customers[i];
    if(!vis[i]){
      vis[i] = true;
      int val = abs(x-curr.x) + abs(y-curr.y);
      ans = min(ans, val + solve(curr.x, curr.y,hx,hy,customers,cnt+1,n));
      vis[i] = false;
    }
  }
  return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      cord customers[n];
      int ox,oy,hx,hy;
      cin >> ox >> oy >> hx >> hy;
      for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        customers[i].x = u;
        customers[i].y = v;
       }
       cout << solve(ox,oy,hx,hy,customers,0,n) << endl;
    }
    return 0;
}


/*
3 <-- Testcases
5 <-- cutomers array length
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6 <-- cutomers array length
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10 <-- cutomers array length
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

*/