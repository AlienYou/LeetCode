/*************************************************************************
	> File Name: LeetCode_1266.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Feb 2020 12:37:26 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int MinTimeToVisitAllPoints(vector<vector<int>>& points)
{
    if (points.size() == 0)
        return 0;
    int minimumTime = 0;

    for (int i = 1; i <  points.size(); ++i)
    {
        int maxLength = 0x80000000;
        for (int j = 0; j < points[0].size(); ++j)
        {
            int diff = abs(points[i][j] - points[i - 1][j]);
            maxLength = maxLength > diff ? maxLength : diff;
        }
        minimumTime += maxLength;
    }
    return minimumTime;
}

void test(const char* testName, vector<vector<int>>& points, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (MinTimeToVisitAllPoints(points) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    int points[][2] = { {1, 1}, {3, 4}, {-1, 0} };
    vector<vector<int>> pointsVec;
    pointsVec.resize(3);
    for (int i = 0; i < 3; ++i)
        pointsVec[i].insert(pointsVec[i].begin(), *(points + i), *(points + i) + 2);
    test("Test1", pointsVec, 7);
}

void test2()
{
    int points[][2] = { {3, 2}, {-2, 2} };
    vector<vector<int>> pointsVec;
    pointsVec.resize(2);
    for (int i = 0; i < 2; ++i)
        pointsVec[i].insert(pointsVec[i].begin(), *(points + i), *(points + i) + 2);
    test("Test2", pointsVec, 5);
}

int main()
{
    test1();
    test2();
}
