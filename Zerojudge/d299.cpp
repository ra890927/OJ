#include <iostream>
using namespace std;

int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int rec[10];
int used[10];

void test(int* num, int* rec, int step, int* used){
	if(step == 10){
		if(rec[1]*10000+rec[4]*1000+rec[5]*100+rec[7]*10+rec[9] + 2*(rec[7]*100+rec[0]*10+rec[3])
		== rec[6]*10000+rec[2]*1000+rec[8]*100+rec[7]*10+rec[9])
			cout << rec[1] << rec[4] << rec[5] << rec[7] << rec[9] << " + " <<
			rec[7] << rec[0] << rec[3] << " + " <<
			rec[7] << rec[0] << rec[3] << " = " <<
			rec[6] << rec[2] << rec[8] << rec[7] << rec[9] << endl;
	}
	
	else{
		for(int i = 0; i < 10; i++){
			if(!used[i]){
				rec[step] = num[i];
				used[i] = 1;
				test(num, rec, step+1, used);
				used[i] = 0;
			}
		}
	}
	
	return;
}

int main(){
	test(num, rec, 0, used);
	return 0;
}