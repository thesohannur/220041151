#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Define the record structure
struct record {
    int Spell_ID;
    char incantation[50];
    char spell_name[50];
    char effect[50];
    char light[50];
};

// Function to read the entire file, including the header
void read_database(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}

// Function to insert a new row into the file
void insert_row(const char *filename, struct record *new_record) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    fprintf(fp, "%d,%s,%s,%s,%s\n",
            new_record->Spell_ID,
            new_record->incantation,
            new_record->spell_name,
            new_record->effect,
            new_record->light);

    fclose(fp);
}

// Function to update a record in the file
void update_row(const char *filename, int id_to_update, struct record *updated_record) {
    FILE *fp = fopen(filename, "r");
    FILE *temp_fp = fopen("temp.txt", "w");
    if (fp == NULL || temp_fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int is_header = 1;
    while (fgets(line, sizeof(line), fp)) {
        if (is_header) {
            fprintf(temp_fp, "%s", line);
            is_header = 0;
            continue;
        }

        struct record rec;
        sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &rec.Spell_ID, rec.incantation, rec.spell_name, rec.effect, rec.light);
        
        if (rec.Spell_ID == id_to_update) {
            fprintf(temp_fp, "%d,%s,%s,%s,%s\n",
                    updated_record->Spell_ID,
                    updated_record->incantation,
                    updated_record->spell_name,
                    updated_record->effect,
                    updated_record->light);
        } else {
            fprintf(temp_fp, "%d,%s,%s,%s,%s\n",
                    rec.Spell_ID,
                    rec.incantation,
                    rec.spell_name,
                    rec.effect,
                    rec.light);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove(filename);
    rename("temp.txt", filename);
}

// Function to delete a record from the file
void delete_row(const char *filename, int id_to_delete) {
    FILE *fp = fopen(filename, "r");
    FILE *temp_fp = fopen("temp.txt", "w");
    if (fp == NULL || temp_fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int is_header = 1;
    while (fgets(line, sizeof(line), fp)) {
        if (is_header) {
            fprintf(temp_fp, "%s", line);
            is_header = 0;
            continue;
        }

        struct record rec;
        sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &rec.Spell_ID, rec.incantation, rec.spell_name, rec.effect, rec.light);
        
        if (rec.Spell_ID != id_to_delete) {
            fprintf(temp_fp, "%d,%s,%s,%s,%s\n",
                    rec.Spell_ID,
                    rec.incantation,
                    rec.spell_name,
                    rec.effect,
                    rec.light);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove(filename);
    rename("temp.txt", filename);
}

// Function to search for a record by ID
void search_by_id(const char *filename, int id_to_search) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int is_header = 1;
    while (fgets(line, sizeof(line), fp)) {
        if (is_header) {
            is_header = 0;
            continue; // Skip the header line
        }

        struct record rec;
        sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &rec.Spell_ID, rec.incantation, rec.spell_name, rec.effect, rec.light);
        
        if (rec.Spell_ID == id_to_search) {
            printf("Found record: %d,%s,%s,%s,%s\n",
                   rec.Spell_ID,
                   rec.incantation,
                   rec.spell_name,
                   rec.effect,
                   rec.light);
            fclose(fp);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id_to_search);
    fclose(fp);
}

int main() {
    const char *filename = "spells.txt";

    // Read the database
    read_database(filename);

    // Insert a new row
    struct record new_record = {5, "Wingardium Leviosa", "Levitation Charm", "Levitate objects", "Blue"};
    insert_row(filename, &new_record);

    // Update a row
    struct record updated_record = {2, "Aguamenti", "Water-Making Spell", "Creates water", "Light Blue"};
    update_row(filename, 2, &updated_record);

    // Delete a row
    delete_row(filename, 3);

    // Search for a row
    search_by_id(filename, 1);

    return 0;
}