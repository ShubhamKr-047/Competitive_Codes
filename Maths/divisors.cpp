vector<int> findDivisors(int n) 
{
    vector<int> divisors; 
    int sqrtN = sqrt(n); 
    for (int i = 1; i <= sqrtN; i++) 
    { 
        if (n % i == 0) 
        { 
            divisors.push_back(i); 
            if (i != n / i) divisors.push_back(n / i); 
        }
    }
    return divisors; 
}
                                
                            