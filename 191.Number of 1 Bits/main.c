#define count_bit(byte)       \
    ((byte & 0x01 ? 1 : 0) + \
    (byte & 0x02 ? 1 : 0)  + \
    (byte & 0x04 ? 1 : 0)  + \
    (byte & 0x08 ? 1 : 0)  + \
    (byte & 0x10 ? 1 : 0)  + \
    (byte & 0x20 ? 1 : 0)  + \
    (byte & 0x40 ? 1 : 0)  + \
    (byte & 0x80 ? 1 : 0))


int hammingWeight(uint32_t n) {
    int r = 0;
    
    r += count_bit((n & 0x000000FF));
    r += count_bit((n & 0x0000FF00) >> 8);
    r += count_bit((n & 0x00FF0000) >> 16);
    r += count_bit((n & 0xFF000000) >> 24);
    
    return r;
}
