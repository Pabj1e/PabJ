#include <stdio.h>

int main(){
	
	char op;
	double num1, num2, result;
	
	printf("Choose An Operator ( + - * / ): ");
	scanf("%c", &op);
	
	printf("Enter num1: ");
	scanf("%lf", &num1);
	
	printf("Enter num2: ");
	scanf("%lf", &num2);	
	
	switch(op){
		
		case '+':
		result = num1 + num2;
		printf("result: %.1lf", result);
		break;
		
		case '-':
		result = num1 - num2;
		printf("result: %lf", result);
		break;
		
		case '*':
		result = num1 * num2;
		printf("result: %.2lf", result);
		break;
		
		case '/':
		result = num1 / num2;
		printf("result: %lf", result);
		break;
		
		default:
		printf("%c Invalid Input");	
		
	}
	
	return 0;
}
