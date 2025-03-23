//
// Created by GlokieYu on 25-3-23.
//
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v, int target) {
    int i = 0, j = v.size() - 1;
    while (i <= j) //i>j means the searching area is empty
    {
        int m = i + (j - i) / 2; //avoid i+j is greater than the int
        if (v[m] < target) {
            i = m + 1;
        } else if (v[m] > target) {
            j = m - 1;
        } else {
            return m; //find
        }
    }
    return -1; //not found
}

int binarySearchIndex(vector<int> vec, int num) {
    int i = 0, j = vec.size() - 1;
    while (i <= j) {
        int m = (i + j) >> 1;
        if (num < vec[m]) {
            j = m - 1;
        } else if (num > vec[m]) {
            i = m + 1;
        } else {
            return m; //if find the sam element, insert its position
        }
    }
    //not found
    return i; //insert the position which is first greater
}

//deal the situation of repeated elements whose value is the same as targed
int binarySearchMultiIndex(vector<int> vec, int target) {
    int i = 0, j = vec.size() - 1;
    while (i <= j) {
        int m = (i + j) >> 1;
        if (target < vec[m]) {
            j = m - 1;
        } else if (target > vec[m]) {
            i = m + 1;
        } else {
            j = m - 1; //the most left element is in the left
        }
    }
    return i;
}

int leftMost(vector<int> vec, int target) {
    int i = 0, j = vec.size() - 1;
    while (i <= j) {
        int m = (i + j) >> 1;
        if (target > vec[m]) {
            i = m + 1;
        } else if (target < vec[m]) {
            j = m - 1;
        } else {
            j = m - 1;
        }
    }
    // i is the left most target or empty
    if (i == vec.size() || vec[i] != target) { return -1; }
    return i;
}

int rightMost(vector<int> vec, int tar) {
    int i = 0, j = vec.size() - 1;
    //the right most index of tar is the left most index of tar+1 -1
    while (i <= j) {
        int m = (i + j) >> 1;
        if (vec[m] < tar + 1) {
            i = m + 1;
        } else if (vec[m] > tar + 1) {
            j = m - 1;
        } else {
            j = m - 1; //the left most index of tar+1,is on the left side
        }
    }
    if (j == 0 || vec[j] != tar)
        return -1;
    return j;
}

int rightMost(vector<int> v, double target) {
    //using double, we can ignore the equal situation
    //i is the first greater element,j is the first smaller element
    target += 0.5;
    int i = 0, j = v.size() - 1;
    while (i <= j) {
        int m = (i + j) >> 1;
        if (target > v[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    if (j==0||v[j]!=target-0.5) {
        return -1;
    }
    return j;
}
int leftMost(vector<int> v,double target) {
    int i=0,j=v.size()-1;
    target -= 0.5;
    while (i<=j) {
        int m=(i+j)>>1;
        if (v[m]<target) {
            i=m+1;
        }else{j=m-1;}
    }
    if (i==v.size() || v[i]!=target+0.5) {
        return -1;
    }
    return i;
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binarySearchIndex(v, 9) << endl;
    cout << binarySearchIndex(v, 10) << endl;
    cout << endl;
    v.insert(v.begin() + 8, 9);
    v.insert(v.begin() + 8, 9);
    v.insert(v.begin() + 8, 9);
    for (int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i] << " ";
    }
    cout << endl;
    cout << binarySearchMultiIndex(v, 9) << endl;
    cout << leftMost(v, 10) << endl;
    cout << leftMost(v, (double)9) << endl;
    cout << endl;
    cout << rightMost(v, (double) 9) << endl;
    cout << rightMost(v, (double) 10) << endl;
    return 0;
}
