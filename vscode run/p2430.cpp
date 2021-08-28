/*
题目背景
Lj的朋友WKY是一名神奇的少年，在同龄人之中有着极高的地位。。。

题目描述
他的老师老王对他的程序水平赞叹不已，于是下决心培养这名小子。

老王的训练方式很奇怪，他会一口气让WKY做很多道题，要求他在规定的时间完成。而老王为了让自己的威信提高，自己也会把这些题都做一遍。

WKY和老王都有一个水平值，他们水平值的比值和做这些题所用时间的比值成反比。比如如果WKY的水平值是1，老王的水平值是2，那么WKY做同一道题的时间就是老王的2倍。

每个题目有他所属的知识点，这我们都知道，比如递归，动归，最短路，网络流。在这里我们不考虑这些事情，我们只知道他们分别是知识点1，知识点2……每一个知识点有他对应的难度，比如动态规划经常难于模拟。

而每一个同一知识点下的题目，对于WKY来讲，都是一样难的。而做出每一道题，老王都有其独特的奖励值。而奖励值和题目的知识点没有必然联系。

现在WKY同学请你帮忙，计算在老王规定的时间内，WKY所能得到最大奖励值是多少 。

输入格式
输入文件包括以下内容：

第一行：

WKY的水平值和老王的水平值。

数据保证WKY的水平值小于老王的水平值（哪怕它不现实），且老王的水平值是WKY的水平值的整数倍。

第二行：

题目的总数m和知识点的总数n。

第三行：

n个整数。第i个整数表示 老王在做第i个知识点的题目所需的时间。

接下来有m行数每一行包括两个整数p，q。p表示该题目所属的知识点，q表示该题目对应的奖励值。

最后一行是规定的时间。

输出格式
输出文件只有一行，表示能到得到的最大奖励值。

输入输出样例
输入 #1复制
1 2
6 4
1 2 3 4
1 5
2 6
3 3
4 8
3 3
4 5
20
输出 #1复制
22
说明/提示
对于100%的数据，题目总数<=5000,规定时间<=5000
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int w,k;
}a[5001];
long long f[5001][5001],d[5001];//f[i][j]表示前i题剩余时间为j的最大奖励
long long ans=0;
int main()
{
    int l1,l2,n,m,p,q,time;
    cin>>l1>>l2>>m>>n;
    int ll=l2/l1;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        d[i]*=ll;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].k>>a[i].w;
        a[i].k=d[a[i].k];
    }
    cin>>time;
    for(int i=1;i<=time;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i>=a[j].k)
                f[j][i]=max(f[j-1][i-a[j].k]+a[j].w,f[j-1][i]);
            f[j][i]=max(f[j-1][i],f[j][i]);
            ans=max(ans,f[j][i]);
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}