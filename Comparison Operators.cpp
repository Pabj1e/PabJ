#include <stdio.h>

int main(){
	
	int password;
	int pass = 05;
	int num0 = 200, num1 = 300;
	int equalto = num0 == num1;
	int notequal = num0 != num1;
	int greater = num0 > num1;
	int lessthan = num0 < num1;
	int GorE = num0 >= num1;
	int LorE = num0 >= num1;
	
	printf(" Comparison Operators \n ( password is 05 )\n\n");
	printf("Enter password: ");
	scanf("%d", &password);
	
	if(pass == password){
	
	
	printf("\n\nEqualto \n200 == 300 is: %d\n\n", equalto);
	printf("Notequal \n200 != 300 is: %d\n\n", notequal);
	printf("Greater \n200 > 300 is: %d\n\n", greater);
	printf("Lessthan \n200 < 300 is: %d\n\n", lessthan);
	printf("GorE \n200 >= 300 is: %d\n\n", GorE);
	printf("LorE \n200 <= 300 is: %d\n\n", LorE);
} else {
	
	printf("Incorrect please try again");
}

return 0;

}
