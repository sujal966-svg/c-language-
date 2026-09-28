#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char date[20];
    char category[30];
    char description[100];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];
int count = 0;

void addExpense() {
    if (count >= MAX_EXPENSES) {
        printf("\nExpense limit reached!\n");
        return;
    }

    printf("\nEnter date (DD-MM-YYYY): ");
    scanf("%19s", expenses[count].date);

    printf("Enter category (Food/Travel/Shopping/etc.): ");
    scanf("%29s", expenses[count].category);

    printf("Enter description: ");
    scanf(" %[^\n]", expenses[count].description);

    printf("Enter amount: Rs. ");
    scanf("%f", &expenses[count].amount);

    count++;

    printf("\nExpense added successfully!\n");
}

void viewExpenses() {
    int i;

    if (count == 0) {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nExpense #%d\n", i + 1);
        printf("Date        : %s\n", expenses[i].date);
        printf("Category    : %s\n", expenses[i].category);
        printf("Description : %s\n", expenses[i].description);
        printf("Amount      : Rs. %.2f\n", expenses[i].amount);
    }
}

void totalExpense() {
    float total = 0;
    int i;

    for (i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Expenses: Rs. %.2f\n", total);
}

void categoryExpense() {
    char category[30];
    float total = 0;
    int i, found = 0;

    printf("\nEnter category to search: ");
    scanf("%29s", category);

    for (i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
            found = 1;
        }
    }

    if (found) {
        printf("Total spent on %s: Rs. %.2f\n", category, total);
    } else {
        printf("No expenses found in this category.\n");
    }
}

void deleteExpense() {
    int number, i;

    if (count == 0) {
        printf("\nNo expenses to delete.\n");
        return;
    }

    viewExpenses();

    printf("\nEnter expense number to delete: ");
    scanf("%d", &number);

    if (number < 1 || number > count) {
        printf("Invalid expense number!\n");
        return;
    }

    for (i = number - 1; i < count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    count--;

    printf("\nExpense deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n========== EXPENSE TRACKER ==========\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Search by Category\n");
        printf("5. Delete Expense\n");
        printf("6. Exit\n");
        printf("=====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpense();
                break;

            case 4:
                categoryExpense();
                break;

            case 5:
                deleteExpense();
                break;

            case 6:
                printf("\nThank you for using Expense Tracker!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
