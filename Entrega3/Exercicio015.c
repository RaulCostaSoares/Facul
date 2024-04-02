#include <stdio.h>

int main(){

    int d, m, a, h, min;

    scanf("%d\n", &d);
    scanf("%d\n", &m);
    scanf("%d\n", &a);
    scanf("%d\n", &h);
    scanf("%d", &min);

    char *nomeM;

    switch (m){
        case 1: nomeM = "janeiro"; break;
        case 2: nomeM = "fevereiro"; break;
        case 3: nomeM = "marco"; break;
        case 4: nomeM = "abril"; break;
        case 5: nomeM = "maio"; break;
        case 6: nomeM = "junho"; break;
        case 7: nomeM = "julho"; break;
        case 8: nomeM = "agosto"; break;
        case 9: nomeM = "setembro"; break;
        case 10: nomeM = "outubro"; break;
        case 11: nomeM = "novembro"; break;
        case 12: nomeM = "dezembro"; break;
    }
    printf("%02d/%02d/%04d - %s\n", d, m, a, nomeM);
    printf("%02d:%02d", h, min);

    return 0;
}