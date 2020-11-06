int smallestDivisor(vector<int>& nums, int threshold) {
	int maxDivisor = 0;
	int size = nums.size();
	for (int i = 0; i < size; ++i){
		maxDivisor = max(nums[i], maxDivisor);
	}
	int left = 1, right = maxDivisor; 
	int res = maxDivisor;
	while (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		int sum = 0;
		for (int i = 0; i < size; ++i)
		{
			sum += nums[i] / mid + (nums[i] % mid ? 1 : 0);
		}
		if (sum > threshold)
			left = mid + 1;
		else 
			right = mid;
	}
	return left;
}