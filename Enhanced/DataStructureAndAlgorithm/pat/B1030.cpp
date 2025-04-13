//
// Created by GlokieYu on 25-4-3.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
/*
 *�������������������Ԫ�ظ��������ǿ����û�����������
 *�ģ�棺
 *while(��ָ��û�дﵽ��β)
 *{
 *while(��������Ŀ��Ҫ��)
 *{
 * *��ָ�벻��������������������������Ԫ��
 *}
 *�������Ž��bestRes
 *��ָ�벻�������Ƴ����ҵ����õ�Ԫ��
 *}
 *���ģ�棺
 *while(��ָ��û�дﵽ��β)
 *{
 *while(������ĿҪ��)
 *{
* *�������Ž��bestRes
 *��ָ�벻�������Ƴ��Ը��ý��
 *}
 * *��ָ�벻�������ƣ������ҵ�����������
 *}
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //��С������ģ��
        int left=0;
        int right=0;
        int minLength=0;
        int sum=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(sum>=target)
            {
                //����Ԫ��
                if(right-left+1<minLength||minLength==0)
                {
                    minLength=right-left+1;
                }
                //��ָ�벻�������ҵ����Ž��
                sum-=nums[left];
                left++;
            }
            //��������������ָ�������ҵ����������Ľ��
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
        ö��rightΪ�Ҷ˵�ķ������������������
        [l,r]֮������Ԫ�س˻���С��k
        [l+1,r] [l+2,r]����Ԫ�س˻���С��k
        ���Է�����rightΪ�Ҷ˵��ҷ���Ҫ��������������������l��r֮������и�������r-l+1
        */
        //ÿ���ҵ����ʵ�Ԫ�ؾͽ�sum+1
        while(right<nums.size())
        {
            prod=prod*nums[right];
            while(prod>=k)
            {
                prod/=nums[left];
                left++;
            }
            //�Ҵ������Ƴ����ҵ������������Ž�
            sum=sum+right-left+1;
            right++;
        }
        return sum;
    }
};
class Solution3 {
public:
    //����һ��hashmap����¼ÿ���ַ��Ƿ���ֹ�
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int left=0,right=0;
        int maxLength=0;
        unordered_set<char> duplicated;
        while(right<s.size())
        {
            while(duplicated.find(s[right])!=duplicated.end())//�������������ƶ���˵������������Ԫ��
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
    //��������ָ�룬һ��ָ����СԪ�أ�һ��ָ�����Ԫ�أ�
    //��СԪ�رȽ���һ�ֺ����Ԫ�������ƶ�һ����
    //�������ָ��Ĳ�ֵ��һ��������Ԫ��
    //���ֻ��һ��Ԫ�صĻ��϶�����
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