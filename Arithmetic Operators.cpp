#include <stdio.h>

int main(){
	
	int password;
	int pass = 1234;
	int f1 = 50, f2 = 3;
	int add = f1 + f2;
	int sub = f1 - f2;
	int multi = f1 * f2;
	int divide = f1 / f2;
	int modulus = f1 % f2;
	
	printf("password is 1234\n\nInput password: ");
	scanf("%d",&password);

	if(pass == password){

	printf("\nPlus operators \n%d + %d = %d\n\n", f1, f2, add);
	printf("Subtract operators \n%d - %d = %d\n\n", f1, f2, sub);
	printf("multiply operators \n%d * %d = %d\n\n", f1, f2, multi);
	printf("divide operators \n%d / %d = %d\n\n", f1, f2, divide);
	printf("modulus operators \n%d %% %d = %d\n\n", f1, f2, modulus);
	
} else {
	
	printf("\nIncorrect password");
}
	
	
	return 0;
}

