#include <vector>
#include <cassert>

class BitBuffer {
private:
  std::vector<unsigned char> buffer;
  int bit_count = 0; // track the number of bits written to the current byte
  int buffer_size = 0;
public:
  void write(bool bit) {
    if (bit_count == 0) {
      buffer.push_back(0);
    }
    if (bit) {
      buffer.back() |= (1 << bit_count);
    }
    bit_count++;
    buffer_size++;
    if (bit_count == 8) {
      bit_count = 0;
    }
  }

  void write_buffer(BitBuffer& buffer) {
    for (int i = 0; i < buffer.size(); i++) {
      this->write(buffer[i]);
    }
  }

  int size() {
    return buffer_size;
  }

  bool operator[](int idx) {
    assert(idx < buffer_size);
    return buffer[idx / 8] & (1 << (idx % 8));
  }
};
