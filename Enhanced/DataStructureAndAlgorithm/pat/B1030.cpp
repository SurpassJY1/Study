//
// Created by GlokieYu on 25-4-3.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
/*
 *这道题是求最大子数组的元素个数的我们可以用滑动窗口来解
 *最长模版：
 *while(右指针没有达到结尾)
 *{
 *while(不满足题目的要求)
 *{
 * *左指针不断往右移抛弃掉不满足条件的元素
 *}
 *更新最优结果bestRes
 *右指针不断往右移尝试找到更好的元素
 *}
 *最短模版：
 *while(右指针没有达到结尾)
 *{
 *while(满足题目要求)
 *{
* *更新最优结果bestRes
 *左指针不断往右移尝试更好结果
 *}
 * *右指针不断往右移，尝试找到符合条件的
 *}
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //最小子数组模版
        int left=0;
        int right=0;
        int minLength=0;
        int sum=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(sum>=target)
            {
                //更新元素
                if(right-left+1<minLength||minLength==0)
                {
                    minLength=right-left+1;
                }
                //左指针不断右移找到最优结果
                sum-=nums[left];
                left++;
            }
            //不符合条件，右指针右移找到符合条件的结果
            right++;
        }
        return minLength;
    }
};
class Solution2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0||k==1)
            return 0;
        int prod=1;
        int sum=0;
        int left=0;
        int right=0;
        /*
        枚举right为右端点的符合条件的子数组个数
        [l,r]之间所有元素乘积都小于k
        [l+1,r] [l+2,r]所有元素乘积都小于k
        所以符合以right为右端点且符合要求的连续子数组个数就是l，r之间的所有个数就是r-l+1
        */
        //每次找到合适的元素就将sum+1
        while(right<nums.size())
        {
            prod=prod*nums[right];
            while(prod>=k)
            {
                prod/=nums[left];
                left++;
            }
            //右窗口右移尝试找到满足条件最优解
            sum=sum+right-left+1;
            right++;
        }
        return sum;
    }
};
class Solution3 {
public:
    //理由一个hashmap来记录每个字符是否出现过
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int left=0,right=0;
        int maxLength=0;
        unordered_set<char> duplicated;
        while(right<s.size())
        {
            while(duplicated.find(s[right])!=duplicated.end())//不满足条件，移动左端点抛弃不满足的元素
            {
                duplicated.erase(s[left]);
                left++;
            }
            duplicated.emplace(s[right]);
            right++;
            if(right-left>maxLength)
                maxLength=right-left;
        }
        return maxLength;
    }
};
int main()
{

    long n;
    long p;
    cin>>n>>p;
    long count=0;
    vector<long> nums;
    for(int i=0;i<n;i++)
    {
        long num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    //利用两根指针，一个指向最小元素，一个指向最大元素，
    //最小元素比较完一轮后最大元素向左移动一根，
    //最后两个指针的差值加一就是最多的元素
    //如果只有一个元素的话肯定可以
    for(long i=nums.size()-1;i>=0;i--)
    {
        for(long j=0;j<=i;j++)
        {
            if(nums[i]<=nums[j]*p)
            {
                count=i-j+1;
                break;
            }
        }
        if(count>0)
            break;
    }
    cout<<count<<endl;
    return 0;
}