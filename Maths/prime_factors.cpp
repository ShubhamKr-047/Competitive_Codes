vector<int> findDivisors(int n) 
{
    vector<int> prime_factors; 
    int sqrtN = sqrt(n); 
    for (int i = 2; i <= sqrtN; i++) 
    { 
        while (n % i == 0) 
        { 
            prime_factors.push_back(i); 
            n /= i;
        }
    }
    return prime_factors; 
}
                                
                            