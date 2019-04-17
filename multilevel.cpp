#include<stdio.h> 
 
int main() 
{ 
      int i, limit, total = 0, x, counter = 0, quantum,j; 
	  int wt = 0, tat = 0,pos,z,p[10],priority[10], at[10], bt[10], tmp[10],b; 
	  float avg_wt, avg_tat;
	  printf("\nEnter Total Number of Processes:"); 
	  scanf("%d", &limit); 
	  x = limit; 
      for(i = 0; i < limit; i++) 
      {
	    p[i]=i+1;
	    priority[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Burst Time:\t");
            scanf("%d", &bt[i]); 
            tmp[i] = bt[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 
		    for(z=0;z<limit;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<limit;j++)
			{
			    if(priority[j]<priority[pos])
				pos=j;
			}
		 
		temp1=priority[z];
		priority[z]=priority[pos];
		priority[pos]=temp1;
		 
			temp1=bt[z];
			bt[z]=bt[pos];
			bt[pos]=temp1;
		 			temp1=at[z];
				at[z]=at[pos];
			at[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=tmp[z];
				tmp[z]=tmp[pos];
			tmp[pos]=temp1;
		    }
		{
		}
            
			if(tmp[i] <= quantum && tmp[i] > 0) 
            { 
                  total = total + tmp[i]; 
                  tmp[i] = 0; 
                  counter = 1; 
            } 
            
			else if(tmp[i] > 0) 
            { 
                  tmp[i] = tmp[i] - quantum; 
                  total = total + quantum; 
            } 

	for(b=0;b<limit;b++)
		{
			if(b==i)
			priority[b]+=1;
			else
			priority[b]+=2;
		}

            if(tmp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], bt[i], total - at[i], total - at[i] - bt[i],priority[i]);
                  wt = wt + total - at[i] - bt[i]; 
                  tat = tat + total - at[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
			}
            else if(at[i + 1] <= total) 
            {
                  i++;
			}
            else 
            {
                  i = 0;
			}		
      } 
      return 0; 
}
