
#include<cmath>
int YPoint(int x, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[2] - weight[0] * x) / (double)(weight[1]));
}


int YPoint2(int x,int i,int dim, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[i* dim + 2] - weight[i * dim] * x) / (double)(weight[i* dim +1]));
}

float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}

int Test_Forward(float* x, double* weight, float* bias, int num_Class, int inputDim) {
	int i, j, index_Max;
	if (num_Class > 2) {
		int tempInputDim = 3;
		float* output = new float[num_Class];
		// Calculation of the output layer input
		for (i = 0; i < num_Class; i++) {
			output[i] = 0.0f;
			output[i] += weight[i * tempInputDim + 0] * x[0];
			output[i] += weight[i * tempInputDim + 1] * x[1];
			output[i] += -1*bias[i];
		}
		for (i = 0; i < num_Class; i++)
			output[i] = tanh(output[i]);

		float temp = output[0];
		index_Max = 0;
		for (i = 1; i < num_Class; i++)
			if (temp < output[i]) {
				temp = output[i];
				index_Max = i;
			}

		delete[] output;
	}
	else {
		float output = 0.0f;
		for (j = 0; j < inputDim; j++) {
			output += weight[j] * x[j];
		}
		output += bias[0];//bias aslýnda weight[2]
		output = tanh(output);
		if (output > 0.0f) {
			index_Max = 0;
		}else{
			index_Max = 1;
		}
	}
	return index_Max;

}//