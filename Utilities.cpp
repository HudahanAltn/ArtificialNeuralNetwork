#include "Resource.h"
#include "Utilities.h"
using namespace System;

Instance addInstanceOnPictureBox(int classId,int temp_x, int temp_y,int height,int width) {
	double x1, x2; //x1 = width, x2 = height
				//mouse ile týklayýnca ekranýn konum deðerleri temp_x ve temp_y deðiþkenlerine atanýr.


	// Noktalarin ana eksenin merkezine gore tasinmasi.x1 yatay eksen, x2 dikey eksen.
	x1 = (double)(temp_x - width);
	x2 = (double)(height - temp_y);

	//her týklamada örnekler diziye geçirilir.
	Instance temp;
	temp.id = classId;

	temp.x1 = x1;
	temp.x2 = x2;

	return temp;
}