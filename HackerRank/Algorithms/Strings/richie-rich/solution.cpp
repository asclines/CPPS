#include <iostream>
#include <vector>

int main() {
  int  n, k, i, pc = 0;
  char x;

  std::cin >> n >> k;

  if (n == 1) {
    if (k > 0) std::cout << 9 << std::endl;
    else {
      std::cin >> x;
      std::cout << x << std::endl;
    }
    return 0;
  }

  std::vector<int> vect_a, vect_b, cost_a, cost_b;

  if (n % 2 != 0) i = -1;
  else i = 0;

  for (; i < n / 2; i++) {
    std::cin >> x;
    vect_a.push_back(x - '0');
    cost_a.push_back(1);
  }

  for (i = 0; i < n / 2; i++) {
    std::cin >> x;
    vect_b.insert(vect_b.begin(), x - '0');
    cost_b.push_back(1);
  }

  for (i = 0; i < n / 2; i++) {
    int a = vect_a.at(i);
    int b = vect_b.at(i);

    if (a < b) {
      vect_a.at(i) = b;
      cost_a.at(i) = 0;
      pc++;
    } else if (b < a) {
      vect_b.at(i) = a;
      cost_b.at(i) = 0;
      pc++;
    }
  }

  if (pc > k) {
    std::cout << "-1" << std::endl;
    return 0;
  }

  k -= pc;

  for (i = 0; i < n / 2; i++) {
    int cost = cost_a.at(i) + cost_b.at(i);
    int a    = vect_a.at(i);
    int b    = vect_b.at(i);

    if ((cost <= k) && (vect_a.at(i) != 9)) {
      vect_a.at(i) = 9;
      vect_b.at(i) = 9;
      k           -= cost;
    }
  }

  if ((n % 2 != 0) && (k > 0)) vect_a.at(n / 2) = 9;

  for (i = 0; i < vect_a.size(); i++) {
    std::cout << vect_a.at(i);
  }

  for (i = vect_b.size() - 1; i >= 0; i--) {
    std::cout << vect_b.at(i);
  }

  std::cout << std::endl;


  return 0;
}
