/////Priority NON Scheduling Algorithm ...............
   ///By , Subrata Mandal
/*In non-preemptive priority scheduling, the CPU gets allocated to a specific process based on the priority numbers assigned.
 After the CPU allocation, 
it will only be released by context switching or terminating the process.*/

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void sorting(int[], int[], int[], int[], int);          //FOR SORTING , PRIORITY WISH
void input(int[], int[], int[], int[], int);            //TAKE INPUT FROM USER
void calculationCT(int[], int[], int[], int[], int);    //CALCULATE RESULT
void priority();


int main()
  {
   int ch;
   //clrscr();
   system("cls");
   while(1)
    {
   //clrscr();
   system("cls");
   printf("\n\n1-> Priority_Non_Preemption\t5-> EXIT\n---> ");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1:
	    priority();
	    break;
      case 5:
	    exit(0);
      default :
		printf("\nWrong Choice !!!");
		getch();
     }
  }
}

// All result printing here.....................
void priority()
{
    int pros[100], at[100], bt[100], ct[100], wt[100], tat[100], pr[100], size;
    float awt = 0.0, atat = 0.0;

    printf("\nHow many Processes do you want?\n---> ");
    scanf("%d", &size);

    printf("\n---Enter the Information---");
    input(pros, at, bt, pr, size);
    sorting(pros, at, bt, pr, size);
    calculationCT(at, bt, ct, pr, size);
  
	printf("\n\t   ***PRIORITY NON SCHEDULING_ALGORITHM***");
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < size; i++)
    {
	tat[i] = ct[i] - at[i];
    if(tat[i]<0)
      tat[i]=0;
	wt[i] = tat[i] - bt[i];
    if(wt[i]<0)
      wt[i]=0;
	printf("P%d\t%d\t%d\t    %d\t\t%d\t%d\t%d\n", pros[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    for (int i = 0; i < size; i++)
    {
	 awt += wt[i];
	 atat += tat[i];
    }

    awt /= size;
    atat /= size;

    printf("\nAverage Waiting Time => %.2f", awt);
    printf("\nAverage Turnaround Time => %.2f\n", atat);

    getch();
}
 //TAKE INPUT FROM USER
void input(int pros[], int at[], int bt[], int pr[], int size)
{
    for (int i = 0; i < size; i++)
    {
	pros[i] = i + 1;
	printf("\nEnter Arrival Time for P%d => ", pros[i]);
	scanf("%d", &at[i]);
     printf("Enter Priority for P%d => ", pros[i]);
	scanf("%d", &pr[i]);
	printf("Enter Burst Time for P%d => ", pros[i]);
	scanf("%d", &bt[i]);
    }
}
//FOR SORTING , PRIORITY WISH
void sorting(int pros[], int at[], int bt[], int pr[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
	for (j = 0; j < size - i - 1; j++)
	{
	    if (pr[j] > pr[j + 1])              //FOR SORTING , PRIORITY WISH
	    {
        temp = pr[j];
		pr[j] = pr[j + 1];
		pr[j + 1] = temp;

		temp = bt[j];               //FOR SORTING , Burst Time
		bt[j] = bt[j + 1];
		bt[j + 1] = temp;

		temp = at[j];               //FOR SORTING , Arrive Time
		at[j] = at[j + 1];
		at[j + 1] = temp;

		temp = pros[j];             //FOR SORTING , Process
		pros[j] = pros[j + 1];
		pros[j + 1] = temp;
	    }
	}
    }
}

void calculationCT(int at[], int bt[], int ct[], int pr[], int size)
{
    int newCT = 0;
    int temp = size;           // remaining process
    int prr[100],bbt[100];                         // Create a copy of burst times for tracking remaining time
    for (int i = 0; i < size; i++)
    {
	prr[i] = pr[i];
	bbt[i]=bt[i];
    }

    while (temp > 0)
    {
	int index = -1;
	int smallPriority = 1000;               // Let Maximum Priority

	for (int j = 0; j < size; j++)
	{
	    if (at[j] <= newCT && prr[j] < smallPriority && bbt[j] > 0)             // Checking Priority and Arrive Time 
	    {
		  smallPriority = prr[j];
		  index = j;
	    }
	}

	if (index == -1)
	{
	       newCT++;        //  Ideal Time, increment time.....If No Processs 
	}
	else
	{
	    ct[index] = newCT + bbt[index];
	    newCT = ct[index];
	    bbt[index] = 0;             // Mark As This Process Is Complete
	    temp--;
	}
    }
	 
}