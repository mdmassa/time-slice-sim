#include <stdio.h>

#define CPU_TIME 20

int main() {
  float time_slice;
  int total_processos;
  int memoria[10];
  int exec;

  int i;

  printf("Digite a quantidade processos (MAX 10): ");
  scanf("%d", &total_processos);

  time_slice = CPU_TIME / total_processos;

  for (i = 0; i < total_processos; i++) {
    memoria[i] = i;
  }

  printf("Tempo total CPU: %.2f\n", time_slice);
  for (i = 0; i < total_processos; i++) {
    printf("\nID Processo: %d\nTempo dedicado: %.2f\n\n", memoria[i],
           time_slice);
  }
}
