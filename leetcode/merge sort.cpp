template <typename T>
void merge_sort(std::vector<T>& array) {
    if (1 < array.size()) {
        std::vector<T> array1(array.begin(), array.begin() + array.size() / 2);
        merge_sort(array1);
        std::vector<T> array2(array.begin() + array.size() / 2, array.end());
        merge_sort(array2);
        merge(array, array1, array2);
    }
}