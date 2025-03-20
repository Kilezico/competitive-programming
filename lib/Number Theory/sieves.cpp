bool isPrime[LIM];
vector<int> Sieve_Eratosthenes()
{
    for (int i=2; i<LIM; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for (int i=2; i<LIM; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i*2; j<LIM; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

ll divisors[LIM];
void SieveDivisors()
{
    for (int i=0; i<LIM; i++) divisors[i] = 0;
    for (int i=1; i<LIM; i++) {
        for (int j=i; j<LIM; j+=i) {
            divisors[j] ++;
        }
    }
}