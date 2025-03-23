//
// Created by GlokieYu on 25-3-23.
//
#include<vector>
#include<iostream>
#include <unordered_map>
using namespace std;
/*
给定一个整数数组 nums 和一个目标元素 target ，请在数组中搜索“和”为 target 的两个元素，并返回它们的数组索引。返回任意一个解即可。
 * */
//暴力枚举
vector<int> find(vector<int> nums,int target){
  for(int i=0;i<nums.size()-1;i++){
    for(int j=i+1;j<nums.size();j++){
      if(nums[i]+nums[j]==target){
        return vector<int>()={i,j};
      }
    }
  }
  return vector<int>();
}
//用hash表优化
vector<int> hashFind(vector<int> vec,int target) {
  unordered_map<int,int> hashMap;
  for (int i=0;i<vec.size();i++) {
    if (hashMap.find(target-vec[i]) != hashMap.end()) {
      return {hashMap[target-vec[i]],i};
    }
    hashMap.insert(make_pair(vec[i],i));
  }
}
int main(){
vector<int> v={1,2,3,4,5,6,7,8,9};
  vector<int> hash=hashFind(v,10);
for (int i=0;i<hash.size();i++) {
  cout<<hash[i]<<" ";
}
  return 0;
}