#include <stdio.h>

#define numeroObj 10
#define salarioBas 545.00
#define comissao 0.05

int main() {
    double precos[numeroObj];
    int quantidades[numeroObj];
    double totalVendas[numeroObj];
    double totalVendasValor = 0.0;
    double comissaoEfetuada;
    int i;
    
    for (i = 0; i < numeroObj; i++) {
        scanf("%lf %d", &precos[i], &quantidades[i]);
        totalVendas[i] = precos[i] * quantidades[i];
        totalVendasValor += totalVendas[i];
    }
    
    comissaoEfetuada = totalVendasValor * comissao;
    
    for (i = 0; i < numeroObj; i++) {
        printf("%d %.4lf %.4lf\n", quantidades[i], precos[i], totalVendas[i]);
    }
    printf("%.4lf %.4lf\n", totalVendasValor, comissaoEfetuada);
    
    int max_quantity = quantidades[0];
    for (i = 1; i < numeroObj; i++) {
        if (quantidades[i] > max_quantity) {
            max_quantity = quantidades[i];
        }
    }

    for (i = 0; i < numeroObj; i++) {
        if (quantidades[i] == max_quantity) {
            printf("%.4lf %d\n", precos[i], i);
        }
    }

    return 0;
}
