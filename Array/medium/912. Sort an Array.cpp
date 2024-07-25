//Quick Sort
class Solution {
public:
    int partition(int low, int high, vector<int>& nums) {
        int pivot = nums[high];
        int pi = low;
        for (int i = low; i < high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[pi], nums[i]);
                pi++;
            }
        }
        swap(nums[pi], nums[high]);
        return pi;
    }

    void quickSort(int low, int high, vector<int>& nums) {
        if (low >= high) return;
        int pi = partition(low, high, nums);
        quickSort(low, pi - 1, nums);
        quickSort(pi + 1, high, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }
};

//mergeSort
class Solution {
public:
   void merge(int low,int mid,int high,vector<int>&nums){
    vector<int>temp(high-low+1);
    int i  = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i];
            i++;
        }else{
            temp[k++] = nums[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++] = nums[i];
        i++;
    }
    while(j<=high){
        temp[k++] = nums[j];
        j++;
    }
    for(int i = low;i<=high;i++){
        nums[i] = temp[i-low];
    }
   }
   void mergeSort(int low,int high,vector<int>&nums){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(low,mid,nums);
    mergeSort(mid+1,high,nums);
    merge(low,mid,high,nums);
   }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};
