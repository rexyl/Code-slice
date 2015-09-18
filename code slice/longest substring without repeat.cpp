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
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,-1);
        int left = 0 , min = 0;

        for(int i = 0 ; i<s.size() ; i++)
        {
        	if(map[s[i]] >= left ) // already occupied
        	{
        		int size = i - left;
        		if(size > min)
        		{
        			min = size;
        		}
        		left = map[s[i]]+1;
        	}
        	map[s[i]] = i;
        }
        min = s.size() - left > min ? s.size()-left : min;
        return min;
    }
};

//int main()
//{
//    Solution s;
//	/*while(1)
//	{
//		string str;
//		cin>>str;cout<<endl;*/
//		cout<<s.lengthOfLongestSubstring("Longest Substring Without Repeating Characters")<<endl;
//	
//    unsigned int i;
//    cin>>i;
//    return 0;
//}