#pragma once

int YPoint(int x, double* weight, int = 1);// x biliniyorsa y 'yi bulan fonksiyon.
int YPoint2(int x, int i, int dim, double* weight, int multiplier = 1);
int Test_Forward(float* x, double* weight, float* bias, int num_Class, int inputDim);
float* init_array_random(int len);