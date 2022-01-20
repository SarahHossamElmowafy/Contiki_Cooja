#include "counter.h"

int next_round(int num){
	if (num > 9) num = 1;
	else num++;
	return num;

}
