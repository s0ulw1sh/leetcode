

int myAtoi(char * str){
    char p;
    long long acum = 0;
    int i = 0, z =0, out = 0;
    
    while (p = *str++) {
        
        switch(p) {
            case ' ':
                
                i = 0;
                break;
            case '+':
            case '-':
                if (i != 0 && z == 0) return 0;
                if (i != 0 && z > 0) {
                    i = 0;
                    break;
                }
                out = '-' - p - 1;
                i++;
                break;
            case '.':
                if (i == 0) return 0;
                goto outcalc;
            default:
                p = p - '0';   
                if (p < 0 || p > 9) {
                        
                        goto outcalc;
                }
                if (i == 0 && acum > 0)
                    goto outcalc;
                if (i == 0 && out != 0)
                    return 0;
                if (z > 0 && i == 0)
                    goto outcalc;
                i++;
                z++;
                acum += p;
                acum *= 10;
                
                if (acum/10 > INT_MAX) goto outcalc;
                if (acum/10 < INT_MIN) goto outcalc;
                
        }
        
    }
    
    outcalc:
    
    acum /= 10;
    
    acum = out == 0 ? acum : acum * out;
    
    if (acum > INT_MAX) return INT_MAX;
    if (acum < INT_MIN) return INT_MIN;
    
    
    return acum;
}
