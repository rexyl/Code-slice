#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <ctime>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
using namespace std;

template <typename T>
void merge_sort(vector<T>& array) {
    if (1 < array.size()) {
        vector<T> array1(array.begin(), array.begin() + array.size() / 2);
        merge_sort(array1);
        vector<T> array2(array.begin() + array.size() / 2, array.end());
        merge_sort(array2);
        merge (array1.begin(),array1.end(),array2.begin(),array2.end(),array.begin());
    }
}

//void merge_sort_thread(vector<int>& array) {
//    if (1 < array.size()) {
//        vector<int> array1(array.begin(), array.begin() + array.size() / 2);
//        thread first(merge_sort_thread,array1);
//        
//        vector<int> array2(array.begin() + array.size() / 2, array.end());
//        thread second(merge_sort_thread,array2);
//        first.join(); //wait for both ended
//        second.join();
//        merge (array1.begin(),array1.end(),array2.begin(),array2.end(),array.begin());
//    }
//}

//template <typename T>
//void merge_sort_thread_arbi(vector<T>& array,int i) {
//    if (1 < array.size()) {
//        vector<T> array1(array.begin(), array.begin() + array.size() / i);
//        thread first(merge_sort_thread_arbi,array1,i);
//        vector<T> array2(array.begin() + array.size() / i, array.end());
//        thread second(merge_sort_thread_arbi,array2,i);
//        first.join(); //wait for both ended
//        second.join();
//        merge (array1.begin(),array1.end(),array2.begin(),array2.end(),array.begin());
//    }
//}

int main()
{
    clock_t timer1,timer2;
    timer1 = clock();
    int a[] = {2,1,3,4,5,7,9,1,3,3,3};
    vector<int> v1(&a[0],&a[sizeof(a)/4]);
    merge_sort(v1);
    timer2 = clock();
    cout<<double(timer2-timer1)/CLOCKS_PER_SEC;
    string s(" United  state of America");
    vector<string> strs;
    boost::split(strs, s, boost::is_any_of( " " ));
    for (int i=0; i<strs.size(); i++) {
        cout<<strs[i]<<endl;
    }
    return 0;
}
