#include "Resource.h"
#include "Normalization.h"
#include <cmath>

Instance averageWeight(Instance* instances,int totalInstance) {

	double totalX = 0.0;
	double totalY = 0.0;

	for (int i = 0; i < totalInstance; i++) {
		totalX += instances[i].x1;
		totalY += instances[i].x2;
	}

	Instance instance;

	instance.id = 0;
	instance.x1 = totalX / totalInstance;
	instance.x2 = totalY / totalInstance;

	return instance;

}

double x_Mean(Instance* instances, int totalInstance) {

	double totalX = 0.0;
	
	for (int i = 0; i < totalInstance; i++) {
		totalX += instances[i].x1;
	}

	return totalX / totalInstance;
}

double y_Mean(Instance* instances, int totalInstance) {
	double totalY = 0.0;

	for (int i = 0; i < totalInstance; i++) {
		totalY += instances[i].x2;
	}

	return totalY / totalInstance;
}

double x_StandartDeviation(Instance* instances, int totalInstance) {

	double totalX = 0.0;
	double mean_X = x_Mean(instances, totalInstance);
	for (int i = 0; i < totalInstance; i++) {
		
		totalX += pow(instances[i].x1 - mean_X, 2);
	}

	return sqrt(totalX * (1 / totalInstance));

}

double y_StandartDeviation(Instance* instances ,int totalInstance) {

	double totalY = 0.0;
	double mean_Y = y_Mean(instances, totalInstance);
	for (int i = 0; i < totalInstance; i++) {

		totalY += pow(instances[i].x1 - mean_Y, 2);
	}

	return sqrt(totalY * (1 / totalInstance));
}




Instance batchNormalization(Instance instance,double mean_X,double standartDevitation_X, double mean_Y, double standartDevitation_Y) {

	Instance tempInst;

	tempInst.id = instance.id;
	tempInst.x1 = (instance.x1 - mean_X) / standartDevitation_X ;
	tempInst.x2 = (instance.x2 - mean_Y) / standartDevitation_Y;

	return tempInst;

}


Instance Normalization(Instance instance) {

	double norm = sqrt(pow(instance.x1, 2) + pow(instance.x2,2));

	Instance temp;
	temp.id = instance.id;
	temp.x1 = instance.x1 / norm;
	temp.x2 = instance.x2 / norm;

	return temp;
}
