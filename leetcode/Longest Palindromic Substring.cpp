#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t size = s.size() ;
        if (size == 1) {
            return s;
        }
        int index , maxlen = INT_MIN;
        string result = "";
        for (index=0; index<size; index++) {
            //for double core
            int i = index,j = index + 1;
            char temp = s[i];
            while (i>=0 && j<size) {
                if (s[i] != s[j]) {
                    break;
                }
                i--;
                j++;
            }
            i++;
            j--;
            if(maxlen < j-i+1 &&j>=i)
            {
                maxlen  = j-i+1;
                result = s.substr(i,j-i+1);
            }
            i = index;
            int step = 0;
            while (index+step<size && index-step>=0) {
                if (s[index+step]!=s[index-step]) {
                    break;
                }
                step++;
            }
            step--;
            if(maxlen < 1+step*2 && step != 0)
            {
                maxlen = 1+step*2;
                result = s.substr(i - step , 2*step+1);
            }
            
        }
        return result;
    }
};
/*int main()
{
    int a[] = {2,2,2,2};
    int b[] = {2,2,2};
    vector<int> v1(&a[0],&a[sizeof(a)/4]);
    vector<int> v2(&b[0],&b[sizeof(b)/4]);
    Solution s;
    string s1="jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";
    string s2 = s1.substr(2,3);
    cout<<s.longestPalindrome(s1);
    return 0;
}*/