#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int pid;
  int arrival_time;
  int burst_time;
} process;

int lowest_burst_time(int n, process *arr)
{
  int lowestBT = 98765;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].pid != -1 && arr[i].burst_time <= lowestBT)
      lowestBT = arr[i].burst_time;
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
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i].pid);
    scanf("%d", &arr[i].arrival_time);
    scanf("%d", &arr[i].burst_time);
  }
  /* read in data - DO NOT EDIT (END) */

  // μεταβλητή τωρινός χρόνος καταιγισμού.
  int temp_burst_time = 0;

  // ελέγχω κάθε διεργασία και 
  for (int i = 0 ; i < n ; i ++)
  {
    // εφόσον βρω την διεργασία με τον μικρότερο χρόνο άφιξης (δηλαδή 0),
    if (arr[i].arrival_time == 0)
    {
      // τότε την εκτυπώνω, 
      for (int j = 0 ; j < arr[i].burst_time ; j ++)
        printf("%d\n", arr[i].pid);
      // θέτω το id ίσο με -1 διότι θα ξέρω ότι αυτή η διεργασία θα έχει επεξεργαστεί και τέλος,
      arr[i].pid = -1;
      // θέτω ως τωρινό χρόνο καταιγισμού την τιμή του χρόνου καταιγισμού της διεργασίας που επεξεργάστηκε.
      temp_burst_time = arr[i].burst_time;
    }
  }

  // μεταβλητή μετρητής που την θέτω με αρχική τιμή = 1 επειδή ήδη έχει επεξεργαστεί μία διεργασία.
  int count = 1;
  // λίστα αναμονής.
  int ready_queue[98765];
  // όσο ο μετρητής είναι μικρότερος από το σύνολο των διεργασιών,
  while (count < n)
  {
    // για κάθε διεργασία,
    for (int i = 0 ; i < n ; i ++)
    {
      /* ελέγχω αν το id της διεργασίας δεν είναι -1 (δηλαδή δεν έχει επεξεργαστεί) και
      αν ο χρόνος άφιξης της διεργασίας δεν είναι μεγαλύτερος από τον τωρινό χρόνο καταιγισμού, 
      και αν ισχύουν αυτά, τότε η διεργασία μπαίνει στην λίστα αναμονής. */
      if (arr[i].pid != -1 && arr[i].arrival_time <= temp_burst_time)
        ready_queue[i] = arr[i].pid;
    }

    // έπειτα, για κάθε διεργασία, 
    for (int i = 0 ; i < n ; i ++)
    {
      /* που βρίσκεται στη λίστα αναμονής και ο χρόνος καταιγισμού της δεν είναι μεγαλύτερος από
      την χαμηλότερη τιμή χρόνου καταιγισμού των διεργασιών που βρίσκονται στη λίστα αναμονής 
      (που υπολογίζεται μέσα σε μια συνάρτηση), τότε */
      if (ready_queue[i] == arr[i].pid && arr[i].burst_time <= lowest_burst_time(n, arr))
      {
        // εμφανίζω την διεργασία, 
        for (int j = 0 ; j < arr[i].burst_time ; j ++)
          printf("%d\n", arr[i].pid);
        // θέτω το id της = -1
        arr[i].pid = -1;
        // αυξάνω τον μετρητή και τέλος
        count ++;
        /* θέτω τον τωρινό χρόνο καταιγισμού με τιμή ίση με τον χρόνο καταιγισμού
        της διεργασίας που επεξεργάστηκε. */
        temp_burst_time = arr[i].burst_time;
      } // τέλος της if συνθήκης.
    } // τέλος της for επανάληψης.
  }  // τέλος της while επανάληψης.

  return 0; /* DO NOT EDIT THIS LINE */
}
