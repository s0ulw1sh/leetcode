#define count_bit(byte)      \
    (((byte & 0x01) != 0)  + \
    ((byte & 0x02)  != 0)  + \
    ((byte & 0x04)  != 0)  + \
    ((byte & 0x08)  != 0)  + \
    ((byte & 0x10)  != 0)  + \
    ((byte & 0x20)  != 0)  + \
    ((byte & 0x40)  != 0)  + \
    ((byte & 0x80)  != 0))

int hammingWeight(uint32_t n) {
    int r = 0;
    
    r += count_bit((n & 0x000000FF));
    r += count_bit((n & 0x0000FF00) >> 8);
    r += count_bit((n & 0x00FF0000) >> 16);
    r += count_bit((n & 0xFF000000) >> 24);
    
    return r;
}
