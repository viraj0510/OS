#include<stdio.h>

int main(){

    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

//allocation matrix
    int allocation[n][m];
    printf("Enter the allocation matrix:\n");
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

//maximum matrix
    int max[n][m];
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
        
    }
    
//available 
    int available[m];
    printf("Enter the available resources:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    
// need matrix
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j= 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
        
    }
    
    printf("Need Table:\n");
    for (i = 0; i < n; i++)
    {
        for (j= 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
    
        }
    printf("\n");  
    }

//initialize finish array
    int finish[n];
    for (i = 0; i < n; i++)
    {
        finish[i]=0;
    }

//safe sequence
    int safeSequence[n];
    int index = 0;

//bankar's algo

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i]==0)
            {
                int flag = 1;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 0;
                        break;
                    }
                    
                    
                }
                if (flag == 1)
                {
                    safeSequence[index++] = i;
                    for (j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = 1;            
                }
                
            }
            
            
            
        }
        
    }

//check if all processes are finished

    int flag = 1;
    for (i = 0; i < n; i++)
    {
        if (finish[i]==0)
        {
            flag=0;
            printf("The system is in an unsafe state.\n");
            break;
        }
    }
    if (flag==1)
    {
        printf("The system is in a safe state.\nSafe sequence is: ");
        for (i = 0; i < n; i++)
        {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
        
    }
    return 0;
    

}

