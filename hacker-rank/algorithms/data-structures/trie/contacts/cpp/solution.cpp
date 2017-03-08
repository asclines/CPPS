#include <iostream>
#include <array>
#include <string>


struct Node {
  Node(char x) : value(x), word_count(0) {children.fill(NULL);}
  char                value;
  int                 word_count;
  std::array<Node*, 26>children;
};


//a=0,b=1,etc...
int getAlphaValue(char x){
  return x - 'a';
}

void add(Node *root, std::string word){
  Node *cur_node = root;
  cur_node->word_count++;
  for(char c:word){
    int alpha_value = getAlphaValue(c);
    Node *next_node = cur_node->children[alpha_value];

    if(next_node == NULL){
      cur_node->children[alpha_value] = new Node(c);
    }
    cur_node->children[alpha_value]->word_count++;
    cur_node = cur_node->children[alpha_value];
  }
}

int find(Node *root, std::string partial){
  Node *cur_node = root;
  for(char c:partial){
    int alpha_value = getAlphaValue(c);
    Node *next_node = cur_node->children[alpha_value];
    if(next_node == NULL){
      return 0;
    }
    cur_node = cur_node->children[alpha_value];
  }

  return cur_node->word_count;
}

int main() {
  int n,count;
  std::string command,option;
  Node tree(' ');


  std::cin >> n;
  for(int i=0; i <n;i++){
    std::cin >> command;
    std::cin >> option;
    if(command.compare("add") == 0){
      add(&tree,option);
    } else {
      count = find(&tree,option);
      std::cout << count << std::endl;
    }

  }



  return 0;
}
