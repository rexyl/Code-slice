#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int missingNumberhelper(vector<int>& nums){
        int size = nums.size();
        if(size == 2)
        {
            return (nums[0] + nums[1])/2;
        }
        int mid_index = (0 + size-1)/2;
        double mid_num = nums[mid_index];
        if(mid_num < double( nums[0] + nums[size-1])/2 )//go right, include mid number
        {
            //vector<int> v(&nums[0],&nums[mid_index]);
			vector<int> v(&nums[mid_index],&nums[size-1]+1);
            return missingNumberhelper(v);
        }
        else //go left
        {
            //vector<int> v(&nums[mid_index],&nums[size-1]);
			vector<int> v(&nums[0],&nums[mid_index]+1);
            return missingNumberhelper(v);
        }
    }
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int size = nums.size();
		if(size == 0)
			return 0;
        if(size == 1&&nums[0]==0)
            return 1;
		if(size == 1&&nums[0]==1)
            return 0;
		if(nums[0]==1 && nums[1]==2)
			return 0;
		if(nums[size-1] == size-1)
			return size;
        return missingNumberhelper(nums);
    }
};
//int main()
//{
//	Solution s;
//	
//	int a[] = {36,23,26,31,41,49,18,11,45,48,35,7,5,33,21,30,22,32,29,34,2,12,19,46,25,39,0,4,10,37,24,42,20,9,28,16,17,43,44,47,38,1,8,15,27,13,6,40,14};
//	vector<int> v(&a[0],&a[sizeof(a)/4]);
//	/*
//	int range = rand()%100 + 1;
//	for(int times = 0 ; times < 1000 ; times ++)
//	{
//		int hole = rand()%range;
//		vector<int> v;
//		for(int i=0;i<range;i++)
//		{
//			if(i!=hole)
//			{
//				v.push_back(i);
//			}
//		}
//		int r = s.missingNumber(v);
//		if(r!=hole)
//			cout<<"something wrong!"<<endl;
//	}*/
//	int r = s.missingNumber(v);
//	
//	int iww;
//	cin>>iww;
//	return 0;
//}
