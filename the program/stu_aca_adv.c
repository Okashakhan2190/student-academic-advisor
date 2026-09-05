#include <stdio.h>
#include <string.h>

int main() {
    int age, num1, num2, num3;
    float assignment, total_assignment;
   float avg, attendance, total_marks;
    char name[50], roll[20];
    char status[20];
    char grade;
     printf("============================================\n");
    printf("\tSTUDENT ACADEMIC ADVISOR\n");
    printf("============================================\n");
    printf("Enter your name           : ");
   scanf("%s", name);
   printf("Enter your roll number    : ");
    scanf("%s", roll);
    printf("Enter your age            : ");
    scanf("%d", &age);
    printf("Enter Marks in PF         : ");
    scanf("%d", &num1);
    printf("Enter Marks in MATHS      : ");
    scanf("%d", &num2);
    printf("Enter marks in ENGLISH    : ");
    scanf("%d", &num3);
    printf("Enter your attendance(%%)  : ");
    scanf("%f", &attendance); 
    printf("Enter assignments done    : ");
    scanf("%f", &assignment);
    printf("Enter total assignments   : ");
    scanf("%f", &total_assignment);
    
    total_marks= num1+num2+num3;
    avg = (total_marks/300)*100;
    float assignment_percentage= (assignment/total_assignment)*100;
    float mk = avg;
    if(mk>=50){
         strcpy(status, "Pass");
    }
    else{
         strcpy(status, "Fail");
    }
    if(avg>84){
        grade = 'A';
    }
    else if(avg>70){
        grade = 'B';
    }
    else if(avg>60){
        grade = 'C';
    }
    else{
        grade ='F'; 
    }
    char scholarship[20];
    if(avg>=80 && attendance>=80){
        strcpy(scholarship, "Eligible");
    }
    else{
        strcpy(scholarship, "Not Eligable");
    }
    char advice[100];
    if(avg>=85 && attendance>=85){
        strcpy(advice,"Excellent performance, KEEP IT UP.");
    }
    else if(avg>=75 && attendance>=75){
        strcpy(advice,"Great job, Try for an A next time.");
    }
    else{
        strcpy(advice,"Work harder and try doing better next time.");
    }
    char warning[50];
    if(attendance>=75){
     strcpy(warning,"Good");
    }
    else{
        strcpy(warning,"Not good");
    }

    printf("--------------------------------------------\n");
    printf("\t   ACADEMIC REPORT\n");
    printf("--------------------------------------------\n");



    printf("NAME             : %s\n", name);
    printf("ROLL NO.         : %s\n", roll);
    printf("AGE              : %d\n", age);
    printf("TOTAL MARKS      : %.0f/300\n", total_marks);
    printf("PERCENTAGE       : %.0f%%\n", avg);
    printf("GRADE            : %c\n", grade);
    printf("ATTENDANCE       : %.2f%%\n", attendance);
    printf("ASSIGNMENTS      : %.2f%%\n", assignment_percentage);
    printf("STATUS           : %s\n", status);
    printf("ATTENDENCE       : %s\n", warning);
    printf("SCHOLARSHIP      : %s\n", scholarship);
    printf("ADVICE: \n%s\n", advice);

  printf("============================================\n");
    printf("\t    END OF RESULT\n");
    printf("============================================\n");
    getchar();
    return 0;
}