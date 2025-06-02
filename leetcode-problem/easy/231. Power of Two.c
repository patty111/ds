bool isPowerOfTwo(int n) {
    if (n == 0) return false;

    while (n >> 1){
        int bit = n & 1;
        if (bit) return false;
        n >>= 1;
    }
    return true;
}