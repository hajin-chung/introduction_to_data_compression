#include "adaptive_huffman_coding.h"

AdaptiveHuffmanCode::AdaptiveHuffmanCode(int n) {
  this->n = n;
  this->check.resize(n);
  this->blocks.resize(n);
}

BitBuffer AdaptiveHuffmanCode::fixed_code(char c) {
  return BitBuffer();
}

void AdaptiveHuffmanCode::update(char) {
  return;
}

BitBuffer AdaptiveHuffmanCode::encode(std::vector<char>) {

}

std::vector<char> AdaptiveHuffmanCode::decode(BitBuffer) {

}
