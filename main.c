#include<stdio.h>
#include"health.h"
#include"Patient.c"
#include"healthworker.c"
#include"pdelete.c"
#include"hdelete.c"
#include"precord.c"
#include"hrecord.c"


int main()
{
    printf("\n\n\tWelcome to MediTrack Management System\n");
    char c;
    int n;
    for(int i=1; i<=100;i++)
    {
        printf("1.Manage Data\n2.Delete\n3.View Record\n4.Exit\n");
        printf("\nEnter Your Choise:");
        scanf(" %c", &c);
        printf("\n");
        switch(c)
    {
        case '1':
        printf("1.Manage patients.\n2.Manage Health Worker.\n");
        printf("Enter Your Choise:");
        scanf("%d",&n);

        if(n==1)
        {
            addpatients();
        }
        else if(n==2)
        {
            addhealthworker();
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;


        case '2':
        printf("1.Delete Patients Record\n2.Delete Healthworkers Record\n");
        printf("Enter Your Choise:");
        scanf("%d",&n);

        if(n==1)
        {
            pdeleterecord();
        }
        else if(n==2)
        {
           hdeleterecord();
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;


        case '3':
        printf("1.View Patients Record\n2.View Healthworkers Record\n");
        printf("Enter Your Choise:");
        scanf("%d",&n);

        if(n==1)
        {
            viewpatient();
        }
        else if(n==2)
        {
            viewhealthworker();
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;


        case '4':
        printf("Exiting...");
        exit(0);


        default: 
        printf("Invalid choice. Try again.\n");
        break;
    }
    }

    
    printf("Thank you so Much!!");
}