#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int pid;
	int arrival_time;
	int burst_time;
} process;


int main()
{

	/* read in data - DO NOT EDIT (START) */
	int n;
	int quantum;
	scanf("%d", &n);
	scanf("%d", &quantum);
	process *arr;
	arr = malloc(n * sizeof(process));
	for (int i = 0; i < n ; ++i) {
		scanf("%d", &arr[i].pid);
		scanf("%d", &arr[i].arrival_time);
		scanf("%d", &arr[i].burst_time);
	}
	/* read in data - DO NOT EDIT (END) */

  int n_temp = n;
  int current_time = 0;
  int q_temp = 0;
  while (n_temp > 0)
  {
    for (int i = 0 ; i < n ; i ++)
    {
      if (arr[i].arrival_time > current_time)
        break;
      if (arr[i].burst_time > 0)
      {
        current_time++;
        q_temp ++;
        printf("%d\n", arr[i].pid);
        arr[i].burst_time --;
      }
      
      if (arr[i].burst_time <= 0)
        n_temp --;
      
      if (q_temp % quantum == 0)
        q_temp = 0;
    }
  }
	return 0; /* DO NOT EDIT THIS LINE */
}
