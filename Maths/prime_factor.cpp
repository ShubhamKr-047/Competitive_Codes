vector<int> prime_factor(int n) 
{
    vector<int> prime_factors; 
    for (int i = 2; i * i <= n; i++) 
    { 
        if (n % i == 0) prime_factors.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 2) prime_factors.push_back(n);
    return prime_factors; 
}

unordered_map<int, int> prime_factor_count(int n)
{
    unordered_map<int, int> prime_factors; 
    for (int i = 2; i * i <= n; i++) 
    { 
        while (n % i == 0) 
        { 
            prime_factors[i]++; 
            n /= i;
        }
    }
    if (n > 1) prime_factors[n]++;
    return prime_factors; 
}