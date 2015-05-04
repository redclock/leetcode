/*
Count the number of prime numbers less than a non-negative number, n
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int halfn = n / 2;
        bool* isComp = new bool[halfn];
        memset(isComp, 0, sizeof(bool) * halfn);
        int maxLimit = (int)sqrt(n);
        for (int i = 3; i <= maxLimit; i += 2) {
            if (isComp[i / 2]) continue;
            for (int x = i * i / 2; x < halfn; x += i) {
                isComp[x] = true;
            }
        }
        int nPrime = 1;
        for (int i = 1; i < halfn; i ++)
        {
            if (!isComp[i]) nPrime++;        
        }
        delete[] isComp;
        return nPrime;
        
    }
};