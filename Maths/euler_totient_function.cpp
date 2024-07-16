/*

Phi(P^x) = P^(x - 1) * (P - 1), where P is prime
Phi(n) = N * (P1 - 1)/P1 * (P2 - 1)/P2 ..., where n is any number and P1, P2... are prime factor of n

*/

vector<int> prime_factor(int n) 
{
    vector<int> prime_factors;  
    for (int i = 2; i * i <= n; i++) 
    { 
        if (n % i == 0) prime_factors.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) prime_factors.push_back(n);
    return prime_factors; 
}

int euler_otient_function(int num)
{
    vector<int> pf = prime_factor(num);
    int phi = num;
    for (int i = 0; i < sz(pf); i++)
    {
        phi = phi / pf[i];
        phi = phi * (pf[i] - 1);
    }
    return phi;
}

//calculate Phi of all numbers form 1 to num
int euler_otient_function__using_sieve(int num)
{
    vector<int> phi(num + 1);
    iota(all(phi), 0);
    for (int i = 2; i <= num; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= num; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}
