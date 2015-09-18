#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        int div2 = 1 ,  div1= 1;
        while (x/div2 >= 10) {
            div2 *= 10;
        }
        while (div2>div1) {
            if (x/div2%10 != (x/div1)%10) {
                return false;
            }
            div1 *= 10;
            div2 /= 10;
        }
        return true;
    }
};
//int main()
// {
//     Solution s;
//     cout<<s.isPalindrome(1221);
//     return 0;
// }