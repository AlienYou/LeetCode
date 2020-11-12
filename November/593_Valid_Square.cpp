int dist(vector<int>& p1, vector<int>& p2){
	return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
	vector<vector<int>> point = {p1, p2, p3, p4};
	auto function = [](vector<int>& p1, vector<int>& p2){
		return p1[0] == p2[0] ? (p1[1] < p2[1]) : (p1[0] < p2[0]);
	};
	sort(point.begin(), point.end(), function);
	return dist(point[0], point[1]) != 0 && dist(point[0], point[1]) == dist(point[1], point[3])
		&& dist(point[1], point[3]) == dist(point[3], point[2]) 
		&& dist(point[2], point[0]) == dist(point[0], point[1])
		&& dist(point[0], point[3]) == dist(point[1], point[2]);
}