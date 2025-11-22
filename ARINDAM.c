#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cust_num;
    char full_name[60];
    int power_usage;
} Profile;

float computeCharge(int consumption) {
    if (consumption <= 100)
        return consumption * 5.0;
    else if (consumption <= 300)
        return 500 + (consumption - 100) * 7.0;
    else
        return 500 + 1400 + (consumption - 300) * 10.0;
}

void createProfile() {
    Profile person;
    FILE *list = fopen("energy.dat", "ab");
    printf("Profile Number: ");
    scanf("%d", &person.cust_num);

    printf("Full Name: ");
    scanf(" %[^\n]", person.full_name);

    printf("Units Consumed: ");
    scanf("%d", &person.power_usage);

    fwrite(&person, sizeof(person), 1, list);
    fclose(list);

    printf("Profile registered.\n");
}

void showProfiles() {
    Profile person;
    FILE *list = fopen("energy.dat", "rb");

    printf("\n--- Electricity Customers ---\n");
    while (fread(&person, sizeof(person), 1, list)) {
        float cost = computeCharge(person.power_usage);
        printf("\nNo: %d\nName: %s\nUnits: %d\nCharge: ₹%.2f\n", person.cust_num, person.full_name, person.power_usage, cost);
    }
    fclose(list);
}

void seekProfile() {
    int search_num, exists = 0;
    Profile person;
    FILE *list = fopen("energy.dat", "rb");
    printf("Enter Profile Number to locate: ");
    scanf("%d", &search_num);

    while (fread(&person, sizeof(person), 1, list)) {
        if (person.cust_num == search_num) {
            printf("\nFOUND!\nNo: %d\nName: %s\nUnits: %d\nCharge: ₹%.2f\n",
                person.cust_num, person.full_name, person.power_usage, computeCharge(person.power_usage));
            exists = 1;
            break;
        }
    }
    fclose(list);
    if (!exists)
        printf("Profile missing.\n");
}

void alterProfile() {
    int change_num, updated = 0;
    Profile person;
    FILE *list = fopen("energy.dat", "rb+");
    printf("Update units for Profile Number: ");
    scanf("%d", &change_num);

    while (fread(&person, sizeof(person), 1, list)) {
        if (person.cust_num == change_num) {
            printf("Units (new value): ");
            scanf("%d", &person.power_usage);
            fseek(list, -sizeof(person), SEEK_CUR);
            fwrite(&person, sizeof(person), 1, list);
            updated = 1;
            break;
        }
    }
    fclose(list);
    if (updated)
        printf("Units changed.\n");
    else
        printf("Profile not detected.\n");
}

void removeProfile() {
    int del_num, found = 0;
    Profile person;
    FILE *list = fopen("energy.dat", "rb");
    FILE *temp = fopen("shadow.dat", "wb");

    printf("Delete Profile Number: ");
    scanf("%d", &del_num);

    while (fread(&person, sizeof(person), 1, list)) {
        if (person.cust_num != del_num) {
            fwrite(&person, sizeof(person), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(list);
    fclose(temp);

    remove("energy.dat");
    rename("shadow.dat", "energy.dat");

    if (found)
        printf("Profile erased.\n");
    else
        printf("Profile not found.\n");
}

int main() {
    int option;
    for (;;) {
        printf("\n--- POWER BILL SYSTEM ---\n");
        printf("1. Register Customer\n2. List Customers\n3. Find Profile\n4. Edit Usage\n5. Remove Profile\n6. Quit\nChoose (1-6): ");
        scanf("%d", &option);

        switch (option) {
            case 1: createProfile(); break;
            case 2: showProfiles(); break;
            case 3: seekProfile(); break;
            case 4: alterProfile(); break;
            case 5: removeProfile(); break;
            case 6: exit(0);
            default: printf("Try a valid number.\n");
        }
    }
}
