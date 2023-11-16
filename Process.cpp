

int YPoint(int x, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[2] - weight[0] * x) / (double)(weight[1]));
}


int YPoint2(int x,int i,int dim, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[i* dim +2] - weight[i* dim] * x) / (double)(weight[i* dim +1]));
}
