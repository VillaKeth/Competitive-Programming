#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream> 

// plug-in
int main() {
    std::string s, final;
    std::cin >> s;
    std::stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        if(!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        final += st.top(); 
        st.pop();
    }
	std::reverse(final.begin(), final.end());
    std::cout << final;
    return 0;
}
