#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

bool homogenousArr(std::vector<int> arr);
float getMean(std::vector<int> arr);
int randInt(int low, int high);
std::vector<int> concatArr(std::vector<int> arr1, std::vector<int> arr2);
std::vector<int> createArr(int low, int high, int size);
std::vector<int> sortArr(std::vector<int> arr);
void printArr(std::vector<int> arr);
void printInt(int x);

int main(){
    srand(time(0));
    int low;
    int high;
    int size;
    std::cout << "Enter in a low value: "; std::cin >> low;
    std::cout << "Enter in a high value: "; std::cin >> high;
    std::cout << "Enter in a size: "; std::cin >> size;
    printArr(sortArr(createArr(low, high, size)));
    return 0;
}

bool homogenousArr(std::vector<int> arr){
    if(arr.size() == 1){
        return true;
    }
    int comp = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != comp){
            return false;
        }
    }
    return true;
}

float getMean(std::vector<int> arr){
    if(arr.size() == 1){
        return arr[0];
    }
    float ans;
    for(int i = 0; i < arr.size(); i++){
        ans += arr[i];
    }
    ans /= arr.size();
    return ans;
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

std::vector<int> concatArr(std::vector<int> arr1, std::vector<int> arr2){
    if(arr1.size() == 0 && arr2.size() == 0){
        return {};
    }else if(arr1.size() == 0){
        return arr2;
    }else if(arr2.size() == 0){
        return arr1;
    }
    std::vector<int> ans;
    for(int i = 0; i < arr1.size(); i++){
        ans.push_back(arr1[i]);
    }
    for(int i = 0; i < arr2.size(); i++){
        ans.push_back(arr2[i]);
    }
    return ans;
}

std::vector<int> createArr(int low, int high, int size){
    std::vector<int> arr;
    while(arr.size() < size){
        arr.push_back(randInt(low, high));
    }
    return arr;
}

std::vector<int> sortArr(std::vector<int> arr){
    float mean = getMean(arr);
    std::vector<int> arr1;
    std::vector<int> arr2;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= mean){
            arr1.push_back(arr[i]);
        }else{
            arr2.push_back(arr[i]);
        }
    }
    if(arr1.size() == 0 && arr2.size() == 0){
        return {};
    }else if(arr1.size() == 0){
        return arr2;
    }else if(arr2.size() == 0){
        return arr1;
    }
    if(!homogenousArr(arr1)){
        arr1 = sortArr(arr1);
    }
    if(!homogenousArr(arr2)){
        arr2 = sortArr(arr2);
    }
    return concatArr(arr1, arr2);
}

void printArr(std::vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << std::endl;
    }
}
