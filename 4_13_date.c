#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Date readDate() {
    struct Date d;
    printf("Enter day: ");
    scanf("%d", &(d.day));
    printf("Enter month: ");
    scanf("%d", &(d.month));
    printf("Enter year: ");
    scanf("%d", &(d.year));
    return d;
}

void displayDate(struct Date d) {
    printf("%d/%d/%d\n", d.day, d.month, d.year);
}

int datesAreEqual(struct Date d1, struct Date d2) {
    return (d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year);
}

int main() {
    struct Date date1, date2;
    
    printf("Enter date 1:\n");
    date1 = readDate();
    printf("Enter date 2:\n");
    date2 = readDate();
    
    printf("Date 1: ");
    displayDate(date1);
    printf("Date 2: ");
    displayDate(date2);
    
    if (datesAreEqual(date1, date2)) {
        printf("The dates are equal.\n");
    } else {
        printf("The dates are not equal.\n");
    }
    
    return 0;
}
