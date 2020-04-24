/*************************************************************************
	> File Name: 01Bag.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Apr 2020 11:10:23 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1010;
int res[N];
int vol[N], value[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> vol[i] >> value[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (j >= vol[i])
                res[j] = max(res[j], res[j - vol[i]] + value[i]);
        }
    }
    cout << res[m] << endl;
    return 0;
}
