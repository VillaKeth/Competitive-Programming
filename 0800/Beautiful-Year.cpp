#include <iostream>
#include <set>

// beautiful year
int main() {
    int y;
    std::cin >> y;
    y++;
    while(1)
    {
        std::set<int> sp;
        int tempY = y;
        bool flag = true;
        while(tempY != 0)
        {
            int temp = tempY%10;
            if(sp.find(temp) != sp.end())
            {
                flag = false;
                break;
            }
            sp.insert(temp);
            tempY /= 10;
        }
        if(flag)
        {
            break;
        }
        y++;
    }
    std::cout << y;
    return 0;
}
