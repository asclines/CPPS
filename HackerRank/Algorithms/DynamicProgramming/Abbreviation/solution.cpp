#include <iostream>
#include <cctype>
#include <string>

std::string calc(std::string a, std::string b){
  std::string cache;
  int i = 0, j = 0;
  while(i < a.size() && j < b.size()){
    char ca = toupper(a[i]);
    char cb = b[j];
    if(ca == cb){
      j++;
      cache.push_back(a[i]);
    } else if (ca == a[i]){
      for(int x = cache.size()-1; x >=0; x++){
        if(cache[x] == toupper(cache[x])) return "NO";
        else if (ca == toupper(cache[x])) {
          cache[x] = ' ';
          break;
        }
      }
    }
    i++;
  }

  if(j == b.size() && i != a.size()){
    while(i < a.size()){
      char ca = toupper(a[i]);
      if (ca == a[i]) {
        int x = 0;
        for(x = cache.size()-1; x >=0; x++){
          if(cache[x] == toupper(cache[x])) return "NO";
          else if (ca == toupper(cache[x])) {
            cache[x] = ' ';
            break;
          }
        }
        if(x > 0) break;
      }
      i++;
    }

  }

  if (j==b.size()) return "YES";
  else return "NO";
}


int main(){
  int Q;
  std::cin >> Q;

  for(int q = 0; q < Q; q++){
    std::string a,b;
    std::cin >> a;
    std::cin >> b;
    std::cout << calc(a,b) << std::endl;
  }


  return 0;
}
