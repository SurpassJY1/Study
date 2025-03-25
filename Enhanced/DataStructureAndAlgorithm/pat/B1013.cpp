//
// Created by GlokieYu on 25-3-24.
//
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrim(int i) {
    if (i == 2)
        return true;
    if (i % 2 == 0)
        return false;
    //odd number
    for (int n = 3; n * n <= i; n += 2) {
        if (i % n == 0)
            return false;
    }
    return true;
}

vector<int> getPrim(int M, int N) {
    vector<int> res;
    int count = 0;
    int i = 2;
    while (count <= N) {
        if (isPrim(i))
            count++;
        if (M <= count && count <= N && isPrim(i)) {
            res.push_back(i);
        }
        i++;
    }
    return res;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> prim = getPrim(M, N);
    vector<vector<int> > ans;
    int count = 0;
    vector<int> temp;
    while (count < prim.size()) {
        temp.push_back(prim[count]);
        count++;
        if (count % 10 == 0) {
            ans.push_back(temp);
            temp.clear();
        }else if (count==prim.size()) {
            ans.push_back(temp);
            temp.clear();
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (j==ans[i].size()-1) {
                cout << ans[i][j]  ;
            }else
                cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
