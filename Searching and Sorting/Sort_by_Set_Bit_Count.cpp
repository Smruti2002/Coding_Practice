/* https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1 */

class solution {
  public:
    
    static bool compare (int a , int b)
    {
        int set_a = __builtin_popcount(a);
        int set_b = __builtin_popcount(b);
        if(set_a > set_b)
            return true;
        return false;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,compare);
    }
};
