//find prime number in range l to r, r <= 10^12 && if L == 1 handle that case seperately by doing l++

const int N = 1e6 + 1;
vector<int> prime;

vector<int> SieveOfEratosthenes()
{
    vector<bool> prime(N + 1, true);
    for (int p = 2; p <= N; p++) 
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= N; i += p) prime[i] = false;
        }
    }
    vector<int> res;
    for (int i = 2; i <= N; i++) if (prime[i]) res.push_back(i);
    return res;
}

vector<int> segmented_sieve_prime_number(int l, int r)
{
    if (l == 1) l++;
    vector<bool> prime_in_range(r - l + 1, true);
    iota(all(prime_in_range), l);
    for (auto &p : prime)
    {
        if (p * p > r) break;
        int curr = (l / p) * p;
        if (curr < l) curr += p;
        while (curr <= r)
        {
            if (curr != p) prime_in_range[curr - l] = 0;
            curr += p;
        }
    }
    vector<int> res;
    for (int i = 0; i < sz(prime_in_range); i++) if (prime_in_range[i]) res.push_back(i + l);
    return res;
}

int32_t main()
{
    FAST_IO;
    prime = SieveOfEratosthenes();
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++)
    {
        solve();
    }
}