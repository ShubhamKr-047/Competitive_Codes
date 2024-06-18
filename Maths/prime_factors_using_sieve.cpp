int N = 2e5 + 5;

vector<bool> prime(N + 1, true);
vector<int> lowest_prime(N + 1), highest_prime(N + 1); 


// precompute this in int main to get prime factors in log(n) time
// we only need to compute either highest or lowest prime of every number
void sieve()
{
    for (int p = 2; p * p <= N; p++) 
    {
        if (prime[p] == true) 
        {
            lowest_prime[p] = highest_prime[p] = p;
            for (int i = p * p; i <= N; i += p) 
            {
                prime[i] = false;
                highest_prime[i] = p;
                if (lowest_prime[i] == 0) lowest_prime[i] = p;
            }
        }
    }
}

vector<int> get_prime_factorization(int x)
{
    vector<int> prime_factors;
    while (x != 1) 
    {
        prime_factors.push_back(lowest_prime[x]);
        x /= lowest_prime[x];
    }
    return prime_factors;
}