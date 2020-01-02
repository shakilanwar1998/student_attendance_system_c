#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int i;

COORD coord = {
  0,
  0
};
void gotoxy(int x, int y) {
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct subject {
  char sub_name[200];
  float cgpa;
};

struct student {
  char name[50];
  char id[50];
  char section[10];
  char batch[10];
  char address[100];
  char department[100];
  char semester[50];
  float Av_cgpa;
  int n_sub, i;
  struct subject sub[5];
}
std, std1, std3, std4, std_g;

struct subject2 {
  char sub_name[200];
  float cgpa;
};

struct student2 {
  char name[50];
  char id[50];
  char section[10];
  char batch[10];
  char address[100];
  char department[100];
  char semester[30];
  float Av_cgpa;
  int n_sub, i;
  struct subject2 sub2[5];
}
std2, std5;

int home();
int welcome();
int teacher_home();
int attendance_data();
int search_attendance();
int search_attendance1(int tdt);
int C_smstr_R();
int admin_home();
int save_student_details();
int view_student_details();
int search_student();
int search1(int tdt);
int search_student_semester();
int search_student_semester1(int tdt);
int ext();
int end_switch_s_s_s();
int delete_student();
int edit_student();
int edit1(int td);
int edit2(char id[50], char edit_smstr[20]);
int search_student_attendance();
int please_wait();
int teacher_log_in();
int admin_log_in();
int edit_att1(int td);
int view_student_att();
int edit_att2(char id[50], char edit_date[20]);
int edit_attendance();
int edit_3(char id[40], char date[40]);
int att_edit1();
int edit_2(int td);

void SetColor(int ForgC) {
  WORD wColor;
  //We will need this handle to get the current background attribute
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  //We use csbi for the wAttributes word.
  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    //Mask out all but the background attribute, and add in the forgournd color
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
  return;
}

int main() {
  home();
  return 0;
}

int home() {
  char hswitch;
  system("cls");
  welcome();
  SetColor(45);
  printf("\n\n");
  printf("\t\t\t\t\t ==> 1. Log In as Teacher\n");
  printf("\t\t\t\t\t ==> 2. Log In as Admin\n");
  printf("\t\t\t\t\t ==> 3. CGPA Calculator\n");
  printf("\t\t\t\t\t ==> 4. EXIT Software\n\n");
  SetColor(11);
  printf("\t\t\t\t\t Select an Option:");
  SetColor(12);
  gotoxy(70, 25);
  printf("© Developed By SHAKIL ANWAR");
  SetColor(45);
  gotoxy(59, 14);
  hswitch = getche();
  switch (hswitch) {
  case '1':
    teacher_log_in();
    break;
  case '2':
    admin_log_in();
    break;
  case '3':
    please_wait();
    C_smstr_R();
    break;
  case '4':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD. TRY AGAIN\n");
    Sleep(1000);
    home();
  }
  return 0;

}

int welcome() {
  SetColor(14);
  printf("\n\n\n\t\t                             WELCOME TO                           \n");
  printf("\t                               STUDENT ATTENDANCE SYSTEM             \n\n\n");
  return 0;
}

//TEACHER OPTION

int teacher_home() {
  system("cls");
  char tswitch;
  printf("\n\n\n");
  SetColor(14);
  printf("\n\n\t\t\t\t\t  ===Teachers Portal===\n\n\n\n\n");
  SetColor(45);
  printf("\t\t\t\t\t ==> 1. Input Attendance\n");
  printf("\t\t\t\t\t ==> 2. View Attendance\n");
  printf("\t\t\t\t\t ==> 3. Search a Student Attendance\n");
  printf("\t\t\t\t\t ==> 4. Edit Attendance\n");
  printf("\t\t\t\t\t ==> 5. Log Out\n\n\n");
  SetColor(11);
  printf("\t\t\t\t\t Select an Option:");
  SetColor(45);
  tswitch = getche();
  switch (tswitch) {
  case '1':
    attendance_data();
    break;
  case '2':
    search_attendance();
    break;
  case '3':
    search_student_attendance();
    break;
  case '4':
    att_edit1();
    break;
  case '5':
    home();
    break;
  default:
    SetColor(4);
    printf("\n\n\t\t\t\t\t  INVALID KEYWORD\n");
    Sleep(1000);
    SetColor(45);
    teacher_home();
  }
  return 0;

}

struct s_attendance {
  char date[30];
  char sid[30];
  char ati[5];
  char sname[50];
  int att_count;
}
s_att, s_att_e, s_att_e1;

struct s_attendance2 {
  char date[30];
  char sid[30];
  char ati[5];
  char sname[50];
  int att_count;
};

int attendance_data() {
  system("cls");
  int i = 0;
  int count = 0;
  char name[100];
  int id[100];
  char date[100];
  int found = 0;
  char att_cmp[5] = {
    "p"
  };
  char att_cmp1[5] = {
    "a"
  };
  FILE * fptr1;
  fptr1 = fopen("Student info.dll", "r");
  FILE * chdate;
  chdate = fopen("Attendance.dll", "r");
  SetColor(14);
  printf("\n\n\n\t\t\t\t\tEnter Current date[dd/mm/yy]:");
  SetColor(9);
  scanf("%s", date);
  while (fread( & s_att, sizeof(s_att), 1, chdate)) {
    if (strcmp(date, s_att.date) == 0) {
      found = 1;
    }
  }

  if (found == 0) {
    while (fread( & std, sizeof(std), 1, fptr1)) {
      fflush(stdin);
      strcpy(s_att.date, date);
      strcpy(s_att.sid, std.id);
      strcpy(s_att.sname, std.name);
      SetColor(13);
      printf("\n\n\t\t\t\t\t  Student Name: %s\n\t\t\t\t\t  Student ID: %s\n\n  ", s_att.sname, s_att.sid);
      SetColor(7);
      printf("\t\t\t\t  Press [p] for present and [a] for absent....");
      SetColor(9);
      scanf("%s", & s_att.ati);
      SetColor(45);
      if (strcmp(s_att.ati, att_cmp) == 0 || strcmp(s_att.ati, att_cmp1) == 0) {
        if (strcmp(s_att.ati, att_cmp) == 0) {
          s_att.att_count = s_att.att_count + 1;
        }
        if (strcmp(s_att.ati, att_cmp1) == 0) {
          s_att.att_count = s_att.att_count + 0;
        }
      } else {
        SetColor(4);
        printf("\n\n\t\t\t\t  Invalid Attendance Case Try Again...!!\n");
        SetColor(45);
      }

      FILE * att1;
      att1 = fopen("Attendance.dll", "a");

      if (att1 == NULL) {
        printf("Error\n");
        exit(1);
      }
      fwrite( & s_att, sizeof(s_att), 1, att1);
      fclose(att1);
    }

    printf("\n  SAVE SUCCESS\n\n\n");
    char end;
    printf("  Press 1 for Input more attendance\n");
    printf("  Press 2 for go Back\n");
    printf("  Press 3 for EXIT Software\n");
    printf(" Select an Option:");

    end = getche();

    switch (end) {
    case '1':
      attendance_data();
      break;
    case '2':
      teacher_home();
      break;
    case '3':
      ext();
      break;
    default:
      printf("\n  INVALID KEYWORD\n");
      Sleep(1000);
      teacher_home();
    }
  } else {
    SetColor(4);
    printf("\n\t\t\t\t\tAttendance Already Taken. TRY ANOTHER DATE\n\n");
    Sleep(2000);
    SetColor(45);
    attendance_data();
  }

  return 0;
}

int search_attendance() {
  int tdt = 0;
  FILE * fptdt;
  fptdt = fopen("Attendance.dll", "r");
  while (fread( & s_att, sizeof(s_att), 1, fptdt)) {
    tdt = tdt + 1;
  }
  fclose(fptdt);
  search_attendance1(tdt);

  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 for search more attendance\n");
  printf("  Press 2 for go Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    search_attendance();
    break;
  case '2':
    teacher_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\nINVALID KEYWORD\n");
    Sleep(1000);
    teacher_home();
  }

  return 0;
}

int search_attendance1(int tdt) {
  system("cls");
  printf("\n\t\t\t\t\t\tSEARCH ATTENDANCE \n");
  int lc = 0;
  char sr_att[30];
  SetColor(14);
  printf("\n\t\t\t\t  Enter the date you want to search attendance: ");
  SetColor(11);
  scanf("%s", sr_att);
  system("cls");
  FILE * fpsr;
  fpsr = fopen("Attendance.dll", "r");
  printf("\n\n  \t\t\t\tDate: %s\n", sr_att);
  SetColor(11);
  while (fread( & s_att, sizeof(s_att), 1, fpsr)) {
    if (strcmp(sr_att, s_att.date) == 0) {
      printf("\n  Student Name: %s\n  Student ID: %s\n  Attendance: %s\n", s_att.sname, s_att.sid, s_att.ati);
    }
  }
  SetColor(45);
  return 0;
}

struct result {
  char sub_name[100];
  float cgpa;
  int credit;
  float m_w_c;

};
struct result1 {
  int i, n_f_S;
  struct result R[5];
}
R1;

int C_smstr_R() {
  system("cls");
  float a_w_m_c = 0;
  int t_c = 0;
  float result = 0;
  printf("\n  SEMESTER RESULT COUNT\n");
  fflush(stdin);
  printf("\n  Enter How Many Subject In This Semester>>");
  scanf("%d", & R1.n_f_S);
  for (R1.i = 1; R1.i <= R1.n_f_S; R1.i++) {
    fflush(stdin);
    printf("\n  Enter Subject %d Name>>", R1.i);
    gets(R1.R[R1.i].sub_name);
    printf("\n  Enter %s GPA Result>>", R1.R[R1.i].sub_name);
    scanf("%f", & R1.R[R1.i].cgpa);
    printf("\n  Enter %s Credit>>", R1.R[R1.i].sub_name);
    scanf("%d", & R1.R[R1.i].credit);
  }
  for (R1.i = 1; R1.i <= R1.n_f_S; R1.i++) {
    R1.R[R1.i].m_w_c = R1.R[R1.i].cgpa * R1.R[R1.i].credit;
  }
  for (R1.i = 1; R1.i <= R1.n_f_S; R1.i++) {
    a_w_m_c = a_w_m_c + R1.R[R1.i].m_w_c;
  }
  for (R1.i = 1; R1.i <= R1.n_f_S; R1.i++) {
    t_c = t_c + R1.R[R1.i].credit;
  }
  result = a_w_m_c / t_c;

  for (R1.i = 1; R1.i <= R1.n_f_S; R1.i++) {
    printf("\n  Subject:: %d %s GPA :: %.2f  Credit :: %d", R1.i, R1.R[R1.i].sub_name, R1.R[R1.i].cgpa, R1.R[R1.i].credit);
  }

  printf("\n  Result is: %.2f\n", result);

  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 for Count More Results\n");
  printf("  Press 2 for go to home page\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    C_smstr_R();
    break;
  case '2':
    home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\nINVALID KEYWORD\n");
    Sleep(1000);
    home();
  }

  return 0;
}

//ADMIN OPTION

int admin_home() {
  SetColor(14);
  system("cls");
  char adswitch;
  printf("\n\n\n\n\t\t\t\t\t\t===Admin Portal===\n\n\n");
  SetColor(45);
  printf("\t\t\t\t\t ==> 1. Save Student Details\n");
  printf("\t\t\t\t\t ==> 2. View Student Details\n");
  printf("\t\t\t\t\t ==> 3. Search a Student by ID\n");
  printf("\t\t\t\t\t ==> 4. Delete Student Data\n");
  printf("\t\t\t\t\t ==> 5. Edit Student Data\n");
  printf("\t\t\t\t\t ==> 6. Log Out\n\n\n");
  SetColor(11);
  printf("\t\t\t\t\t   Select an Option:");
  SetColor(45);
  adswitch = getche();
  switch (adswitch) {
  case '1':
    save_student_details();
    break;
  case '2':
    view_student_details();
    break;
  case '3':
    search_student();
    break;
  case '4':
    delete_student();
    break;
  case '5':
    edit_student();
    break;
  case '6':
    home();
    break;
  default:
    printf("INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }
  return 0;

}

int save_student_details() {
  char more;
  system("cls");
  SetColor(14);
  printf("\n\t\t\t\t\t  ===SAVE STUDENT DETAILS===\n");
  FILE * fptr;
  fptr = fopen("Student info.dll", "a");
  if (fptr == NULL) {
    printf("Error");
    exit(1);
  }
  fflush(stdin);
  printf("\n   \tEnter Student Name: ");
  SetColor(11);
  gets(std.name);
  SetColor(14);
  printf("\n   \tEnter Student ID: ");
  SetColor(11);
  gets(std.id);
  SetColor(14);
  printf("\n   \tEnter Section: ");
  SetColor(11);
  gets(std.section);
  SetColor(14);
  printf("\n   \tEnter Student BATCH: ");
  SetColor(11);
  gets(std.batch);
  SetColor(14);
  printf("\n   \tEnter Student Address[Village,Thana,District:] ");
  SetColor(11);
  gets(std.address);
  SetColor(14);
  printf("\n   \tEnter Department: ");
  SetColor(11);
  gets(std.department);
  SetColor(14);
  printf("\n   \tEnter Semester: ");
  SetColor(11);
  gets(std.semester);
  SetColor(14);
  printf("\n   \tEnter Average CGPA: ");
  SetColor(11);
  scanf("%f", & std.Av_cgpa);
  SetColor(14);

  fwrite( & std, sizeof(std), 1, fptr);
  printf("\n\n >> SAVE SUCCESSFUL <<\n");
  fclose(fptr);
  printf("\t\t\tSave more Student details[y/n] ");
  more = getche();

  switch (more) {
  case 'y':
    save_student_details();
    break;
  case 'n':
    admin_home();
    break;
    SetColor(5);
  default:
    printf("\n\t\t\t\t  INVALID KEYWORD\n");
    SetColor(45);
    Sleep(1000);
    admin_home();

  }

  return 0;
}

int view_student_details() {
  system("cls");
  SetColor(14);
  printf("\n\t\t\t\t  ALL STUDENTS INFORMATION\n\n");
  FILE * fptr1;
  fptr1 = fopen("Student info.dll", "r");
  while (fread( & std, sizeof(std), 1, fptr1)) {
    SetColor(11);
    printf("\n\t\t\t  NAME: %s\n\t\t\t  ID: %s\n\t\t\t  Section: %s\n\t\t\t  Batch: %s\n\t\t\t  Address: %s\n\t\t\t  Department: %s\n\t\t\t  Semester: %s\n\t\t\t  AVERAGE CGPA: %.2f\n", std.name, std.id, std.section, std.batch, std.address, std.department, std.semester, std.Av_cgpa);
  }
  fclose(fptr1);

  //EXIT_Switch
  SetColor(45);
  char end;
  printf("\n\n  Press 1 for View All Students Again\n");
  printf("  Press 2 for go to Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    view_student_details();
    break;
  case '2':
    admin_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }

  return 0;
}

int search_student() {
  int tdt = 0;
  FILE * fptdt;
  fptdt = fopen("Student info.dll", "r");
  while (fread( & std, sizeof(std), 1, fptdt)) {
    tdt = tdt + 1;
  }
  fclose(fptdt);
  search1(tdt);

  //EXIT_Switch
  char end;
  SetColor(45);
  printf("\n\n  Press 1 for Search More Students\n");
  printf("  Press 2 for go to Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    search_student();
    break;
  case '2':
    admin_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }
  return 0;
}

int search1(int tdt) {
  system("cls");
  int lc = 0;
  FILE * fptr2;
  fptr2 = fopen("Student info.dll", "r");
  char id[30];
  int smstr;
  SetColor(14);
  printf("\n\t\t\t  Enter The ID You Want To Search: ");
  fflush(stdin);
  SetColor(11);
  gets(id);

  while (fread( & std, sizeof(std), 1, fptr2)) {
    if (strcmp(id, std.id) == 0) {
      printf("\n\n\t\t\t  Student Information\n");
      printf("\n\n\t\t\t  NAME: %s\n\t\t\t  ID: %s\n\t\t\t  Section: %s\n\t\t\t  Batch: %s\n\t\t\t  Address: %s\n\t\t\t  Department: %s\n\t\t\t  Semester: %s\n\t\t\t  AVERAGE CGPA: %.2f\n", std.name, std.id, std.section, std.batch, std.address, std.department, std.semester, std.Av_cgpa);
      break;
    }
    lc = lc + 1;
    if (lc == tdt) {
      SetColor(4);
      printf("\n  Search Not Matching\n");
      SetColor(45);
    }
  }

  fclose(fptr2);

  return 0;
}

int search_student_semester() {
  int tdt = 0;
  FILE * fptdt;
  fptdt = fopen("Student info.dll", "r");
  while (fread( & std, sizeof(std), 1, fptdt)) {
    tdt = tdt + 1;
  }
  fclose(fptdt);
  search_student_semester1(tdt);
  end_switch_s_s_s();
  return 0;
}

int search_student_semester1(int tdt) {
  system("cls");
  printf("\n  ====SEARCH PAGE====\n");
  int lc = 0;
  FILE * fptr2;
  fptr2 = fopen("Student info.dll", "r");
  char id[30];
  char smstr[30];
  printf("\n  Enter The Semester You Want To Search >>");
  fflush(stdin);
  gets(smstr);

  while (fread( & std, sizeof(std), 1, fptr2)) {
    if (strcmp(smstr, std.semester) == 0) {
      printf("\n  Search Matching\n");
      printf("\n  NAME: %s\n  ID: %s\n  Section: %s\n  Batch: %s\n  Address: %s\n  Department: %s\n  Semester: %s\n  AVERAGE CGPA: %.2f\n", std.name, std.id, std.section, std.batch, std.address, std.department, std.semester, std.Av_cgpa);
      for (std.i = 1; std.i <= std.n_sub; std.i++) {
        printf("  Subject: %d : %s GPA: %.2f\n", std.i, std.sub[std.i].sub_name, std.sub[std.i].cgpa);
      }
      break;
    }
    lc = lc + 1;
    if (lc == tdt) {
      printf("\n  Search Not Matching\n");
    }
  }

  fclose(fptr2);
  return 0;
}

int ext() {
  system("cls");
  printf("\n  EXIT PAGE\n");
  char c_exit;
  fflush(stdin);
  printf("\n  Press 1 Cancel Exit");
  printf("\n  Press 0 For Exit Software");
  c_exit = getche();
  switch (c_exit) {
  case '1':
    home();
    break;
  case '0':
    printf("\n  THANKS FOR USING STUDENT ATTENDANCE SYSTEM");
    printf("\n  Press Any Key To EXIT......");
    _getch();
    exit(EXIT_SUCCESS);
    break;
  default:
    printf("INVALID KEYWORD\n");
    Sleep(1000);
    ext();
  }
  return 0;
}

int end_switch_s_s_s() {
  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 for Search again\n");
  printf("  Press 2 for go to home page\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    search_student_semester();
    break;
  case '2':
    home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("INVALID KEYWORD");
  }
  return 0;
}

int delete_student() {
  system("cls");
  printf("\n  Delete Student Information\n");
  FILE * fp1, * fp2;
  struct student std, std1;
  int found = 0;
  char id[50];
  fp1 = fopen("Student info.dll", "r");
  fp2 = fopen("Delete.dll", "w");
  fflush(stdin);
  printf("\n  Enter The Student ID You Want To Delete  ");
  gets(id);
  while (1) {
    fread( & std1, sizeof(std1), 1, fp1);
    if (feof(fp1)) {
      break;
    }
    if (strcmp(id, std1.id) == 0) {
      found = 1;
    } else {
      fwrite( & std1, sizeof(std1), 1, fp2);
    }
  }
  fclose(fp1);
  fclose(fp2);
  if (found == 0) {
    printf("\n\n  DATA NOT FOUND \n");
  } else {
    fp1 = fopen("Student info.dll", "w");
    fp2 = fopen("Delete.dll", "r");
    while (1) {
      fread( & std1, sizeof(std1), 1, fp2);
      if (feof(fp2)) {
        break;
      }
      fwrite( & std1, sizeof(std1), 1, fp1);
    }
    printf("\n\n  >> DELETE SUCCESSFUL <<  \n\n");
  }
  fclose(fp1);
  fclose(fp2);

  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 for Search again\n");
  printf("  Press 2 for go Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    delete_student();
    break;
  case '2':
    admin_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }
  fflush(stdin);
  return 0;
}

int edit_student() {
  int td = 0;
  FILE * edit;
  edit = fopen("Student info.dll", "r");
  while (fread( & std, sizeof(std), 1, edit)) {
    td = td + 1;
  }
  fclose(edit);
  edit1(td);

  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 To Edit More Student Details\n");
  printf("  Press 2 for go Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    edit_student();
    break;
  case '2':
    admin_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }
  fflush(stdin);

  return 0;
}

struct for_edit {
  char id[50];
  char edit_smstr[20];
}
std_edit;

int edit1(int td) {
  system("cls");
  printf("\n  EDIT STUDENT INFORMATION\n");
  int loopc = 0;
  FILE * edit1;
  edit1 = fopen("Student info.dll", "r");

  struct student std, std1, std3, std4;
  struct student2 std2, std5;

  printf("\n  Enter The Student ID You Want To Edit : ");
  fflush(stdin);
  gets(std_edit.id);

  while (fread( & std4, sizeof(std4), 1, edit1)) {

    if (strcmp(std_edit.id, std4.id) == 0) {
      edit2(std_edit.id, std_edit.edit_smstr);
      break;
    }
    loopc = loopc + 1;
    if (loopc == td) {
      printf("\n  Data Not Matching \n");
    }
  }

  fclose(edit1);
  return 0;
}

int edit2(char id[50], char edit_smstr[20]) {
  printf("\n  Data Matching\n");
  FILE * fpedt, * fpedt1;

  struct student2 std2, std5;
  struct student std, std1, std3, std4;

  int found = 0;
  fpedt = fopen("Student info.dll", "r");
  fpedt1 = fopen("Edit.dll", "w");

  fflush(stdin);
  printf("\n  Enter New Student Name:");
  gets(std2.name);
  printf("  Enter New Student Section:");
  gets(std2.section);
  printf("  Enter New Student BATCH:");
  gets(std2.batch);
  printf("  Enter New Student Address[Village,Thana,District]:");
  gets(std2.address);
  printf("  Enter New Student Department:");
  gets(std2.department);
  printf("  Enter Semester:");
  gets(std2.semester);
  printf("  Enter New Average CGPA:");
  scanf("%f", & std2.Av_cgpa);

  while (1) {
    fread( & std3, sizeof(std3), 1, fpedt);
    if (feof(fpedt)) {
      break;
    }

    if (strcmp(id, std3.id) == 0) {
      found = 1;
      strcpy(std3.name, std2.name);
      strcpy(std3.id, id);
      strcpy(std3.section, std2.section);
      strcpy(std3.batch, std2.batch);
      strcpy(std3.address, std2.address);
      strcpy(std3.department, std2.department);
      strcpy(std3.semester, std2.semester);
      std3.Av_cgpa = std2.Av_cgpa;

      fwrite( & std3, sizeof(std3), 1, fpedt1);
    } else {
      fwrite( & std3, sizeof(std3), 1, fpedt1);
    }
  }
  fclose(fpedt);
  fclose(fpedt1);
  if (found == 0) {
    printf("\n\n  SORRY DATA NOT FOUND  \n\n");
  } else {
    fpedt = fopen("Student info.dll", "w");
    fpedt1 = fopen("Edit.dll", "r");
    while (1) {
      fread( & std3, sizeof(std3), 1, fpedt1);
      if (feof(fpedt1)) {
        break;
      }
      fwrite( & std3, sizeof(std3), 1, fpedt);
    }
    printf("\n\n  EDIT SUCCESSFUL  \n\n");
  }
  fclose(fpedt);
  fclose(fpedt1);

  //EXIT_Switch
  char end;
  printf("\n\n  Press 1 To Edit More Student Details\n");
  printf("  Press 2 for go Back\n");
  printf("  Press 3 for EXIT Software\n");
  printf(" Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    edit_student();
    break;
  case '2':
    admin_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD\n");
    Sleep(1000);
    admin_home();
  }
  fflush(stdin);

  return 0;
}

int search_student_attendance() {
  system("cls");
  float present = 0;
  float absent = 0;
  int y = 25;
  float mark_att1, mark_att2;
  float count = 0;
  float count1 = 0;
  float count2;
  char p[20] = {
    "p"
  };
  char a[20] = {
    "a"
  };
  FILE * ssatt;
  ssatt = fopen("Attendance.dll", "r");
  char id[30];
  char dtls;
  int i = 0, found = 0;
  view_student_att();
  SetColor(14);
  gotoxy(50, 5);
  printf(" Enter The ID You Want To Search: ");
  SetColor(11);
  fflush(stdin);
  gets(id);
  SetColor(45);
  while (fread( & s_att, sizeof(s_att), 1, ssatt)) {
    if (strcmp(id, s_att.sid) == 0) {
      if (strcmp(p, s_att.ati) == 0) {
        present = present + 1;
      } else {
        absent = absent + 1;
      }
      count = count + 1;
      found = 1;
    }
  }
  if (found == 0) {
    SetColor(4);
    gotoxy(51, 10);
    printf("DATA NOT FOUND");
    SetColor(45);
  } else

  {
    char idfc[20];
    FILE * stdptr1;
    stdptr1 = fopen("Student info.dll", "r");
    while (fread( & std, sizeof(std), 1, stdptr1)) {
      strcpy(idfc, std.id);
      break;
    }
    fclose(stdptr1);
    FILE * stdptr2;
    stdptr2 = fopen("Attendance.dll", "r");
    while (fread( & s_att, sizeof(s_att), 1, stdptr2)) {
      if (strcmp(idfc, s_att.sid) == 0) {
        count1 = count1 + 1;
      }
    }
    fclose(stdptr2);

    FILE * stdptr;
    stdptr = fopen("Student info.dll", "r");
    while (fread( & std, sizeof(std), 1, stdptr)) {
      if (strcmp(id, std.id) == 0) {
        SetColor(11);
        gotoxy(50, 7);
        printf(">> Attendance <<\n\n");
        SetColor(14);
        gotoxy(50, 9);
        printf("Name:%s", std.name);
        gotoxy(50, 10);
        printf("ID: %s", std.id);
        gotoxy(50, 11);
        printf("Department: %s", std.department);
        gotoxy(50, 12);
        printf("Section: %s", std.section);
        gotoxy(50, 14);
        printf("Total Class: %0.0f", count1);
        gotoxy(50, 15);
        printf("Present: %0.0f Days", present);
        gotoxy(50, 16);
        printf("Absent: %0.0f Days", absent);
      }
    }

    if (count1 > count) {
      count2 = count1 - count;
      SetColor(4);
      gotoxy(50, 18);
      printf("[Registered after %0.0f Class]", count2);
      SetColor(14);
    }
    mark_att1 = (present * 5) / count1;
    mark_att2 = (present * 7) / count1;
    gotoxy(50, 20);
    printf("Attendance Mark: %0.2f  [Out of 5.0]\n", mark_att1);
    gotoxy(50, 21);
    printf("Attendance Mark: %0.2f  [Out of 7.0]\n\n", mark_att2);
    gotoxy(50, 23);
    printf("Do you want to view attendance details[y/n]");
    scanf("%c", & dtls);
    //printf("\n\n");
    if (dtls == 'y') {
      FILE * temp2;
      temp2 = fopen("Attendance.dll", "r");
      while (fread( & s_att, sizeof(s_att), 1, temp2)) {
        if (strcmp(id, s_att.sid) == 0) {
          if (strcmp(p, s_att.ati) == 0) {
            SetColor(11);
            gotoxy(50, y);
            printf("%s: Present\n", s_att.date);
          } else if (strcmp(a, s_att.ati) == 0) {
            SetColor(4);
            gotoxy(50, y);
            printf("%s: Absent\n", s_att.date);
            SetColor(11);
          }
          y++;
        }

      }
      fclose(temp2);
    }

    fclose(ssatt);
  }

  //EXIT_Switch
  SetColor(45);
  char end;
  gotoxy(50, y + 2);
  printf("Press 1 To Search Again");
  gotoxy(50, y + 3);
  printf("Press 2 for go Back");
  gotoxy(50, y + 4);
  printf("Press 3 for EXIT Software");
  gotoxy(50, y + 5);
  printf("Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    search_student_attendance();
    break;
  case '2':
    teacher_home();
    break;
  case '3':
    ext();
    break;
  default:
    printf("INVALID KEYWORD");
    Sleep(1000);
    home();
  }

  return 0;
}

int teacher_log_in() {
  system("cls");
  int i, found = 0, s = 0;
  char name[20], password[20], p;
  char tID[20] = {
    "172352142"
  };
  char tPASS[20] = {
    "2142"
  };
  SetColor(14);
  printf("\n\n\t\t\t\t\t  ===Teachers Portal===\n\n\n\n\n");
  SetColor(45);
  SetColor(11);
  printf("\n\n\t\t\t\t\tYou must log in first\n");
  SetColor(6);
  printf("\n\n\t\t\t\t\tTeacher ID: ");
  SetColor(3);
  gets(name);
  SetColor(6);
  printf("\n\n\t\t\t\t\tPassword: ");
  SetColor(3);
  while (p != 13) {
    p = _getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';
  if (strcmp(tID, name) == 0) {
    if (strcmp(tPASS, password) == 0) {
      found = 1;
      SetColor(11);
      printf("\n\n\n\t\t\t\t\tLog In Success\n");
      Sleep(1500);
      system("cls");
      please_wait();
      system("cls");
      teacher_home();
    } else {
      SetColor(4);
      printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
      Sleep(3000);
      SetColor(45);
      teacher_log_in();
    }
  } else {
    SetColor(4);
    printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
    Sleep(3000);
    SetColor(45);
    teacher_log_in();
  }
}

int admin_log_in() {
  system("cls");
  int i, s = 0;
  char name[20], password[20], p;
  char tID[20] = {
    "172352142"
  };
  char tPASS[20] = {
    "2142"
  };
  SetColor(14);
  printf("\n\n\t\t\t\t\t  ===Admin Portal===\n\n\n\n\n");
  SetColor(45);
  SetColor(11);
  printf("\n\n\t\t\t\t\tYou must log in first\n");
  SetColor(6);
  printf("\n\n\t\t\t\t\tAdmin ID: ");
  SetColor(3);
  gets(name);
  SetColor(6);
  printf("\n\n\t\t\t\t\tPassword: ");
  SetColor(3);
  while (p != 13) {
    p = _getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';
  if (strcmp(tID, name) == 0) {
    if (strcmp(tPASS, password) == 0) {
      SetColor(11);
      printf("\n\n\n\t\t\t\t\tLog In Success\n");
      Sleep(1500);
      system("cls");
      please_wait();
      system("cls");
      admin_home();
    } else {
      SetColor(4);
      printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
      Sleep(3000);
      SetColor(45);
      admin_log_in();
    }
  } else {
    SetColor(4);
    printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
    Sleep(3000);
    SetColor(45);
    admin_log_in();
  }
}

int please_wait() {
  for (i = 0; i < 2; i++) {
    SetColor(14);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait.");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait..");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait...");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait....");
    Sleep(300);
    system("cls");
    SetColor(45);
  }
}

int att_edit1() {
  FILE * fpedt_att;
  fpedt_att = fopen("Attendance.dll", "r");
  int td = 0;
  while (fread( & s_att, sizeof(s_att), 1, fpedt_att)) {
    td = td + 1;
  }
  fclose(fpedt_att);
  edit_2(td);
  return 0;
}

struct Edit_take {
  char id[40];
  char date[40];
  char new_att[5];
}
edit_scan, edit_scan1;

int edit_2(int td) {
  system("cls");
  FILE * fread_att;
  int found = 0;
  int found2 = 0;
  int loopc = 0;

  struct s_attendance s_att, s_att_e, s_att_e1;

  fread_att = fopen("Attendance.dll", "r");
  fflush(stdin);
  SetColor(14);
  printf("\n\n\t\t\t\t\t Enter date: ");
  SetColor(11);
  gets(edit_scan.date);
  FILE * fpsr;
  fpsr = fopen("Attendance.dll", "r");
  SetColor(14);
  printf("\n\n  Date: %s\n", edit_scan.date);
  SetColor(11);
  while (fread( & s_att, sizeof(s_att), 1, fpsr)) {
    if (strcmp(edit_scan.date, s_att.date) == 0) {
      found2 = 1;
      printf("\n  Student Name: %s\n  Student ID: %s\n  Attendance: %s\n", s_att.sname, s_att.sid, s_att.ati);
    }
  }
  if (found2 == 1) {
    SetColor(14);
    gotoxy(50, 5);
    printf("Enter Student ID You want to Edit: ");
    SetColor(11);
    gets(edit_scan.id);
    while (fread( & s_att, sizeof(s_att), 1, fread_att)) {
      loopc = loopc + 1;
      if (strcmp(edit_scan.id, s_att.sid) == 0 && strcmp(edit_scan.date, s_att.date) == 0) {
        SetColor(14);
        gotoxy(50, 8);
        printf("Student Name: %s", s_att.sname);
        gotoxy(50, 9);
        printf("Student ID: %s", s_att.sid);
        gotoxy(50, 10);
        printf("Attendance: %s", s_att.ati);
        edit_3(s_att.sid, s_att.date);
        break;
      }

      if (loopc == td) {
        SetColor(4);
        gotoxy(50, 11);
        printf("Student Not Found");
        //EXIT_Switch
        SetColor(45);
        char end;
        gotoxy(50, 19);
        printf("Press 1 To Edit More");
        gotoxy(50, 20);
        printf("Press 2 for go Back");
        gotoxy(50, 21);
        printf("Press 3 for EXIT Software");
        gotoxy(50, 22);
        printf("Select an Option:");

        end = getche();

        switch (end) {
        case '1':
          att_edit1();
          break;
        case '2':
          teacher_home();
          break;
        case '3':
          ext();
          break;
        default:
          gotoxy(50, 23);
          printf("INVALID KEYWORD");
          Sleep(1000);
          home();
        }

      }
    }
  }
  if (found2 == 0) {
    SetColor(4);
    gotoxy(50, 12);
    printf("Data Not Found");
    //EXIT_Switch
    SetColor(45);
    char end;
    gotoxy(50, 19);
    printf("Press 1 To Edit More");
    gotoxy(50, 20);
    printf("Press 2 for go Back");
    gotoxy(50, 21);
    printf("Press 3 for EXIT Software");
    gotoxy(50, 22);
    printf("Select an Option:");

    end = getche();

    switch (end) {
    case '1':
      att_edit1();
      break;
    case '2':
      teacher_home();
      break;
    case '3':
      ext();
      break;
    default:
      gotoxy(50, 23);
      printf("INVALID KEYWORD");
      Sleep(1000);
      home();
    }
  }

  return 0;
}

int edit_3(char id[40], char date[40]) {
  FILE * fread_att1;
  FILE * edit_file;
  fread_att1 = fopen("Attendance.dll", "r");
  edit_file = fopen("Attendance Edit.dll", "w");

  struct s_attendance s_att, s_att_e, s_att_e1;
  struct Edit_take edit_scan, edit_scan1;
  int found = 0;
  SetColor(12);
  gotoxy(50, 13);
  printf("Press [p] for present and [a] for absent....");
  fflush(stdin);
  SetColor(11);
  scanf("%s", & edit_scan1.new_att);
  while (1) {
    fread( & s_att_e, sizeof(s_att_e), 1, fread_att1);
    if (feof(fread_att1)) {
      break;
    }
    if (strcmp(id, s_att_e.sid) == 0 && strcmp(date, s_att_e.date) == 0) {
      found = 1;
      strcpy(s_att_e.date, s_att_e.date);
      strcpy(s_att_e.sid, s_att_e.sid);
      strcpy(s_att_e.sname, s_att_e.sname);
      strcpy(s_att_e.ati, edit_scan1.new_att);
      fwrite( & s_att_e, sizeof(s_att_e), 1, edit_file);
    } else {
      fwrite( & s_att_e, sizeof(s_att_e), 1, edit_file);
    }
  }

  fclose(fread_att1);
  fclose(edit_file);
  if (found == 0) {
    SetColor(4);
    gotoxy(50, 12);
    printf("Data Not Found");
  } else {
    fread_att1 = fopen("Attendance.dll", "w ");
    edit_file = fopen("Attendance Edit.dll", "r");
    while (1) {
      fread( & s_att_e, sizeof(s_att_e), 1, edit_file);
      if (feof(edit_file)) {
        break;
      }
      fwrite( & s_att_e, sizeof(s_att_e), 1, fread_att1);
    }
    SetColor(14);
    gotoxy(50, 16);
    printf("Edit Successful");
  }
  fclose(fread_att1);
  fclose(edit_file);

  //EXIT_Switch
  SetColor(45);
  char end;
  gotoxy(50, 19);
  printf("Press 1 To Edit More");
  gotoxy(50, 20);
  printf("Press 2 for go Back");
  gotoxy(50, 21);
  printf("Press 3 for EXIT Software");
  gotoxy(50, 22);
  printf("Select an Option:");

  end = getche();

  switch (end) {
  case '1':
    att_edit1();
    break;
  case '2':
    teacher_home();
    break;
  case '3':
    ext();
    break;
  default:
    gotoxy(50, 23);
    printf("INVALID KEYWORD");
    Sleep(1000);
    home();
  }

  return 0;
}

int view_student_att() {
  system("cls");
  SetColor(14);
  printf("\n\t  ALL STUDENTS\n\n");
  FILE * fptr_att;
  fptr_att = fopen("Student info.dll", "r");
  while (fread( & std, sizeof(std), 1, fptr_att)) {
    SetColor(11);
    printf("\n\t  NAME: %s\n\t  ID: %s\n", std.name, std.id, std.section);
  }
  fclose(fptr_att);

  return 0;
}
