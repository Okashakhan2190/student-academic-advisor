#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_blank(const char *s) {
    while (*s) {
        if (!isspace((unsigned char)*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

void flush_stdin(void){
    int c;
    while( (c = getchar()) != '\n' && c != EOF);
}

void read_required_line(const char *prompt, char *buf, int size) {
    do {
        printf("%s", prompt);
        if (fgets(buf, size, stdin)) {
            size_t len = strlen(buf);
            if (len > 0 && buf[len - 1] == '\n') {
                buf[len - 1] = '\0';
            } else {
                flush_stdin();
            }
        } else {
            buf[0] = '\0';
        }
        if (buf[0] == '\0' || is_blank(buf)) {
            printf("This field cannot be blank.\n");
        }

    } while (is_blank(buf));
}

int read_input_int(const char *prompt, int min, int max) {
    char line[100];
    int value;
    char extra;

    while (1) {
        printf("%s", prompt);

        if (!fgets(line, sizeof(line), stdin)) {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        } else {
            flush_stdin();
        }

        if (sscanf(line, "%d %c", &value, &extra) != 1) {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        if (value < min || value > max) {
            printf("Please enter a value between %d and %d.\n", min, max);
            continue;
        }

        break;
    }
    return value;
}

float read_input_float(const char *prompt, float min, float max){
    float value;
    char line[100];
    char extra;

    while(1){
        printf("%s", prompt);

        if(!fgets(line, sizeof(line), stdin)){
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n'){
            line[len - 1] = '\0';
        } else {
            flush_stdin();
        }

        if(sscanf(line, "%f %c", &value, &extra) != 1){
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if(isnan(value) || isinf(value)){
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if(value < min || value > max){
            printf("Please enter a value between %.2f and %.2f.\n", min, max);
            continue;
        }
        break;
    }

    return value;
}

int main() {
    //constant-variable declaration.
    const float min_attendence = 80.0;
    const float pass_marks = 50.0;
    const float scholarship_marks = 85.0;
    int age, num1, num2, num3;
    float assignment, total_assignment;
    float avg, attendance, total_marks;
    char name[50], roll[20];
    char status[50];
    char grade;

    //input block.
    printf("============================================\n");
    printf("\tSTUDENT ACADEMIC ADVISOR\n");
    printf("============================================\n");

    // inputs.
    read_required_line("Enter your name           : ", name, sizeof(name));
    read_required_line("Enter your Roll no.       : ", roll, sizeof(roll));
    age = read_input_int("Enter your age            : ", 16, 80);
    num1 = read_input_int("Enter Marks in PF         : ", 0, 100);
    num2 = read_input_int("Enter Marks in MATHS      : ", 0, 100);
    num3 = read_input_int("Enter marks in ENGLISH    : ", 0, 100);
    attendance = read_input_float("Enter your attendance(%)  : ", 0, 100);
    total_assignment = read_input_float("Enter total assignments   : ", 1, 100);
    assignment = read_input_float("Enter assignments done    : ", 0, total_assignment);

    // calculations.
    total_marks = num1 + num2 + num3;
    avg = (total_marks / 300) * 100;
    float assignment_percentage = (assignment / total_assignment) * 100;

    if (num1 < pass_marks || num2 < pass_marks || num3 < pass_marks){
        if(num1 < pass_marks && num2 < pass_marks && num3 < pass_marks){
            strcpy(status, "Failed in ALL SUBJECTS");
        }
        else if(num1 < pass_marks && num2 < pass_marks){
            strcpy(status, "Failed in PF and MATHS");
        }
        else if(num1 < pass_marks && num3 < pass_marks){
            strcpy(status, "Failed in PF and ENGLISH");
        }
        else if(num2 < pass_marks && num3 < pass_marks){
            strcpy(status, "Failed in MATHS and ENGLISH");
        }
        else if(num1 < pass_marks){
            strcpy(status, "Failed in PF");
        }
        else if(num2 < pass_marks){
            strcpy(status, "Failed in MATHS");
        }
        else if(num3 < pass_marks){
            strcpy(status, "Failed in ENGLISH");
        }
    }
    else {
        strcpy(status, "Pass");
    }

    if(avg >= 85){
        grade = 'A';
    }
    else if(avg >= 70){
        grade = 'B';
    }
    else if(avg >= 60){
        grade = 'C';
    }
    else if(avg >= 50){
        grade = 'D';
    }
    else{
        grade = 'F';
    }

    char scholarship[20];
    if(avg >= scholarship_marks && attendance >= min_attendence){
        strcpy(scholarship, "Eligible");
    }
    else{
        strcpy(scholarship, "Not Eligable");
    }

    char advice[100];
    if(avg >= 85 && attendance >= min_attendence){
        strcpy(advice, "Excellent performance, KEEP IT UP.");
    }
    else if(avg >= 75 && attendance >= min_attendence){
        strcpy(advice, "Great job, Try for an A next time.");
    }
    else if(attendance < min_attendence){
        strcpy(advice, "Improve your attendence.");
    }
    else{
        strcpy(advice, "Work harder and try doing better next time.");
    }

    char warning[50];
    if(attendance >= min_attendence){
        strcpy(warning, "Good");
    }
    else{
        strcpy(warning, "Not good");
    }

    // output block.
    printf("--------------------------------------------\n");
    printf("\t   ACADEMIC REPORT\n");
    printf("--------------------------------------------\n");

    // outputs.
    printf("NAME             : %s\n", name);
    printf("ROLL NO.         : %s\n", roll);
    printf("AGE              : %d\n", age);
    printf("TOTAL MARKS      : %.0f/300\n", total_marks);
    printf("PERCENTAGE       : %.2f%%\n", avg);
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

    flush_stdin();
    return 0;
}