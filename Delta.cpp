#include "Learning.h"
#include "Process.h"
#include <cmath>



double sigmoidFunction(double net,double lambda) {

	return (2 / (1 + std::exp(lambda * net))) - 1.0;
}

double sigmoidFunctionDerivate(double sigmoidResult) {

	return 0.5 * (1 - std::pow(sigmoidResult,2));
}


double softMax(double netk,double* netj,int mSize ) {

	double temp = 0.0;
	for (int i = 0; i < mSize; i++) {

		temp += std::exp(netj[i]);
	}
	return std::exp(netk) / temp;
}
double softMaxDerivate(double net,double desiredOutput) {

	return ((desiredOutput / net) + ((1 - desiredOutput) / (1 - net)));
}


double feedForward(Instance instance, double* middleWeights, double* outWeights,double c,double*mFNetArray,double*oFNetArray,int mLayerSize,int oLayerSize) {

	//mNetArray noron+ bias sayýsý kadar elemanlý fnet deðerleirni tuutan dizi olsun.Msize direkt ara noron nasýyýsý olsun
	//oNetArray ise outputnet deðerlerini tutan dizi olsun. oSize'da output noron sayýsý kadar olsun.
	double inputBias = -1.0, middleBias = -1.0, derivateOutput = 0.0, sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
	int dim = 3;//Ýnput dimension daima sabit ve 3
	int middleLayerDim = mLayerSize + 1;
	//middleLayer.Msize = 2 veya 3 olblr

	for (int i = 0; i < mLayerSize; i++) {// ara katmanda 2 noron varsa 2 tane fnet hesaplýcak.6 tane middleweight var.
		
		double net = instance.x1 * middleWeights[i* dim] + instance.x2 * middleWeights[i* dim +1] + inputBias * middleWeights[i* dim +2];
		mFNetArray[i] = sigmoidFunction(net, -1.0);//fnet deðerini tutacak.burada 2 tane attýk fnet1 ve f net2
	}
	

	//outlayer.
	for (int i = 0; i < oLayerSize; i++) {//çýkýþta 1 tane noron var.3 tane ooutWightvar.outweigh sayýsý ile mNetarray sayýsý eþit.
		double net = 0.0;
		for (int j = 0; j < mLayerSize; j++) {//msize=2

			net += mFNetArray[j] * outWeights[i* middleLayerDim + j];
			
		}
		net += (-1.0) * outWeights[(i* middleLayerDim) + (mLayerSize)];
		oFNetArray[i] = sigmoidFunction(net, -1.0);//çýkýþnoronunun fneti.bu dizide 1 tane var.
	}

	
	double error = 0.0;
	//en kucuk kareler
	for (int i = 0; i < oLayerSize; i++) {
		error += pow(desiredOutput - oFNetArray[i], 2);
	}

	//en kucuk kareler.
	//for (int i = 0; i < oLayerSize; i++) {
	//	error += desiredOutput*log10(oFNetArray[i]) + (1-desiredOutput)*log10(1-oFNetArray[i]);
	//}
	//return error*(-1);//aðýrlýklar eþit deðil ise hata = desiredOutput - output

	return error * 0.5;
}

//feedforward tamam.
void backForward(Instance instance,bool momentum, double* middleWeights, double* outWeights, double c, double* mFNetArray, double* oFNetArray, int mLayerSize, int oLayerSize) {
	double inputBias = -1, middleBias = -1, net = 0.0, derivateOutput = 0.0, sigmoidOutput = 0.0;
	double desiredOutput = (int)instance.id;
	int dim = 3;
	int middleLayerDim = mLayerSize + 1;
	double beta = momentum ? 0.9 : 0;

	//out layer aðýrlýk güncllemeleri
	for (int i = 0; i < oLayerSize; i++) {
		for (int j = 0; j < mLayerSize ; j++) {
			
			double deltaWeight = c * (desiredOutput - oFNetArray[i]) * sigmoidFunctionDerivate(oFNetArray[i]) * mFNetArray[j];
			deltaWeight = deltaWeight * beta + deltaWeight * (1 - beta);

			outWeights[i * middleLayerDim + j] += deltaWeight;
			outWeights[i * middleLayerDim + j] += c * (desiredOutput - oFNetArray[i]) * sigmoidFunctionDerivate(oFNetArray[i]) * mFNetArray[j];
		}
		outWeights[i * middleLayerDim + mLayerSize ] += c * (desiredOutput - oFNetArray[i]) * sigmoidFunctionDerivate(oFNetArray[i]) * (-1.0);
	}
	 //buraya kadar 2-1,3-1,2-2,3-2,4-2,2-3 aðlarýnda sorunsuz iþlem saðlandý.---------

	//middlelayer aðýrlýk güncellemeleri.
	for (int i = 0; i < mLayerSize; i++) {

		double temp = 0.0;

		for (int j = 0; j < oLayerSize; j++) {

			temp += (desiredOutput - oFNetArray[j]) * sigmoidFunctionDerivate(oFNetArray[j]) * outWeights[j * middleLayerDim + i];
		}
		middleWeights[i * dim] += c * sigmoidFunctionDerivate(mFNetArray[i]) * instance.x1 * temp;
		middleWeights[i * dim + 1] += c * sigmoidFunctionDerivate(mFNetArray[i]) * instance.x2 * temp;
		middleWeights[i * dim + 2] += c * sigmoidFunctionDerivate(mFNetArray[i]) * inputBias * temp;
	}

	
}