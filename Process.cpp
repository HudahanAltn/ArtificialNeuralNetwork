

int YPoint(int x, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[2] - weight[0] * x) / (double)(weight[1]));
}

