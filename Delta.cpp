#include "Learning.h"
#include "Process.h"
#include <cmath>



double sigmoidFunction(double net,double lambda) {

	return (2 / (1 + std::exp(lambda * net))) - 1;
}

double sigmoidFunctionDerivate(double sigmoidResult) {

	return 0.5 * (1 - std::pow(sigmoidResult,2));
}



double deltaLearning(Instance instance, double* weights, double c) {//bu fonksiyon her instance için bir hata deðeri döndürür.
	//tek nöronlu að c öðrenme sabiti 0.1
	// w1,w2,w3
	//bias x3 deðeri genelde 1 e eþit, net=W*x, output = f(net)
	double bias = -1, net = 0.0, derivateOutput = 0.0,sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
  
	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir örnek için net hesaplansýn.
	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];

	sigmoidOutput = sigmoidFunction(net, -1);
	derivateOutput = sigmoidFunctionDerivate(sigmoidOutput);// çýkýþ -1 veya + 1 olur.

	double error = 0.5 * pow(desiredOutput - sigmoidOutput, 2);
	

	weights[0] = weights[0] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x1;
	weights[1] = weights[1] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x2;
	weights[2] = weights[2] + c * (desiredOutput - sigmoidOutput) * derivateOutput * bias;
	
	return error;//aðýrlýklar eþit deðil ise hata = desiredOutput - output
}


double createNeuron(Instance instance, double* weights,int i,int dim, double c, double desiredOutput) {//bu fonksiyon her instance için bir hata deðeri döndürür.
	//çoklu nöronlu að c öðrenme sabiti 0.1
	// w1,w2,w3
	//bias x3 deðeri genelde 1 e eþit, net=W*x, output = f(net)
	double bias = -1, net = 0.0, derivateOutput = 0.0, sigmoidOutput = 0.0;
	

	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir örnek için net hesaplansýn.
	net = instance.x1 * weights[i * dim] + instance.x2 * weights[i * dim + 1] + bias * weights[i * dim + 2];

	sigmoidOutput = sigmoidFunction(net, -1);
	derivateOutput = sigmoidFunctionDerivate(sigmoidOutput);// çýkýþ -1 veya + 1 olur.

	double error = 0.5 * pow(desiredOutput - sigmoidOutput, 2);

	
	weights[i*dim] = weights[i * dim] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x1;
	weights[i * dim +1] = weights[i * dim + 1] + c * (desiredOutput - sigmoidOutput) * derivateOutput * instance.x2;
	weights[i * dim +2] = weights[i * dim + 2] + c * (desiredOutput - sigmoidOutput) * derivateOutput * bias;
	
	return error;//aðýrlýklar eþit deðil ise hata = desiredOutput - output
}

void feedForward(Instance instance, double* middleWeights, double* outWeights,double c,double*mFNetArray,double*oFNetArray,int mLayerSize,int oLayerSize) {

	//mNetArray noron+ bias sayýsý kadar elemanlý fnet deðerleirni tuutan dizi olsun.Msize direkt ara noron nasýyýsý olsun
	//oNetArray ise outputnet deðerlerini tutan dizi olsun. oSize'da output noron sayýsý kadar olsun.
	double inputBias = -1, middleBias = -1, derivateOutput = 0.0, sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
	int dim = 3;//Ýnput dimension daima sabit ve 3
	int middleLayerDim = mLayerSize + 1;
	//middleLayer.Msize = 2 veya 3 olblr

	for (int i = 0; i < mLayerSize; i++) {// ara katmanda 2 noron varsa 2 tane fnet hesaplýcak.6 tane middleweight var.
		int net = instance.x1 * middleWeights[i* dim] + instance.x2 * middleWeights[i* dim +1] + inputBias * middleWeights[i* dim +2];
		mFNetArray[i] = sigmoidFunction(net, -1);//fnet deðerini tutacak.burada 2 tane attýk fnet1 ve f net2
	}
	

	//outlayer.
	for (int i = 0; i < oLayerSize; i++) {//çýkýþta 1 tane noron var.3 tane ooutWightvar.outweigh sayýsý ile mNetarray sayýsý eþit.
		int net = 0;
		for (int j = 0; j < mLayerSize; j++) {//msize=2

			net += mFNetArray[j] * outWeights[i* middleLayerDim + j];
			
		}
		net += (-1) * outWeights[(i* middleLayerDim) + (mLayerSize)];
		oFNetArray[i] = sigmoidFunction(net, -1);//çýkýþnoronunun fneti.bu dizide 1 tane var.
	}
}

//feedforward tamam.
double backForward(Instance instance, double* middleWeights, double* outWeights, double c, double* mFNetArray, double* oFNetArray, int mLayerSize, int oLayerSize) {
	double inputBias = -1, middleBias = -1, net = 0.0, derivateOutput = 0.0, sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
	int dim = 3;
	int middleLayerDim = mLayerSize + 1;

	//out layer aðýrlýk güncllemeleri
	for (int i = 0; i < oLayerSize; i++) {
		for (int j = 0; j < mLayerSize ; j++) {
			outWeights[i* middleLayerDim + j] += c * (desiredOutput + oFNetArray[i]) * sigmoidFunctionDerivate(oFNetArray[i]) * mFNetArray[j];
		}
		outWeights[i * middleLayerDim + mLayerSize ] += c * (desiredOutput + oFNetArray[i]) * sigmoidFunctionDerivate(oFNetArray[i]) * (-1);
	}
	 //buraya kadar 2-1,3-1,2-2,3-2,4-2,2-3 aðlarýnda sorunsuz iþlem saðlandý.---------

	//middlelayer aðýrlýk güncellemeleri.Burada kaldýk.!!!!!!!!!!
	/*for (int i = 0; i < mSize; i++) {

		for (int j = 0; j < oSize; j++) {

			middleWeights[i * dim] += c * mNetArray[i] * instance.x1 * (desiredOutput - oNetArray[j]) * sigmoidFunctionDerivate(sigmoidFunction(oNetArray[0], -1)) * outWeights[mSize];
			middleWeights[i * dim + 1] += c * mNetArray[i] * instance.x2 * (desiredOutput - oNetArray[j]) * sigmoidFunctionDerivate(sigmoidFunction(oNetArray[0], -1)) * outWeights[mSize];
			middleWeights[i * dim + 2] += c * mNetArray[i] * inputBias * (desiredOutput - oNetArray[j]) * sigmoidFunctionDerivate(sigmoidFunction(oNetArray[0], -1)) * outWeights[mSize];

		}
		
	}
	double error = 0.5 * pow(desiredOutput - oNetArray[0], 2);*/


	//return error;//aðýrlýklar eþit deðil ise hata = desiredOutput - output
}