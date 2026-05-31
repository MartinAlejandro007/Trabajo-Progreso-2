#include <stdio.h>

#define MAX_EST 1000
#define N_ASIG 3
#define NOTA_APR 6.0

void pedirNotas(int nEst, float notas[][N_ASIG]);
void calcularPromediosEstudiantes(int nEst, float notas[][N_ASIG], float promEst[]);
void calcularPromediosAsignaturas(int nEst, float notas[][N_ASIG], float promAsig[]);
void buscarMaxMinEstudiantes(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[]);
void buscarMaxMinAsignaturas(int nEst, float notas[][N_ASIG], float maxAsig[], float minAsig[]);

int main() {
    int nEst;
    
    printf("=== GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes (max %d): ", MAX_EST);
    scanf("%d", &nEst);
    
    if (nEst <= 0 || nEst > MAX_EST) {
        printf("Error: El numero debe estar entre 1 y %d.\n", MAX_EST);
        return 1;
    }
    
    float notas[MAX_EST][N_ASIG];
    float promEst[MAX_EST];
    float promAsig[N_ASIG];
    float maxEst[MAX_EST];
    float minEst[MAX_EST];
    float maxAsig[N_ASIG];
    float minAsig[N_ASIG];
    int apr[N_ASIG];
    int rep[N_ASIG];
    
    pedirNotas(nEst, notas);
    
    calcularPromediosEstudiantes(nEst, notas, promEst);
    calcularPromediosAsignaturas(nEst, notas, promAsig);
    buscarMaxMinEstudiantes(nEst, notas, maxEst, minEst);
    buscarMaxMinAsignaturas(nEst, notas, maxAsig, minAsig);
    
    printf("\n=== PROMEDIOS POR ESTUDIANTE ===\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promEst[i]);
    }
    
    printf("\n=== PROMEDIOS POR ASIGNATURA ===\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promAsig[j]);
    }
    
    printf("\n=== MAXIMOS Y MINIMOS POR ESTUDIANTE ===\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: Max=%.2f, Min=%.2f\n", i + 1, maxEst[i], minEst[i]);
    }
    
    printf("\n=== MAXIMOS Y MINIMOS POR ASIGNATURA ===\n");
    for (int j = 0; j < N_ASIG; j++) {
        printf("Asignatura %d: Max=%.2f, Min=%.2f\n", j + 1, maxAsig[j], minAsig[j]);
    }
    
    return 0;
}

void pedirNotas(int nEst, float notas[][N_ASIG]) {
    for (int i = 0; i < nEst; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < N_ASIG; j++) {
            do {
                printf("Asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: Fuera de rango. Intente de nuevo.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}

void calcularPromediosEstudiantes(int nEst, float notas[][N_ASIG], float promEst[]) {
    for (int i = 0; i < nEst; i++) {
        float suma = 0;
        for (int j = 0; j < N_ASIG; j++) {
            suma += notas[i][j];
        }
        promEst[i] = suma / N_ASIG;
    }
}

void calcularPromediosAsignaturas(int nEst, float notas[][N_ASIG], float promAsig[]) {
    for (int j = 0; j < N_ASIG; j++) {
        float suma = 0;
        for (int i = 0; i < nEst; i++) {
            suma += notas[i][j];
        }
        promAsig[j] = suma / nEst;
    }
}

void buscarMaxMinEstudiantes(int nEst, float notas[][N_ASIG], float maxEst[], float minEst[]) {
    for (int i = 0; i < nEst; i++) {
        maxEst[i] = notas[i][0];
        minEst[i] = notas[i][0];
        for (int j = 1; j < N_ASIG; j++) {
            if (notas[i][j] > maxEst[i]) {
                maxEst[i] = notas[i][j];
            }
            if (notas[i][j] < minEst[i]) {
                minEst[i] = notas[i][j];
            }
        }
    }
}

void buscarMaxMinAsignaturas(int nEst, float notas[][N_ASIG], float maxAsig[], float minAsig[]) {
    for (int j = 0; j < N_ASIG; j++) {
        maxAsig[j] = notas[0][j];
        minAsig[j] = notas[0][j];
        for (int i = 1; i < nEst; i++) {
            if (notas[i][j] > maxAsig[j]) {
                maxAsig[j] = notas[i][j];
            }
            if (notas[i][j] < minAsig[j]) {
                minAsig[j] = notas[i][j];
            }
        }
    }
}