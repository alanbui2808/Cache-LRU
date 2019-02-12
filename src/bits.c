#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
  int set_bits = cache->set_bits;
  int block_bits = cache->block_bits;
  int L = 32-set_bits-block_bits;
  int R = 32-set_bits;
  int result = address << L >> R;
  return result;
}

int get_line (Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  int tag_bits = 32 - cache->set_bits - cache->block_bits;
  int result = address >> (32-tag_bits);
  return result;
}

int get_byte (Cache *cache, address_type address) {
  // TODO
  // Extract the block (byte index) bits from a 32-bit address.
  //
  int block_bits = cache->block_bits;
  int L = 32 - block_bits;
  int R = L;
  int result = address << L >> R;
  return result;
}

