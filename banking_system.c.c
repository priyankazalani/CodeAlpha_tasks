#include <stdio.h>
#include <stdlib.h>

struct bank
{
    int accno;
    char name[20];
    float balance;
};

void deposit(struct bank *b)
{
    float amt;

    printf("Enter Deposit Amount: ");
    scanf("%f", &amt);

    b->balance = b->balance + amt;

    printf("Amount Deposited\n");
}

void withdraw(struct bank *b)
{
    float amt;

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amt);

    if(amt > b->balance)
    {
        printf("Insufficient Balance\n");
    }
    else
    {
        b->balance = b->balance - amt;

        printf("Amount Withdrawn\n");
    }
}

void balance(struct bank b)
{
    printf("Current Balance = %.2f\n", b.balance);
}

int main()
{
    struct bank b;
    FILE *fp;
    int choice;

    fp = fopen("bank.txt", "w+");

    printf("Enter Account Number: ");
    scanf("%d", &b.accno);

    printf("Enter Name: ");
    scanf("%s", b.name);

    printf("Enter Balance: ");
    scanf("%f", &b.balance);

    fwrite(&b, sizeof(b), 1, fp);

    while(1)
    {
        printf("\n1.Deposit\n2.Withdraw\n3.Balance\n4.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            deposit(&b);
        }

        else if(choice == 2)
        {
            withdraw(&b);
        }

        else if(choice == 3)
        {
            balance(b);
        }

        else if(choice == 4)
        {
            fp = fopen("bank.txt", "w");

            fwrite(&b, sizeof(b), 1, fp);

            fclose(fp);

            printf("Thank You\n");

            break;
        }

        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
