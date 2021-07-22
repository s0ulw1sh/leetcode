

char * defangIPaddr(char * address){
    int  i, len;
    char p, *out;
    
    if (!address)
        return NULL;
    
    len = strlen(address);
    out = (char*)calloc(len+6+1, sizeof(char));
    i   = 0;
    
    while(p = *address++) {
        if (p == '.') {
            *(out+i++) = '[';
            *(out+i++) = '.';
            *(out+i++) = ']';
        } else {
            *(out+i++) = p;
        }
    }
    
    return out;
}

