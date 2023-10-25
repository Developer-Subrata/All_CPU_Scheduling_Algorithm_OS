/////FCFS Scheduling Algorithm ...............
   ///By , Subrata Mandal

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void input(int[],int[],int);
void sort(int[],int[],int[],int);
void calculation(int[],int[],int[],int[],int[],int[],int);
void fcfs();
int i,j;

int main()
  {
   int ch;
   //clrscr();
   system("cls");
   while(1)
    {
   //clrscr();
   system("cls");
   printf("\n\n1->FCFS\t5->EXIT\n---> ");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1:
	    fcfs();
	    break;
      case 5:
	    exit(0);
      default :
		printf("\nWrong Choice !!!");
		getch();
     }
  }
}
void input(int arr[],int arrp[],int size)
  {
   for(i=0;i<size;i++)
     {
      printf("\n  %d ==> ",i+1);
      scanf("%d",&arr[i]);
      arrp[i]=(i+1);
     }
  }

void sort(int arrat[],int arrbt[],int arrp[],int size)
  {
   int temp;
   for(i=0;i<size-1;i++)
     {
      for(j=0;j<size-1-i;j++)
	{
	 if(arrat[j]>arrat[j+1])
	   {
	    temp=arrat[j];          ///arrival time sorting
	    arrat[j]=arrat[j+1];
	    arrat[j+1]=temp;

	    temp=arrbt[j];          ////burst time sorting
	    arrbt[j]=arrbt[j+1];
	    arrbt[j+1]=temp;

	    temp=arrp[j];           ////process sorting
	    arrp[j]=arrp[j+1];
	    arrp[j+1]=temp;
	   }
	}
     }
  }

///fcfs calculation
void calculation(int at[],int bt[],int ct[],int tat[],int wt[],int rt[],int size)
  {
    ct[0]=at[0]+bt[0];

    for(i=1;i<size;i++)
      {
        int temp=0;
	      if(ct[i-1]<at[i])
          {
            temp=at[i]-ct[i-1];
          }
	      ct[i]=ct[i-1]+bt[i]+temp;
      }
    for(i=0;i<size;i++)
    {
      tat[i]=ct[i]-at[i];
	      wt[i]=tat[i]-bt[i];
	      rt[i]=wt[i];

       if(tat[i]<0)
	      {
	        tat[i]=0;
	      }
       if(wt[i]<0)
	      {
	        wt[i]=0;
	      }
       if(rt[i]<0)
	      {
	        rt[i]=0;
	      }
    }    
  }

void fcfs()
  {
   int fprocess[100],fat[100],fbt[100],fct[100],ftat[100],fwt[100],frt[100];
   int size;
   printf("\nEnter How Many Process There Are ?\n---> ");
   scanf("%d",&size);
   printf("\nEnter %d Arrival Time : ",size);
   input(fat,fprocess,size);
   printf("\nEnter %d Burst Time : ",size);
   input(fbt,fprocess,size);
   sort(fat,fbt,fprocess,size);
calculation(fat,fbt,fct,ftat,fwt,frt,size);   ///going to calculate
printf("\n\t ***FCFS SCHEDULING_ALGORITHM***");
printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT\tRT");
int totalwaiting=0;
int totaltat=0;
  for(i=0;i<size;i++)
   {
    totalwaiting+=fwt[i];
    totaltat+=ftat[i];
    printf("\n  %d\t%d\t%d\t%d\t %d\t%d\t%d",fprocess[i],fat[i],fbt[i],fct[i],ftat[i],fwt[i],frt[i]);
   }
	printf("\nTotal Waiting Time          => %d",totalwaiting);
	printf("\nAverage Waiting Time        => %f\n",(totalwaiting/size));
	printf("\nTotal Turn Around Time      => %d",totaltat);
	printf("\nAverage TurnAroundTime Time => %f",(totaltat/size));
getch();
}

