#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int pid;
	int arrival_time;
	int burst_time;
} process;

int sum_burst_time(int n, process *arr)
{
  int sumBT = 0;
  for (int i = 0; i < n; i ++)
    sumBT += arr[i].burst_time;
  return sumBT;
}

int lowest_burst_time(int n, int ready_queue[])
{
  int lowestBT = 99999;
  for (int i = 0 ; i < n ; i ++)
  {
    if (ready_queue[i] < lowestBT && ready_queue[i] > 0)
      lowestBT = ready_queue[i];
  }
  return lowestBT;
}

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

  // τωρινός χρόνος, άθροισμα όλων των χρόνων καταιγισμού, λίστα αναμονής.
  int current_time = 0, sumBT = sum_burst_time(n, arr), ready_queue[n];

  // για κάθε θέση στη λίστα αναμονής, βάζω το -1 ως αρχική τιμή.
  for (int i = 0 ; i < n ; i ++)
    ready_queue[i] = -1;

  /* όσες διεργασίες να δώσει ο χρήστης και οποιεσδήποτε τιμές στα πεδία χρόνος άφιξης και χρόνος καταιγισμού, 
  τότε η επανάληψη γουαιλ θα τρέξει όσο το άθροισμα όλων των χρόνων καταιγισμού όλων των διεργασιών. Έτσι, 
  όσο η τωρινή τιμή χρόνου είναι μικρότερη από το συνολκό άθροισμα όλων των χρόνων καταιγισμού, τότε */
  while (current_time < sumBT)
  {
    // για κάθε διεργασία, 
    for (int i = 0 ; i < n ; i ++)
    {
      /* αν ο χρόνος άφιξής της δεν είναι μεγαλύτερος από την παρόντα χρόνο
      τότε προσθέτω στη λίστα αναμονής τον χρόνο καταιγισμού της. */
      if (arr[i].arrival_time <= current_time)
        ready_queue[i] = arr[i].burst_time;
    }

    // μεταβλητή i.
    int i = 0;
    // (βασική while) όσο το i είναι μικρότερο του n, δηλαδή για κάθε διεργασία, 
    while (i < n)
    {
      /* αν βρίσκεται στη λίστα αναμονής, αν ο χρόνος καταιγισμού της είναι μεγαλύτερος του 0 και
      αν ο χρόνος καταιγισμού της είναι ίσος με τον μικρότερο χρόνο καταιγισμού των διεργασιών
      που βρίσκονται στη λίστα αναμονής, τότε */
      if (arr[i].burst_time == ready_queue[i] && ready_queue[i] > 0 && arr[i].burst_time == lowest_burst_time(n, ready_queue))
      {
        // εκτυπώνω την διεργασία και επίσης,
        printf("%d\n", arr[i].pid);
        // μειώνω τον χρόνο καταιγισμού της κατά 1, εφόσον επεξεργάστηκε 1 φορά (δηλαδή για 1 τιμή χρόνου),
        arr[i].burst_time --;
        // αυξάνω τον χρόνο άφιξης της διεργασίας και
        arr[i].arrival_time ++;
        /* θέτω το i ίσο με n, για να τερματίσει η εσωτερική επανάληψη γουαιλ και
        έτσι προχωράω στον έλεγχο του επόμενου χρόνου (εφόσον τον αυξήσω στο τέλος της βασικής γουαιλ). */
        i = n;
      } // τέλος συνθήκης if.
      i ++;
    } // τέλος εσωτερικής επανάληψης while
    // αύξηση του τωρινού χρόνου κατά 1, εφόσον ελέγχω και επεξεργάζομαι κάθε διεργασία κάθε 1 τιμή χρόνου.
    current_time ++;
  } // τέλος βασικής επανάληψης while.
	return 0; /* DO NOT EDIT THIS LINE */
}
