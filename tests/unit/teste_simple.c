#include <stdio.h>

int main() {
    FILE *f = fopen("data/Company Users/DataFlights.dat", "r");
    int id, seats, occ;
    char cc[10], fn[20], o[50], dd[12], dt[7], des[50], ad[12], at[7];
    
    printf("Lendo primeira linha:\n");
    int result = fscanf(f, "%d;%9[^;];%19[^;];%49[^;];%11[^;];%6[^;];%49[^;];%11[^;];%6[^;];%d;%d",
                        &id, cc, fn, o, dd, dt, des, ad, at, &seats, &occ);
    
    printf("Resultado: %d campos\n", result);
    printf("ID: %d\nCC: %s\nFN: %s\nO: %s\n", id, cc, fn, o);
    
    fclose(f);
    return 0;
}
