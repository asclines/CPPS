#include <iostream>
#include <cmath>


int main(){
  int n;
  std::cin >> n;
  int rightSum = 0;
  int leftSum = 0;
  for(int i = 0; i < n; i++){
    for(int j =0; j < n; j++) {
      int x;
      std::cin >> x;
      if(j == i) leftSum += x;
      if(j == n - 1 - i) rightSum +=x;
    }
  }
  std::cout << abs(rightSum-leftSum);



  return 0;
}
