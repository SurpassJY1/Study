//
// Created by GlokieYu on 25-3-24.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    long T;
    cin >> T;
    for (long i = 0; i < T; i++) {
        long A, B, C;
        cin >> A >> B >> C;
        if (A+B>C) {
            cout<<"Case #"<<(i+1)<<": true"<<endl;
        }else
            cout<<"Case #"<<(i+1)<<": false"<<endl;
    }
    return 0;
}
//
// Created by GlokieYu on 25-3-24.
//
