#include "Learning.h"
#include "Process.h"


//
//       w1
//   x1 -----------
//             -------
//       w2         -----
//   x2 --------------------- net------sgn(net) -1 or +1
//                  -----
//       w3     -----
//   x3=1 ----------
//

//double perceptronLearning(Instance instance, double* weights, double c ) {//bu fonksiyon her instance için bir hata deðeri döndürür.
//	//tek nöronlu að c öðrenme sabiti 0.1
//	// w1,w2,w3
//	//bias x3 deðeri genelde 1 e eþit, net=W*x, output = f(net)
//	double bias = 1, net = 0.0, output = 0.0;
//	double desiredOutput = (int)instance.id;
//
//	// net = w[0]*x1 + w[1].x2 + w[2]*bias
//	//her bir örnek için net hesaplansýn.
//	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];
//
//	output = sgn(net);// çýkýþ -1 veya + 1 olur.
//
//	if (output != desiredOutput) {//örneðin beklenen çýkýþý ile aðýn ürettiði çýkýþ karþýlaþtýrýlsýn.eþit deðilse aðýrlýklar güncellensin.
//		weights[0] = weights[0] + c * (desiredOutput - output) * instance.x1;
//		weights[1] = weights[1] + c * (desiredOutput - output) * instance.x2;
//		weights[2] = weights[2] + c * (desiredOutput - output) * bias;
//
//		return desiredOutput - output;;//aðýrlýklar eþit deðil ise hata = desiredOutput - output
//	}
//	else {//eþit ise aðýrlýklar güncellenmez.
//		return 0; //aðýrlýklar eþit deðilse hata = 0
//	}
//}

bool perceptronLearning(Instance instance, double* weights, double c) {//bu fonksiyon her instance için bir hata deðeri döndürür.
	//tek nöronlu að c öðrenme sabiti 0.1
	// w1,w2,w3
	//bias x3 deðeri genelde 1 e eþit, net=W*x, output = f(net)
	double bias = 1, net = 0.0, output = 0.0;
	double desiredOutput = (int)instance.id;

	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir örnek için net hesaplansýn.
	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];

	output = sgn(net);// çýkýþ -1 veya + 1 olur.

	if (output != desiredOutput) {//örneðin beklenen çýkýþý ile aðýn ürettiði çýkýþ karþýlaþtýrýlsýn.eþit deðilse aðýrlýklar güncellensin.
		weights[0] = weights[0] + c * (desiredOutput - output) * instance.x1;
		weights[1] = weights[1] + c * (desiredOutput - output) * instance.x2;
		weights[2] = weights[2] + c * (desiredOutput - output) * bias;

		return false;//aðýrlýklar eþit deðil ise hata = desiredOutput - output
	}
	else {//eþit ise aðýrlýklar güncellenmez.
		return true; //aðýrlýklar eþit  hata = 0
	}
}
