/* course_system.c
   Simple Course Registration System in C
   - Role selection: Student | Faculty | Administrative
   - Student menu:
       1. Check Available Courses
       2. Opt For A Course
       3. View Students opted for course (aggregated)
       4. Opt out from a course
       5. Exit (to role menu)
   - Faculty:
       - select course, select student by roll -> update/add attendance per sem and add/update grades per sem
   - Administrative:
       - Add new course
   Data stored in text files:
     courses.txt, registrations.csv, attendance.csv, grades.csv
   Keep this simple for first-year project.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 512
#define MAX_FIELD 128

/* Utility functions */
void trim_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0'; len--;
    }
}

int file_exists(const char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) return 0;
    fclose(f);
    return 1;
}

void ensure_base_files() {
    if (!file_exists("courses.txt")) {
        FILE *f = fopen("courses.txt", "w");
        if (f) {
            fprintf(f, "Btech\nBFM\nBBA\nB.com\nBsc\n");
            fclose(f);
        }
    }
    if (!file_exists("registrations.csv")) {
        FILE *f = fopen("registrations.csv", "w");
        if (f) fclose(f);
    }
    if (!file_exists("attendance.csv")) {
        FILE *f = fopen("attendance.csv", "w");
        if (f) fclose(f);
    }
    if (!file_exists("grades.csv")) {
        FILE *f = fopen("grades.csv", "w");
        if (f) fclose(f);
    }
}

/* Read and print courses with enrollment counts */
void list_courses() {
    FILE *fc = fopen("courses.txt", "r");
    if (!fc) {
        printf("No courses found.\n");
        return;
    }
    char line[MAX_LINE];
    int index = 1;
    printf("\nAvailable courses and enrollment counts:\n");
    while (fgets(line, sizeof line, fc)) {
        trim_newline(line);
        if (strlen(line) == 0) continue;
        /* count enrollment */
        FILE *fr = fopen("registrations.csv", "r");
        int count = 0;
        char rline[MAX_LINE];
        while (fr && fgets(rline, sizeof rline, fr)) {
            char *c = strtok(rline, ",");
            if (c && strcmp(c, line) == 0) count++;
        }
        if (fr) fclose(fr);
        printf("%d. %s  (Enrolled: %d)\n", index++, line, count);
    }
    fclose(fc);
}

/* Append registration */
void opt_for_course() {
    list_courses();
    char course[MAX_FIELD], name[MAX_FIELD], roll[MAX_FIELD], email[MAX_FIELD], year[MAX_FIELD];
    char choiceStr[16];
    int choice = 0, index = 0;

    /* Let student choose course by NUMBER (easier than typing exact name) */
    printf("\nEnter course number to opt for: ");
    if (!fgets(choiceStr, sizeof choiceStr, stdin)) return;
    choice = atoi(choiceStr);
    if (choice <= 0) {
        printf("Invalid course number.\n");
        return;
    }

    /* Read courses.txt again and pick the chosen course line */
    FILE *fc = fopen("courses.txt", "r");
    if (!fc) {
        printf("Could not open courses file.\n");
        return;
    }
    char tmp[MAX_LINE];
    while (fgets(tmp, sizeof tmp, fc)) {
        trim_newline(tmp);
        if (strlen(tmp) == 0) continue;
        index++;
        if (index == choice) {
            strncpy(course, tmp, sizeof(course));
            course[sizeof(course) - 1] = '\0';
            break;
        }
    }
    fclose(fc);
    if (index != choice) {
        printf("No course at that number.\n");
        return;
    }

    printf("Student full name: ");
    if (!fgets(name, sizeof name, stdin)) return; trim_newline(name);
    if (strlen(name) == 0) { printf("Name cannot be empty.\n"); return; }

    printf("Student roll number / ID: ");
    if (!fgets(roll, sizeof roll, stdin)) return; trim_newline(roll);
    if (strlen(roll) == 0) { printf("Roll cannot be empty.\n"); return; }

    printf("Student email (optional): ");
    if (!fgets(email, sizeof email, stdin)) return; trim_newline(email);

    printf("Year/Semester (optional): ");
    if (!fgets(year, sizeof year, stdin)) return; trim_newline(year);

    /* check duplicate in registrations for this course by roll */
    FILE *fr = fopen("registrations.csv", "r");
    char rline[MAX_LINE];
    while (fr && fgets(rline, sizeof rline, fr)) {
        char rcourse[MAX_FIELD], rroll[MAX_FIELD];
        char *p = strtok(rline, ","); if (!p) continue; strncpy(rcourse, p, MAX_FIELD);
        p = strtok(NULL, ","); if (!p) continue; strncpy(rroll, p, MAX_FIELD);
        trim_newline(rcourse); trim_newline(rroll);
        if (strcmp(rcourse, course) == 0 && strcmp(rroll, roll) == 0) {
            printf("Student with this roll already enrolled in this course.\n");
            if (fr) fclose(fr);
            return;
        }
    }
    if (fr) fclose(fr);

    FILE *fw = fopen("registrations.csv", "a");
    if (!fw) { printf("Could not open registrations file to write.\n"); return; }
    /* CSV: course,roll,name,email,year */
    fprintf(fw, "%s,%s,%s,%s,%s\n", course, roll, name, email, year);
    fclose(fw);
    printf("Student '%s' added to %s\n", name, course);
}

/* Aggregate and view students by course */
void view_students_aggregate() {
    FILE *fr = fopen("registrations.csv", "r");
    if (!fr) { printf("No registrations.\n"); return; }
    char line[MAX_LINE];
    /* We'll load courses into an array then print students by course */
    FILE *fc = fopen("courses.txt", "r");
    if (!fc) { printf("No courses.\n"); fclose(fr); return; }
    char course[MAX_FIELD];
    while (fc && fgets(course, sizeof course, fc)) {
        trim_newline(course);
        if (strlen(course) == 0) continue;
        printf("\n--- %s ---\n", course);
        rewind(fr);
        int count = 0;
        while (fgets(line, sizeof line, fr)) {
            char lcourse[MAX_FIELD], lroll[MAX_FIELD], lname[MAX_FIELD], lemail[MAX_FIELD], lyear[MAX_FIELD];
            char *p = strtok(line, ","); if (!p) continue; strncpy(lcourse, p, MAX_FIELD);
            p = strtok(NULL, ","); if (!p) continue; strncpy(lroll, p, MAX_FIELD);
            p = strtok(NULL, ","); if (!p) continue; strncpy(lname, p, MAX_FIELD);
            p = strtok(NULL, ","); if (!p) continue; strncpy(lemail, p, MAX_FIELD);
            p = strtok(NULL, ","); if (!p) continue; strncpy(lyear, p, MAX_FIELD);
            trim_newline(lcourse); trim_newline(lroll); trim_newline(lname); trim_newline(lemail); trim_newline(lyear);
            if (strcmp(lcourse, course) == 0) {
                count++;
                printf("Roll: %s | Name: %s | Email: %s | Year: %s\n", lroll, lname, lemail, lyear);
            }
        }
        if (count == 0) printf("No students enrolled.\n");
    }
    fclose(fr); fclose(fc);
}

/* Opt out from a course (remove registration) */
void opt_out_course() {
    list_courses();
    char course[MAX_FIELD], roll[MAX_FIELD];
    char choiceStr[16];
    int choice = 0, index = 0;

    /* Use course NUMBER (same style as opt_for_course) */
    printf("\nEnter course number to opt out from: ");
    if (!fgets(choiceStr, sizeof choiceStr, stdin)) return;
    choice = atoi(choiceStr);
    if (choice <= 0) {
        printf("Invalid course number.\n");
        return;
    }

    /* Find that course in courses.txt */
    FILE *fc = fopen("courses.txt", "r");
    if (!fc) {
        printf("Could not open courses file.\n");
        return;
    }
    char tmp[MAX_LINE];
    while (fgets(tmp, sizeof tmp, fc)) {
        trim_newline(tmp);
        if (strlen(tmp) == 0) continue;
        index++;
        if (index == choice) {
            strncpy(course, tmp, sizeof(course));
            course[sizeof(course) - 1] = '\0';
            break;
        }
    }
    fclose(fc);
    if (index != choice) {
        printf("No course at that number.\n");
        return;
    }

    printf("Enter roll number / ID of student to remove: ");
    if (!fgets(roll, sizeof roll, stdin)) return; trim_newline(roll);
    if (strlen(roll) == 0) { printf("No roll provided.\n"); return; }

    FILE *fr = fopen("registrations.csv", "r");
    if (!fr) { printf("No registrations file.\n"); return; }
    FILE *fw = fopen("registrations.tmp", "w");
    if (!fw) { printf("Could not create temp file.\n"); fclose(fr); return; }

    char line[MAX_LINE];
    int found = 0;
    while (fgets(line, sizeof line, fr)) {
        char lcopy[MAX_LINE]; strcpy(lcopy, line);
        char *p = strtok(lcopy, ","); if (!p) continue;
        char lcourse[MAX_FIELD]; strncpy(lcourse, p, MAX_FIELD);
        p = strtok(NULL, ",");
        char lroll[MAX_FIELD]; if (p) strncpy(lroll, p, MAX_FIELD); else lroll[0] = '\0';
        trim_newline(lcourse); trim_newline(lroll);
        if (strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0) {
            found = 1; /* skip this line (delete) */
        } else {
            fputs(line, fw); /* keep */
        }
    }
    fclose(fr); fclose(fw);
    if (found) {
        remove("registrations.csv");
        rename("registrations.tmp", "registrations.csv");
        printf("Student with roll %s removed from %s\n", roll, course);

        /* Also optionally remove attendance & grades for that student-course */
        /* attendance.csv */
        FILE *fa = fopen("attendance.csv", "r");
        FILE *fatmp = fopen("attendance.tmp", "w");
        if (fa && fatmp) {
            while (fgets(line, sizeof line, fa)) {
                char lcopy[MAX_LINE]; strcpy(lcopy, line);
                char *p = strtok(lcopy, ",");
                char lcourse[MAX_FIELD]; if (p) strncpy(lcourse, p, MAX_FIELD); else lcourse[0] = '\0';
                p = strtok(NULL, ",");
                char lroll[MAX_FIELD]; if (p) strncpy(lroll, p, MAX_FIELD); else lroll[0] = '\0';
                trim_newline(lcourse); trim_newline(lroll);
                if (!(strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0)) {
                    fputs(line, fatmp);
                }
            }
            fclose(fa); fclose(fatmp);
            remove("attendance.csv"); rename("attendance.tmp", "attendance.csv");
        } else {
            if (fa) fclose(fa);
            if (fatmp) fclose(fatmp);
        }
        /* grades.csv */
        FILE *fg = fopen("grades.csv", "r");
        FILE *fgtmp = fopen("grades.tmp", "w");
        if (fg && fgtmp) {
            while (fgets(line, sizeof line, fg)) {
                char lcopy[MAX_LINE]; strcpy(lcopy, line);
                char *p = strtok(lcopy, ",");
                char lcourse[MAX_FIELD]; if (p) strncpy(lcourse, p, MAX_FIELD); else lcourse[0] = '\0';
                p = strtok(NULL, ",");
                char lroll[MAX_FIELD]; if (p) strncpy(lroll, p, MAX_FIELD); else lroll[0] = '\0';
                trim_newline(lcourse); trim_newline(lroll);
                if (!(strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0)) {
                    fputs(line, fgtmp);
                }
            }
            fclose(fg); fclose(fgtmp);
            remove("grades.csv"); rename("grades.tmp", "grades.csv");
        } else {
            if (fg) fclose(fg);
            if (fgtmp) fclose(fgtmp);
        }

    } else {
        remove("registrations.tmp");
        printf("Student not found in that course.\n");
    }
}

/* Simple function to prompt and get a line */
void get_input(const char *prompt, char *out, int sz) {
    printf("%s", prompt);
    if (!fgets(out, sz, stdin)) { out[0] = '\0'; return; }
    trim_newline(out);
}

/* Faculty: select course, select student, then update attendance/grades */
void faculty_menu() {
    printf("\n-- Faculty Menu --\n");
    list_courses();
    char course[MAX_FIELD];
    char choiceStr[16];
    int choice = 0, index = 0;

    /* Select course by NUMBER (same style as student options) */
    printf("\nEnter course number to manage: ");
    if (!fgets(choiceStr, sizeof choiceStr, stdin)) return;
    choice = atoi(choiceStr);
    if (choice <= 0) {
        printf("Invalid course number.\n");
        return;
    }

    /* Resolve course name from courses.txt */
    FILE *fc = fopen("courses.txt", "r");
    if (!fc) {
        printf("Could not open courses file.\n");
        return;
    }
    char tmp[MAX_LINE];
    while (fgets(tmp, sizeof tmp, fc)) {
        trim_newline(tmp);
        if (strlen(tmp) == 0) continue;
        index++;
        if (index == choice) {
            strncpy(course, tmp, sizeof(course));
            course[sizeof(course) - 1] = '\0';
            break;
        }
    }
    fclose(fc);
    if (index != choice) {
        printf("No course at that number.\n");
        return;
    }

    /* Show students in course */
    FILE *fr = fopen("registrations.csv", "r");
    if (!fr) { printf("No registrations.\n"); return; }
    char line[MAX_LINE];
    int foundAny = 0;
    printf("\nStudents in %s:\n", course);
    while (fgets(line, sizeof line, fr)) {
        char lcourse[MAX_FIELD], lroll[MAX_FIELD], lname[MAX_FIELD];
        char *p = strtok(line, ","); if (!p) continue; strncpy(lcourse, p, MAX_FIELD);
        p = strtok(NULL, ","); if (!p) continue; strncpy(lroll, p, MAX_FIELD);
        p = strtok(NULL, ","); if (!p) continue; strncpy(lname, p, MAX_FIELD);
        trim_newline(lcourse); trim_newline(lroll); trim_newline(lname);
        if (strcmp(lcourse, course) == 0) {
            foundAny = 1;
            printf("Roll: %s | Name: %s\n", lroll, lname);
        }
    }
    fclose(fr);
    if (!foundAny) { printf("No students enrolled.\n"); return; }

    char roll[MAX_FIELD];
    get_input("\nEnter roll number of student to manage: ", roll, sizeof roll);
    if (strlen(roll) == 0) { printf("No roll selected.\n"); return; }

    while (1) {
        printf("\nFaculty actions for %s - student %s:\n", course, roll);
        printf("1. Update/Add attendance for a semester\n");
        printf("2. Update/Add grade for a semester\n");
        printf("3. View attendance & grades for this student\n");
        printf("4. Back to role menu\n");
        char choice[8];
        get_input("Choice: ", choice, sizeof choice);
        if (strcmp(choice, "1") == 0) {
            char sem[MAX_FIELD], perc[MAX_FIELD];
            get_input("Enter semester (e.g., sem1): ", sem, sizeof sem);
            get_input("Enter attendance percent (e.g., 85): ", perc, sizeof perc);
            /* read attendance.csv, replace if exists or append */
            FILE *fa = fopen("attendance.csv", "r");
            FILE *fatmp = fopen("attendance.tmp", "w");
            int replaced = 0;
            if (!fatmp) { if (fa) fclose(fa); printf("File error.\n"); continue; }
            if (fa) {
                while (fgets(line, sizeof line, fa)) {
                    char cp[MAX_LINE]; strcpy(cp, line);
                    char *p = strtok(cp, ",");
                    char lcourse[MAX_FIELD]; if (p) strncpy(lcourse, p, MAX_FIELD); else lcourse[0]='\0';
                    p = strtok(NULL, ","); char lroll[MAX_FIELD]; if (p) strncpy(lroll, p, MAX_FIELD); else lroll[0]='\0';
                    p = strtok(NULL, ","); char lsem[MAX_FIELD]; if (p) strncpy(lsem, p, MAX_FIELD); else lsem[0]='\0';
                    trim_newline(lcourse); trim_newline(lroll); trim_newline(lsem);
                    if (strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0 && strcmp(lsem, sem) == 0) {
                        /* replace */
                        fprintf(fatmp, "%s,%s,%s,%s\n", course, roll, sem, perc);
                        replaced = 1;
                    } else {
                        fputs(line, fatmp);
                    }
                }
                fclose(fa);
            }
            if (!replaced) {
                fprintf(fatmp, "%s,%s,%s,%s\n", course, roll, sem, perc);
            }
            fclose(fatmp);
            remove("attendance.csv");
            rename("attendance.tmp", "attendance.csv");
            printf("Attendance updated for %s, %s, %s = %s\n", course, roll, sem, perc);
        } else if (strcmp(choice, "2") == 0) {
            char sem[MAX_FIELD], grade[MAX_FIELD];
            get_input("Enter semester (e.g., sem1): ", sem, sizeof sem);
            get_input("Enter grade (e.g., A / 85): ", grade, sizeof grade);
            FILE *fg = fopen("grades.csv", "r");
            FILE *fgtmp = fopen("grades.tmp", "w");
            int replaced = 0;
            if (!fgtmp) { if (fg) fclose(fg); printf("File error.\n"); continue; }
            if (fg) {
                while (fgets(line, sizeof line, fg)) {
                    char cp[MAX_LINE]; strcpy(cp, line);
                    char *p = strtok(cp, ",");
                    char lcourse[MAX_FIELD]; if (p) strncpy(lcourse, p, MAX_FIELD); else lcourse[0]='\0';
                    p = strtok(NULL, ","); char lroll[MAX_FIELD]; if (p) strncpy(lroll, p, MAX_FIELD); else lroll[0]='\0';
                    p = strtok(NULL, ","); char lsem[MAX_FIELD]; if (p) strncpy(lsem, p, MAX_FIELD); else lsem[0]='\0';
                    trim_newline(lcourse); trim_newline(lroll); trim_newline(lsem);
                    if (strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0 && strcmp(lsem, sem) == 0) {
                        fprintf(fgtmp, "%s,%s,%s,%s\n", course, roll, sem, grade);
                        replaced = 1;
                    } else {
                        fputs(line, fgtmp);
                    }
                }
                fclose(fg);
            }
            if (!replaced) {
                fprintf(fgtmp, "%s,%s,%s,%s\n", course, roll, sem, grade);
            }
            fclose(fgtmp);
            remove("grades.csv");
            rename("grades.tmp", "grades.csv");
            printf("Grade updated for %s, %s, %s = %s\n", course, roll, sem, grade);
        } else if (strcmp(choice, "3") == 0) {
            /* Ask for CURRENT semester to view */
            char semFilter[MAX_FIELD];
            get_input("Enter current semester to view (e.g., sem1): ", semFilter, sizeof semFilter);
            if (strlen(semFilter) == 0) {
                printf("No semester provided.\n");
                continue;
            }

            /* print attendance only for that semester */
            printf("\nAttendance records (Semester: %s):\n", semFilter);
            FILE *fa = fopen("attendance.csv", "r");
            int any = 0;
            if (fa) {
                while (fgets(line, sizeof line, fa)) {
                    char lcourse[MAX_FIELD], lroll[MAX_FIELD], lsem[MAX_FIELD], lperc[MAX_FIELD];
                    char cp[MAX_LINE]; strcpy(cp, line);
                    char *p = strtok(cp, ","); if (!p) continue; strncpy(lcourse, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lroll, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lsem, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lperc, p, MAX_FIELD);
                    trim_newline(lcourse); trim_newline(lroll); trim_newline(lsem); trim_newline(lperc);
                    if (strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0
                        && strcmp(lsem, semFilter) == 0) {
                        any = 1;
                        printf("Semester: %s | Attendance: %s\n", lsem, lperc);
                    }
                }
                fclose(fa);
            }
            if (!any) printf("No attendance records.\n");

            /* print grades only for that semester */
            printf("\nGrades records (Semester: %s):\n", semFilter);
            FILE *fg = fopen("grades.csv", "r");
            any = 0;
            if (fg) {
                while (fgets(line, sizeof line, fg)) {
                    char lcourse[MAX_FIELD], lroll[MAX_FIELD], lsem[MAX_FIELD], lgrade[MAX_FIELD];
                    char cp[MAX_LINE]; strcpy(cp, line);
                    char *p = strtok(cp, ","); if (!p) continue; strncpy(lcourse, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lroll, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lsem, p, MAX_FIELD);
                    p = strtok(NULL, ","); if (!p) continue; strncpy(lgrade, p, MAX_FIELD);
                    trim_newline(lcourse); trim_newline(lroll); trim_newline(lsem); trim_newline(lgrade);
                    if (strcmp(lcourse, course) == 0 && strcmp(lroll, roll) == 0
                        && strcmp(lsem, semFilter) == 0) {
                        any = 1;
                        printf("Semester: %s | Grade: %s\n", lsem, lgrade);
                    }
                }
                fclose(fg);
            }
            if (!any) printf("No grades records.\n");
        } else if (strcmp(choice, "4") == 0) {
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
}

/* Administrative: add new course */
void admin_menu() {
    printf("\n-- Administrative Menu --\n");
    char course[MAX_FIELD];
    get_input("Enter new course name to add (exact string, e.g. Mtech): ", course, sizeof course);
    if (strlen(course) == 0) { printf("No course provided.\n"); return; }
    /* Check if exists */
    FILE *fc = fopen("courses.txt", "r");
    char line[MAX_LINE];
    while (fc && fgets(line, sizeof line, fc)) {
        trim_newline(line);
        if (strcmp(line, course) == 0) {
            printf("Course already exists.\n");
            fclose(fc); return;
        }
    }
    if (fc) fclose(fc);
    FILE *fw = fopen("courses.txt", "a");
    if (!fw) { printf("Could not open courses file.\n"); return; }
    fprintf(fw, "%s\n", course);
    fclose(fw);
    printf("Course '%s' added.\n", course);
}

/* Top-level Student menu */
void student_menu() {
    while (1) {
        printf("\n-- Student Menu --\n");
        printf("1. Check Available Courses\n");
        printf("2. Opt For A Course\n");
        printf("3. View Students opted for course (aggregate)\n");
        printf("4. Opt out from a course\n");
        printf("5. Back to role selection\n");
        char choice[8];
        get_input("Choice: ", choice, sizeof choice);
        if (strcmp(choice, "1") == 0) {
            list_courses();
        } else if (strcmp(choice, "2") == 0) {
            opt_for_course();
        } else if (strcmp(choice, "3") == 0) {
            view_students_aggregate();
        } else if (strcmp(choice, "4") == 0) {
            opt_out_course();
        } else if (strcmp(choice, "5") == 0) {
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
}

/* Main */
int main() {
    ensure_base_files();
    printf("=== Simple Course Registration System (C) ===\n");
    while (1) {
        printf("\nSelect role:\n");
        printf("1. Student\n");
        printf("2. Faculty\n");
        printf("3. Administrative\n");
        printf("4. Exit\n");
        char role[8];
        get_input("Enter role number: ", role, sizeof role);
        if (strcmp(role, "1") == 0) {
            student_menu();
        } else if (strcmp(role, "2") == 0) {
            faculty_menu();
        } else if (strcmp(role, "3") == 0) {
            admin_menu();
        } else if (strcmp(role, "4") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        } else {
            printf("Invalid role.\n");
        }
    }
    return 0;
}