#include "fila.h"
#include <stdio.h>
#include <unistd.h>

#define CPU_TIME 20

int main() {
  float time_slice;
  float total_processos;
  int memoria[10];
  int i, j;
  char op;

  printf("Digite a quantidade processos (MAX 10): ");
  scanf("%f", &total_processos);

  // Divide o tempo total da CPU igualmente para cada processo
  time_slice = CPU_TIME / total_processos;

  // Armazena os processos na memória
  for (i = 0; i < total_processos; i++) {
    memoria[i] = i;
  }

  printf("\n\n");
  printf("         ==== Memoria (10 ESPAÇOS) ====\n");
  printf("0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9 \n");
  printf("---+----+----+----+----+----+----+----+----+----\n");
  for (i = 0; i < total_processos; i++) {
    printf("p%d | ", memoria[i]);
  }
  printf("\n---+----+----+----+----+----+----+----+----+----\n");
  printf("\n\n");

  sleep(2);

  Fila espera = fila(total_processos);
  Fila pronto = fila(total_processos);
  int execucao;

  // Coleta os processos da memória e ordena eles na fila de ESPERA
  for (i = 0; i < total_processos; i++) {
    enfileira(memoria[i], espera);
    printf(
        "\nProcesso %d da memoria adicionado a posicao %d da fila de espera.\n",
        memoria[i], i);
  }

  printf("\n\nIniciar execucoes? (s/n) ");
  scanf("%s", &op);

  if (op == 's') {
    system("clear");
    sleep(1);
    // Coleta os processos da fila de ESPERA e ordena eles um por vez em PRONTO
    for (i = 0; i < total_processos; i++) {
      enfileira(desenfileira(espera), pronto);
      printf("⏲ ESPERA: processo nº %d\n", i + 2);
      printf("\n✓ PRONTO: processo nº %d\n", i + 1);
      
      execucao = desenfileira(pronto);
      printf("\n▶ EXECUTANDO: processo nº %d.\n", execucao);
      sleep(time_slice);
      
      system("clear");
    }

    printf("RELATORIO FINAL DE EXECUÇÃO:\n\n");
    printf("Tempo total CPU: 20s\n");
    for (i = 0; i < total_processos; i++) {
      printf("\nID Processo: %d\nTempo dedicado: %.2fs\n", memoria[i],
             time_slice);
    }
  } else {
    printf("\n\nRELATORIO FINAL DE EXECUÇÃO:\n\n");
    printf("Nada executado.\n");
  }
}
