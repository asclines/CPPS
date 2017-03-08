#include <iostream>
#include <vector>
#include <algorithm>



typedef long long var;

struct Triple{
  int a,b,c;
};

int main(){
  int N,M;
  std::cin >> N >> M;

  std::vector<Triple> triples;

  for(int m = 0; m < M; m++){
    int a,b,k;
    std::cin >> a >> b >> k;
    Triple start;
    start.a = a;
    start.b = 0;
    start.c =k;

    Triple end;
    end.a = b;
    end.b=1;
    end.c=k;

    triples.push_back(start);
    triples.push_back(end);
  }

  std::sort(triples.begin(), triples.end(), [](const Triple & a, const Triple & b) -> bool{
    return (a.a<b.a || ((a.a == b.a)&&(a.b<b.b)));
    // return a.a < b.a;
  });

  int size = triples.size();
  var result = 0;
  var tmp = 0;
  for(int i = 0; i < size; i++){
    if ( triples[i].b == 0){ //Start
      tmp += triples[i].c;
      if(tmp>result) result = tmp;
    } else { //==1 //End
      tmp -= triples[i].c;
    }
  }
  std::cout << result << std::endl;

  return 0;
}
