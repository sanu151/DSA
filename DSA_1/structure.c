#include<stdio.h>

struct Student
{
    char name[20];
    int usn;
    char dept[10];
};

int main()
{
    struct Student s;
    printf("\nRead Name, USN, Dept : ");
    scanf("%s %d %s", s.name, &s.usn, s.dept);

    printf("\nName: %s", s.name);
    printf("\nUSN : %d", s.usn);
    printf("\nDept: %s", s.dept);

    return 0;
}
