#include <iostream>
#include <vector>

#define NMax (10000 + 1)

std::vector<long> get_primes(int n) {
    std::vector<bool> is_prime(NMax, true);
    std::vector<long> primes;
    is_prime[1] = false;
    for (long i = 2; i < NMax; ++i)
        if (is_prime[i]) {
            primes.push_back(i);
            if (primes.size() >= n)
                break;
            for (long j = i; (i * j) < NMax; ++j)
                is_prime[i * j] = false;
        }
    return std::move(primes);
}

void do_pass(bool is_forward, std::vector<bool> &free, const std::vector<int> &num, int mod) {
    int n = num.size();
    int start = 0, end = n, delta = 1;
    if (!is_forward)
        start = n - 1, end = -1, delta = -1;
    for (int i = start; i != end; i += delta)
        if (free[i] && (num[i] % mod == 0))
        {
            free[i] = false;
            std::cout << num[i] << std::endl;
        }
}

int main() {
    int n, it;
    std::cin >> n >> it;
    std::vector<bool> free(n, true);
    std::vector<int> num(n);
    for (int i = 0; i < n; ++i)
        std::cin >> num[i];

    std::vector<long> primes = get_primes(it);
    /*for (auto a : primes) {
        std::cout << a << " ";
    }
    std::cout << std::endl << std::endl;*/
    bool is_forward = true;
    for (int p = 0; p < it; ++p) {
        do_pass(is_forward, free, num, primes[p]);
        is_forward = !is_forward;
    }
    do_pass(!is_forward, free, num, 1);

    return 0;
}