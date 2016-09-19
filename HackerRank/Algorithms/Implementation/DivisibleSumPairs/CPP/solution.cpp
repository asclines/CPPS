#include <iostream>
#include <vector>

int main() {
  int n,k,a,sum,count=0;
  std::cin >> n >> k;
  std::vector<int> elements;
  for(int i=0; i < n; i++){
    std::cin >> a;
    for(auto element: elements) {
      sum = a + element;
      if(sum % k == 0){
        count++;
      }
    }
    elements.push_back(a);
  }
  std::cout << count;
  return 0;
}
