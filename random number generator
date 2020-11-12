#include<cstdlib>
#include<iostream>
#include<random>

int randInt(int low, int high);
int main(){
srand(time(0));
}

int randInt(int low, int high){
  int ans;
  if(low > high){
    low += high;
    high = low - high;
    low -= high;
  }
  if(low == high){
    return low;
  }else if(low > 0){
    ans = 1 + (rand() % high);
  }else if(low == 0 && high > 0){
    ans = 1 + (rand() % (high + 1));
    if(ans > high){
      return 0;
    }
  }else if(low < 0 && high > 0){
    ans = 1 + (rand() % (high - low + 1));
    if(ans > high){
      ans -= high + 1;
      ans *= -1;
    }
  }else if(low < 0 && high == 0){
    ans = -(1 + (rand() % (-low + 1)));
    if(ans < low){
      return 0;
    }
  }else{
    ans = -(randInt(-low, -high));
  }
  if(ans < low){
    return randInt(low, high);
  }
  return ans;
}
