#include <iostream>


int main() {
  int t,n,k,a,count;

  std::cin >> t;
  for(int i = 0; i < t; i++){
    std::cin >> n >> k;
    count = 0;
    for(int j=0; j < n; j++){
      std::cin >> a;
      if (a <= 0) count++;
    }
    if(count >= k) std::cout << "NO" << std::endl;
    else std::cout << "YES" << std::endl;

  }

  return 0;
}
