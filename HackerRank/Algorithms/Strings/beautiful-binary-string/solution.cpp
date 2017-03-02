#include <iostream>
#include <vector>

int main() {
  int n;
  int count = 0;

  std::cin >> n;
  std::vector<char> list;

  for (int i = 0; i < n; i++) {
    char x;
    std::cin >> x;
    list.push_back(x);
  }

  for (int i = 1; i < n - 1; i++) {
    char a = list[i - 1];
    char b = list[i];
    char c = list[i + 1];

    if ((b == '1') && (a == '0') && (c == '0')) {
      list[i + 1] = '1';
      count++;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
