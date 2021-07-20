#include "queue.h"

/*Se usar colocar essa linha de comando no Cmake:
 *

add_executable(arquivos josephus.c queue.c)

 *
 Se não usar, pode ignorar                        */

int main () {
  int i, m, n;

  printf("Josephus - digite o passo da morte e numero de competidores: ");
  scanf("%d %d", &m, &n);
  Queue *q = create_queue ();
  for(i=1; i<=n; i++){;
      q = enqueue(q, i);
  }

  q = linkStartEnd(q);

  while(!lastOne(q)){
          q = dequeue(q, m);
  }
  winner(q);
  free_queue (q);
  return 0;
}