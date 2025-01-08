#include <iostream>
#include <vector>
#include <map>

// inaccurate subsequence search
int main() {
    long long t, n, m, k;
    std::cin >> t;
    while(t-- > 0)
    {
        std::cin >> n >> m >> k;
        std::vector<long long> bruh(n);
        std::vector<long long> b(m);
        std::map<long long, long long> mp;
        std::map<long long, long long> cmp;
        long long count = 0;
        long long curCount = 0;
        for(int i = 0; i < n; i++)
        {
            std::cin >> bruh[i];
        }
        for(int i = 0; i < m; i++)
        {
            std::cin >> b[i];
            mp[b[i]]++;
        }
        
        for(int i = 0; i < m; i++)
        {
            if(mp[bruh[i]])
            {
                if(cmp[bruh[i]] < mp[bruh[i]])
                {
                    curCount++;
                }
                cmp[bruh[i]]++;
            }
        }
        if(curCount >= k)
        {
            count++;
        }
        for(int i = m; i < n; i++)
        {
            if(mp[bruh[i-m]])
            {
                if(cmp[bruh[i-m]] <= mp[bruh[i-m]])
                {
                    curCount--;
                }
                cmp[bruh[i-m]]--;
            }
            if(mp[bruh[i]])
            {
                if(cmp[bruh[i]] < mp[bruh[i]])
                {
                    curCount++;
                }
                cmp[bruh[i]]++;
            }
            if(curCount >= k)
            {
                count++;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
