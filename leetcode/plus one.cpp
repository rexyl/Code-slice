#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;

 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
		int carry = 1;
		for(int i=size-1;i>=0;i--)
		{
			if(digits[i] + carry > 9)
			{
				digits[i] = digits[i] + carry - 10;
				carry = 1;
			}
			else
			{
				digits[i] = digits[i] + carry;
				carry = 0;
			}
		}
		if(carry == 1)
		{
			digits.insert(digits.begin() , 1);
		}
		return digits;
    }
};

int main()
{
	Solution s;
	
	int a[] = {9,9,9,9,9};
	vector<int> v(&a[0],&a[sizeof(a)/4]);
	v = s.plusOne(v);
	
	int iww;
	cin>>iww;
	return 0;
}
