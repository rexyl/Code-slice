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
    string addBinary(string a, string b) {
        if(a.size() == 0)
			return b;
		if(b.size() == 0)
			return a;
		unsigned long ia = atoi(a.c_str());
		unsigned long ib = atoi(b.c_str());
		unsigned long sum = ia+ib;
		string result = "";
		int i;
		if(sum == 0)
			return "0";
		while(sum != 0)
		{
			unsigned long r = sum%10;
			if(r >=2 )
			{
				stringstream ss;
				ss<<r-2;
				string temp;
				ss>>temp;
				result = temp + result;
				sum = sum/10;
				sum++; //carry
			}
			else
			{
				stringstream ss;
				ss<<r;
				string temp;
				ss>>temp;
				result = temp + result;
				sum = sum/10;
			}
		}
		return result;
		
    }
};

//int main()
//{
//	Solution s;
//	string str;
//	str = s.addBinary("1110110101","1110111011");
//	cout<<str<<endl;
//	int iww;
//	cin>>iww;
//	return 0;
//}
