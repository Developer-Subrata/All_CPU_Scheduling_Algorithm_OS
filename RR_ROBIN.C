/////ROUND ROBIN Scheduling Algorithm ...............
///By Subrata Mandal
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void input(int[], int[], int);
//void sort(int[], int[], int[], int);
void rcalculation(int[], int[], int[], int[], int[], int, int);
void rr();
int i, j, temp;

int main()
  {
   int ch;
   //clrscr();
   system("cls");
   while(1)
	{
   system("cls");
   printf("\n\n1-> Round_Robin\t5-> EXIT\n---> ");
   scanf("%d",&ch);
   switch(ch)
	 {
	  case 1:
		rr();
		break;
	  case 5:
		exit(0);
	  default :
		printf("\nWrong Choice !!!");
		getch();
	 }
   }
}

void rr()
{
	printf("----ROUND ROBIN----\n");
	int rprocess[100], rat[100], rbt[100], rct[100], rtat[100], rwt[100];
	int size, slice;
	printf("\nEnter How Many Processes There Are ?\n---> ");
	scanf("%d", &size);
	printf("\nEnter %d Arrival Time : ", size);
	input(rat, rprocess, size);

	printf("\nEnter %d Burst Time : ", size);
	input(rbt, rprocess, size);

	printf("\n**Enter Time Slice :\n---> ");
	scanf("%d", &slice);
	//sort(rat, rbt, rprocess, size);
	rcalculation(rat, rbt, rct, rtat, rwt, slice, size); // Going to calculate
	printf("\n\t   ***ROUND ROBIN SCHEDULING_ALGORITHM***\n");
	printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT");
	int totalwaiting = 0;
	int totaltat = 0;
	for (i = 0; i < size; i++)
	{
		totalwaiting += rwt[i];
		totaltat += rtat[i];
		printf("\n  %d\t%d\t%d\t%d\t %d\t%d", rprocess[i], rat[i], rbt[i], rct[i], rtat[i], rwt[i]);
	}
	printf("\nTotal Waiting Time          => %d", totalwaiting);
	printf("\nAverage Waiting Time        => %f\n", (float)totalwaiting / size);
	printf("\nTotal Turn Around Time      => %d", totaltat);
	printf("\nAverage TurnAroundTime Time => %f", (float)totaltat / size);
getch();
}

void input(int arr[], int arrp[], int size)
{
	for (i = 0; i < size; i++)
	{
	printf("\n  %d ==> ", i + 1);
	scanf("%d", &arr[i]);
	arrp[i] = (i + 1);
	}
}
/*     It is not Mandatory to sort In Round Robin 
void sort(int arrat[], int arrbt[], int arrp[], int size)
{
	for (i = 0; i < size - 1; i++)
	 {
	for (j = 0; j < size - 1 - i; j++)
	  {
		if (arrat[j] > arrat[j + 1])
		  {
		temp = arrat[j]; 				// Arrival time sorting
		arrat[j] = arrat[j + 1];
		arrat[j + 1] = temp;

		temp = arrbt[j]; 				// Burst time sorting
		arrbt[j] = arrbt[j + 1];
		arrbt[j + 1] = temp;

		temp = arrp[j]; 				// Process sorting
		arrp[j] = arrp[j + 1];
		arrp[j + 1] = temp;
		}
	}
  }
}*/          

void rcalculation(int at[], int bt[], int ct[], int tat[], int wt[], int slice, int size) 
{
    int remainingTime[size]; // Create an array to track remaining burst times
    int currentTime = 0;

    for (int i = 0; i < size; i++) 
    {
        remainingTime[i] = bt[i];
    }
    int completed = 0; 						// To keep track of the number of processes completed
    while (completed < size) 
    {
        int isProcessExecuted = 0; 			// Flag to check if a process is executed in this iteration

        for (int i = 0; i < size; i++) 
        {
            if (at[i] <= currentTime && remainingTime[i] > 0) 
            {
                isProcessExecuted = 1;
                
                if (remainingTime[i] <= slice) 
                {
                    currentTime += remainingTime[i];
                    ct[i] = currentTime;
                    remainingTime[i] = 0;
                    completed++;
                } 
                else 
                {
                    currentTime += slice;
                    remainingTime[i] -= slice;
                }
            }
        }

        if (!isProcessExecuted) 
        {
            // No process can be executed at this time, increment time
            currentTime++;
        }
    }

 // Calculate TAT, WT, RT for each process
		for (j = 0; j < size; j++)
		{
				tat[j] = ct[j] - at[j];
				wt[j] = tat[j] - bt[j];
				if(tat[j]<0)
				 tat[j]=0;
				if(wt[j]<0)
				 wt[j]=0;
		}
  }
