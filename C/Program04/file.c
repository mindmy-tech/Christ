#include <stdio.h>

int main(void)
{
    printf("Account Holder's Name: ");
    char name[100];
    scanf("%s", &name);

    printf("Account Number: ");
    unsigned account_number;
    scanf("%i", &account_number);

    printf("Branch: ");
    char branch[50];
    scanf("%s", &branch);

    printf("Current Balance :");
    int balance;
    scanf("%i", &balance);

    printf("Type of Account: ");
    char type_acc[50];
    scanf("%s", &type_acc);

    char oper;
    do 
    {
        printf("\n\n BANKING OPERATIONS\n 1] Deposit\n 2] Withdrawal\n 3] Check Balance\n 4] Guidelines\n 5] Exit\n\n");
        printf("Operation :");
        int operation;
        scanf("%i", &operation);

        switch (operation)
        {
            case 1:
                printf("---------Deposit---------\nEnter Amount: ");
                int add_amount;
                scanf("%i", &add_amount);
                balance += add_amount;
                printf("---------Money Credited---------\n");
                break;
            
            case 2:
                printf("---------Withdraw---------\nEnter Amount: ");
                int debit_amount;
                scanf("%i", &debit_amount);
                balance -= debit_amount;
                printf("---------Money Debited---------\n");

                break;
            
            case 3:
                printf("---------Balance---------\n");
                printf("Balance: %i\n", balance);
                printf("---------Balance---------\n");
                break;

            
            case 4:
                printf("---------Guidelines---------\n");
                printf(" Minimum balance should be 4000");
                break;

            case 5:
                return 0;
            
            default:
                break;
        }
        printf("\nDo You Want to continue Y/N :");
        scanf(" %c", &oper);
    }
    while(oper == 'Y');
}