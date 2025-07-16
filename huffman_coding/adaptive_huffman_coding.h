#include "bit_buffer.h"
#include <vector>

#ifndef __BIT_BUFFER_H__
#define __BIT_BUFFER_H__

class HuffmanNode {
public:
  int num;
  int weight;
  HuffmanNode* parent = nullptr;
  HuffmanNode* left = nullptr;
  HuffmanNode* right = nullptr;
};

class AdaptiveHuffmanCode {
private:
  std::vector<bool> check; // check if symbol is in NYT
  std::vector<std::vector<HuffmanNode*>> blocks;
  HuffmanNode* root;
  int n;
public:
  AdaptiveHuffmanCode(int);
  BitBuffer fixed_code(char);
  void update(char);
  BitBuffer encode(std::vector<char>);
  std::vector<char> decode(BitBuffer);
};

#endif
