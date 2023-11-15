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

//double perceptronLearning(Instance instance, double* weights, double c ) {//bu fonksiyon her instance i�in bir hata de�eri d�nd�r�r.
//	//tek n�ronlu a� c ��renme sabiti 0.1
//	// w1,w2,w3
//	//bias x3 de�eri genelde 1 e e�it, net=W*x, output = f(net)
//	double bias = 1, net = 0.0, output = 0.0;
//	double desiredOutput = (int)instance.id;
//
//	// net = w[0]*x1 + w[1].x2 + w[2]*bias
//	//her bir �rnek i�in net hesaplans�n.
//	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];
//
//	output = sgn(net);// ��k�� -1 veya + 1 olur.
//
//	if (output != desiredOutput) {//�rne�in beklenen ��k��� ile a��n �retti�i ��k�� kar��la�t�r�ls�n.e�it de�ilse a��rl�klar g�ncellensin.
//		weights[0] = weights[0] + c * (desiredOutput - output) * instance.x1;
//		weights[1] = weights[1] + c * (desiredOutput - output) * instance.x2;
//		weights[2] = weights[2] + c * (desiredOutput - output) * bias;
//
//		return desiredOutput - output;;//a��rl�klar e�it de�il ise hata = desiredOutput - output
//	}
//	else {//e�it ise a��rl�klar g�ncellenmez.
//		return 0; //a��rl�klar e�it de�ilse hata = 0
//	}
//}

bool perceptronLearning(Instance instance, double* weights, double c) {//bu fonksiyon her instance i�in bir hata de�eri d�nd�r�r.
	//tek n�ronlu a� c ��renme sabiti 0.1
	// w1,w2,w3
	//bias x3 de�eri genelde 1 e e�it, net=W*x, output = f(net)
	double bias = 1, net = 0.0, output = 0.0;
	double desiredOutput = (int)instance.id;

	// net = w[0]*x1 + w[1].x2 + w[2]*bias
	//her bir �rnek i�in net hesaplans�n.
	net = instance.x1 * weights[0] + instance.x2 * weights[1] + bias * weights[2];

	output = sgn(net);// ��k�� -1 veya + 1 olur.

	if (output != desiredOutput) {//�rne�in beklenen ��k��� ile a��n �retti�i ��k�� kar��la�t�r�ls�n.e�it de�ilse a��rl�klar g�ncellensin.
		weights[0] = weights[0] + c * (desiredOutput - output) * instance.x1;
		weights[1] = weights[1] + c * (desiredOutput - output) * instance.x2;
		weights[2] = weights[2] + c * (desiredOutput - output) * bias;

		return false;//a��rl�klar e�it de�il ise hata = desiredOutput - output
	}
	else {//e�it ise a��rl�klar g�ncellenmez.
		return true; //a��rl�klar e�it  hata = 0
	}
}
