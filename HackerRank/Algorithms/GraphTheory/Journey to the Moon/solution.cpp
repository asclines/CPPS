#include <iostream>
#include <vector>


int main() {
  int N, I;

  std::cin >> N >> I;
  std::vector<std::vector<int> > adj_list;
  std::vector<bool> visited;

  // Initialize data
  for (int n = 0; n < N; n++) {
    std::vector<int> new_vec;
    adj_list.push_back(new_vec);
    visited.push_back(false);
  }

  // Read in edges and add to adj_list
  for (int i = 0; i < I; i++) {
    int a, b;
    std::cin >> a >> b;
    adj_list.at(a).push_back(b);
    adj_list.at(b).push_back(a);
  }

  // BFS throught this
  std::vector<int> countries; // holds number of astronaunts for each country

  for (int n = 0; n < N; n++) {
    if (!visited[n]) {
      visited[n] = true;
      int count = 1;
      std::vector<int> frontier;

      for (auto & e: adj_list[n]) {
        frontier.push_back(e);
      }

      while (!frontier.empty()) {
        std::vector<int> new_frontier;

        for (auto & e: frontier) {
          if (!visited[e]) {
            visited[e] = true;
            count++;

            for (auto & x: adj_list[e]) {
              new_frontier.push_back(x);
            }
          }
        }
        frontier = new_frontier;
      }
      countries.push_back(count);
    }
  }


  // Calc values
  int  S      = 0;
  long result = 0;

  for (auto & c: countries) {
    S += c;
  }

  for (auto & c: countries) {
    S       = S - c;
    result += c * S;
  }

  std::cout << result << std::endl;


  return 0;
}
