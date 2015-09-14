#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = 0;
        if (x<0) {
            neg = 1;
        }
        long y = abs(x);
        stringstream s;
        string num;
        s<<y;s>>num;
        std::reverse(num.begin(), num.end());
        if (y!=0) {
            int i = 0;
            while (num[i]=='0') {
                i++;
            }
            num = num.substr(i,num.size());
        }
        long result = std::atol(num.c_str());
        if (result > (long)INT_MAX) {
            return 0;
        }
        return neg == 1? (int)(-1*result):(int)result;
    }
};

int main()
 {
     Solution s;
     string s1="ABCDE";
     string temp = s1 + 'c';
     string s2 = s1.substr(2,3);
     stringstream ss;
     cout<<s.reverse(2381283);
     return 0;
 }