
#include "sequence_detection.h"

typedef enum {A,B,C,D} sequence_type;

void sequence_detection(
		bool input,
		bool &count){
#pragma HLS INTERFACE ap_none port=count
#pragma HLS INTERFACE ap_none port=input
#pragma HLS INTERFACE ap_ctrl_none port=return

	static sequence_type state = A;
	sequence_type next_state = A;
	bool temp_count;

	switch(state){

	case A:
		if(input==1){
			next_state = B;

		}else{
			next_state = A;
		}
		temp_count = 0;
		break;
	case B:
			if(input==0){
				next_state = C;

			}else{
				next_state = A;
			}
			temp_count = 0;
			break;
	case C:
			if(input==1){
				next_state = D;

			}else{
				next_state = A;
			}
			temp_count = 0;

			break;
	case D:
			if(input==1){
				next_state = B;
				temp_count = 1;

			}else{
				next_state = B;
				temp_count = 0;
			}


			break;
	default:
		break;
	}

	state = next_state;
	count = temp_count;

}
