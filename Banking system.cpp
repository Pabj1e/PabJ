#include <stdio.h>

int main(){
	
	const int pass = 1000;
	int pin;
	int choice;
	double balance = 0.00;
	double amount;
	int deposit;
	
	printf("Enter you pin: ");
	
	   while (1) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &pin) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            // Clear invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (pin == pass) {
            break; // proceed to menu
        } else {
            printf("Incorrect PIN. Please try again.\n");
        }
    }
    
     while (1) {
        printf("\n( Select Operator )\n\n");
        printf("1. Check balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. (Exit)\n\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
	}
		
 if (choice == 1) {
            printf("Your current balance: PHP %.2f\n", balance);
        }
        else if (choice == 2) {
            printf("Enter deposit amount: PHP ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Invalid amount. Please enter a positive value.\n");
            } 
            else if (amount < 10) {
                printf("Minimum deposit is PHP 10-100. Please enter a larger amount.\n");
            }
            else {
                balance += amount;
                printf("Deposit successful! New balance: PHP %.2f\n", balance);
            }
        }
        else if (choice == 3) {
            printf("Enter withdrawal amount: PHP ");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("Invalid amount. Please enter a positive value.\n");
            }
            else if (amount > balance) {
                printf("Insufficient funds. Your balance is PHP %.2f\n", balance);
            }
            else {
                balance -= amount;
                printf("Withdrawal successful! New balance: PHP %.2f\n", balance);
            }
        }
        else if (choice == 4) {
            printf("Thank you for using our service. Goodbye!\n");
        }
        else {
            printf("Invalid choice. Please select 1–4.\n");
        }
}

	return 0;
	
}
