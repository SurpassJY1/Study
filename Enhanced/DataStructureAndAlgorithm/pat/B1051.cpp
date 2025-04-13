#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
    double R1;
    double P1;
    double R2;
    double P2;
    cin>>R1>>P1>>R2>>P2;
    double realNum=R1*cos(P1)*R2*cos(P2)-R1*sin(P1)*R2*sin(P2);
    double pNum=R1*sin(P1)*R2*cos(P2)+R1*cos(P1)*R2*sin(P2);
    if(realNum>0&&realNum>=0.01)
        cout<<fixed<<setprecision(2)<<realNum;
    else if(realNum<0)
        cout<<"-"<<fixed<<setprecision(2)<<(-realNum);
    if(pNum>0&&pNum>=0.01)
        cout<<"+"<<fixed<<setprecision(2)<<pNum<<"i";
    else if(pNum<0&&pNum<=-0.01)
        cout<<"-"<<fixed<<setprecision(2)<<(-pNum)<<"i";
    if(realNum==0||realNum<0.01&&realNum>0||realNum>-0.01&&realNum<0){
        if(pNum>=0.01)
        {
            cout<<fixed<<setprecision(2)<<pNum;
        }else if(pNum<=-0.01)
        {
            cout<<"-"<<fixed<<setprecision(2)<<pNum;
        }else
        {
            cout<<"0.00";
        }
    }
    return 0;
}
