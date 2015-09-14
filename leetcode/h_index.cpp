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
    static bool cmp(int a, int b)
    {
        return a>b;
    };
    int hIndex(vector<int>& citations) {
        int paper_num = citations.size();
        //sort(citations.begin() , citations.end() , cmp);
        int h;
        bool ans = 0;
        for(h = paper_num-1; h>=0 ; h--)
        {
            int satisfy_num=0;
            if(citations[paper_num-1-h] >= h+1)
            {
                ans =1;
                break;
            }
        }
        if(ans ==1)
            return h+1;
        else
            return 0;
    }
};

//int main()
//{
//	Solution s;
//	int a[]={3, 0, 6, 1, 5};
//	vector<int> v(&a[0],&a[sizeof(a)/4]);
//	sort(v.begin(),v.end());
//	cout<<s.hIndex(v);
//	int iww;
//	cin>>iww;
//	return 0;
//}
