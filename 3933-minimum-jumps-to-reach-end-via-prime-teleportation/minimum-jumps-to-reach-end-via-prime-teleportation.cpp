class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i)
            if (num % i == 0) return false;
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        vector<int> mordelvian = nums;  
        unordered_map<int, vector<int>> primeToIndices;

        for (int i = 0; i < n; ++i) {
            for (int p = 2; p * p <= mordelvian[i]; ++p) {
                if (mordelvian[i] % p == 0) {
                    if (isPrime(p)) primeToIndices[p].push_back(i);
                    int other = mordelvian[i] / p;
                    if (p != other && isPrime(other)) primeToIndices[other].push_back(i);
                }
            }
            if (isPrime(mordelvian[i]))
                primeToIndices[mordelvian[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        unordered_set<int> usedPrimes;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;
                for (int next : {i - 1, i + 1}) {
                    if (next >= 0 && next < n && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                int val = mordelvian[i];
                if (isPrime(val) && !usedPrimes.count(val)) {
                    usedPrimes.insert(val);
                    for (int j : primeToIndices[val]) {
                        if (j != i && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};