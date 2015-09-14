#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Forward declaration of isBadVersion API.
//2126753390 versions, 1702766719 is the first bad version.
bool isBadVersion(unsigned int version)
{
    if(version >= 1702766719)
        return 1;
    else
        return 0;
}

class Solution {
public:
    unsigned int firstBadVersion(unsigned int n) {
        unsigned int left = 1;
        unsigned int right = n;
        while(left <= n && right >= 1)
        {
            unsigned int mid = (left + right)/2;
            if(isBadVersion(mid) == 1)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
            if(right == left+1 || right == left)
                    return right;
        }
        return 0;
    }
};

//int main()
//{
//    Solution s;
//    cout<<s.firstBadVersion(2126753390)<<endl;
//    unsigned int i;
//    cin>>i;
//    return 0;
//}