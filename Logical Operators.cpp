#include <stdio.h>

int main(){
	
	int pass;
	int password = 05;
	int num9 = 1, num10 = 1, num11 = 0, num12 = 1, num13 = 0, num14 = 0;
	int num16 = num9 && num10;
	int num17 = num12 && num13;
	int check1 = num9 || num10;
	int check2 = num11 || num12;
	int check3 = num13 || num14;
	
	
	
	printf(" Logical Operators \n The password 05\n\n\n Enter password: ");
	scanf("%d", &pass);
	
	if(pass == password){
	
	printf("\n BOTH VALUE ARE TRUE");
	printf("\n && (AND) operator \n\n contain1 = 1 && contain2 = 1\n result is: %d",num16);
	printf("\n\n contain1 = 1 && contain2 = 0\n result is: %d",num17);
	printf("\n ----------------------------");
	
	
	printf("\n\n EITHER OF TWO VALUES HAVE CONTAIN AUTOMATIC TRUE IF BOTH NO CONTAIN ANSWER IS FALSE");
	printf(" \n || (OR) operator \n\n contain1 = 1 || contain2 = 0\n result is: %d", check1);
	printf("\n\n contain1 = 0 || contain2 = 0\n result is: %d", check3);
	
	printf("\n ----------------------------");
	
	printf("\n\n REVERSE THE VALUE OF FALSE OR TRUE ");
	printf(" \n ! (NOT) operator \n\n contain1 = 1;\n ", num10);
	printf("\n !contain1 is: Not true 1 it's false 0");
	printf("\n  contain1 is: True 1 ");
	
} else {

	
	printf("Incorrect password please try again");
}

return 0;

}
