int reverse(int x){
    long z, i, acm = 0;
    int out = 0;
    
    for (z = 1 ;; z *= 10)
        if (x % z == x)
            break;
    
    for (i = 1; z > 1; i *= 10, z /= 10)
        acm += (x % z) / (z / 10) * i;

    out = acm;
    
    return out == acm ? out : 0;
}
