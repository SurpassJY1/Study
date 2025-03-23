#include<iostream>
#include<vector>
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
        for (int j = 0; j < vec.size() - 1; j++) {
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
int getMedian(vector<int> nums,int left,int mid,int right) {
int l=nums[left],m=nums[mid],r=nums[right];
    if (l<m&&m<r||r<m&&m<l)
        return mid;
    if (m<l&&l<r||r<l&&l<m)
        return left;
    return right;
}
int partitionWithMedian(vector<int> &nums,int left,int right) {
    int mid=getMedian(nums,left,(left+right)/2,right);
    //exchange left and mid
    swap(nums[left],nums[mid]);
    int i=left,j=right;
    while (i<j) {
        while (nums[j]>nums[left])
            j--;
        while (nums[i]<nums[left])
            i++;
        swap(nums[i],nums[j]);
    }
    swap(nums[left],nums[i]);
    return i;
}

int partition(vector<int> &nums, int left, int right) {
    //left is the base
    int i = left, j = right;
    while (i < j) {
        //from right to find the element less than base
        while (nums[j]>nums[left])
            j--;
        //from left to find the one greater than base
        while (nums[i]<nums[left])
            i++;
        //found,swap
        swap(nums[i], nums[j]);
    }
        //i is greater than j
    //swap base to the edge
    swap(nums[i],nums[left]);
    return i;
}
void quickSort(vector<int> &nums, int left, int right) {
    // if (left >= right)
    //     return; //the array only has one or zero element
    while (left < right) {
        int pivot=partitionWithMedian(nums,left,right);
        // quickSort(nums,pivot+1,right);
        // quickSort(nums,left,pivot-1);
        //Õ»Ö¡¿Õ¼äÓÅ»¯
        if (pivot-left<right-pivot) {
            quickSort(nums,left,pivot-1);
            left=pivot+1;
        }else {
            quickSort(nums,pivot+1,right);
            right=pivot-1;
        }
    }
}

int main() {
    vector<int> vec;
    for (int i = 6; i >= 0; i--) {
        vec.push_back(i);
    }
    quickSort(vec, 0, vec.size() - 1);
    for (int i: vec) {
        cout << i << " ";
    }
    return 0;
}
