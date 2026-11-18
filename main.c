include <stdio.h>

struct Patient {
    int id, age;
    char name[50], disease[50], doctor[50];
    int severity;
};

void display(struct Patient p) {
    printf("\nPatient ID: %d", p.id);
    printf("\nName: %s", p.name);
    printf("\nAge: %d", p.age);
    printf("\nDisease: %s", p.disease);
    printf("\nDoctor: %s", p.doctor);
}

int main() {
    struct Patient p[100];
    int n = 0, choice, i, id, found;
    float cost;

    do {
        printf("\n\n--- Hospital Patient Record System ---");
        printf("\n1. Register Patient");
        printf("\n2. Search Patient");
        printf("\n3. Display All Patients");
        printf("\n4. Calculate Treatment Cost");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Patient ID: ");
            scanf("%d", &p[n].id);

            printf("Enter Name: ");
            scanf(" %49[^\n]", p[n].name);

            printf("Enter Age: ");
            scanf("%d", &p[n].age);

            printf("Enter Disease: ");
            scanf(" %49[^\n]", p[n].disease);

            printf("Enter Doctor Name: ");
            scanf(" %49[^\n]", p[n].doctor);

            printf("Severity (1-Mild, 2-Moderate, 3-Severe): ");
            scanf("%d", &p[n].severity);

            n++;
            printf("Patient registered successfully!");
        }

        else if (choice == 2) {
            printf("Enter Patient ID to search: ");
            scanf("%d", &id);
            found = 0;

            for (i = 0; i < n; i++) {
                if (p[i].id == id) {
                    display(p[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Patient not found!");
        }

        else if (choice == 3) {
            for (i = 0; i < n; i++)
                display(p[i]);

            if (n == 0)
                printf("No patient records available.");
        }

        else if (choice == 4) {
            printf("Enter Patient ID: ");
            scanf("%d", &id);
            found = 0;

            for (i = 0; i < n; i++) {
                if (p[i].id == id) {
                    if (p[i].severity == 1)
                        cost = 1000;
                    else if (p[i].severity == 2)
                        cost = 3000;
                    else
                        cost = 5000;

                    printf("Treatment Cost: Rs. %.2f", cost);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Patient not found!");
        }

        else if (choice == 5)
            printf("Exiting system...");

        else
            printf("Invalid choice!");

    } while (choice != 5);

    return 0;
}
