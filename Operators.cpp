#include <stdio.h>

int main() {
	
    const int CORRECT_PIN = 1000;
    int entered_pin;
    int choice;
    float amount;
    int f1 = 50, f2 = 3;
	int add = f1 + f2;
	int sub = f1 - f2;
	int multi = f1 * f2;
	int divide = f1 / f2;
	int modulus = f1 % f2;
	int num0 = 200, num1 = 300;
	int equalto = num0 == num1;
	int notequal = num0 != num1;
	int greater = num0 > num1;
	int lessthan = num0 < num1;
	int GorE = num0 >= num1;
	int LorE = num0 >= num1;
	int num9 = 1, num10 = 1, num11 = 0, num12 = 1, num13 = 0, num14 = 0;
	int num16 = num9 && num10;
	int num17 = num12 && num13;
	int check1 = num9 || num10;
	int check2 = num11 || num12;
	int check3 = num13 || num14;
	int o;

    printf("Please Enter Password  \n");

    // PIN authentication loop
    while (1) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &entered_pin) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            // Clear invalid input
            while ((o = getchar()) != '\n' && o != EOF);
            continue;
        }
        if (entered_pin == CORRECT_PIN) {
            break; // proceed to menu
        } else {
            printf("Incorrect PIN. Please try again.\n");
        }
    }

    // Main transaction loop
    while (1) {
        printf("\n( Select Operator )\n\n");
        printf("1. Arithmetic Operator\n");
        printf("2. Comparison Operator\n");
        printf("3. Logical Operator\n");
        printf("4. (Exit)\n\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (choice == 1) {
        
		printf("(Arithmetic Operator)\n");		
       	printf("\nPlus operators \n%d + %d = %d\n\n", f1, f2, add);
		printf("Subtract operators \n%d - %d = %d\n\n", f1, f2, sub);
		printf("multiply operators \n%d * %d = %d\n\n", f1, f2, multi);
		printf("divide operators \n%d / %d = %d\n\n", f1, f2, divide);
		printf("modulus operators \n%d %% %d = %d\n\n", f1, f2, modulus);
            
            
        } else if (choice == 2) {
           
                
		printf("(Comparison Operator)\n");	
       	printf("\nEqualto \n200 == 300 is: %d\n\n", equalto);
		printf("Notequal \n200 != 300 is: %d\n\n", notequal);
		printf("Greater \n200 > 300 is: %d\n\n", greater);
		printf("Lessthan \n200 < 300 is: %d\n\n", lessthan);
		printf("GorE \n200 >= 300 is: %d\n\n", GorE);
		printf("LorE \n200 <= 300 is: %d\n\n", LorE);
		
        } else if (choice == 3) {
        
        printf("(Logical Operator)\n");	
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

		} else if (choice == 4) {	 
		
			printf("Exited");
			break;  
			
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

