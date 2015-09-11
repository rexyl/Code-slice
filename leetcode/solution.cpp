#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t s1 = nums1.size();
        size_t s2 = nums2.size();
        size_t sum = s1+s2;
        if (sum == 0) {
            return 0;
        }
        if(s2==0){
            if(s1%2 == 0){
                return (nums1[s1/2 - 1]+nums1[s1/2])/2.0;
            }
            else{
                return nums1[s1/2];
            }
        }
        if(s1==0){
            if(s2%2 == 0){
                return (nums2[s2/2 - 1]+nums2[s2/2])/2.0;
            }
            else{
                return nums2[s2/2];
            }
        }
        size_t index1 = (sum-1)/2;
        
        size_t i = 0 , j = 0 , index = 0;
        while (i+j<s1+s2-1) {
            if (nums1[i] < nums2[j]) {
                if (index == index1) {
                    if (sum%2 == 0) {
                        size_t second;
                        if (i+1<s1)
                            second = min(nums1[i+1],nums2[j]);
                        else
                            second = nums2[j];
                        return (second+nums1[i])/2.0;
                    }
                    else
                    {
                        return nums1[i];
                    }
                }
                index++;
                if (i+1<s1) {
                    i++;
                }
                else{
                    break;
                }
                
            }
            else if(nums1[i] >= nums2[j]){
                
                
                if (index == index1) {
                    if (sum%2 == 0) {
                        size_t second;
                        if (j+1<s2) {
                            second = min(nums1[i],nums2[j+1]);
                        }
                        else
                            second = nums1[i];
                        return (second+nums2[j])/2.0;
                    }
                    else{
                        return nums2[j];
                    }
                }
                index++;
                if (j+1<s2) {
                    j++;
                }
                else
                    break;
            }
        
        }
        if (i==s1-1) {
            j = j+index1-index;
            if (sum%2 == 0) {
                return (nums2[j]+nums2[j+1])/2.0;
            }
            else
                return nums2[j];
        }
        if (j==s2-1) {
            i = i+index1-index;
            if (sum%2 == 0) {
                return (nums1[i]+nums1[i+1])/2.0;
            }
            else
                return nums1[i];
        }
        return 0;
    }
};

int main()
{
    int a[] = {2,2,2,2};
    int b[] = {2,2,2};
    vector<int> v1(&a[0],&a[sizeof(a)/4]);
    vector<int> v2(&b[0],&b[sizeof(b)/4]);
    Solution s;
    cout<<s.findMedianSortedArrays(v1, v2);
    //int i;
    //cout<<"am i success?"<<endl;
    //cin>>i;
    return 0;
}