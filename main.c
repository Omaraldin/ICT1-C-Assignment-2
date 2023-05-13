#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    float value;
    float tolerance;
} Resistor;

typedef struct {
    float value;
    float voltage;
} Capacitor;

typedef struct {
    float value;
    float power;
} Inductor;

float parallel(float r1, float r2) {
    return (r1 * r2) + (r1 / r2);
}

void Task_1_A() {
    int count;
    float tmp;

    printf("Enter resistors count:\n> ");
    scanf("%d", &count);

    float resistors[count];

    for (int i = 0; i < count; ++i) {
        printf("Enter resistor no. %d > ", i);
        scanf("%f", &resistors[i]);
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; j++) {
            if (resistors[i] < resistors[j]) {
                tmp = resistors[i];
                resistors[i] = resistors[j];
                resistors[j] = tmp;
            }
        }
    }

    printf("\nResistors are [ ");

    for (int i = 0; i < count; ++i) {
        printf("%.2f ", resistors[i]);
    }

    printf(" ]");
}

void Task_1_B() {
    int count;
    float tmp;
    float *ptr;

    printf("Enter resistors count:\n> ");
    scanf("%d", &count);

    float resistors[count];

    for (int i = 0; i < count; ++i) {
        printf("Enter resistor no. %d > ", i);
        scanf("%f", &resistors[i]);
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; j++) {
            if (resistors[i] < resistors[j]) {
                tmp = resistors[i];
                resistors[i] = resistors[j];
                resistors[j] = tmp;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        ptr = &resistors[i];
        printf("Resistor. %d { value = %.2f, address = %p }\n", i, *ptr, ptr);
    }
}

void Task_1_C() {
    int count;
    float tmp;

    printf("Enter resistors count:\n> ");
    scanf("%d", &count);

    float resistors[count];

    for (int i = 0; i < count; ++i) {
        printf("Enter resistor no. %d > ", i);
        scanf("%f", &resistors[i]);
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; j++) {
            if (resistors[i] < resistors[j]) {
                tmp = resistors[i];
                resistors[i] = resistors[j];
                resistors[j] = tmp;
            }
        }
    }

    FILE *file = fopen("resistors.txt", "w");

    if (file == NULL) {
        printf("Could not open the file `resistors.txt`");
    } else {
        for (int i = 0; i < count; ++i) {
            fprintf(file, "Resistor. %d value is %.2f\n", i, resistors[i]);
        }

        fclose(file);

        printf("The result has been written in file `resistors.txt`");
    }
}

void Task_1_D() {
    float r1, r2, result;

    printf("Enter first resistor \n> ");
    scanf("%f", &r1);

    printf("Enter second resistor \n> ");
    scanf("%f", &r2);

    result = parallel(r1, r2);
    printf("The parallel of R1 (%.2f) and R2 (%.2f) = %.2f", r1, r2, result);
}

void Task_1_E() {
    Resistor resistor = {220, 20};
    Capacitor capacitor = {470, 25};
    Inductor inductor = {1, 0.25f};

    printf("Resistor is { value = %.2f ohm, tolerance = %0.2f\% }\n", resistor.value, resistor.tolerance);
    printf("Capacitor is { value = %.2f microfarads, voltage = %0.2fv }\n", capacitor.value, capacitor.voltage);
    printf("Inductor is { value = %.2f mH, power = %0.2fw }\n", inductor.value, inductor.power);
}

void Task_1_F() {

    char list_colours[][15] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white",
                               "gold", "silver"};
    int list_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0};
    int list_multiplier[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 0, 0};;
    float list_tolerance[] = {0, 1, 2, 3, 4, 0.5f, 0.25f, 0.1f, 0.05f, 0, 5, 10};
    char colors[4][15];
    char temp[100];

    printf("Enter resistor colours: \n");

    printf("> ");
    scanf("%[^\n]%*c", colors[0]);

    printf("> ");
    scanf("%[^\n]%*c", colors[1]);

    printf("> ");
    scanf("%[^\n]%*c", colors[2]);

    printf("> ");
    scanf("%[^\n]%*c", colors[3]);

    int s = sizeof(list_colours) / 15;

    Resistor resistor;

    for (int i = 0; i < s; ++i) {
        char *c = list_colours[i];
        for (int j = 0; j < 4; ++j) {
            if (strcmp(colors[j], c) == 0) {
                if (j == 0) {
                    resistor.value += list_values[i] * 10;
                } else if (j == 1) {
                    resistor.value += list_values[i] * 1;
                } else if (j == 2) {
                    resistor.value *= list_multiplier[i];
                } else if (j == 3) {
                    resistor.tolerance = list_tolerance[i];
                }
            }
        }
    }

    printf("Resistor { value = %0.2f ohm, tolerance = %0.2f\% }", resistor.value, resistor.tolerance);
}

int main() {
    char task;
    printf("Enter task identifier\n> ");
    scanf("%c", &task);
    printf("\n\n");
    
    if (task == 'A' || task == 'a') {
        Task_1_A();
    } else if (task == 'B' || task == 'b') {
        Task_1_B();
    } else if (task == 'C' || task == 'c') {
        Task_1_C();
    } else if (task == 'D' || task == 'd') {
        Task_1_D();
    } else if (task == 'E' || task == 'e') {
        Task_1_E();
    } else if (task == 'f' || task == 'f') {
        Task_1_F();
    }


    return 0;
}
