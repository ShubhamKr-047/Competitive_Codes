int binary_exponentiation(int a, int b)
{
    int result = 1;
    while (b) 
    {
        if (b & 1LL) result = (result * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        b >>= 1LL;
    }
    return result;
}