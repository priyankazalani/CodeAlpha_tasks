#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
    float marks;
};

int main()
{
    struct student s;
    FILE *fp;
    int choice;

    while(1)
    {
        printf("\n1.Add\n2.Display\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp = fopen("student.txt", "a");

            printf("Enter Roll: ");
            scanf("%d", &s.roll);

            printf("Enter Name: ");
            scanf("%s", s.name);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);

            fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);

            fclose(fp);

            printf("Record Added\n");
        }

        else if(choice == 2)
        {
            fp = fopen("student.txt", "r");

            printf("\nStudent Records:\n");

            while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF)
            {
                printf("Roll: %d\n", s.roll);
                printf("Name: %s\n", s.name);
                printf("Marks: %.2f\n", s.marks);
                printf("\n");
            }

            fclose(fp);
        }

        else if(choice == 3)
        {
            exit(0);
        }

        else
        {
            printf("Invalid Choice");
        }
    }

    return 0;
}
