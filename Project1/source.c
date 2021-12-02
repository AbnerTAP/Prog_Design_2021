#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#define SIZE 1000
static char mingzi[20];
char input[8]; 
char path1[1000];
char path2[1000];
void printInfo();
void Register();
void Secretword(char key[]);
int Strong(char Keystrong[]);
void Login();
void RegisterorLogin();
void Menu();
void Visit();
void Vocabulary();
void danciyulanordancixuexi();
void Choice();
void Text();
void cuotiben();
void Exit();
void delword();
void addword();
void addnewzw();
void changeword();
void Again();
void Do_Again_Choice();
void Do_Again_Text();
void chart_c();
void Scoreboard();
void Punch();
void Cuoti_Choice();
void Cuoti_Again();

typedef struct User_data
{
	char name[20];
	char password[8];
	int score;
	int dkts;
	int dktm_year;
	int dktm_mon;
	int dktm_day;
}sj;
sj User[1000]; 
typedef struct word
{
	int j;
	char px[500];
	char cx[500];
	char zw[500];
}dcxx;
dcxx dcsj[1000], ct[9000], ct_new[9000], ct_ag[9000], ct_bk[9000], ctyy[9000], sample[1000];

int main()
{
	RegisterorLogin();
	Menu();
	Exit();
	return 0;
}
void RegisterorLogin()
{
	int i;
	printInfo();                       
	scanf("%d", &i);
	system("cls");
	if (i == 1 || i == 2 || i == 3|| i == 4)
	{
		switch (i)
		{
		case 1: Register(); break;
		case 2: Login(); break;
		case 3: chart_c(); break;
		case 4: exit(0); break;
		}
	}
	else
	{
		printf("请选择正确的数字。\n");
		printf("请按任意键返回重新输入。\n");
		getchar(); getchar();
		system("cls");
		RegisterorLogin();
	}

}
void Register()
{
	int dk = 0, i = 0, j = 0, k = 0, check = 0, KeyStrong_check = 0,all;
	char User_Name[20], Key1[20], Key2[20], Key3[20], Key_Fin[20], Confirm[10], Confirm1[10];
	char dir1[1000], txt2[1000], txt3[1000];
	FILE* fp; FILE* fp1; FILE* fp2; FILE* fp3;
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d", User[i].name, User[i].password, &User[i].dkts);
		i++;
	}

	printf("请输入你的用户名:\n");
	for (j = 0; j < 1000; j++)
	{
		scanf("%s", User_Name);
		for (k = 0; k <= i; k++)
		{
			if (!strcmp(User_Name, User[k].name))
			{
				printf("已存在该用户名，请重新输入:\n");
				break;
			}
		}
		if (strcmp(User_Name, User[k++].name))
			break;
	}

	printf("请输入密码:\n"); Secretword(Key1); 
	KeyStrong_check = Strong(Key1);
	while (KeyStrong_check == 1)
	{
		printf("是否重新键入的密码：\n");
		printf("键入Y或y重新键入，键入其他继续\n");
		scanf("%s", Confirm1);
		if (!strcmp(Confirm1, "Y") || !strcmp(Confirm1, "y"))
		{
			printf("请重新输入密码：");
			Secretword(Key1);
			KeyStrong_check = Strong(Key1);
		}
		else
			break;
	}
	printf("请确认密码:\n"); Secretword(Key2); 
	if (!strcmp(Key1, Key2))
	{
		strcpy(Key_Fin, Key1);
		printf("注册成功!请按任意键返回主页面进行登录！");
		getchar(); getchar();
	}
	else
	{
		printf("是否显示第一次输入的密码：\n");
		printf("键入Y或y显示，键入其他重新输入\n");
		scanf("%s", Confirm);
		if (!strcmp(Confirm, "Y") || !strcmp(Confirm, "y"))
		{
			printf("您刚刚输入的是：\n");
			printf("%s\n", Key1);
		}
		printf("请再次确认密码:\n");
		Secretword(Key3);
		if (!strcmp(Key1, Key3))    //若第一次不一致则需第二次确认一致。
		{
			strcpy(Key_Fin, Key1);
			printf("注册成功!请按任意键返回主页面进行登录！");
			getchar(); getchar();
		}
		else
		{
			printf("注册失败!\n是否重新注册？\n");
			printf("键入Y或y重新注册，键入其他返回上一级\n");
			Again();
		}
	}

	fprintf(fp, "%s %s %d %d %d %d %d\n", User_Name, Key_Fin, dk, 0, 0, 0, 0);

	sprintf(dir1, "D:\\Desktop\\PROG_DATA\\%s", User_Name);_mkdir(dir1);

	i = 0;
	fp1 = fopen("D:\\Desktop\\PROG_DATA\\Word_Book_sample.txt", "r");
	while (!feof(fp1))
	{
		fscanf(fp1, "%d%s%s%s", &sample[i].j, sample[i].px, sample[i].cx, sample[i].zw);
		i++;
	}
	all = i - 1;

	sprintf(txt2, "D:\\Desktop\\PROG_DATA\\%s\\%s.txt", User_Name,"Word_Book"); 
	fp2 = fopen(txt2, "w+");
	for (i = 0; i < all; i++)
	{
		fprintf(fp2, "%d %s %s %s\n", i + 1, sample[i].px, sample[i].cx, sample[i].zw);
	}

	sprintf(txt3, "D:\\Desktop\\PROG_DATA\\%s\\%s.txt", User_Name, "Wrong_Collection"); fp3 = fopen(txt3, "w+");
	fclose(fp); fclose(fp1); fclose(fp2); fclose(fp3);
	system("cls");
	RegisterorLogin();
	}
void Secretword(char key[])
{
	char c;
	int i = 0;
	while ((c = _getch()) != '\r') 
	{
		if (i < 100 && isprint(c)) 
		{
			key[i] = c;
			i++;
			putchar('*');
		}
		else if (i > 0 && c == '\b') {
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	printf("\n");
	key[i] = '\0';
}
int Strong(char Keystrong[])
{
	int i, t = 0, zimu = 0, shuzi = 0, fuhao = 0, sum = 0, Sum = 0, Re = 0;
	for (i = 0; ; i++)
	{
		if (Keystrong[i] == '\0')
			break;
		if (Keystrong[i] >= 'a' && Keystrong[i] <= 'z')
			zimu = 1;
		if (Keystrong[i] >= 48 && Keystrong[i] <= 57)
			shuzi = 1;
		else
			fuhao = 1;
	}
	t = i;
	if (t >= 8)
		sum = 1;
	Sum = sum + zimu + shuzi + fuhao;
	if (Sum == 1 || (Sum == 2 && t >= 8) || t <= 4)
	{
		printf("\033[31;5m你的密码强度较弱\033[0m\n");
		Re = 1;
		return Re;
	}
	if ((Sum == 2 && shuzi == 1 && zimu == 1) || Sum == 3)
		printf("\033[36m你的密码强度中等\033[0m\n");
	if (Sum == 4)
		printf("\033[32m你的密码强度较强\033[0m\n");

}
void Again()
{
	char Confirm[10]; 
	scanf("%s", Confirm);
	system("cls");
	if (!strcmp(Confirm, "Y") || !strcmp(Confirm, "y"))
		Register(); 
	else
		RegisterorLogin(); system("cls"); 
}
void Login()
{
	int ch = 0;
	int i = 0;
	FILE* fp;
	printf("请输入用户名登录:\n");
	scanf("%s", mingzi);
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%d%d%d", User[i].name, User[i].password, &User[i].score, &User[i].dkts, &User[i].dktm_year, &User[i].dktm_mon, &User[i].dktm_day);
		i++;
	}
	fclose(fp);
	for (i = 0; i < 1000; i++)
	{
		if (!strcmp(mingzi, User[i].name))
		{
			ch = 1;
			printf("请输入密码（2次机会）：\n");
			Secretword(input);
			if (!strcmp(input, User[i].password))
			{
				printf("登录成功！（请按回车继续）\n");
				getchar(); getchar();
				break;
			}
			else
			{
				printf("密码错误，请重新输入：\n");
				Secretword(input);
				if (!strcmp(input, User[i].password))
				{
					printf("登录成功！请按任意键继续\n");
					getchar(); getchar(); 
					break;
				}
				else
				{
					printf("输入错误次数过多，按任意键返回主界面！\n");
					getchar(); getchar(); 
					system("cls"); RegisterorLogin(); 
				}
			}
		}
	}
	if (ch == 0)
	{
		printf("无此用户名，请按任意键进入注册界面！\n"); getchar(); getchar();
		system("cls");
		Register();
	}
}
void Menu()
{
	system("cls");
	int i;
	do {
		printf("******************************\033[31;5m主菜单\033[0m******************************\n");
		printf("·1.查看单词本\n");
		printf("·2.编辑单词本\n");
		printf("·3.单词学习\n");
		printf("·4.查看错题集\n");
		printf("·5.退出\n");
		printf("请输入您的选择：");
		scanf("%d", &i);
		getchar();
		switch (i)         //菜单栏往下跳转
		{
		case 1:system("cls"); Visit(); break;
		case 2:system("cls"); Vocabulary();break;
		case 3:system("cls"); danciyulanordancixuexi(); break;
		case 4:system("cls"); cuotiben(); break;
		case 5:system("cls"); Exit(); break;
		default:printf("请输入正确的选择!\n");
		}

	} while (i);
}

void Visit()
{
	int i = 0, k=0, count=0;
	char yhxz = 0, dy;
	dcxx dcsj[1000];
	FILE* fp;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d %[a-z] %s %s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx,dcsj[i].zw);
		i++;
	}
	count = i-1;
	printf("单词本如下：\n\n");
	while (k< count)
	{
		printf("%d\t%s\t%s\t%s\n", dcsj[k].j, dcsj[k].px, dcsj[k].cx, dcsj[k].zw);
		k++;
	}
	printf("\n\n");
	printf("请按任意键继续！\n");
	getchar(); 
	system("cls");    //清屏
	Menu();
}

void Vocabulary()
{
	int i;
	do {
		printf("1.增加单词\n");
		printf("2.查找单词\n");
		printf("3.补充释义\n");
		printf("4.修改单词\n");
		printf("0.返回菜单\n");
		printf("请输入你的选择：");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:
			system("cls"); addword();
			break;
		case 2:
			system("cls"); addnewzw();
			break;
		case 3: 
			system("cls"); delword();
			break;
		case 4:
			system("cls"); changeword();
			break;
		case 0:
			system("cls");Menu();
			break;
		default:printf("请输入正确选项!\n");
		}

	} while (i);
}
void addword()
{
	int ch = 0, count = 0, j = 0, k = 0;
	char add_px[500], add_cx[500], add_zw[500];
	int i = 0;
	FILE* fp;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	count = i - 1;

	printf("请输入你要添加的单词的英文：\n");
	for (j = 0; j < 1000; j++)
	{
		scanf("%s", add_px);
		for (k = 0; k < count; k++)
		{
			if (!strcmp(add_px, dcsj[k].px))
			{
				printf("已存在该单词，请重新输入:\n");
				break;
			}
		}
		if (strcmp(add_px, dcsj[k++].px))
			break;
	}
	printf("请输入你要添加的单词的词性：\n");
	scanf("%s", add_cx);
	printf("请输入你要添加的单词的中文：\n");
	scanf("%s", add_zw);

	fprintf(fp, "%d %s %s %s\n", count+2, add_px, add_cx, add_zw);
	fclose(fp);
	printf("添加成功！请按任意键返回上级目录！\n");
	getchar(); getchar();
	system("cls");
	Vocabulary();
}
void delword()
{
	int ch = 0, count = 0, count1 = 0, k = 0, i = 0;
	char del[500];
	FILE* fp; FILE* fp1;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s %s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	count = i - 1;
	fclose(fp);

	printf("请输入你要删除的单词（中文或英文）：\n");
	scanf("%s", del);

	for (i = 0; i < count; i++)
	{
		if (!strcmp(del, dcsj[i].px))
		{
			ch = 1;
			printf("已找到该单词并删除!\n");
			count1 = i;
			break;
		}
		if (!strcmp(del, dcsj[i].zw))
		{
			ch = 1;
			printf("已找到该单词并删除!\n");
			count1 = i;
			break;
		}
	}
	if (ch == 0)
	{
		printf("查不到该单词！请按任意键返回上一级！\n");
		getchar(); getchar();
		system("cls");
		Vocabulary();
	}
	
	dcsj[count].j = 0;
	strcpy(dcsj[count + 1].px, "###");
	strcpy(dcsj[count + 1].cx, "###");
	strcpy(dcsj[count + 1].zw, "###");
	for (i = count1; i < count; i++)
	{
		dcsj[i] = dcsj[i + 1];
	}
	count = i-1;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp1 = fopen(path1, "r");
	rewind(fp1);
	printf("更新后的单词表为：\n");
	while (k<count-1)
	{
		fprintf(fp1, "%d %s %s %s\n", k + 1, dcsj[k].px, dcsj[k].cx, dcsj[k].zw);
		printf("%d %s %s %s\n", k + 1, dcsj[k].px, dcsj[k].cx, dcsj[k].zw);
		k++;
	};
	fclose(fp1);
	printf("\n\n请按任意键返回上级目录！\n");
	getchar(); getchar();
	system("cls");
	Vocabulary();
}
void addnewzw()
{
	int ch = 0, count = 0, count1 = 0;
	char find[500];
	int i = 0;
	FILE* fp;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	fclose(fp);
	count = i;
	printf("请输入你要查找单词（中文或英文）：\n");
	scanf("%s", find);
	for (i = 0; i < count + 1; i++)
	{
		if (!strcmp(find, dcsj[i].px))
		{
			ch = 1;
			count1 = i; 
			break;
		}
		if (!strcmp(find, dcsj[i].zw))
		{
			ch = 1;
			count1 = i;
			break;
		}
	}
	printf("您所查找的单词为：\n");
	printf("%s %s %s\n", dcsj[count1].px, dcsj[count1].cx, dcsj[count1].zw);
	printf("请按任意键返回上级目录！\n");
	getchar(); getchar();
	system("cls");
	Vocabulary();
	if (ch == 0) 
	{
		printf("查不到该单词！\n");
		printf("请按任意键返回上级目录！\n");
		getchar(); getchar();
		system("cls");
		Vocabulary(); 
	}
}
void changeword()
{
	int count = 0, count1 = 0, k = 0, check;
	char change[500], new_change[500];
	int i = 0;
	FILE* fp;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	fclose(fp);
	count = i - 1;
	printf("请输入你要修改的单词（中文或英文）：\n");
	scanf("%s", change);
	for (i = 0; i < count + 1; i++)
	{
		if (!strcmp(change, dcsj[i].px))
		{
			count1 = i;
			break;
		}
		if (!strcmp(change, dcsj[i].zw))
		{
			count1 = i;
			break;
		}
	}
	printf("查找到单词为：\n");
	printf("%s %s %s\n", dcsj[count1].px, dcsj[count1].cx, dcsj[count1].zw);
	printf("您想修改的是：\n");
	printf("1.英文\n");
	printf("2.词性\n");
	printf("3.中文\n");
	scanf("%d", &check);
	printf("请输入您需要修改的内容：\n");
	scanf("%s", new_change);
	if (check == 1)
	{
		strcpy(dcsj[count1].px, new_change);
	}
	if (check == 2)
	{
		strcpy(dcsj[count1].cx, new_change);
	}
	if (check == 3)
	{
		strcpy(dcsj[count1].zw, new_change);
	}

	fp = fopen(path1, "w+");
	while (k < count)
	{
		fprintf(fp, "%d %s %s %s\n", k + 1, dcsj[k].px, dcsj[k].cx, dcsj[k].zw);
		k++;
	};
	fclose(fp);
	printf("\n\n\n修改成功\n请按任意键返回上级目录！\n");
	getchar(); getchar();
	system("cls");
	Vocabulary();
}
void danciyulanordancixuexi()
{
	int xz1, xz2, ch, i = 0, h = 0, t, a1, b1, c1, c2, count, count1 = 0, count2 = 0, score = 0, k = 0, zql, s = 0, m = 0;
	int check = 1;
	char yhxz, zq[2], dy, Confirm1[20];
	char dadj[4][100];
	int sjs1[1000], sjs2[1000], sjs3[5];
	char zwsr[100];
	FILE* fp; FILE* fp1; FILE* fp2; FILE* fp3;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	count = i - 1;
	fclose(fp);

	sprintf(path2, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fp1 = fopen(path2, "a+");
	while (!feof(fp1))
	{
		fscanf(fp1, "%d%s%s%s", &ct[m].j, ct[m].px, ct[m].cx, ct[m].zw);
		m++;
	}
	count2 = m;
	fclose(fp1);

	fp2 = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp2))
	{
		fscanf(fp2, "%s%s%d%d%d%d%d", User[s].name, User[s].password, &User[s].score, &User[s].dkts, &User[s].dktm_year, &User[s].dktm_mon, &User[s].dktm_day);
		s++;
	}
	count1 = s;
	fclose(fp2);

	printf("1.进行单词预览\n2.进行单词学习\n3.返回\n");
	scanf("%d", &ch);
	if (ch == 1)
	{
		printf("进行单词预览\n");
		while (k < count)
		{
			printf("%d\t%s\t%s\t%s\n", k + 1, dcsj[k].px, dcsj[k].cx, dcsj[k].zw);
			k++;
		}
		printf("单词预览结束，按任意键（除空格键）进入单词学习！\n");
		getchar(); getchar();
		system("cls");
	}
	if (ch == 2)
	{
		while (1)
		{
			system("cls");
			printf("请选择单词背诵模式:\n1.选择题背诵\n2.拼写单词背诵\n3.错题重做\n4.返回\n");
			scanf("%d", &a1);
			switch (a1)
			{
			case 1:system("cls"); Choice(); break;
			case 2:system("cls"); Text(); break;
			case 3:system("cls"); Cuoti_Again(); break;
			case 4:system("cls"); Menu(); break;
			}
		}
	}
	if (ch == 3)
	{
		system("cls");
		Menu();
	}
}

void Choice()
{
	int xz1, xz2, ch, i = 0, h = 0, t, a1, b1, c1, c2, count, count1 = 0, count2 = 0, score = 0, k = 0, zql, s = 0, m = 0,r,j;
	char yhxz, zq[2], dy;
	char dadj[4][100];
	int sjs1[1000], sjs2[1000], sjs3[5];
	char zwsr[100];
	srand(time(NULL));
	FILE* fp; FILE* fp1; FILE* fp2; FILE* fp3;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	count = i - 1;
	fclose(fp);

	sprintf(path2, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fp1 = fopen(path2, "a+");
	while (!feof(fp1))
	{
		fscanf(fp1, "%d%s%s%s", &ct[m].j, ct[m].px, ct[m].cx, ct[m].zw);
		m++;
	}
	count2 = m;
	fclose(fp1);

	fp2 = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp2))
	{
		fscanf(fp2, "%s%s%d%d%d%d%d", User[s].name, User[s].password, &User[s].score, &User[s].dkts, &User[s].dktm_year, &User[s].dktm_mon, &User[s].dktm_day);
		s++;
	}
	count1 = s;
	fclose(fp2); system("cls");
	printf("进行选择题背诵,请输入单词背诵组数(一组10个)：\n");
	scanf("%d", &c2);
	c1 = c2 * 10;

	r = rand() % count;
	sjs1[0] = r;
	b1 = 1;

	while (b1 < c1)
	{
		r = rand() % count;
		for (j = b1 - 1; j >= 0; j--)
		{
			if (r == sjs1[j])
				break;
		}
		if (r == sjs1[0])
			j = c1;
		j = j - 1;
		if (j < 0)
		{
			sjs1[b1] = r;
			b1++;
		}
	}
	system("cls");
	for (b1 = 0; b1 < c1; b1++)
	{
		do {
			for (i = 0; i < 3; i++)
			{
				sjs2[i] = rand() % count;
			}
		} while (sjs2[0] == sjs2[1] || sjs2[0] == sjs2[2] || sjs2[0] == sjs1[b1] || sjs2[1]
			== sjs2[2] || sjs2[1] == sjs1[b1] || sjs2[2] == sjs1[b1]);
		do {
			for (i = 0; i < 4; i++)
			{
				sjs3[i] = rand() % 4 + 1;
			}
		} while (sjs3[0] == sjs3[1] || sjs3[0] == sjs3[2] || sjs3[0] == sjs3[3] || sjs3[1]
			== sjs3[2] || sjs3[1] == sjs3[3] || sjs3[2] == sjs3[3]);
		strcpy(dadj[sjs3[0] - 1], dcsj[sjs2[0]].zw);
		strcpy(dadj[sjs3[1] - 1], dcsj[sjs1[b1]].zw);
		strcpy(dadj[sjs3[2] - 1], dcsj[sjs2[1]].zw);
		strcpy(dadj[sjs3[3] - 1], dcsj[sjs2[2]].zw);
		printf("单词：\t%s\n词性：\t%s\n选项：\nA.\t%s\nB.\t%s\nC.\t%s\nD.\t%s\n请输入您的选项(A/B/C/D)：\t", dcsj[sjs1[b1]].px, dcsj[sjs1[b1]].cx, dadj[0], dadj[1], dadj[2], dadj[3]);
		t = sjs3[1] - 1;
		switch (t)
		{
		case 0:zq[0] = 'A', zq[1] = 'a'; break;
		case 1:zq[0] = 'B', zq[1] = 'b'; break;
		case 2:zq[0] = 'C', zq[1] = 'c'; break;
		case 3:zq[0] = 'D', zq[1] = 'd'; break;
		}
		scanf("%s", &yhxz);
		if (yhxz >= 'a' && yhxz <= 'd')
		{
			zql = zq[1];
		}
		else {
			zql = zq[0];
		}
		
		if (yhxz != zql)
		{
			score -= 10;
			printf("背诵错误，已计入错题本！请继续加油\n很遗憾，积分-10\n\n");
			printf("%s（词性：%s）的中文释义为：\n%s\n",dcsj[sjs1[b1]].px, dcsj[sjs1[b1]].cx, dcsj[sjs1[b1]].zw);
			ct_new[h] = dcsj[sjs1[b1]];
			h++;
		}
		else
		{
			printf("背诵正确，请继续答题！\n10积分get！\n");
			score += 10;
		}
		getchar(); 
		system("cls");
	}
	for (i = 0; i < count1; i++)
	{
		if (!strcmp(mingzi, User[i].name))
		{
			break;
			{
				User[i].score += score;
			}
		}
	}
	if (score == 10 * c1)
	{
		printf("您本次回答完全正确，获得积分%d，加油！\n", score);
		getchar(); getchar();
	}
	else
	{
		printf("您本次错题如下：\n");
		for (i = 0; i < h; i++)
			printf("%d %s %s %s\n", i + 1, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
		printf("您错误的题数为： %d\n您本次的得分为：%d分。\n", h, score);
		}
	printf("您目前总积分为：");
	for (i = 0; i < count; i++)
	{
		if (!strcmp(mingzi, User[i].name))
		{
			{
				printf("%d分。\n", User[i].score);
			}
		}
		sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
		fp3 = fopen(path1, "a+");
		if (count2 < 2)
		{
			for (i = 0; i < h; i++)
				fprintf(fp3, "%d %s %s %s\n", i + 1, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
			fclose(fp3);
		}
		else
		{
			for (i = 0; i < h; i++)
			{
				for (k = 0; k < count2; k++)
				{
					if (!(strcmp(ct_new[i].px, ct[k].px)) && !(strcmp(ct_new[i].zw, ct[k].zw)))
					{
						strcpy(ct_new[i].px, "***");
						break;
					}
				}
			}
			for (i = 0; i < h; i++)
			{
				if (strcmp(ct_new[i].px, "***") != 0)
					fprintf(fp3, "%d %s %s %s\n", count2++, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
			}
			ct_new[2000] = ct_bk[2000];
			fclose(fp3);
		}
		getchar();
		while (score <= 0)
		{
			Cuoti_Choice(h);
		}
		getchar(); 
		Menu();
	}
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "a+");
	for (i = 0; i < count1 - 1; i++)
	{
		fprintf(fp, "%s %s %d %d %d %d %d\n", User[i].name, User[i].password, User[i].score, User[i].dkts, User[i].dktm_year, User[i].dktm_mon, User[i].dktm_day);
	}
	fclose(fp);
	getchar(); 
	system("cls");
	danciyulanordancixuexi();
}
void Text()
{
	int xz1, xz2, ch, i = 0, h = 0, t, a1, b1, c1, c2, count, count1 = 0, count2 = 0, score = 0, k = 0, zql, s = 0, m = 0, r, j;
	char yhxz, zq[2], dy;
	char dadj[4][100];
	int sjs1[1000], sjs2[1000], sjs3[5];
	char zwsr[100];
	srand(time(NULL));
	FILE* fp; FILE* fp1; FILE* fp2; FILE* fp3;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	count = i - 1;
	fclose(fp);

	sprintf(path2, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fp1 = fopen(path2, "a+");
	while (!feof(fp1))
	{
		fscanf(fp1, "%d%s%s%s", &ct[m].j, ct[m].px, ct[m].cx, ct[m].zw);
		m++;
	}
	count2 = m;
	fclose(fp1);

	fp2 = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp2))
	{
		fscanf(fp2, "%s%s%d%d%d%d%d", User[s].name, User[s].password, &User[s].score, &User[s].dkts, &User[s].dktm_year, &User[s].dktm_mon, &User[s].dktm_day);
		s++;
	}
	count1 = s;
	fclose(fp2); system("cls");
	printf("进行选择题背诵,请输入单词背诵组数(一组10个)：\n");
	scanf("%d", &c2);
	c1 = c2 * 10;

	r = rand() % count;
	sjs1[0] = r;
	b1 = 1;
	system("cls");
	while (b1 < c1)
	{
		r = rand() % count;
		for (j = b1 - 1; j >= 0; j--)
		{
			if (r == sjs1[j])
				break;
		}
		if (r == sjs1[0])
			j = c1;
		j = j - 1;
		if (j < 0)
		{
			sjs1[b1] = r;
			b1++;
		}
	}

	for (b1 = 0; b1 < c1; b1++)
	{
		printf("请输入%s(词性：%s)的英文：", dcsj[sjs1[b1]].zw, dcsj[sjs1[b1]].cx);
		scanf("%s", zwsr);
		if (strcmp(zwsr, dcsj[sjs1[b1]].px) != 0)
		{
			printf("背诵错误，已计入错题本！请继续加油\n很遗憾，积分-10\n\n");
			printf("正确答案是:%s哦\n",dcsj[sjs1[b1]].px);
			ct[h] = dcsj[sjs1[b1]];
			score -= 10;
		}
		else
		{
			printf("背诵正确，请继续答题！\n10积分get！\n");
			score += 10;
		}
		getchar(); getchar();
		system("cls");
	}
	for (i = 0; i < count1; i++)
	{
		if (!strcmp(mingzi, User[i].name))
		{
			break;
			{
				User[i].score += 10;
			}
		}
	}
	if (score == 10 * c1)
	{
		printf("您本次回答完全正确，获得积分%d，加油！\n", score);
		getchar(); getchar();
	}
	else
	{
		printf("您本次错题如下：\n");
		for (i = 0; i < h; i++)
			printf("%d %s %s %s\n", i + 1, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
		printf("您错误的题数为： %d\n您本次的得分为：%d分。\n", h, score);
	}
	printf("您目前总积分为：");
	for (i = 0; i < count; i++)
	{
		if (!strcmp(mingzi, User[i].name))
		{
			{
				printf("%d分。\n", User[i].score);
			}
		}
		sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
		fp3 = fopen(path1, "a+");
		if (count2 < 2)
		{
			for (i = 0; i < h; i++)
				fprintf(fp3, "%d %s %s %s\n", i + 1, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
			fclose(fp3);
		}
		else
		{
			for (i = 0; i < h; i++)
			{
				for (k = 0; k < count2; k++)
				{
					if (!(strcmp(ct_new[i].px, ct[k].px)) && !(strcmp(ct_new[i].zw, ct[k].zw)))
					{
						strcpy(ct_new[i].px, "***");
						break;
					}
				}
			}
			for (i = 0; i < h; i++)
			{
				if (strcmp(ct_new[i].px, "***") != 0)
					fprintf(fp3, "%d %s %s %s\n", count2++, ct_new[i].px, ct_new[i].cx, ct_new[i].zw);
			}
			ct_new[2000] = ct_bk[2000];
			fclose(fp3);
		}
		getchar();
		while (score <= 0)
		{
			Cuoti_Choice(h);
		}
		getchar();
		Menu();
	}
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "a+");
	for (i = 0; i < count1 - 1; i++)
	{
		fprintf(fp, "%s %s %d %d %d %d %d\n", User[i].name, User[i].password, User[i].score, User[i].dkts, User[i].dktm_year, User[i].dktm_mon, User[i].dktm_day);
	}
	fclose(fp);
	getchar();
	system("cls");
	danciyulanordancixuexi();
}
void Cuoti_Choice()
{
	int check = 1;
	char Confirm1[20];
	getchar();
	system("cls");
	printf("您是否选择错题重做？");
	printf("键入Y或y重新键入，键入其他返回\n");
	scanf("%s", Confirm1);
	if (!strcmp(Confirm1, "Y") || !strcmp(Confirm1, "y"))
	{
		system("cls"); Cuoti_Again();
	}
	else
		system("cls");
		Menu();
}
void Cuoti_Again()
{
	int Confirm2;
	printf("请选择重做的类型：\n");
	printf("1.选择题\n");
	printf("2.填空题\n");
	scanf("%d", &Confirm2);
	switch (Confirm2)
	{
	case 1: system("cls"); Do_Again_Choice(); break;
	case 2: system("cls"); Do_Again_Text(); break;
	}
}
void Do_Again_Choice()
{
	int i = 0, d1 = 0, j = 0, sjs4[100], sjs5[100], sjs6[100], dadj2[100][4], r, t, score = 0, countt, h_n = 0, k,countw;
	char yhxz = 0, zq1, zq[2];
	srand(time(NULL));
	FILE* fpK; FILE* fpM; FILE* fp;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fpK = fopen(path1, "r");
	while (!feof(fpK))
	{
		fscanf(fpK, "%d%s%s%s", &ctyy[i].j, ctyy[i].px, ctyy[i].cx, ctyy[i].zw);
		i++;
	}
	countt = i-1;
	
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	countw = i - 1;
	fclose(fp);
	if (countt == 0)
	{
		printf("暂时没有错题哦！\n快去练习吧！\n");
		getchar(); getchar();
		system("cls");
		danciyulanordancixuexi();
	}
	else
	{
		r = rand() % countt;
		sjs4[0] = r;
		d1 = 1;
		while (d1 < countt)
		{
			r = rand() % countt;
			for (j = d1 - 1; j >= 0; j--)
			{
				if (r == sjs4[j])
					break;
			}
			if (r == sjs4[0])
				j = 8;
			j = j - 1;
			if (j < 0)
			{
				sjs4[d1] = r;
				d1++;
			}
		}

		for (d1 = 0; d1 < countt; d1++)
		{
			do {
				for (i = 0; i < 3; i++)
				{
					sjs5[i] = rand() % countw;
				}
			} while (sjs5[0] == sjs5[1] || sjs5[0] == sjs5[2] || sjs5[1] == sjs5[2] || !strcmp(dcsj[sjs5[0]].zw, ctyy[sjs4[d1]].zw) || !strcmp(dcsj[sjs5[1]].zw, ctyy[sjs4[d1]].zw) || !strcmp(dcsj[sjs5[2]].zw, ctyy[sjs4[d1]].zw));
			do {
				for (i = 0; i < 4; i++)
				{
					sjs6[i] = rand() % 4 + 1;
				}
			} while (sjs6[0] == sjs6[1] || sjs6[0] == sjs6[2] || sjs6[0] == sjs6[3] || sjs6[1] == sjs6[2] || sjs6[1] == sjs6[3] || sjs6[2] == sjs6[3]);

			strcpy(dadj2[sjs6[0] - 1], dcsj[sjs5[0]].zw);
			strcpy(dadj2[sjs6[1] - 1], ctyy[sjs4[d1]].zw);
			strcpy(dadj2[sjs6[2] - 1], dcsj[sjs5[1]].zw);
			strcpy(dadj2[sjs6[3] - 1], dcsj[sjs5[2]].zw);

			printf("单词：\t%s\n词性：\t%s\n选项：\nA.\t%s\nB.\t%s\nC.\t%s\nD.\t%s\n请输入您的选项(A/B/C/D)：\t", ctyy[sjs4[d1]].px, ctyy[sjs4[d1]].cx, dadj2[0], dadj2[1], dadj2[2], dadj2[3]);
			t = sjs6[1] - 1;
			switch (t)
			{
			case 0:zq[0] = 'A', zq[1] = 'a'; break;
			case 1:zq[0] = 'B', zq[1] = 'b'; break;
			case 2:zq[0] = 'C', zq[1] = 'c'; break;
			case 3:zq[0] = 'D', zq[1] = 'd'; break;
			}
			scanf("%s", &yhxz);
			if (yhxz >= 'a' && yhxz <= 'd')
			{
				zq1 = zq[1];
			}
			else
			{
				zq1 = zq[0];
			}
			if (yhxz != zq1)
			{
				printf("背诵错误，已计入错题本！请继续加油\n很遗憾，积分-10\n\n");
				printf("%s（词性：%s）的中文释义为：\n%s\n", ctyy[sjs4[d1]].px, ctyy[sjs4[d1]].cx, ctyy[sjs4[d1]].zw);
				score -= 10;
				ct_ag[h_n] = ctyy[sjs4[d1]];
				h_n++;
			}
			else
			{
				printf("背诵正确，请继续答题！\n10积分get！\n");
				score += 10;
				strcpy(ctyy[sjs4[d1]].px, "###");
			}
			getchar(); getchar();
			system("cls");
		}
		if (h_n == 0)
		{
			printf("完全正确！错题本已清空！\n继续加油！！ヾ(◍°∇°◍)ﾉﾞ\n");
			sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
			fpM = fopen(path1, "w+");
			fclose(fpM);
			getchar(); getchar();
			system("cls");
			Menu();
		}

		else
		{
			k = 0;
			sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
			fpM = fopen(path1, "w+");
			for (i = 0; i < h_n; i++)
			{
				fprintf(fpM, "%d %s %s %s\n", k + 1, ct_ag[i].px, ct_ag[i].cx, ct_ag[i].zw);
				k++;
			}
			fclose(fpM);
			printf("错题如下：\n");
			for (i = 0; i < h_n; i++)
			{
				printf("%d %s %s %s\n", i + 1, ct_ag[i].px, ct_ag[i].cx, ct_ag[i].zw);
			}
			printf("您错误的题数为： %d\n您的得分为：%d\n", h_n, score);
			Cuoti_Choice(h_n);
		}
		fclose(fpK);
	}
}
void Do_Again_Text()
{
	int i = 0, d1 = 0, j = 0, sjs4[100], sjs5[100], sjs6[100], dadj2[100][4], r, t, score = 0, countt, h_n = 0, k, countw;
	char yhxz = 0, zq1, zq[2];
	char zwsr[500];
	FILE* fpK; FILE* fpM; FILE* fp;
	srand(time(NULL));
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fpK = fopen(path1, "r");
	while (!feof(fpK))
	{
		fscanf(fpK, "%d%s%s%s", &ctyy[i].j, ctyy[i].px, ctyy[i].cx, ctyy[i].zw);
		i++;
	}
	countt = i - 1;

	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Word_Book.txt", mingzi);
	fp = fopen(path1, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	countw = i - 1;
	fclose(fp);
	if (countt == 0)
	{
		printf("暂时没有错题哦！\n快去练习吧！\n");
		getchar(); getchar();
		system("cls");
		danciyulanordancixuexi();
	}
	else
	{
		r = rand() % countt;
		sjs4[0] = r;
		d1 = 1;
		while (d1 < countt)
		{
			r = rand() % countt;
			for (j = d1 - 1; j >= 0; j--)
			{
				if (r == sjs4[j])
					break;
			}
			if (r == sjs4[0])
				j = 8;
			j = j - 1;
			if (j < 0)
			{
				sjs4[d1] = r;
				d1++;
			}
		}

		for (d1 = 0; d1 < countt; d1++)
		{
			printf("请输入%s(词性：%s)的英文：", ctyy[sjs4[d1]].zw, ctyy[sjs4[d1]].cx);
			scanf("%s", zwsr);
			if (strcmp(zwsr, ctyy[sjs4[d1]].px) != 0)
			{
				printf("背诵错误，已计入错题本！请继续加油\n很遗憾，积分-10\n\n");
				printf("正确答案是:%s哦\n", ctyy[sjs4[d1]].px);
				score -= 10;
				ct_ag[h_n] = ctyy[sjs4[d1]];
				h_n++;
			}
			else
			{
				printf("背诵正确，请继续答题！\n10积分get！\n");
				score += 10;
				strcpy(ctyy[sjs4[d1]].px, "###");
			}
			getchar(); getchar();
			system("cls");
		}
		if (h_n == 0)
		{
			printf("完全正确！错题本已清空！\n继续加油！！ヾ(◍°∇°◍)ﾉﾞ\n");
			sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
			fpM = fopen(path1, "w+");
			fclose(fpM);
			getchar(); getchar();
			system("cls");
			Menu();
		}

		else
		{
			k = 0;
			sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
			fpM = fopen(path1, "w+");
			for (i = 0; i < h_n; i++)
			{
				fprintf(fpM, "%d %s %s %s\n", k + 1, ct_ag[i].px, ct_ag[i].cx, ct_ag[i].zw);
				k++;
			}
			fclose(fpM);
			printf("错题如下：\n");
			for (i = 0; i < h_n; i++)
			{
				printf("%d %s %s %s\n", i + 1, ct_ag[i].px, ct_ag[i].cx, ct_ag[i].zw);
			}
			printf("您错误的题数为： %d\n您的得分为：%d\n", h_n, score);
			Cuoti_Choice(h_n);
		}
		fclose(fpK);
	}
}

void cuotiben()
{
	int i = 0;
	FILE* fp;
	sprintf(path1, "D:\\Desktop\\PROG_DATA\\%s\\Wrong_Collection.txt", mingzi);
	fp = fopen(path1, "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%d%s%s%s", &dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
		i++;
	}
	fclose(fp);
	dcsj[i].j = 0;
	if (i == 0)
	{
		printf("暂时没有错题哦！\n快去练习吧！\n");
		getchar(); getchar();
		system("cls");
		Menu();
	}
	else
	{
		i = 0;
		printf("错题本如下：\n");
		printf("编号\t英文\t词性\t中文\n");
		while (dcsj[i].j != 0)
		{
			printf("%d\t%s\t%s\t%s\n", dcsj[i].j, dcsj[i].px, dcsj[i].cx, dcsj[i].zw);
			i++;
		}
		printf("\n\n\n\n\n");
		getchar();
		Menu();
	}
	
}

void chart_c()
{
	int i;
	printf("1.积分榜\n");
	printf("2.打卡榜\n");
	printf("3.返回主页面。\n");
	printf("请选择您想查看的榜单。\n");
	scanf("%d", &i);
	system("cls");
	if (i == 1 || i == 2 || i == 3)
	{
		switch (i)
		{
		case 1: Scoreboard(); break;
		case 2: Punch(); break;
		case 3: RegisterorLogin(); break;
		}
	}
	else
	{
		printf("请选择正确的数字。\n");
		printf("按任意键返回输入。\n");
		getchar(); getchar();
		system("cls");
		chart_c();
		system("cls");
	}
}
void Scoreboard()
{
	int i = 0, count, k = 1;
	FILE* fp;
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%d%d%d", User[i].name, User[i].password, &User[i].score, &User[i].dkts, &User[i].dktm_year, &User[i].dktm_mon, &User[i].dktm_day);
		i++;
	}
	count = i - 1;
	fclose(fp);
	if (count == 0)
	{
		printf("暂时还没有注册用户，快去注册学习吧！");
		getchar(); getchar();
		system("cls"); RegisterorLogin(); 

	}
	else
	{
		for (i = 0; i < count; i++)
		{
			for (int j = 0; j < count - i - 1; j++)
			{
				if (User[j + 1].score > User[j].score)
				{
					sj md = User[j];
					User[j] = User[j + 1];
					User[j + 1] = md;
				}
			}
		}
		printf("名次\t用户名\t积分\n");
		for (i = 0; i < count; i++)
		{
			printf("%d\t%s\t%d\n", k, User[i].name, User[i].score);
			if (User[i].score > User[i + 1].score)
				k++;
		}
		printf("请按任意键返回上一级。\n");
		getchar(); getchar();
		system("cls");
		chart_c();
	}
}
void Punch()
{
	int i = 0, count, k = 1;
	FILE* fp;
	fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%d%d%d", User[i].name, User[i].password, &User[i].score, &User[i].dkts, &User[i].dktm_year, &User[i].dktm_mon, &User[i].dktm_day);
		i++;
	}
	count = i - 1;
	fclose(fp);
	if(count==0)
	{ 
		printf("暂时还没有注册用户，快去注册学习吧！");
		getchar(); getchar();
		system("cls"); RegisterorLogin();
	}

	else
	{
		for (i = 0; i < count; i++)
		{
			for (int j = 0; j < count - i - 1; j++)
			{
				if (User[j + 1].dkts > User[j].dkts)
				{
					sj md = User[j];
					User[j] = User[j + 1];
					User[j + 1] = md;
				}
			}
		}
		printf("名次\t用户名\t打卡天数\n");
		for (i = 0; i < count; i++)
		{
			printf("%d\t%s\t%d\n", k, User[i].name, User[i].dkts);
			if (User[i].dkts > User[i + 1].dkts)
				k++;
		}
		printf("请按任意键返回上一级。\n");
		getchar(); getchar();
		system("cls");
		chart_c();
	}
}

void Exit()
{
	int i = 0, a, count = 0;
	int times[8];
	printf("是否确认退出并打卡（1、是，2、否）：");
	scanf("%d", &a);
	system("cls");
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = gmtime(&rawtime);
	if (a == 1)
	{
		FILE* fp;
		fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "r");
		while (!feof(fp))
		{
			fscanf(fp, "%s%s%d%d%d%d%d", User[i].name, User[i].password, &User[i].score, &User[i].dkts, &User[i].dktm_year, &User[i].dktm_mon, &User[i].dktm_day);
			i++;
		}
		count = i - 1;
		fclose(fp);
		for (i = 0; i < count; i++)
		{
			if (!strcmp(mingzi, User[i].name))
			{
				if (info->tm_year + 1900 == User[i].dktm_year && info->tm_mon + 1 == User[i].dktm_mon && info->tm_mday == User[i].dktm_day)
				{
					printf("您今天已经打卡过啦，不要急于求成哦！\n");
					printf("请按任意键退出程序。\n");
					getchar(); getchar();
					exit(1);
				}
				else
				{
					User[i].dkts++;
					printf("您已成功退出并累计打卡%d次。\n", User[i].dkts);
					printf("您的打卡时间为：%d-%d-%d %d:%d:%d。\n加油，坚持就是胜利。\n", info->tm_year + 1900, info->tm_mon + 1, info->tm_mday, info->tm_hour + 8, info->tm_min, info->tm_sec);
					fp = fopen("D:\\Desktop\\PROG_DATA\\User_Data.txt", "w+");
					for (i = 0; i < count - 1; i++)
					{
						fprintf(fp, "%s %s %d %d %d %d %d\n", User[i].name, User[i].password, User[i].score, User[i].dkts, info->tm_year + 1900, info->tm_mon + 1, info->tm_mday);
					}
					fclose(fp);
					getchar(); getchar();
					exit(1);
				}

			}
		}
	}
	else if (a == 2)     //不退出则重新回到菜单栏
	{
		Menu();
	}

}
void printInfo()
{
	printf("\n\n\n\n\n");
	printf("\t                                     ***********************************\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &      欢迎开始每日单词背诵       &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &             1.注册              &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &             2.登录              &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &             3.榜单              &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &             4.退出              &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &    请键入对应的数字进入功能！   &\n");
	printf("\t                                     &                                 &\n");
	printf("\t                                     &**********************************\n\n");
}