#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void insertionSort(vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        int j = i, temp = vec[i];
        while (j > 0 && temp < vec[j - 1]) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = temp;
    }
}

vector<int> selectionSort(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        //the last element is definitely the greatest
        int k = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[k])
                k = j;
        }
        swap(vec[i], vec[k]);
    }
    return vec;
}

vector<int> bubbleSort(vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }

    return vec;
}

vector<int> bubbleSortWithFlag(vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
            flag = true;
        }
        if (!flag) {
            return vec;
        }
    }
    return vec;
}

int getMedian(vector<int> nums, int left, int mid, int right) {
    int l = nums[left], m = nums[mid], r = nums[right];
    if (l < m && m < r || r < m && m < l)
        return mid;
    if (m < l && l < r || r < l && l < m)
        return left;
    return right;
}

int partitionWithMedian(vector<int> &nums, int left, int right) {
    int mid = getMedian(nums, left, (left + right) / 2, right);
    //exchange left and mid
    swap(nums[left], nums[mid]);
    int i = left, j = right;
    while (i < j) {
        while (nums[j] > nums[left])
            j--;
        while (nums[i] < nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

int partition(vector<int> &nums, int left, int right) {
    //left is the base
    int i = left, j = right;
    while (i < j) {
        //from right to find the element less than base
        while (nums[j] > nums[left])
            j--;
        //from left to find the one greater than base
        while (nums[i] < nums[left])
            i++;
        //found,swap
        swap(nums[i], nums[j]);
    }
    //i is greater than j
    //swap base to the edge
    swap(nums[i], nums[left]);
    return i;
}

void quickSort(vector<int> &nums, int left, int right) {
    // if (left >= right)
    //     return; //the array only has one or zero element
    while (left < right) {
        int pivot = partitionWithMedian(nums, left, right);
        // quickSort(nums,pivot+1,right);
        // quickSort(nums,left,pivot-1);
        //栈帧空间优化
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1);
            left = pivot + 1;
        } else {
            quickSort(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

//void merge(vector<int> &nums, int left, int mid, int right) {
//    //create an temp array to record.
//    vector<int> temp;
//    //merge the smallest
//    int i = left, j = mid + 1;
//    while (i <= mid && j <= right) {
//        if (nums[i] < nums[j]) //left array element is smaller
//            temp.push_back(nums[i++]);
//        else //right array element is smaller
//            temp.push_back(nums[j++]);
//    }
//    //one array part has been inserted already
//    while (i <= mid)
//        temp.push_back(nums[i++]);
//    while (j <= right)
//        temp.push_back(nums[j++]);
//
//    //assign temp to nums
//    for (int k = 0; k < temp.size(); k++) {
//        nums[left + k] = temp[k];
//    }
//}
//
//void mergeSort(vector<int> &nums, int left, int right) {
//    //the array only has one element
//    if (left >= right)
//        return;
//    //calculate the mid
//    int mid = left + (right - left) / 2;
//    //divede the left array
//    mergeSort(nums, left, mid);
//    //divide the right part
//    mergeSort(nums, mid + 1, right);
//    //merge
//    merge(nums, left, mid, right);
//}
void merge(vector<int> &nums,int left,int mid,int right){
      //using a temp array to store the ordered part
      vector<int> temp;
      //insert the smallest part
      int i=left,j=mid+1,k=0;
      while(i<=mid&&j<=right){
        //left part is smalller
        if(nums[i]<nums[j])
          temp.push_back(nums[i++]);
        else temp.push_back(nums[j++]);
      }
      //insert the not inserted part
      while(i<=mid)
        temp.push_back(nums[i++]);
      while(j<=right)
        temp.push_back(nums[j++]);
      //input
      for(int i=0;i<temp.size();i++)
      {
        nums[left+i]=temp[i];
      }
}
void mergeSort(vector<int> &nums,int left,int right){
  if(left>=right)//one element
    return;
  //divide the left array to one element, the right element array to one element
  int mid=left+(right-left)/2;
  mergeSort(nums,left,mid);
  mergeSort(nums,mid+1,right);
  //merge the ordered part
  merge(nums,left,mid,right);
}
//堆排序
//因为堆顶元素一直弹出要用n来收缩范围
void siftDown(vector<int> & nums,int n,int i) {
    while (true) {
        int l=2*i+1;
        int r=2*i+2;
        int max=i;
        if (l<n&&nums[l]>nums[max])//using max not i here to avoid the right is greater
            max=l;
        if (r<n&&nums[r]>nums[max])
            max=r;
        if (max==i)
            //the sift down is over or l and r are greater than the range
                break;
        swap(nums[i],nums[max]);
        i=max;
    }
}
void heapSort(vector<int> &nums) {
    //make the array a heap
    for (int i=(nums.size()-1)/2;i>=0;i--) {
        siftDown(nums, nums.size(),i);
    }
    //get the max element
    //n-1 round
    for (int i=nums.size()-1;i>0;i--) {
        swap(nums[0],nums[i]);//move to last
        siftDown(nums,i,0);
    }
}
//bucket sort
void bucketSort(vector<double> vec) {
    //the num inside vec is from 0 to 1
    //creater n/2 buckets
    int k = vec.size() / 2;
    vector<vector<double>> buckets(k);
    //using num*k to map the num to buckets
    for (double num : vec) {
        buckets[num * k].push_back(num);
    }
    //sort every small bucket
    for (int i = 0;i < k;i++) {
        sort(buckets[i].begin(),buckets[i].end());
    }
    for (int i = 0;i < buckets.size();i++) {
        for (int j = 0;j < buckets[i].size();j++) {
            cout << buckets[i][j] << " ";
        }
    }
}
void countingSort(vector<int>& nums)
{
    //1.get the max value
    int m = 0;
    for (int num : nums) {
        m = max(num, m);
    }
    //2.create an array whose size is m
    vector<int> counter(m + 1, 0);
    for (int num : nums)
    {
        counter[num]++;
    }
    //traverse the counter and put the index with its counts to the original nums
    nums.clear();
    for (int i=0;i<m+1;i++) 
    {
        if (counter[i] != 0)
            for(int j=0;j<counter[i];j++)
            nums.push_back(i);
    }
}

void fullCountingSort(vector<int>&nums) 
{
    //get the max element
    int m = 0;
    for (int num:nums) 
    {
        m=max(num,m);
    }
    //create a vector whose size is m+1 and count num
    vector<int> counter(m+1,0);
    //count
    for (int num:nums) 
    {
        counter[num]++;
    }
    //change the count of elements to its prefix
    //this step change the counts of element to its index+1 
    for (int i=0;i<counter.size()-1;i++) 
    {
        counter[i + 1] += counter[i];
    }
    //traverse the nums from the last element, insert it to a temp array
    vector<int> temp(nums.size());
    for (int i=nums.size()-1;i>=0;i--) 
    {
        temp[counter[nums[i]] - 1] = nums[i];
        counter[nums[i]]--;
    }
    //assign the temp to original vector
    nums = temp;
}

int getDigit(int num,int exp)//exp=10^k-1
{
    return num /exp%10;
}

void countingSortRadix(vector<int> &nums,int exp) 
{
    vector<int> counter(10,0);
    //get the digit and count the element
    for (int i=0;i<nums.size();i++) 
    {
        int digit = getDigit(nums[i],exp);
        counter[digit]++;
    }
    //get the prefix, turning the counts to index+1
    for (int i=0;i<9;i++) 
    {
        counter[i + 1] += counter[i];
    }
    //traverse the original vector reversely,and put element to a new vector
    vector<int> temp(nums.size(),0);
    for (int i=nums.size()-1;i>=0;i--) 
    {
        //we should get the digit to map the index here
        int digit = getDigit(nums[i],exp);
        temp[counter[digit]-1] = nums[i];
        counter[digit]--;
    }
    //assign the temp to original nums
    for(int i=0;i<nums.size();i++)
    {
        nums[i] = temp[i];
    }
}
void radixSort(vector<int> &nums) //适用于整数，且位数一致并较大的时候，如学号
{
    //get the max element to get the number of digit
    int m = 0;
    for (int num:nums) 
    {
        m = max(m, num);
    }
    for (int exp=1;exp<=m;exp*=10) 
    {
        countingSortRadix(nums,exp);
    }
}
int main() {
    vector<int> vec;
    for (int i = 6; i >= 0; i--) {
        vec.push_back(i);
    }
    //vector<double> doubleVec = {0.1,0.3,0.2,0.7,0.5,0.4,0.3};
    //bucketSort(doubleVec);
    //fullCountingSort(vec);
    vector<int> vec2 = { 780245,581746,581735,666666,999999 };
    radixSort(vec2);
    for (int i=0;i<vec2.size();i++) 
    {
        cout << vec2[i] << " ";
    }
    return 0;
}
