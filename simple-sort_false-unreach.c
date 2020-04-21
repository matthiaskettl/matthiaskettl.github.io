extern int __VERIFIER_nondet_int();

#define TRUE 0
#define FALSE 1

int isSorted(int a[], int len){
	for(int i = 0; i < len-1; i++) {
		if(a[i] > a[i+1]) {
			return FALSE;
		}	
	}
	return TRUE;
}

int main(){
	
	//sort any array of size 3 from smallest to biggest value
	int first = __VERIFIER_nondet_int();
	int second = __VERIFIER_nondet_int();
	int third = __VERIFIER_nondet_int();
	int a[] = {first,second,third};
	int len = 3;
	int i = 0;
	while(!isSorted(a,len)) {
		int buff = a[i];
		a[i] = a[i+1];
		a[i+1] = buff;
		i++;
		if (i == len-1) {
			i = 0;		
		}	
	}

	//POST-CONDITION check if the array is sorted?
	if (a[0] <= a[1] && a[1] <= a[2]) {
		goto EXIT;	
	} else {
		goto ERROR;	
	}


EXIT: return 0;
ERROR: return 1;

}
