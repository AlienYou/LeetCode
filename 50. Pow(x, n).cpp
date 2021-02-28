double myPow(double x, int n) {
	long long int N = n;
	return N > 0 ? core(x, N) : 1 / core(x, -N);
}
double core(double x, long long int n){
	if (n == 0)
		return 1;
	double part = core(x, n / 2);
	part *= part;
	if (n & 1)
		part *= x;
	return part;
}