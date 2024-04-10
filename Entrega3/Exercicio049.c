#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int ang, quad, voltas;
    char *dire;

    scanf("%d", &ang);

    if (ang >= 360 || ang <= -360) {
        if(ang<0){
            ang = ang*(-1);
        }
        voltas = ang / 360;
    } else {
        voltas = 0;
    }
    while (ang > 360) {
        ang = ang - 360;
    }
    while (ang < -360) {
        ang = ang + 360;
    }
    if (ang == 0 || ang == 180 || ang == -180 || ang == 360 || ang == -360 || ang == 90 || ang == -90 || ang == 270 || ang == -270) {
        quad = 0;
    } else if (ang > 0) {
        if (ang < 90) {
            quad = 1;
        } else if (ang < 180) {
            quad = 2;
        } else if (ang < 270) {
            quad = 3;
        } else {
            quad = 4;
        }
    } else {
        if (ang > -90) {
            quad = 4;
        } else if (ang > -180) {
            quad = 3;
        } else if (ang > -270) {
            quad = 2;
        } else {
            quad = 1;
        }
    }

    if (ang >= 0) {
        dire = "HORARIO";
    } else {
        dire = "ANTI-HORARIO";
    }

    if (quad == 0) {
        if (ang == 0 || ang == 360 || ang == -360 || ang == 180 || ang == -180) {
            printf("EIXO X\n");
        } else {
            printf("EIXO Y\n");
        }
        printf("%s\n", dire);
        printf("%d", voltas);
    } else {
    printf("%d\n", quad);
    printf("%s\n", dire);
    printf("%d", voltas);
    }

    return 0;
}
