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
    printf("=== TESTE DE PARSING DE CIDADES COMPOSTAS ===\n\n");
    
    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d", 
                  &flight.id, flight.companyCode, flight.flightNumber, flight.origin, 
                  flight.depDate, flight.depTime, flight.destination, 
                  flight.arrDate, flight.arrTime, &flight.totalSeats, &flight.occupiedSeats) == 11) {
        
        // Mostrar apenas voos com cidades compostas
        if (strchr(flight.origin, ' ') || strchr(flight.destination, ' ')) {
            printf("ID: %d\n", flight.id);
            printf("Voo: %s (%s)\n", flight.flightNumber, flight.companyCode);
            printf("Origem: %s\n", flight.origin);
            printf("Data/Hora Saída: %s às %s\n", flight.depDate, flight.depTime);
            printf("Destino: %s\n", flight.destination);
            printf("Data/Hora Chegada: %s às %s\n", flight.arrDate, flight.arrTime);
            printf("Assentos: %d/%d\n", flight.occupiedSeats, flight.totalSeats);
            printf("---\n");
        }
    }
    
    fclose(file);
    printf("\n✅ Teste de parsing concluído com sucesso!\n");
    return 0;
}
