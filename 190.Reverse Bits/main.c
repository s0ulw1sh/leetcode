
#define reverse_bit(byte)       \
    ((byte & 0x01 ? 0x80 : 0) | \
    (byte & 0x02 ? 0x40 : 0)  | \
    (byte & 0x04 ? 0x20 : 0)  | \
    (byte & 0x08 ? 0x10 : 0)  | \
    (byte & 0x10 ? 0x08 : 0)  | \
    (byte & 0x20 ? 0x04 : 0)  | \
    (byte & 0x40 ? 0x02 : 0)  | \
    (byte & 0x80 ? 0x01 : 0))

uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;
    
    r |= (uint32_t) reverse_bit((n & 0x000000FF))       << 24;
    r |= (uint32_t) reverse_bit((n & 0x0000FF00) >> 8)  << 16;
    r |= (uint32_t) reverse_bit((n & 0x00FF0000) >> 16) << 8;
    r |= (uint32_t) reverse_bit((n & 0xFF000000) >> 24);
    
    return r;
}
