#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0)
            return "";
        if(s.size() < t.size())
            return "";
        vector<int> required(128,0);
        
        for(int j = 0;j<t.size();j++ ) //char in j is >=1 now, not in j is 0
            required[t[j]]++;
        int i=0,start=0,remain=t.size(), minlen = INT_MAX, left=0,right=0;
        while(i<=s.size() && start<s.size() )
        {
            if(remain)
            {
				if(i == s.size())
					break;
                int temp= --required[s[i]];
                if(temp >= 0) //once in t
                {
                    remain--;
                }
                i++;
            }
            else //all the char in j is found
            {
                int len = i - start;
                if(len < minlen)
                {
                    minlen = len;
                    left = start;
                    right = i+1;
                }
                if(required[s[start]] >= 0) //if it is currently just enough, or even need more
                {
                    remain++;
                }
                required[s[start]]++;
                start++;
            }
        }
        return minlen==INT_MAX ? "" : s.substr(left,minlen);
    }
};

//int main()
//{
//	Solution s;
//	cout<<s.minWindow("ab","a")<<endl;
//	int iww;
//	cin>>iww;
//	return 0;
//}
