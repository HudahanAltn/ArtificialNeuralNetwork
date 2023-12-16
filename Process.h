#pragma once

int YPoint(int x, double* weight, int = 1);// x biliniyorsa y 'yi bulan fonksiyon.
int YPoint2(int x, int i, int dim, double* weight, int multiplier = 1);
int MultiLayer_Test_Forward(float* x, double* weightMiddle, float* biasMiddle,double* outWeights, float* outBias, int inputDim, int middleNeuronNumber);
