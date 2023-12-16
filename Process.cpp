
#include<cmath>
int YPoint(int x, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[2] - weight[0] * x) / (double)(weight[1]));
}


int YPoint2(int x,int i,int dim, double* weight, int multiplier = 1) {

	return (int)((double)(-1 * (double)multiplier * weight[i* dim + 2] - weight[i * dim] * x) / (double)(weight[i* dim +1]));
}

int MultiLayer_Test_Forward(float* x, double* weightMiddle, float* biasMiddle, double* outWeights, float* outBias, int inputDim, int middleNeuronNumber)
{
int index_Max = 0;

	// Giriþ katmaný Feedforward
	float* middleLayerOutput = new float[middleNeuronNumber];
	for (int i = 0; i < middleNeuronNumber; i++) {
		middleLayerOutput[i] = 0.0f;

		for (int j = 0; j < (inputDim-1); j++) {
			middleLayerOutput[i] += weightMiddle[i * inputDim+j] * x[j];
		}
		middleLayerOutput[i] += biasMiddle[i];
		middleLayerOutput[i] = tanh(middleLayerOutput[i]);
	}

	// Çýkýþ katmaný Feedforward
	float output = 0.0f;
	for (int j = 0; j < middleNeuronNumber; j++) {
		output += outWeights[j] * middleLayerOutput[j];
	}
	output += outBias[0];
	output = tanh(output);

	if (output > 0.0f) {
		index_Max = 0;
	}
	else {
		index_Max = 1;
	}

	delete[] middleLayerOutput;

	return index_Max;
}