#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // std::to_string( )

void LogD(std::string message) {
  #if defined(CLINES_LOG_ALL) || defined(CLINES_LOG_DEBUG)
  std::cout << "[DEBUG]: " << message << std::endl;
  #endif // if defined(CLINES_LOG_ALL) || defined(CLINES_LOG_DEBUG)
}

typedef std::vector<int>::iterator coin_itr;

int getCount(coin_itr coin_start,
             coin_itr coin_end,
             int      current_value,
             int      goal_value) {
  LogD("getCount(" + std::to_string(*coin_start) + "," +
       std::to_string(*(coin_end - 1)) + "," + std::to_string(
         current_value) + "," + std::to_string(goal_value) + ")");

  if (coin_start >= coin_end) return 0;       // We've reached the end of the
                                              // coin list

  if (current_value == goal_value) return 1;  // We have reached our goal. Stop
                                              // here, everything afterwards
                                              // will be greater than our goal
                                              // so need to continue.

  if (current_value > goal_value) return 0;   // We went over the goal. Stop.

  // If we have reached this point, we know that we aren't at the end of the
  // coin list and that our current value is less than the goal value

  coin_itr next_coin_itr = coin_start;
  int next_coin_value;
  int count = 0;

  do {
    next_coin_value = *next_coin_itr;
    int next_current_value = next_coin_value;
    LogD("next coin value = " + std::to_string(next_coin_value));

    count += getCount(next_coin_itr, coin_end, next_current_value, goal_value);
    next_coin_itr++;
  } while (next_coin_itr != coin_end);


  return count;
}

int main() {
  int n; // The amount we are trying to get to 1<=n<=250
  int m; // The number of distinct coin values 1<=m<=50
  int c; // The coin value being read in. 1<=C<=50

  std::vector<int> coins;

  std::cin >> n;
  std::cin >> m;

  for (int i = 0; i < m; i++) {
    std::cin >> c;
    coins.push_back(c);
  }

  std::sort(coins.begin(), coins.end());

  int count = getCount(coins.begin(), coins.end(), *coins.begin(), m);

  std::cout << count << std::endl;


  return 0;
}
