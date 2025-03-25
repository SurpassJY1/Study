#include<iostream>
#include<vector>
#include<list>
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
    for (int i=nums.size()/2-1;i>=0;i--) {
        siftDown(nums, nums.size(),i);
    }
    //get the max element
    //n-1 round
    for (int i=nums.size()-1;i>0;i--) {
        swap(nums[0],nums[i]);//move to last
        siftDown(nums,i,0);
    }
}


int main() {
    vector<int> vec;
    for (int i = 6; i >= 0; i--) {
        vec.push_back(i);
    }
    heapSort(vec);
    for (int i: vec) {
        cout << i << endl;
    }
    return 0;
}
