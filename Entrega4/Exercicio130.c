#include <stdio.h>

int main(){

    int idade, maiorIdade = 0, menorIdade = 999, mulherSal = 0, quantiaH = 0;
    double sal, totSal = 0, medSal;
    char sexo;

    while (1) {
      scanf("%d", &idade);
      if (idade < 0) {
        break;
      }
      scanf(" %c %lf", &sexo, &sal);

      // Cálculo da média de salário
      totSal += sal;
      quantiaH++;

      // Verificar maior e menor idade
      if (idade > maiorIdade) {
        maiorIdade = idade;
      }
      if (idade < menorIdade) {
        menorIdade = idade;
      }

      // Verificar quantidade de mulheres com salário até 500
      if (sexo == 'F' && sal <= 500.00) {
        mulherSal++;
      }
    }

    if (quantiaH > 0) {
      medSal = totSal / quantiaH;
      printf("%.4lf %d %d %d\n", medSal, maiorIdade, menorIdade, mulherSal);
    
    } else {
      printf("Nenhum dado foi inserido para este teste.\n");
    }
    




    return 0;
}