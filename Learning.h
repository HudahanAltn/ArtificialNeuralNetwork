#pragma once
#include "Resource.h"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

bool perceptronLearning(Instance, double*, double);
double deltaLearning(Instance, double*, double);
double createNeuron(Instance instance, double* weights, int i, int dim, double c, double desiredOutput);
void feedForward(Instance, double*, double*, double, double*, double*, int, int);
double backForward(Instance, double*, double*, double, double*, double*, int, int);