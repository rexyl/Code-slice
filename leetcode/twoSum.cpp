#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		map<int,int> mymap;
		map<int,int>::iterator it;
        for(int i = 0; i<nums.size();i++)
        {
            int adder = target - nums[i];
			it = mymap.find(adder);
			if(it != mymap.end())
			{
				int ind = it->second;
				int first = min(i,ind);
                int second = max(i,ind);
                result.push_back(first+1);
                result.push_back(second+1);
                break;
			}
			mymap[nums[i]] = i;
			
           /* vector<int>::iterator index;
            index = find(nums.begin(), nums.end() , adder);
            if(index!=nums.end() && index!=nums.begin()+i)
            {
                int ind = index-nums.begin();
                int first = min(i,ind);
                int second = max(i,ind);
                result.push_back(first);
                result.push_back(second);
                break;
            }*/
        }
        return result;
    }
};

//int main()
//{
//    Solution s;
//    /*while(1)
//    {
//        string str;
//        cin>>str;cout<<endl;*/
//	vector<int> v;
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(4);
//    vector<int> result = s.twoSum(v,6);
//    
//    unsigned int i;
//    cin>>i;
//    return 0;
//}