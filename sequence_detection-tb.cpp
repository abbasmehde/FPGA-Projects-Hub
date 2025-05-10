#include "sequence_detection-tb.h"
#include "stdio.h"

int main(){
	int status=0;
	int gold_output[11] = {0,0,0,0,1,0,0,0,0,0,1};
	bool x;
	bool y;
	bool count;
	int input_data[11] = {0,1,0,1,1,1,0,1,0,1,1};
	int output[11];
	for(int i=0; i<11; i++){
		x = input_data[i];
		sequence_detection(x,count);
		printf("x=%d, detected=%d\n",(int)x,(int)count);
		output[i] = count;

	}

	for(int i=0; i<11; i++){
		if(output[i]!=gold_output[i]){
			printf("At index %d: Gold output is %d but sequence bit is %d\n",i,gold_output[i],output[i]);
			status = -1;
		}
	}

	if (status == 0)
	    printf("Test Passed: All outputs match.\n");
	else
	    {printf("Test Failed: Output mismatch found.\n");}



	return status;
}
