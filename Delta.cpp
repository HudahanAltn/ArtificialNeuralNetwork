#include "Learning.h"
#include "Process.h"
#include <cmath>



double sigmoidFunction(double net,double lambda) {

	return (2 / (1 + std::exp(lambda * net))) - 1;
}

double sigmoidFunctionDerivate(double sigmoidResult) {

	return 0.5 * (1 - std::pow(sigmoidResult,2));
}



double deltaLearning(Instance instance, double* weights, double c) {//bu fonksiyon her instance i�in bir hata de�eri d�nd�r�r.
	//tek n�ronlu a� c ��renme sabiti 0.1
	// w1,w2,w3
	//bias x3 de�eri genelde 1 e e�it, net=W*x, output = f(net)
	double bias = 1, net = 0.0, derivateOutput = 0.0,sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
  
	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir �rnek i�in net hesaplans�n.
	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];

	sigmoidOutput = sigmoidFunction(net, -1);
	derivateOutput = sigmoidFunctionDerivate(sigmoidOutput);// ��k�� -1 veya + 1 olur.

	double error = 0.5 * pow(desiredOutput - sigmoidOutput, 2);
	

	weights[0] = weights[0] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x1;
	weights[1] = weights[1] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x2;
	weights[2] = weights[2] + c * (desiredOutput - sigmoidOutput) * derivateOutput * bias;

	return error;//a��rl�klar e�it de�il ise hata = desiredOutput - output
}


double createNeuron(Instance instance, double* weights,int i,int dim, double c, double desiredOutput) {//bu fonksiyon her instance i�in bir hata de�eri d�nd�r�r.
	//�oklu n�ronlu a� c ��renme sabiti 0.1
	// w1,w2,w3
	//bias x3 de�eri genelde 1 e e�it, net=W*x, output = f(net)
	double bias = 1, net = 0.0, derivateOutput = 0.0, sigmoidOutput = 0.0;
	

	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir �rnek i�in net hesaplans�n.
	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];

	sigmoidOutput = sigmoidFunction(net, -1);
	derivateOutput = sigmoidFunctionDerivate(sigmoidOutput);// ��k�� -1 veya + 1 olur.

	double error = 0.5 * pow(desiredOutput - sigmoidOutput, 2);


	weights[i] = weights[0] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x1;
	weights[i+1] = weights[1] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x2;
	weights[i+2] = weights[2] + c * (desiredOutput - sigmoidOutput) * derivateOutput * bias;

	return error;//a��rl�klar e�it de�il ise hata = desiredOutput - output
}