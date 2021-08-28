/*
题目描述
为了更好的备战 NOIP2013 ，电脑组的几个女孩子 LYQ,ZSC,ZHQ 认为，我们不光需要机房，我们还需要运动，于是就决定找校长申请一块电脑组的课余运动场地，听说她们都是电脑组的高手，校长没有马上答应他们，而是先给她们出了一道数学题，并且告诉她们：你们能获得的运动场地的面积就是你们能找到的这个最大的数字。

校长先给他们一个 N\times NN×N 矩阵。要求矩阵中最大加权矩形，即矩阵的每一个元素都有一权值，权值定义在整数集上。从中找一矩形，矩形大小无限制，是其中包含的所有元素的和最大 。矩阵的每个元素属于 [-127,127][−127,127] ,例如

 0 –2 –7  0 
 9  2 –6  2
-4  1 –4  1 
-1  8  0 –2
在左下角：

9  2
-4  1
-1  8
和为15。

几个女孩子有点犯难了，于是就找到了电脑组精打细算的 HZH，TZY 小朋友帮忙计算，但是遗憾的是他们的答案都不一样，涉及土地的事情我们可不能含糊，你能帮忙计算出校长所给的矩形中加权和最大的矩形吗？

输入格式
第一行：nn ，接下来是 nn 行 nn 列的矩阵。

输出格式
最大矩形（子矩阵）的和。

输入输出样例
输入 #1复制
4
0 -2 -7 0
 9 2 -6 2
-4 1 -4  1 
-1 8  0 -2
输出 #1复制
15
说明/提示
n\le 120n≤120
*/
#include<bits/stdc++.h>
using namespace std;
int dp[121],mp[121][121],tem[121];
int ans=-999;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        memset(tem,0,sizeof(tem));
        memset(dp,0,sizeof(dp));
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                tem[k]+=mp[j][k];
            }
            for(int l=1;l<=n;l++)
            {
                dp[l]=max(dp[l],dp[l-1]+tem[l]);
                ans=max(ans,dp[l]);
            }
            memset(dp,0,sizeof(dp));

        }
    }
    cout<<ans;
    system("pause");
    return 0;
}