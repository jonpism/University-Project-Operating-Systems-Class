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

  //για κάθε διεργασία,
  for (int i = 0 ; i < n ; )
  {
    //αν ο χρόνος καταιγισμού της διεργασίας i είναι μεγαλύτερος του 0,
    if (arr[i].burst_time > 0)
    {
      //τότε εμφανίζω το id της διεργασίας στην οθόνη και
      printf ("%d\n", arr[i].pid);
      //μειώνω τον χρόνο καταιγισμού της κατά 1 ενώ,
      arr[i].burst_time --;
    }
    else
      /* αν ο χρόνος καταιγισμού της διεργασίας i είναι ίσος με το 0
      τότε αυξάνω το i και ελέγχω την επόμενη διεργασία i */
      i ++;
  }
  
	return 0; /* DO NOT EDIT THIS LINE */
}
