#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


typedef long long var;

/**
   Givens:
   trip_count    - 1 <= t <= 20
   stick_goal   - 1 <= n <= 10^5
   boxes_avail   - 1 <= k <= 10^18
   box_goal      - 1 <= b <= 10^18

   b <= k

 **/
int main() {
  int trip_count;

  std::cin >> trip_count;

  for (int tc = 0; tc < trip_count; tc++) {
    var stick_goal, boxes_avail, box_goal;
    std::cin >> stick_goal >> boxes_avail >> box_goal;
    var max_sticks = 0;

    for (var i = boxes_avail - box_goal + 1; i <= boxes_avail; i++) {
      max_sticks += i;

      if (max_sticks > stick_goal) break;
    }

    if ((stick_goal > max_sticks) ||
        (stick_goal < ((1 + box_goal) * box_goal) / 2)) std::cout << -1;
    else {
      for (var boxes_left = box_goal; boxes_left > 0; boxes_left--) {
        var cur_box = 0;
        if (boxes_left % 2 == 0) {
          if (stick_goal % boxes_left >  boxes_left / 2) {
            cur_box = stick_goal / boxes_left + 2 + (boxes_left - 1) / 2;
          }
          else{
            cur_box = stick_goal / boxes_left + (boxes_left - 1) / 2 + 1;
          }
        }
        else {
          if (stick_goal % boxes_left > 0){
            cur_box = stick_goal / boxes_left + (boxes_left - 1) / 2  + 1;
          }
          else {
            cur_box = stick_goal / boxes_left + (boxes_left - 1) / 2;
          }
        }

        stick_goal -= cur_box;
        std::cout << cur_box;

        if (boxes_left != 1) std::cout << " ";
      }
    }

    if (tc != trip_count - 1) std::cout << std::endl;
  }

  return 0;
}
