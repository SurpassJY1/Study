//
// Created by GlokieYu on 25-3-29.
//
#include<iostream>
#include<vector>

using namespace std;


int partition(vector<int>&nums,int left,int right) {
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
void quickSort(vector<int>&nums,int left,int right) {
  if (left>=right)
    return;
  int pivot=partition(nums,left,right);
  quickSort(nums,0,pivot-1);
  quickSort(nums,pivot+1,right);
}
void merge(vector<int>&nums,int left,int m,int right) {
  int i=left,j=m+1;
  vector<int> temp;
  while (i<=m&&j<=right) {
    if (nums[i]<nums[j]) {
      temp.push_back(nums[i]);
      i++;
    }else {
      temp.push_back(nums[j]);
      j++;
    }
  }
  while (i<=m) {
    temp.push_back(nums[i]);
    i++;
  }
  while (j<=right) {
    temp.push_back(nums[j]);
    j++;
  }
  for (int i=0;i<temp.size();i++) {
    nums[left+i]=temp[i];
  }
}
void mergeSort(vector<int> &nums,int left,int right) {
  if (left>=right)
    return;
  int m=left+(right-left)/2;
  mergeSort(nums,left,m);
  mergeSort(nums,m+1,right);
  merge(nums,left,m,right);
}
int main()
{
  vector<int> vec;
  for(int i=3;i>=0;i--)
  {
    vec.push_back(i);
  }
   mergeSort(vec,0,vec.size()-1);
for (int var:vec) {
  cout<<var<<" ";
}
  return 0;
}
