//
// Created by GlokieYu on 25-3-24.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>//used to control the double
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> leaveTwo;
    vector<int> leaveThree;
    vector<int> leaveFour;
    bool flag =false;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0;
    for (int i = 0; i < N; i++) {
        if (nums[i] % 2 == 0 && nums[i] % 5 == 0)
            A1 += nums[i];
        if (nums[i] % 5 == 1) {
            flag=true;
            leaveTwo.push_back(nums[i]);
        }
        if (nums[i] % 5 == 2)
            A3++;
        if (nums[i] % 5 == 3)
            leaveThree.push_back(nums[i]);
        if (nums[i] % 5 == 4)
            leaveFour.push_back(nums[i]);
    }
    double sum = 0;
    if (leaveTwo.size() > 0) {
        for (int i = 0; i < leaveTwo.size(); i++) {
            if ((i+1)%2==1) {
                A2+=leaveTwo[i];
            }else A2-=leaveTwo[i];
        }
    }

    if (leaveThree.size() > 0) {
        for (int i=0;i<leaveThree.size();i++) {
            sum+=leaveThree[i];
        }
        A4 = sum / leaveThree.size();
    }
    if (leaveFour.size() > 0) {
        sort(leaveFour.begin(), leaveFour.end());
        A5 = leaveFour[leaveFour.size() - 1];
    }
    if (A1 != 0)
        cout << A1 << " ";
    else
        cout << "N" << " ";

    if ( flag)//A2可能数字相加为0，如果直接A2不等于0最后一个测试点过不了
        cout << A2 << " ";
    else
        cout << "N" << " ";

    if (A3 != 0)
        cout << A3 << " ";
    else
        cout << "N" << " ";
    if (A4 != 0) {
        cout << fixed << setprecision(1) << A4 << " ";
    }
    else
        cout << "N" << " ";
    if (A5 != 0)
        cout << A5;
    else
        cout << "N";
    return 0;
}
