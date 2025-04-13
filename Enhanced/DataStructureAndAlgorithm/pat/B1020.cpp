#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>//setprecision�����ͷ�ļ�
using namespace std;
//ע������ܲ���������NΪ����
//���ÿ���±��ĵ�λ�ۼۣ�����������λ�ۼ۸ߵ�
class MoonCake
{
public:
    double m_Storage;
    int m_TotalPrice;
    double m_Price;
    MoonCake(double storage):m_Storage(storage)
    {
    }
};
bool myCompare(MoonCake cake1,MoonCake cake2)
{
    return cake1.m_Price>cake2.m_Price;
}
int main()
{
    int N;
    double D;
    cin>>N>>D;
    vector<MoonCake> cakes;
    for(int i=0;i<N;i++)
    {
        double storage;
        cin>>storage;
        cakes.push_back(MoonCake(storage));
    }
    for(int i=0;i<N;i++)
    {
        int totalPrice;
        cin>>totalPrice;
        cakes[i].m_TotalPrice=totalPrice;
        cakes[i].m_Price=(double)totalPrice/cakes[i].m_Storage;//����Ҫע�⾫��
    }
    sort(cakes.begin(),cakes.end(),myCompare);
    //���������С�ڵ��ڿ���±�������
    if(cakes[0].m_Storage>=D)
    {
        cout<<fixed<<setprecision(2)<<cakes[0].m_Price*D<<endl;
    }else if(cakes[0].m_Storage<D)//������������ڿ���±����ĵĴ���
    {
        double res=0;
        for(int i=0;i<N;i++)
        {
            if (D==0)
                break;
            //��ǰ���±���ʣ����������

            if(cakes[i].m_Storage>D)
            {

                res+=cakes[i].m_Price*D;
                D=0;
            }else
            {
                res+=cakes[i].m_Price*cakes[i].m_Storage;
                D-=cakes[i].m_Storage;
            }
        }
        cout<<fixed<<setprecision(2)<<res;
    }
    return 0;
}