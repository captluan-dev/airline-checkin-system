#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char companyCode[10];
    char flightNumber[20];
    char origin[50];
    char depDate[12];
    char depTime[7];
    char destination[50];
    char arrDate[12];
    char arrTime[7];
    int totalSeats;
    int occupiedSeats;
} Flight;

int main() {
    FILE *file = fopen("data/Company Users/DataFlights.dat", "r");
    if (!file) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    
    Flight flight;
    printf("=== TESTE DE PARSING - DEBUG ===\n\n");
    int count = 0;
    
    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d", 
                  &flight.id, flight.companyCode, flight.flightNumber, flight.origin, 
                  flight.depDate, flight.depTime, flight.destination, 
                  flight.arrDate, flight.arrTime, &flight.totalSeats, &flight.occupiedSeats) == 11) {
        
        count++;
        printf("Voo %d lido com sucesso:\n", count);
        printf("  ID: %d\n", flight.id);
        printf("  Código Empresa: %s\n", flight.companyCode);
        printf("  Número Voo: %s\n", flight.flightNumber);
        printf("  Origem: %s\n", flight.origin);
        printf("  Data Saída: %s\n", flight.depDate);
        printf("  Hora Saída: %s\n", flight.depTime);
        printf("  Destino: %s\n", flight.destination);
        printf("  Data Chegada: %s\n", flight.arrDate);
        printf("  Hora Chegada: %s\n", flight.arrTime);
        printf("  Assentos Totais: %d\n", flight.totalSeats);
        printf("  Assentos Ocupados: %d\n", flight.occupiedSeats);
        printf("\n");
    }
    
    fclose(file);
    printf("✅ Total de %d voos lidos com sucesso!\n", count);
    return 0;
}
