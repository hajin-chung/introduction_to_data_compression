#include "bit_buffer.h"
#include <iostream>

bool test_bit_buffer_write_size() {
  BitBuffer buffer;
  unsigned char data = 5;
  int size = 0;

  while (data) {
    buffer.write(data & 1);
    data >>= 1;
    size++;
  }

  return buffer.size() == size;
}

bool test_bit_buffer_write_read() {
  BitBuffer buffer;
  unsigned char data = 5;

  for (int i = 0; (data>>i); i++) {
    buffer.write(data & (1<<i));
  }

  int read_data = 0;
  for (int i = 0; i < buffer.size(); i++) {
    if (buffer[i]) {
      read_data |= (1<<i);
    }
  }
  
  return data == read_data;
}

bool test_bit_buffer_write_buffer() {
  BitBuffer buffer1, buffer2;
  unsigned char data = 5;

  for (int i = 0; (data>>i); i++) {
    buffer1.write(data & (1<<i));
  }
  for (int i = 0; (data>>i); i++) {
    buffer2.write(data & (1<<i));
  }
  buffer2.write_buffer(buffer1);

  int read_data = 0;
  for (int i = 0; i < buffer2.size(); i++) {
    if (buffer2[i]) {
      read_data |= (1<<i);
    }
  }
  
  return ((data<<3)|data) == read_data;
}

int main() {
  std::cout<<"TEST test_bit_buffer_write_size(): " << test_bit_buffer_write_size()<<std::endl;
  std::cout<<"TEST test_bit_buffer_write_read(): " << test_bit_buffer_write_read()<<std::endl;
  std::cout<<"TEST test_bit_buffer_write_buffer(): " << test_bit_buffer_write_buffer()<<std::endl;
}
