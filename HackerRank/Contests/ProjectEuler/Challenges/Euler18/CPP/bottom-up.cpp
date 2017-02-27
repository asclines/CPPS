#include <iostream>
#include <vector>

void calc() {
  int row_count, number;

  std::cin >> row_count;
  std::vector<std::vector<int> > pyramid;

  for (int row = 1; row <= row_count; row++) {
    std::vector<int> level;
    int spot = 0;

    do {
      std::cin >> number;
      level.push_back(number);
      spot++;
    } while (spot < row);
    pyramid.push_back(level);
  }

  for (int row_index = pyramid.size() - 1; row_index > 0; row_index--) {
    std::vector<int> row = pyramid.at(row_index);

    for (int spot_index = 0; spot_index < row.size() - 1; spot_index++) {
      int parent_index = ((2 * spot_index) + 1) / 2;
      int parent       = pyramid.at(row_index - 1).at(parent_index);
      int spot         = row.at(spot_index);
      int next_spot    = row.at(spot_index + 1);

      if (next_spot > spot) {
        pyramid.at(row_index - 1).at(parent_index) = next_spot + parent;
      } else {
        pyramid.at(row_index - 1).at(parent_index) = spot + parent;
      }
    }
  }

  std::cout << pyramid.at(0).at(0) << std::endl;
}

int main() {
  int test_count;

  std::cin >> test_count;

  for (int i = 0; i < test_count; i++) {
    calc();
  }


  return 0;
}
