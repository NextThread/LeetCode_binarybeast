class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
	int n = points.size();
	int count = 0;
	double d2r = 3.14/180.00;
	int res = 0;

	for(int i = 0; i < n; i++){
		double pa = points[i][0];
		double pb = points[i][1];

		for(int ang = 0; ang < 360; ang++){
			// center of the circle
			double a = pa + (double)r*cos(d2r*ang);
			double b = pb + (double)r*sin(d2r*ang);

			int count = 0;
			for(int k = 0; k < n; k++){
				double dist = sqrt(pow(a-points[k][0], 2) + pow(b-points[k][1], 2));

				if(dist <= (double)(r+0.01)){
					count += 1;
				}
			}
			res = max(res, count);
		}
	}

	return res;
}
};