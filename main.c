#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    char albumName[32];
    char artistName[32];
} RECORD;

RECORD *fetchRecords(RECORD *records, int n, int year, int *count, int *recordPositions) {
    int i, recordCount = 0;
    RECORD *filteredRecords;
    for (i = 0; i < n; i++) {
        if (records[i].year == year) {
            recordPositions[recordCount] = i;
            recordCount++;
            recordPositions = (int*)realloc(recordPositions, sizeof(int) * recordCount);
        }
    }
    filteredRecords = (RECORD*)malloc(sizeof(RECORD) * recordCount);
    printf("There are %d records\n", recordCount);
    recordCount = 0;
    for (i = 0; i < n; i++) {
        if (records[i].year == year) {
            filteredRecords[recordCount] = records[i];
            recordCount++;
        }
    }
    *count = recordCount;
    return filteredRecords;
}

int main() {
    RECORD *records, *filteredRecords;
    int *recordPositions = (int*)malloc(sizeof(int));
    int n, i, year, count = 0;
    printf("Number of Records: ");
    scanf("%d", &n);
    records = (RECORD*)malloc(sizeof(RECORD) * n);
    for (i = 0; i < n; i++) {
        printf("%d Record Year: ", i + 1);
        scanf("%d", &records[i].year);
        printf("%d Album Name: ", i + 1);
        scanf("%s", records[i].albumName);
        printf("%d Artist Name: ", i + 1);
        scanf("%s", records[i].artistName);
        printf("\n");
    }
    printf("Enter the year to fetch records: ");
    scanf("%d", &year);
    filteredRecords = fetchRecords(records, n, year, &count, recordPositions);
    for (i = 0; i < count; i++) {
        printf("%d - ", recordPositions[i] + 1);
        printf("%d - ", filteredRecords[i].year);
        printf("%s - ", filteredRecords[i].albumName);
        printf("%s", filteredRecords[i].artistName);
        printf("\n");
    }
    free(records);
    free(filteredRecords);
    free(recordPositions);
    return 0;
}
