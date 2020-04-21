extern int __VERIFIER_nondet_int();

/** 
  * Calculate the maximum scoring sequence.
  * The input is an array of integers.
  * The output is the highest sum of consecutive elements in the array.
  * Example: for array = [2, -1, 7, -5, 2] the output is 8 because 2 + (-1) + 7 = 8
  * There is no other partial sequence wich sums up to a higher value.
*/
int main(){

	int a[] = {-2, 5, -2, 5};
	int test = 0;
	
	// 4 = length of array
	for (int i = 1; i <= 4; i++) {
		for (int j = i - 1; j < 4; j++) {
			int s = 0;
			for (int k = i; k <= j; k++) {
				s = s + a[k - 1];
			}
			if (s > test) {
				test = s;
			}
		}
	}

	if(test != 8) {
		goto ERROR;
	}

EXIT: return 0;
ERROR: return 1;
}
