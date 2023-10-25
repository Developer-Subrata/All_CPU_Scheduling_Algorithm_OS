/////SJF NON Preemption Scheduling Algorithm ...............
   ///By , Subrata Mandal

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

//void sorting(int[], int[], int[], int);
void input(int[], int[], int[], int);
void calculationCT(int[], int[], int[], int);
void non_sjf();

int main()
  {
   int ch;
   //clrscr();
   system("cls");
   while(1)
    {
   //clrscr();
   system("cls");
   printf("\n\n1-> SJF_NON_PREEMPTION\t5-> EXIT\n---> ");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1:
	    non_sjf();
	    break;
      case 5:
	    exit(0);
      default :
		printf("\nWrong Choice !!!");
        getch();
     }
   }
  }

void non_sjf()
{
    int pros[100], at[100], bt[100], ct[100], wt[100], tat[100], size;
    float awt = 0.0, atat = 0.0;

    printf("\nHow many Processes do you want?\n---> ");
    scanf("%d", &size);

    printf("\n---Enter the Information---");
    input(pros, at, bt, size);
    //sorting(pros, at, bt, size);
    calculationCT(at, bt, ct, size);
    printf("\n\t   ***SJF NON SCHEDULING_ALGORITHM***");
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < size; i++)
    {
	tat[i] = ct[i] - at[i];
	wt[i] = tat[i] - bt[i];
				if(tat[i]<0)
                 tat[i]=0;
                if(wt[i]<0)
                 wt[i]=0;
	printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pros[i], at[i], bt[i], ct[i], tat[i], wt[i]);
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

void input(int pros[], int at[], int bt[], int size)
{
    for (int i = 0; i < size; i++)
    {
	pros[i] = i + 1;
	printf("\nEnter Arrival Time for P%d => ", pros[i]);
	scanf("%d", &at[i]);
	printf("Enter Burst Time for P%d => ", pros[i]);
	scanf("%d", &bt[i]);
    }
}

/*void sorting(int pros[], int at[], int bt[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
	for (j = 0; j < size - i - 1; j++)
	{
	    if (bt[j] > bt[j + 1])
	    {
		temp = bt[j];
		bt[j] = bt[j + 1];
		bt[j + 1] = temp;

		temp = at[j];
		at[j] = at[j + 1];
		at[j + 1] = temp;

		temp = pros[j];
		pros[j] = pros[j + 1];
		pros[j + 1] = temp;
	    }
	}
    }
}*/

void calculationCT(int at[], int bt[], int ct[], int size)
{
    int newCT = 0;
    int temp = size;           // remaining process
    int bbt[100];                         // Create a copy of burst times for tracking remaining time
    for (int i = 0; i < size; i++)
    {
	    bbt[i] = bt[i];
    }

    while (temp > 0)
    {
	    int index = -1;
	    int smallBurst = 1000;

	for (int j = 0; j < size; j++)
	{
	    if (at[j] <= newCT && bbt[j] < smallBurst && bbt[j] > 0)
	    {
		  smallBurst = bbt[j];
		  index = j;
	    }
	}
	if (index == -1)
	{
	       newCT++;        //  Ideal Time, increment time
	}
	else
	{
	    ct[index] = newCT + bbt[index];
	    newCT = ct[index];
	    bbt[index] = 0;            // This Process Is Complete
	    temp--;
	}
  }
}
