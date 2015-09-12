#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        size_t size = s.size();
        string result="";
        if (numRows<=1) {
            return s;
        }
        int numberingroup = numRows + numRows - 2;
        int groups = size/(numberingroup);
        for(int row = 0; row < numRows ; row++)
        {
            for (int i = 0; i<=groups; i++) {
                int i1 = i*numberingroup + row;
                if (i1 < size) {
                    result += s[i1];
                }
                //result +=  s[i*numberingroup + row];
                if(row!=0 && row!=numRows-1)
                {
                    int index = (numRows-1)+ i*numberingroup + numRows - row - 1;
                    if (index < size) {
                        result += s[index];
                    }
                }
            }
        }
        return result;
    }
};

int main()
 {
     Solution s;
     string s1="ABCDE";
     string temp = s1 + 'c';
     string s2 = s1.substr(2,3);
     cout<<s.convert(s1, 4);
     return 0;
 }