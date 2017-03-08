#include <iostream>
#include <cmath>


int main() {
  float x1, x2, v1, v2, t, speed_delta, distance_delta;

  std::cin >> x1 >> v1 >> x2 >> v2;

  speed_delta    = v2 - v1;
  distance_delta = x1 - x2;

  // If they are going the same speed then they need to have started at the same
  // position, else they will never meet
  if (speed_delta == 0) {
    if (distance_delta == 0) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
  }

  t = distance_delta / speed_delta;

  // Seeing as the kangaroo are hopping, time is discrete, so not only must time
  // > 0, but it must be a whole number or integer.
  if ((roundf(t) == t) && (t > 0)) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
