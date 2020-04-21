extern int __VERIFIER_nondet_int();

int isPrime(int n){
	for(int i = 2; i < n/2 + 1; i++){
		if(n % i == 0) return 0;	
	}
	return 1;
}

int main(){

	//Calculate prime factors of number;
	int number = __VERIFIER_nondet_int();
	if (number <= 0) {
		//Tell user that a positive number is required.
		goto EXIT;
	}

	int test = 1;

	for(int i = 2; i <= number; i++){
		if (number % i == 0 && isPrime(i)) {
			// Multiply all prime factors to test
			test *= i;
			// Reset i to restart computation with new number
			number = number / i;
			i = 2;
		}
	}

	// POST-CONDITION check if test equals number (test should equal the product of all found prime factors)
	if(test != number) {
		goto ERROR;	
	}

EXIT: return 0;
ERROR: return 1;
}
