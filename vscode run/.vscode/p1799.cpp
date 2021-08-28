/*
题目描述
虽然 msh 长大了，但她还是很喜欢找点游戏自娱自乐。有一天，她在纸上写了一串数字：1, 1, 2, 5, 41,1,2,5,4。接着她擦掉了一个 11，结果发现剩下 1, 2, 41,2,4 都在自己所在的位置上，即 11 在第 11 位，22 在第 22 位，44 在第 44 位。她希望擦掉某些数后，剩下的数列中在自己位置上的数尽量多。她发现这个游戏很好玩，于是开始乐此不疲地玩起来……不过她不能确定最多能有多少个数在自己的位置上，所以找到你，请你帮忙计算一下！

输入格式
第一行为一个数 nn，表示数列的长度。

接下来一行为 nn个用空格隔开的正整数，第 ii 行表示数 A_iA 
i
​
 。

输出格式
一行一个整数，表示擦掉某些数后，最后剩下的数列中最多能有多少个数在自己的位置上，即 A_i=iA 
i
​
 =i 最多能有多少。

输入输出样例
输入 #1复制
5
1 1 2 5 4
输出 #1复制
3
说明/提示
对于 20\%20% 的数据，n\leq 20n≤20;

对于 60\%60% 的数据，n\leq 100n≤100;

对于 100\%100% 的数据，n\leq 10^3n≤10 
3
 。
*/
#include<bits/stdc++.h>
using namespace std;
int f[1001][1001],a[1001];
int main()
{
    int ans;
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)            
        cin>>a[i];
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j>0)
                f[i][j]=f[i-1][j-1];
            f[i][j]=max(f[i][j],f[i-1][j]+(a[i]==i-j));
            ans=max(ans,f[i][j]);
        }
    }              
    cout<<ans;
    system("pause");
    return 0;
} 
