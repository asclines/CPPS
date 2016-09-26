#include <iostream>
#include <vector>

int main() {
  int test_count, row_count, number;

  std::cin >> test_count;

  for (int i_test = 0; i_test < test_count; i_test++) {
    std::cin >> row_count;
    std::cin >> number;

    int total_max_value = number; // The absolute max value

    std::vector<int> frontier;    // Holds the values of the previous row
    frontier.push_back(number);

    for (int i_row = 1; i_row < row_count; i_row++) {
      std::vector<int> new_frontier;
      int row_max_value = -1;                        // One way to look at this
                                                     // is the max value that
                                                     // could be obtained if
                                                     // this row was the bottom
                                                     // row

      for (int i_num = 0; i_num <= i_row; i_num++) { // For each number in the
                                                     // row
        std::cin >> number;

        int num_max_value = -1;                      // By the end of this loop,
                                                     // this will hold the max
                                                     // value that could be
                                                     // obtained if this was the
                                                     // ending value

        if (i_num != 0) {                            // Not the left most
          num_max_value = frontier[i_num - 1];
        }

        if (i_num != i_row) {              // Not the right most
          int right_max = frontier[i_num];

          if (right_max > num_max_value) { // If the max value of the right
                                           // parent is greater than the max
                                           // value of the left parent or if the
                                           // left parent does not exist
            num_max_value = right_max;
          }
        }
        num_max_value += number;             // Don't forget to add the value of
                                             // this number to the max value

        if (num_max_value > row_max_value) { // Update the row max value if this
                                             // is the current highest way to go
                                             // down the triangle
          row_max_value = num_max_value;
        }

        new_frontier.push_back(num_max_value);
      }

      if (row_max_value > total_max_value) {
        total_max_value = row_max_value;
      }
      frontier = new_frontier;
    }
    std::cout << std::to_string(total_max_value)  << std::endl;
  }
  return 0;
}
