#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STUD_N 30
#define COURSE_N 6
#define NAME_MAX 30

//����ṹ�����ͣ��ýṹ������������������ʵ��ѧ���ɼ�����ϵͳ
//����ѧ����Ϣ
typedef struct student
{
    long stuID;             //ѧ��ѧ��
    char stuName[NAME_MAX]; //ѧ������
    int score[COURSE_N];    //ѧ�����Ƴɼ�
    int stuSum;             //ѧ���ܷ�
    float stuAver;          //ĳһλѧ������ƽ����

}STUDENT;

//����ԭ�ͣ�
int *ShowMenu(void);
char *AnsforRe(void);
int ReadData_1(STUDENT stu[], int n, int m);
int CourseSumAver_2(STUDENT stu[], int sumC[], float averC[], int n, int m);
int StuSumAver_3(STUDENT stu[], int n, int m);
int DescendScore_4(STUDENT stu[], int n, int m);
int AscendScore_5(STUDENT stu[], int n, int m);
int AscendNum_6(STUDENT stu[], int n, int m);
int AscendName_7(STUDENT stu[], int n, int m);
int SearchNum_8(STUDENT stu[], int n, int m);
int SearchName_9(STUDENT stu[], int n, int m);
int DegreeDeal_10(STUDENT stu[], int n, int m);
int PrintData_11(STUDENT stu[], int n, int m);

int main(void)
{
    STUDENT stu[STUD_N];
    int n, m = 0;       //�ֱ���ѧ�������Ϳγ���Ŀ
    int *pCommand = NULL; //����ָ��
    char *ansReturn = NULL; //�û����Ƿ񷵻ز˵�������
    int sumC[COURSE_N] = {0};    //ÿ�ſγ̵��ܷ�
    float averC[COURSE_N] = {0}; //ÿ�ſγ̵�ƽ����

    //��ʾ���˵�
    Menu:
    pCommand = ShowMenu();

    switch(*pCommand)
    {
    case 1:
        {
            //¼����Ϣ
            printf("How many students?(n <= 30) ");
            scanf("%d", &n);
            printf("How many courses?(m <= 6) ");
            scanf("%d", &m);

            if(n<0||n>30||m<0||m>6) //������������
            {
                printf("OVERFLOW, BREAK!\n");
                break;
            }

            int flag_1; //���ñ�־�����۲��������
            flag_1 = ReadData_1(stu, n, m);
            if(flag_1==1) printf("Operation 1 finish correctly!\n");
            else          printf("Operation 1 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 2:
        {
            //����ÿ�ſγ̵��ֺܷ�ƽ����
            int flag_2;
            flag_2 = CourseSumAver_2(stu, sumC, averC, n, m);
            if(flag_2==1) printf("Operation 2 finish correctly!\n");
            else          printf("Operation 2 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 3:
        {
            //����ÿ��ѧ�����ֺܷ�ƽ����
            int flag_3;
            flag_3 = StuSumAver_3(stu, n, m);
            if(flag_3==1) printf("Operation 3 finish correctly!\n");
            else          printf("Operation 3 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 4:
        {
            //��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
            int flag_4;
            flag_4 = DescendScore_4(stu, n, m);
            PrintData_11(stu, n,m);
            if(flag_4==1) printf("Operation 4 finish correctly!\n");
            else          printf("Operation 4 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 5:
        {
            //��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
            int flag_5;
            flag_5 = AscendScore_5(stu, n, m);
            PrintData_11(stu, n,m);
            if(flag_5==1) printf("Operation 5 finish correctly!\n");
            else          printf("Operation 5 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 6:
        {
            //��ѧ����С�����ų��ɼ���
            int flag_6;
            flag_6 = AscendNum_6(stu, n, m);
            PrintData_11(stu, n,m);
            if(flag_6==1) printf("Operation 6 finish correctly!\n");
            else          printf("Operation 6 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 7:
        {
            //�������ֵ�˳���ų��ɼ���
            int flag_7;
            flag_7 = AscendName_7(stu, n, m);
            PrintData_11(stu, n,m);
            if(flag_7==1) printf("Operation 7 finish correctly!\n");
            else          printf("Operation 7 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 8:
        {
            //��ѧ�Ų�ѯѧ���������俼�Գɼ�
            int flag_8;
            flag_8 = SearchNum_8(stu, n, m);
            if(flag_8==1) printf("Operation 8 finish correctly!\n");
            else          printf("Operation 8 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 9:
        {
            //��������ѯѧ���������俼�Գɼ�
            int flag_9;
            flag_9 = SearchName_9(stu, n, m);
            if(flag_9==1) printf("Operation 9 finish correctly!\n");
            else          printf("Operation 9 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 10:
        {
            //�������
            int flag_10;
            flag_10 = DegreeDeal_10(stu, n, m);
            if(flag_10==1) printf("Operation 10 finish correctly!\n");
            else          printf("Operation 10 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu; //�������˵�
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }

    case 11:
        {
            int flag_11;
            flag_11 = PrintData_11(stu, n, m);
            if(flag_11==1) printf("Operation 11 finish correctly!\n");
            else           printf("Operation 11 finish wrongly!\n");

            {//ѯ���û��Ƿ񷵻ز˵�
            getchar();
            ansReturn = AnsforRe();
            if(*ansReturn=='Y')
            {
                goto Menu;
            }
            if(*ansReturn=='N')
            {
                printf("See you next time!\n");
                break;
            }
            if(*ansReturn!='Y'&&*ansReturn!='N')
            {
                printf("RETURN FAILURE, BREAK!\n");
                break;
            }
            }
        }
    case 0:
        {
            printf("See you next time!\n");
            break;
        }
    default:
        {
            printf("INPUT ERROR!\n");
            break;
        }
    }
    return 0;
}


//�������ܣ���ӡ�˵�
int *ShowMenu(void)
{
    int Order;
    int *pOrder = &Order;
    printf("===============================================================\n");
    printf("                    **Student Score System**                   \n");
    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("0. Exit\n");
    printf("===============================================================\n");
    printf("Please enter your choice:");
    scanf("%d", &Order);
    return pOrder;
}

//�������ܣ����û������Ƿ񷵻����˵��Ļش�������Ӧ
char *AnsforRe(void)
{
    char ans;
    char *ansRe = &ans;
    printf("Do you want to return to the menu?(Y/N)");
    scanf("%c", &ans);
    return ansRe;
}

//1.�������ܣ�¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
int ReadData_1(STUDENT stu[], int n, int m)
{
    int i, j; //iΪ����ѭ����jΪ�γ�ѭ��
    int flag = 0;
    printf("Please input data in following form:\n");
    printf("Input record n:NAME\t\tID\t\tSCORE\n");
    for(i = 0; i < n; i++)
    {
        printf("Input record %d:", i+1);
        scanf("%s", stu[i].stuName);
        scanf("%ld", &stu[i].stuID);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &stu[i].score[j]);
            flag = 1;
        }
    }
    return flag;
}

//2.�������ܣ�����ÿ�ſγ̵��ֺܷ�ƽ����
int CourseSumAver_2(STUDENT stu[], int sumC[], float averC[], int n, int m)
{
    int i, j;
    int flag = 0;
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            sumC[j] = sumC[j] + stu[i].score[j];
            flag = 1;
        }
        averC[j] = (float)sumC[j] / n;
        printf("Subject %d:Sum = %d, Average = %f\n", j+1, sumC[j], averC[j]);
    }
    return flag;
}

//3.�������ܣ�����ÿ��ѧ�����ֺܷ�ƽ����
int StuSumAver_3(STUDENT stu[], int n, int m)
{
    int i, j;
    int flag = 0;
    printf("NAME\t\tID\t\tSUM\t\tAVER:\n");
    for(i = 0; i < n; i++)
    {
        //��ʼ��Ϊ0
        stu[i].stuSum = 0;
        stu[i].stuAver = 0;

        for(j = 0; j < m; j++)
        {
            stu[i].stuSum = stu[i].stuSum + stu[i].score[j];
            flag = 1;
        }
        stu[i].stuAver = (float)stu[i].stuSum / m;
        printf("%s\t\t%ld\t\t%d\t\t%f\n", stu[i].stuName, stu[i].stuID, stu[i].stuSum, stu[i].stuAver);
    }
    return flag;
}

//4.�������ܣ���ÿ��ѧ�����ܷ��ɸߵ����ų����α�
int DescendScore_4(STUDENT stu[], int n, int m)
{
    //ע�⣺�ṹ�������г�Ա��Ҫ�������������׷�����λ
    int p, q;
    int flag = 0;
    STUDENT tempStu;
    for(p = 0; p < n - 1; p++)
    {
        for(q = p + 1; q < n; q++)
        {
            if(stu[p].stuSum < stu[q].stuSum) //���������������
            {
                tempStu = stu[q];
                stu[q] = stu[p];
                stu[p] = tempStu;
            }
            flag = 1;
        }
    }
    return flag;
}

//5.�������ܣ���ÿ��ѧ�����ܷ��ɵ͵����ų����α�
int AscendScore_5(STUDENT stu[], int n, int m)
{
    //ע�⣺�ṹ�������г�Ա��Ҫ�������������׷�����λ
    int p, q;
    int flag = 0;
    STUDENT tempStu;
    for(p = 0; p < n - 1; p++)
    {
        for(q = p + 1; q < n; q++)
        {
            if(stu[p].stuSum > stu[q].stuSum) //���������������
            {
                tempStu = stu[q];
                stu[q] = stu[p];
                stu[p] = tempStu;
            }
            flag = 1;
        }
    }
    return flag;
}

//6.�������ܣ���ÿ��ѧ����ѧ����С�����ų��ɼ���
int AscendNum_6(STUDENT stu[], int n, int m)
{
    //ע�⣺�ṹ�������г�Ա��Ҫ�������������׷�����λ
    int p, q;
    int flag = 0;
    STUDENT tempStu;
    for(p = 0; p < n - 1; p++)
    {
        for(q = p + 1; q < n; q++)
        {
            if(stu[p].stuID > stu[q].stuID) //���������������
            {
                tempStu = stu[q];
                stu[q] = stu[p];
                stu[p] = tempStu;
            }
            flag = 1;
        }
    }
    return flag;
}

//7.�������ܣ��������ֵ�˳���ų��ɼ���
int AscendName_7(STUDENT stu[], int n, int m)
{
    //ע�⣺�ṹ�������г�Ա��Ҫ�������������׷�����λ
    int p, q;
    int flag = 0;
    STUDENT tempStu;
    for(p = 0; p < n - 1; p++)
    {
        for(q = p + 1; q < n; q++)
        {
            if(strcmp(stu[p].stuName, stu[q].stuName) > 0) //���������������
            {
                tempStu = stu[q];
                stu[q] = stu[p];
                stu[p] = tempStu;
            }
            flag = 1;
        }
    }
    return flag;
}

//8.�������ܣ���ѧ�Ų�ѯѧ���������俼�Գɼ�
int SearchNum_8(STUDENT stu[], int n, int m)
{
    int i, j;
    int flag = 0;
    int find = -1;
    int under;
    long lookfor = 0;
    char ansforContinue = '0';
    do{
        printf("Please input the ID:");
        scanf("%ld", &lookfor);
        for(i = 0; i < n; i++)
        {
            if(lookfor==stu[i].stuID)
            {
                find = 1;
                under = i; //�����±�
                break;
            }
            else find = 0;
        }
        if(find==1)
        {
            printf("NAME\t\tID\t\tSCORE:\n");
            printf("%s\t\t%ld\t\t", stu[under].stuName, stu[under].stuID);
            for(j = 0; j < m; j++)
            {
                printf("%d ", stu[under].score[j]);
                flag = 1;
            }
            printf("\n");
            find = -1; //��find��Ϊ-1
        }
        if(find==0)
        {
            printf("I'm so sorry that the student you look for is not existed...\n");
            flag = 1;
        }

        printf("Do you want to continue?(Y/N)");
        getchar();
        scanf("%c", &ansforContinue);
        if(ansforContinue!='Y'&&ansforContinue!='N')
        {
            printf("I don't know what you mean...\nSorry I have to leave!\n");
            break;
        }
    }while(ansforContinue=='Y');
    return flag;
}

//9.�������ܣ���������ѯѧ���������俼�Գɼ�
int SearchName_9(STUDENT stu[], int n, int m)
{
    int flag = 0;
    int i;
    int find = -1;
    int under = 100;
    char lookfor[NAME_MAX];
    printf("Input the name:");
    scanf("%s", lookfor);
    for(i = 0; i < n; i++)
    {
        if(strcmp(lookfor, stu[i].stuName)==0)
        {
            under = i;
            find = 1;
            break;
        }
        else find = 0;
    }
    if(find == 1)
    {
        printf("NAME\t\tID\t\tSCORE:\n");
        printf("%s\t\t%ld\t\t", stu[under].stuName, stu[under].stuID);
        for(int j = 0; j < m ; j++)
        {
            printf("%d ", stu[under].score[j]);
            flag = 1;
        }
        printf("\n");
    }
    if(find == 0)
    {
        printf("Sorry, the student you find is not existed...\n");
        flag = 1;
    }
    return flag;
}

//10.�������ܣ������㣨90-100�֡����ã�80-89�֣����еȣ�70-79�֣�������60 -69�֣���������(0-59 ��)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
int DegreeDeal_10(STUDENT stu[], int n, int m)
{
    int counter[COURSE_N][5] = {0};
    float rate[COURSE_N][5] = {0};
    int flag = 0;
    int i, j, k;
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(stu[i].score[j]>=90&&stu[i].score[j]<=100) counter[j][0]++;
            if(stu[i].score[j]>=80&&stu[i].score[j]<=89)  counter[j][1]++;
            if(stu[i].score[j]>=70&&stu[i].score[j]<=79)  counter[j][2]++;
            if(stu[i].score[j]>=60&&stu[i].score[j]<=69)  counter[j][3]++;
            if(stu[i].score[j]>=0&&stu[i].score[j]<=59)   counter[j][4]++;
            flag = 1;
        }
        for(k = 0; k < 5; k++)
        {
            rate[j][k] = (float)counter[j][k] / n;
        }
    }
    for(j = 0; j < m; j++)
    {
        printf("Subject%d:T1 = %d, T2 = %d, T3 = %d, T4 = %d, T5 = %d\n", j+1, counter[j][0], counter[j][1], counter[j][2], counter[j][3], counter[j][4]);
        printf("         R1 = %.2f, R2 = %.2f, R3 = %.2f, R4 = %.2f, R5 = %.2f\n", rate[j][0], rate[j][1], rate[j][2], rate[j][3], rate[j][4]);
    }
    return flag;
}

//11.�������ܣ����ÿ��ѧ����ѧ�š����������ƿ��Գɼ�
int PrintData_11(STUDENT stu[], int n, int m)
{
    int i, j;
    int flag = 0;
    printf("Output in following form:\n");
    printf("NAME\t\tID\t\tScore:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t\t%ld\t\t", stu[i].stuName, stu[i].stuID);
        for(j = 0; j < m; j++)
        {
            printf("%4d ", stu[i].score[j]);
            flag = 1;
        }
        printf("\n");
    }
    return flag;
}
