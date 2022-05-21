#include <iostream>
using namespace std;

int pos[3] = {-1,0,1};
int grid[100][100];
int n;

bool isValid(int x, int y){
  return x >= 0 and x < n and y >= 0 and y < 5;
}

int max(int a, int b){
  return (a >= b) ? a : b;
}

int solve(int r, int c, int power, int effect){
  if(r < 0){
    return 0;
  }

  int ans = 0;
  int p = 0;

  for(int d = 0; d < 3; d++){
    int x = r - 1;
    int y = c + pos[d];

    if(isValid(x,y)){
      if(grid[x][y] == 2){
        if(power == 0 and effect > 0){
          p = solve(x,y,power, effect-1);
        }
        if(power == 1){
          p = solve(x,y,power-1,5);
        }
      }

      if(grid[x][y] == 0 or grid[x][y] == 1){
        if(power == 0){
          p = solve(x,y,power, effect-1);
        }
        else{
          p = solve(x,y,power,5);
        }
      }
    }
    ans = max(ans, p);
  }
  if(grid[r][c] == 1){
    ans++;
  }
  return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < 5; j++){
        cin >> grid[i][j];
      }
    }

    cout << solve(n,2,1,0) << endl;

    return 0;
}
