/* 

To calcumate (a / b) % MOD we use MMI (Modular Multiplicative Inverse)
(a / b) % MOD = (a * b^(-1)) % MOD = (a % MOD * (b^(-1)) % MOD) % MOD;
b^(-1) = binary_exponentiation(b, MOD - 2);

MOD should be a prime number

*/

int N = 100001;
vector<int> factorial(N);

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

void calculate_factorial()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < N; i++) factorial[i] = (factorial[i - 1] * 1LL * i) % MOD;
}

int nCr(int n, int r)
{
    int numo = factorial[n];
    int deno = (factorial[n - r] * 1LL * factorial[r]) % MOD;
    int result = (numo * 1LL * binary_exponentiation(deno, MOD - 2)) % MOD;
    return result;
}

