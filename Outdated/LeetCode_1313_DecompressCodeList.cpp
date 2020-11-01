/*************************************************************************
	> File Name: LeetCode_1313_DecompressCodeList.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2020 07:00:39 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;


vector<int> DecompressRLElist(vector<int>& nums)
{
    vector<int> result;
    if (nums.size() <= 0 || ((nums.size() & 0x1) != 0))
        return result;
    
    for (int i = 0; i < nums.size(); i += 2)
    {
        for (int j = 0; j < nums[i]; j++)
            result.push_back(nums[i + 1]);
    }
    return result;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = DecompressRLElist(nums);
    vector<int>::const_iterator it = result.begin();
    for (; it != result.end(); it++)
        printf("%d ", *it);
}

void test1()
{
    int nums[] = {1, 2, 3, 4};
    vector<int> numsVec(nums, nums + 4);
    test("Test1", numsVec);
}

int main()
{
    test1();
}
