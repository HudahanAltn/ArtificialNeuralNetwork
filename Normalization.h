#pragma once


Instance averageWeight(Instance* instances, int totalInstance);

double x_Mean(Instance* instances, int totalInstance);
double y_Mean(Instance* instances, int totalInstance);
double x_StandartDeviation(Instance* instances, int totalInstance);
double y_StandartDeviation(Instance* instances, int totalInstance);

Instance batchNormalization(Instance instance, double mean_X, double standartDevitation_X, double mean_Y, double standartDevitation_Y);

Instance Normalization(Instance instance);

void Z_Score(float* x, int Size, int dim, float* mean, float* std);