#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include<Mmsystem.h>//����������Ҫ��ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���ؾ�̬�⣬���߱�����������winmm.lib���ļ�
#define MAP_SIZE1 10  //�򵥣�ÿһ��10��ͼ��
#define MAP_SIZE2 12  //�еȣ�ÿһ��12��ͼ��
#define MAP_SIZE3 14  //���ѣ�ÿһ��14��ͼ��
#define TIME 250  //�ܼ�ʱ�÷�
#define BIGGER_SIZE 8//ͼƬ�����Ŵ��ͼ��ߴ�

#define BACKGROUND_WIDTH 1136 //�������
#define BACKGROUND_HEIGHT 800  //�����߶�
#define SUM_ICON_WIDTH 360  //����̨������ͼ��ͼƬ�Ŀ��
#define SUM_ICON_HEIGHT 90  //����̨������ͼ��ͼƬ�ĸ߶�
#define ICON_ROW_NUM 8//ͼ��ͼƬһ�еĸ���
#define ICON_COLUMN_NUM 2//ͼ��ͼƬһ�еĸ���
#define ICON_SIZE 45 //ͼ��ߴ�
#define GAMEPLACE_Y (112+5)//��Ϸ��ʼ��y����
#define ABOUT_WINDOW_SIZE  900 //�����ڡ�����ͼƬ�ߴ�
#define ABOUT_YES_WIDTH 102//���ڴ��ڵġ�ȷ������ť���
#define ABOUT_YES_HEIGHT 33//���ڴ��ڵġ�ȷ������ť�߶�
#define ABOUT_YES_X (391+(BACKGROUND_WIDTH-ABOUT_WINDOW_SIZE)/2) //���ڴ��ڵġ�ȷ������ť������
#define ABOUT_YES_Y 525//���ڴ��ڵġ�ȷ������ť������
#define BUTTON_WIDTH 107 //��ҳ���ϵİ�ť���
#define BUTTON_HEIGHT 38 //��ҳ���ϵİ�ť�߶�
#define ABOUT_BUTTON_X 937//���ڰ�ť���Ͻ�λ�ú�����
#define BUTTON_Y 39//��ť���Ͻ�λ��������(������ť��һ����)
#define TIMER_X 211//��ʱ��������
#define TIMER_Y 33//��ʱ��������
#define TIMER_LINE_Y 95//��ʱ��������
#define TIMER_LINE_LENGTH 850//��ʱ���ܳ�
#define EXIT_BUTTON_X 343//�˳���ť���Ͻ�λ�ú�����
#define BEGIN_BUTTON_X 500//��ʼ��ť���Ͻ�λ�ú�����
#define SUSPEND_BUTTON_X 646//��ͣ��ť���Ͻ�λ�ú�����
#define RANKINGLIST_BUTTON_X 791//���а�ť���Ͻ�λ�ú�����
#define START_WINDOW_WIDTH 900//����ʼ������Ӯ�ˡ��������ˡ����ڿ��
#define START_WINDOW_HEIGHT 634//����ʼ������Ӯ�ˡ��������ˡ����ڸ߶�
#define START_NAME_SIZE 23//��ʼ������������������С
#define START_NAME_X (342+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ���������ֿ�ʼ���λ�ú�����
#define START_NAME_Y (237+GAMEPLACE_Y)//��ʼ���������ֿ�ʼ���λ�ã���Ӯ�˴�������ʱ��ʼ���λ��������
#define START_N_WIDTH 100//��ʼ�����й�ģѡ��ť�Ŀ��
#define START_N_HEIGHT 34//��ʼ�����й�ģѡ��ť�ĸ߶�
#define START_N_Y (360+GAMEPLACE_Y)//��ʼ�����й�ģѡ��ť�������꣨������ť����������ͬ������Ӯ�˴�����������������
#define START_N1_X (329+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ�����й�ģѡ��n=10��ť�ĺ�����
#define START_N2_X (449+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ�����й�ģѡ��n=12��ť�ĺ�����
#define START_N3_X (570+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ�����й�ģѡ��n=14��ť�ĺ�����
#define START_YES_WIDTH 138//��ʼ����,��Ӯ�˴�����ȷ����ť�Ŀ��
#define START_YES_HEIGHT 48//��ʼ����,��Ӯ�˴�����ȷ����ť�ĸ߶�
#define START_YES_X (369+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ����,��Ӯ�˴�����ȷ����ť��ʼλ�ú�����
#define START_YES_Y (451+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//��ʼ����,��Ӯ�˴�����ȷ����ť��ʼλ��������
#define WIN_SCORE_Y (303+GAMEPLACE_Y)//��Ӯ�˴����е÷ֿ�ʼ���λ��������
#define LOST_REMAIN_X (420+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//�����˴����С���ʣ����ʼ���λ�ú�����
#define LOST_REMAIN_Y (250+GAMEPLACE_Y)//�����˴����С���ʣ����ʼ���λ��������
#define LOST_X (385+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//�����˴����С��÷֡�����������ʼ���λ�ú�����
#define LOST_SCORE_Y (324+GAMEPLACE_Y)//�����˴����С��÷֡���ʼ���λ��������
#define LOST_RANK_Y (387+GAMEPLACE_Y)//�����˴����С���������ʼ���λ��������
#define RANKLIST_TITLE_SIZE 35//���а񴰿ڱ����������С
#define RANKLIST_TITLE_Y 209//���а񴰿ڱ�����������
#define RANKLIST_TITLE_RANK_X 183//���а񴰿ڱ���������������
#define RANKLIST_TITLE_NAME_X 300//���а񴰿ڱ����������������
#define RANKLIST_TITLE_SCORE_X 551//���а񴰿ڱ����е÷ֺ�����
#define RANKLIST_TITLE_DATE_X 758//���а񴰿ڱ��������ں�����
#define RANKLIST_DATA_SIZE 27//���а񴰿������������С
#define RANKLIST_DATA_N 15//���а񴰿������и���
#define RANKLIST_DATA_sY 8//���а񴰿������м��
#define RANKLIST_DATA_NAME_X 260//���а񴰿ڱ����������������
#define RANKLIST_DATA_DATE_X 675//���а񴰿����������ں�����
#define RANKLIST_QUIT_SIZE 38//���а񴰿����˳����桱��ť�ĳߴ�
#define RANKLIST_QUIT_X 943//���а񴰿����˳����桱��ť�ĺ�����
#define RANKLIST_QUIT_Y 208//���а񴰿����˳����桱��ť��������
#define RANKLIST_N_WIDTH 282//���а񴰿��й�ģ��ť�Ŀ��
#define RANKLIST_N_HEIGHT 50//���а񴰿��й�ģ��ť�ĸ߶�
#define RANKLIST_N1_X 140//���а񴰿��е�һ����ģ��ť�ĺ�����
#define RANKLIST_N1_Y 145//���а񴰿��е�һ����ģ��ť��������

struct Index//��¼�������
{
	int x;
	int y;
}begin = { -1,-1 }, end = {-1,-1};//��ʼ����ͽ������(x��y��Χ��[1,n])

struct Player//�����Ϣ
{
	char name[20];//�����
	int score;//�÷�
	int n;//��ģ
	double time;//����ʱ��
	int rank;//����
	int remain;//ʣ��û������ͼ��ĸ���
	char date[20];//��ʼ��Ϸ������
}player_now;

IMAGE img_beijing;//����ͼƬ
IMAGE img_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//ͼ��ͼƬ��ԭͼ��
IMAGE img_mask_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//ͼ��ͼƬ������ͼ��
IMAGE big_img_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//ͼ��ͼƬ��ԭͼ��(�Ŵ��)
IMAGE big_img_mask_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//ͼ��ͼƬ������ͼ��
IMAGE img_about, img_mask_about;//���ڴ���ͼƬ
IMAGE img_start, img_mask_start;//��ʼ����ͼƬ
IMAGE img_win, img_mask_win;//��Ӯ�˴���ͼƬ
IMAGE img_lost, img_mask_lost;//�����˴���ͼƬ
IMAGE img_continue, img_mask_continue;//������ťͼƬ
IMAGE img_rankinglist, img_mask_rankinglist;//���а�ͼƬ

static int iconClicking = 0;//ͼ����״̬��1��ʾ��һ�ε㣬2��ʾ�ڶ��ε㣬�ڶ��ε���1��0��ʾ��ʹ�á�
static int map[MAP_SIZE3 + 2][MAP_SIZE3 + 2] = {0};  //���ֵ�ͼ
int startIcon_x, startIcon_y;//ͼ�꿪ʼ����λ��
int size;//ͼ�꣫�߿�ĳߴ�
int n = MAP_SIZE1;//ʵ��ѡ�����Ϸͼ�����
double sumTime = 0.0;//��ʱ��
double preTime = 0.0;//��֮ͣǰ��ʱ��
int numRemain;//��ʣ��û������ͼ�����
int isAbout = 0;//���ڴ����Ƿ���
int isStart = 0;//��ʼ�����Ƿ���
int isWin = 0;//��Ӯ�˴����Ƿ���
int isLost = 0;//�����˴����Ƿ���
int isSuspend = 0;//�Ƿ�����ͣ״̬
int isRankinglist = 0;//���а񴰿��Ƿ���
int n_choose = 10;//���а���ѡ��Ĺ�ģ
int first_xiao = 1;//�ж��ǲ��ǵ�һ������
time_t startTime, endTime;

void gameInit();
void showMap();
void iconDraw();
void shuffleMap();
void mouseIcon(MOUSEMSG msg);
void About();
void Start();
void mouseGet();
bool isIcon(int x, int y);
bool line(struct Index begin, struct Index end);
bool oneTurn(struct Index begin, struct Index end);
bool twoTure(struct Index begin, struct Index end);
bool earse(struct Index begin, struct Index end);
int score(int remain, double time);
void GameRun();
void newMap();
int GetTime();
void SizeN1();
void SizeN2();
void SizeN3();
void Win();
void Lost();
void WritePlayer();
void Suspend();
void rankingList();
void pageRefresh();

//�����µ����ֵ�ͼ
void newMap()
{
	//�ò�ͬ���ֱ�ʾ��ͬͼ�꣬0��ʾû��ͼ��
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			map[i][j] = i;
		}
		printf("\n");
	}
	for (int i = 0; i < n + 2; i++)
	{
		map[i][n + 1] = 0;
		map[n + 1][i] = 0;
	}
}

//���ֵ�ͼ+ͼƬ��ʼ��
void gameInit()//nΪͼ������
{
	srand((unsigned)time(NULL));//���������
	newMap();//���ֵ�ͼ��ʼ��

	//���ر���ͼ
	initgraph(BACKGROUND_WIDTH, BACKGROUND_HEIGHT, SHOWCONSOLE);//����ͼ�񴰿�
	loadimage(&img_beijing, "����������(3).png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
	putimage(0, 0, &img_beijing);

	IMAGE icon;
	loadimage(&icon, "ԭͼ2.png", SUM_ICON_WIDTH, SUM_ICON_HEIGHT);
	//�и�ͼƬ
	SetWorkingImage(&icon);//���ù�����
	for (int i=0;i< ICON_COLUMN_NUM;i++)
	{
		for (int j=0;j< ICON_ROW_NUM;j++)
		{
			// �ӵ�ǰ��ͼ�豸��ȡͼ��
			if(j==4)//������С��һ��ͼƬ��ʹ֮�и�󲻻�����
				getimage(&img_icon[i][j], j * ICON_SIZE+3, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if(j==5)
				getimage(&img_icon[i][j], j * ICON_SIZE + 2, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if (j == 6)
				getimage(&img_icon[i][j], j * ICON_SIZE + 1, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else
			    getimage(&img_icon[i][j], j*ICON_SIZE,i* ICON_SIZE, ICON_SIZE, ICON_SIZE);	
		}
	}
	SetWorkingImage();//�ָ�Ĭ�Ϲ���������

	IMAGE mask_icon;
	loadimage(&mask_icon, "����ͼ2.png", SUM_ICON_WIDTH, SUM_ICON_HEIGHT);
	SetWorkingImage(&mask_icon);//���ù�����
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// �ӵ�ǰ��ͼ�豸��ȡͼ��
			if (j==4)
				getimage(&img_mask_icon[i][j], j * ICON_SIZE + 3, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if(j==5)
				getimage(&img_mask_icon[i][j], j * ICON_SIZE + 2, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if (j == 6)
				getimage(&img_mask_icon[i][j], j * ICON_SIZE + 1, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else
			    getimage(&img_mask_icon[i][j], j * ICON_SIZE, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);

		}
	}
	SetWorkingImage();//�ָ�Ĭ�Ϲ���������




	//�����Ŵ��ͼ��ͼƬ
	IMAGE big_icon;
	loadimage(&big_icon, "ԭͼ2.png", (ICON_SIZE + BIGGER_SIZE) *ICON_ROW_NUM, (ICON_SIZE + BIGGER_SIZE) *ICON_COLUMN_NUM);
	//�и�ͼƬ
	SetWorkingImage(&big_icon);//���ù�����
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// �ӵ�ǰ��ͼ�豸��ȡͼ��
			if (j == 4)//������С��һ��ͼƬ��ʹ֮�и�󲻻�����
				getimage(&big_img_icon[i][j], j * (ICON_SIZE+BIGGER_SIZE) + 3, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 5)
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 2, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 6)
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 1, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE), i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
		}
	}
	SetWorkingImage();//�ָ�Ĭ�Ϲ���������

	IMAGE big_mask_icon;
	loadimage(&big_mask_icon, "����ͼ2.png", SUM_ICON_WIDTH + BIGGER_SIZE * ICON_ROW_NUM, SUM_ICON_HEIGHT + BIGGER_SIZE * ICON_COLUMN_NUM);
	SetWorkingImage(&big_mask_icon);//���ù�����
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// �ӵ�ǰ��ͼ�豸��ȡͼ��
			if (j == 4)//������С��һ��ͼƬ��ʹ֮�и�󲻻�����
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 3, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 5)
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 2, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 6)
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 1, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE), i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
		}
	}
	SetWorkingImage();//�ָ�Ĭ�Ϲ���������

	//���ع��ڴ���ͼƬ
	loadimage(&img_about, "����_ԭͼ.png", ABOUT_WINDOW_SIZE, ABOUT_WINDOW_SIZE);
	loadimage(&img_mask_about, "����_����ͼ.png", ABOUT_WINDOW_SIZE, ABOUT_WINDOW_SIZE);

	//���ؿ�ʼ����ͼƬ
	loadimage(&img_start, "��ʼ_ԭͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_start, "��ʼ_����ͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//������Ӯ�˴���ͼƬ
	loadimage(&img_win, "��Ӯ��_ԭͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_win, "��Ӯ��_����ͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//���������˴���ͼƬ
	loadimage(&img_lost, "������_ԭͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_lost, "������_����ͼ.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//���ؼ�����ťͼƬ
	loadimage(&img_continue, "����_ԭͼ.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	loadimage(&img_mask_continue, "����_����ͼ.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	
	//�������а񱳾�ͼƬ
	loadimage(&img_rankinglist, "���а�ԭͼ.png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
	loadimage(&img_mask_rankinglist, "���а�����ͼ.png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
}

//���ֵ�ͼ��ӡ
void showMap()
{
	for (int i = 0; i <n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			printf("%-2d ", map[i][j]);
		}
		printf("\n");
	}
}

//����ͼ��
void iconDraw()
{
	for (int i = 1; i <= n; i++)//��y��
	{
		for (int j = 1; j <= n; j++)//��x��
		{
			//������map[i][j]��ͼ��
			if (map[i][j] == 0)
				continue;//mapΪ0��û��ͼ��
			putimage(startIcon_x+(j-1) * size, startIcon_y+(i-1) * size, &img_mask_icon[(map[i][j]-1) / ICON_ROW_NUM][(map[i][j]-1) % ICON_ROW_NUM], SRCAND);//����ͼ
			putimage(startIcon_x + (j - 1) * size, startIcon_y + (i - 1) * size, &img_icon[(map[i][j]-1)/ ICON_ROW_NUM][(map[i][j]-1) % ICON_ROW_NUM], SRCPAINT);//ԭͼ
		}
	}
	if (iconClicking == 2 &&begin.x != 0 && begin.y != 0  && begin.x != -1 && begin.y != -1 &&end.x==-1&&end.y==-1&& map[begin.y][begin.x] != 0)
	{
		putimage(startIcon_x + (begin.x - 1) * size-BIGGER_SIZE/2, startIcon_y + (begin.y - 1) * size- BIGGER_SIZE / 2, &big_img_mask_icon[(map[begin.y][begin.x] - 1) / ICON_ROW_NUM][(map[begin.y][begin.x] - 1) % ICON_ROW_NUM], SRCAND);//����ͼ
		putimage(startIcon_x + (begin.x - 1) * size-BIGGER_SIZE / 2, startIcon_y + (begin.y - 1) * size- BIGGER_SIZE / 2, &big_img_icon[(map[begin.y][begin.x] - 1) / ICON_ROW_NUM][(map[begin.y][begin.x] - 1) % ICON_ROW_NUM], SRCPAINT);//ԭͼ
	}
}

//����������ֵ�ͼ
void shuffleMap() 
{
	for (int i = 1; i < n; i++) 
	{  
		for (int j = 1; j < n; j++) 
		{ 
			int x = rand() % n + 1;
			int y = rand() % n + 1; 
			int swap = map[i][j];
			map[i][j] = map[x][y];
			map[x][y] = swap;
		}
	}
}

//������Ϸ�Ķ�ͼ��������Ϣ����ȡ�����ͼ���±꣨��꣩+�������������
void mouseIcon(MOUSEMSG msg)
{
	if (iconClicking != 0)
	{
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= startIcon_x && msg.x <= startIcon_x + n * size && msg.y >= startIcon_y && msg.y <= startIcon_y + n * size && (msg.x - startIcon_x) % size <= ICON_SIZE && (msg.y - startIcon_y) % size <= ICON_SIZE && iconClicking == 1)
		{
			begin.x = (msg.x - startIcon_x) / size + 1;
			begin.y = (msg.y - startIcon_y) / size + 1;
			if (map[begin.y][begin.x] != 0)//�ų�����������հ״�
			{
				iconClicking = 2;
				printf("begin(%d,%d),end(%d,%d)\n", begin.x, begin.y, end.x, end.y);
			}
				iconClicking = 2;
			
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= startIcon_x && msg.x <= startIcon_x + n * size && msg.y >= startIcon_y && msg.y <= startIcon_y + n * size && (msg.x - startIcon_x) % size <= ICON_SIZE && (msg.y - startIcon_y) % size <= ICON_SIZE && iconClicking == 2)
		{
			end.x = (msg.x - startIcon_x) / size + 1;
			end.y = (msg.y - startIcon_y) / size + 1;
			iconClicking = 1;
			if (earse(begin, end))
			{
				if (first_xiao == 0)
				{
					mciSendString("stop se", NULL, 0, NULL);
					mciSendString("close se", NULL, 0, NULL);
				}
				mciSendString("open sound_efforts.wma alias se", 0, 0, 0);
				mciSendString("play se", NULL, 0, NULL);
				first_xiao = 0;
				printf("begin(%d,%d),end(%d,%d)\n", begin.x, begin.y, end.x, end.y);
				printf("begin=%d,end=%d������\n", map[begin.y][begin.x], map[end.y][end.x]);
				numRemain -= 2;
				map[begin.y][begin.x] = 0;
				map[end.y][end.x] = 0;
			}
			begin.x = -1;
			begin.y = -1;
			end.x = -1;
			end.y = -1;
		}
	}
	
}

//�����������ڡ���ť�����
void About()
{	
	printf("���¡����ڡ�\n");
	putimage((BACKGROUND_WIDTH-ABOUT_WINDOW_SIZE)/2, 0 , &img_mask_about, SRCAND);//����ͼ
	putimage((BACKGROUND_WIDTH - ABOUT_WINDOW_SIZE) / 2, 0, &img_about, SRCPAINT);//ԭͼ
	isAbout = 1;
}

//����������ʼ����ť�����
void Start() 
{
	first_xiao = 1;
	sumTime = 0.0;
	preTime = 0.0;
	//�Ե�ͼ�Ĵ�������+����+չʾ
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_start, SRCAND);//����ͼ
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_start, SRCPAINT);//ԭͼ
	isStart = 1;

	InputBox(player_now.name, 20, "�������������");//�öԻ����ȡ����

    //����������
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	// ����������ʽ  �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = START_NAME_SIZE;						// ��������߶�
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	outtextxy(START_NAME_X,START_NAME_Y,player_now.name);//���������

	//ѡ����Ϸ��ģ
	while (isStart == 1)
	{
		mouseGet();
	}
	newMap();
	shuffleMap();
	showMap();
	GetTime();
	player_now.n = n;
	n_choose = n;
	iconClicking = 1;
	if(isStart==0)
		GameRun();//��������Ϸ����

}

//����ѡ���ģ
void SizeN1()
{
	n = MAP_SIZE1;
	printf("ѡ���ģΪn=10��\n");
	setlinecolor(WHITE);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
	setlinecolor(RED);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
}
void SizeN2()
{
	n = MAP_SIZE2;
	printf("ѡ���ģΪn=12��\n");
	setlinecolor(WHITE);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
	setlinecolor(RED);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
}
void SizeN3()
{
	n = MAP_SIZE3;
	printf("ѡ���ģΪn=14��\n");
	setlinecolor(WHITE);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	setlinecolor(RED);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
}

//ˢ��ҳ�棬��ʱ��+����+ͼ��
void pageRefresh()
{
	
	putimage(0, 0, &img_beijing);//ˢ��ҳ��
	if (isSuspend == 1)//���������ͣ״̬��
	{
		//�ָ�ԭ��ҳ���ϵ�һ��
		
		//��������
		putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_mask_continue, SRCAND);
		putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_continue, SRCPAINT);
		
        iconDraw();//��ͼ��

		//����ʱ  
		// �����ֵ���Ƚ����ָ�ʽ�����Ϊ�ַ�����MBCS �ַ�����
		char s[10];
		sprintf_s(s, "%d", TIME - (int)preTime);
		setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
		settextcolor(DARKGRAY);//������ɫ
		// ����������ʽ  �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
		LOGFONT f;
		gettextstyle(&f);						// ��ȡ��ǰ��������
		f.lfHeight = 48;						// ��������߶�Ϊ 48
		_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
		settextstyle(&f);						// ����������ʽ

		outtextxy(TIMER_X, TIMER_Y, s);//������ʱ
		setlinecolor(BLUE);
		line(TIMER_X, TIMER_LINE_Y, TIMER_X + TIMER_LINE_LENGTH * (TIME - preTime) / TIME, TIMER_LINE_Y);
	}
	
}
//��ȡ�����������Ϣ
void mouseGet()
{
	if (MouseHit())//��ȡһ�������Ϣ
	{
		MOUSEMSG msg = GetMouseMsg();
		
		//���+���ڹ��ڷ�Χ��+��������Ϸ/��ʼ״̬
		if (iconClicking==0&&isStart==0&&msg.uMsg == WM_LBUTTONDOWN && msg.x >= ABOUT_BUTTON_X && msg.x <= ABOUT_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT) {
			About();
		}
		//���+���ڹ��ڵ�ȷ����ť��Χ��+���ڴ����Ѵ�
		if (isAbout == 1 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= ABOUT_YES_X && msg.x <= ABOUT_YES_X + ABOUT_YES_WIDTH && msg.y >= ABOUT_YES_Y && msg.y <= ABOUT_YES_Y + ABOUT_YES_HEIGHT)
		{
			isAbout = 0;
			pageRefresh();
			printf("���¹���ҳ���ȷ��!\n");
		}
		
		//�жϼӴ���
		//���+������Ϸͼ�귶Χ�ڵ��ͼ��+��ʼ��Ϸ
		mouseIcon(msg);
		
		//���+�����˳���ť��Χ��
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= EXIT_BUTTON_X && msg.x <= EXIT_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			closegraph();//�ر�ͼ�񴰿�
			exit(0);//�����˳�
		}

		//���+��ʼ����δ��+���ڿ�ʼ��ť��Χ��
		if (msg.uMsg == WM_LBUTTONDOWN &&isStart==0&& msg.x >= BEGIN_BUTTON_X && msg.x <=BEGIN_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			Start();
		}
		
		//���+��ʼ���ڴ�+����n=10��ģ��ť��Χ��
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N1_X && msg.x <= START_N1_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN1();
		}
		//���+��ʼ���ڴ�+����n=12��ģ��ť��Χ��
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N2_X && msg.x <= START_N2_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN2();
		}
		//���+��ʼ���ڴ�+����n=14��ģ��ť��Χ��
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N3_X && msg.x <= START_N3_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN3();
		}
		//���+��ʼ���ڴ�+����ȷ����ť��Χ��->�رմ���
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isStart = 0;
			putimage(0, 0, &img_beijing);//ˢ��ҳ��
			printf("���¿�ʼҳ���ȷ��!\n");
		}
		//���+��Ӯ�˴��ڴ�+����ȷ����ť��Χ��->�رմ���
		if (msg.uMsg == WM_LBUTTONDOWN && isWin == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isWin = 0;
			putimage(0, 0, &img_beijing);//ˢ��ҳ��
			printf("������Ӯ��ҳ���ȷ��!\n");
		}
		//���+�����˴��ڴ�+����ȷ����ť��Χ��->�رմ���
		if (msg.uMsg == WM_LBUTTONDOWN && isLost == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isLost = 0;
			putimage(0, 0, &img_beijing);//ˢ��ҳ��
			printf("����������ҳ���ȷ��!\n");
		}

		//���+�������а�ť��Χ��
		if ( msg.uMsg == WM_LBUTTONDOWN && msg.x >= RANKINGLIST_BUTTON_X && msg.x <= RANKINGLIST_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			rankingList();
			printf("�������а�ť!\n");
		}
		//���+���а񴰿ڴ�+�������а���˳���ť��
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_QUIT_X && msg.x <= RANKLIST_QUIT_X + RANKLIST_QUIT_SIZE && msg.y >= RANKLIST_QUIT_Y && msg.y <= RANKLIST_QUIT_Y + RANKLIST_QUIT_SIZE)
		{
			isRankinglist = 0;
			pageRefresh();
			printf("�������а�ҳ����˳�!\n");
		}
		//���+���а񴰿ڴ�+�������а��10*10��ģ��ť��
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 10;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("�������а�ҳ���10*10��ģ��!\n");
		}
		//���+���а񴰿ڴ�+�������а��12*12��ģ��ť��
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X+ RANKLIST_N_WIDTH && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH*2 && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 12;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("�������а�ҳ���12*12��ģ��!\n");
		}
		//���+���а񴰿ڴ�+�������а��14*14��ģ��ť��
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X+RANKLIST_N_WIDTH*2 && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH*3 && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 14;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("�������а�ҳ���14*14��ģ��!\n");
		}
		//���+������ͣ��ť��Χ��+������Ϸ״̬
		if (iconClicking != 0 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= SUSPEND_BUTTON_X && msg.x <= SUSPEND_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT) 
		{
			Suspend();
			printf("������ͣ��ť!\n");
			return;//�˳�������ִ������ļ���
		}
		//���+���ڼ�����ť��Χ��+������Ϸ״̬
		if (isSuspend== 1 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= SUSPEND_BUTTON_X && msg.x <= SUSPEND_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			isSuspend = 0;
			iconClicking = 1;
			startTime = time(NULL);
			putimage(0, 0, &img_beijing);//ˢ��ҳ��
			printf("���¼�����ť\n");
		}

	}
}



//�ж�ĳλλ���Ƿ���ͼ��
bool isIcon(int x, int y)
{
	return map[y][x];
}

//ֱ������
bool line(struct Index begin, struct Index end)
{
	if (begin.x == end.x)
	{
		int maxY = begin.y > end.y ? begin.y : end.y;
		int minY = begin.y < end.y ? begin.y : end.y;
		for (int i = minY + 1; i < maxY; i++)
		{
			if (isIcon(begin.x, i))
				return false;
		}
	}
	else if (begin.y == end.y)
	{
		int maxX = begin.x > end.x ? begin.x : end.x;
		int minX = begin.x < end.x ? begin.x : end.x;
		for (int i = minX + 1; i < maxX; i++)
		{
			if (isIcon(i, begin.y))
				return false;
		}
	}
	else
		return false;
	return true;
}

//һ��ת�ǵ����
bool oneTurn(struct Index begin, struct Index end)
{
	struct Index turn1 = { begin.x,end.y }, turn2 = { end.x,begin.y };
	if (!isIcon(turn1.x, turn1.y))//��һ��ת��û��ͼ��
	{
		if (line(begin, turn1) && line(turn1, end))
			return true;
	}
	if (!isIcon(turn2.x, turn2.y))
	{
		if (line(begin, turn2) && line(turn2, end))
			return true;
	}
	return false;
}

//����ת�ǵ����
bool twoTure(struct Index begin, struct Index end)
{
	//�����ս�λ��ͬһ��
	for (int i = 0; i < n+2 ; i++)
	{
		if (i == begin.x || i == end.x)//�ų���begin��endλ��ͬһ�е����
			continue;
		struct Index turn1 = { i,begin.y }, turn2 = { i,end.y };
		if (isIcon(turn1.x, turn1.y) || isIcon(turn2.x, turn2.y))//turn1��turn2������ͼ��
			continue;
		if(line(begin,turn1)&&line(turn1,turn2)&&line(turn2,end))
			return true;
	}
	//�����ս�λ��ͬһ��
	for (int i = 0; i < n+2; i++)
	{
		if (i == begin.y || i == end.y)//�ų���begin��endλ��ͬһ�е����
			continue;
		struct Index turn1 = { begin.x,i }, turn2 = { end.x,i };
		if (isIcon(turn1.x, turn1.y) || isIcon(turn2.x, turn2.y))
			continue;
		if (line(begin, turn1) && line(turn1, turn2) && line(turn2, end))
			return true;
	}
	return false;
}

//�ж��ܷ�����begin��end������ͼ��
bool earse(struct Index begin, struct Index end)
{
	if (map[begin.y][begin.x] != map[end.y][end.x])//���ͼ�겻һ��
		return false;
	if (begin.x == end.x && begin.y == end.y)//�������ͼ��Ϊͬһ��
		return false;
	bool flag = false;
	if (line(begin, end))//����ͬһ��ֱ���ϵ�����
		flag = true;
	else if (oneTurn(begin, end))//һ��ת�ǵ�����
		flag = true;
	else if (twoTure(begin, end))//����ת������
		flag = true;
	return flag;
}

//������Ϸ�÷�
int score(int remain, double time)
{
	return (TIME - (int)time) * 50 + (n * n - remain) * 25;//ʣ��ʱ��+����ͼ��
}

//������Ϸ
void GameRun()
{
	if (iconClicking == 0)
		return;
	//iconClicking = 1;//Ҫ����������ʱ����������1
	mciSendString("open ���-һ�����£����ɰ棩.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);//��������
	startIcon_x = (BACKGROUND_WIDTH - n * ICON_SIZE) / 2;
	startIcon_y = GAMEPLACE_Y + (MAP_SIZE3 - n) / 2 * ICON_SIZE;
	switch (n)
	{
	case 10:
	{
		startIcon_x -= 60;
		startIcon_y -= 40;
		size = ICON_SIZE + 10;
		break;
	}
	case 12:
	{
		startIcon_x -= 20;
		startIcon_y -= 20;
		size = ICON_SIZE + 5;
		break;
	}
	case 14:
	{
		size = ICON_SIZE + 1;
		break;
	}
	}
	numRemain = n * n;
	startTime = time(NULL);
	while (1)
	{
		BeginBatchDraw();//��ʼ˫�����ͼ
		putimage(0, 0, &img_beijing);//�ű���ͼ
		iconDraw();//��ͼ��
		//����ʱ  
		// �����ֵ���Ƚ����ָ�ʽ�����Ϊ�ַ�����MBCS �ַ�����
		char s[10];
		sprintf_s(s, "%d", TIME-(int)(sumTime+preTime));
		setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
		settextcolor(DARKGRAY);//������ɫ
		// ����������ʽ  �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
		LOGFONT f;
		gettextstyle(&f);						// ��ȡ��ǰ��������
		f.lfHeight = 48;						// ��������߶�Ϊ 48
		_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
		settextstyle(&f);						// ����������ʽ
		
		outtextxy(TIMER_X, TIMER_Y, s);//������ʱ
		setlinecolor(BLUE);
		line(TIMER_X, TIMER_LINE_Y, TIMER_X+ TIMER_LINE_LENGTH*(TIME-(sumTime+preTime))/TIME, TIMER_LINE_Y);
		EndBatchDraw();//����˫�����ͼ

		//��ͼ����ˢ�������жϣ������������ͼ�������������
		if ((int)(sumTime+ preTime)== TIME)
		{
			iconClicking = 0;
			endTime = time(NULL);//ֹͣ��ʱ
			sumTime = TIME;
			player_now.time = sumTime;
			player_now.score = score(numRemain, sumTime);
			player_now.remain = numRemain;
			printf("��Ϸʧ�ܣ���ʱ��%.2f,�÷֣�%d\n", player_now.time,player_now.score);
			WritePlayer();
			mciSendString("stop bgm", NULL, 0, NULL);
			mciSendString("close bgm", NULL, 0, NULL);
			Lost();

			break;
		}

		if (numRemain == 0)//ȫ�����꣬��Ϸ����
		{
			iconClicking = 0;
			Sleep(500);//����ҿ�һ��ȫ����Ľ��棬�Ƚ��гɾ͸�
			endTime = time(NULL);//ֹͣ��ʱ
			sumTime = endTime - startTime+preTime;
			//�������Ϣ�����ļ������õ��ȽϺ������
			player_now.time = sumTime;
			player_now.score = score(numRemain, sumTime);
			player_now.remain = 0;
			WritePlayer();
			printf("��Ϸ��������ʱ��%.2f,�÷֣�%d\n", player_now.time, player_now.score);
			mciSendString("stop bgm", NULL, 0, NULL);
			mciSendString("close bgm", NULL, 0, NULL);
			Win();

			break;
		}
		mouseGet();
		//�����ʱʱ��
		while (isSuspend == 1)//��ͣʱ�����ж�
		{
			mouseGet();
		}
		endTime = time(NULL);
		sumTime = endTime - startTime;

	}
}

//�ѿ�ʼ��ʱ��ŵ�player_now����
int GetTime()
{
	time_t now;
	time(&now);
	struct tm* tm = localtime(&now);// ת��Ϊ struct tm �Ա�ֽ�������
	// ��ʱ�������ʽ��Ϊ�ַ���
	char timeString[100];
	sprintf(timeString, "%04d-%02d-%02d-%02d:%02d:%02d",
		tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	
	snprintf(player_now.date, sizeof(player_now.date), "%s", timeString);
	return 0;
}

//������Ӯ�˴��ڲ������Ϣ
void Win()
{
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_win, SRCAND);//����ͼ
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_win, SRCPAINT);//ԭͼ
	isWin = 1;
	
	//�����ʱ
	char s1[10];
	sprintf_s(s1, "%d", (int)player_now.time);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f1;
	gettextstyle(&f1);						// ��ȡ��ǰ��������
	f1.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f1.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f1.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f1);						// ����������ʽ
	outtextxy(START_NAME_X, START_NAME_Y, s1);

	//����÷�
	char s2[10];
	sprintf_s(s2, "%d", player_now.score);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f2;
	gettextstyle(&f2);						// ��ȡ��ǰ��������
	f2.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f2.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f2.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f2);						// ����������ʽ
	outtextxy(START_NAME_X, WIN_SCORE_Y, s2);

	//�������
	char s3[10];
	sprintf_s(s3, "%d", player_now.rank);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f3;
	gettextstyle(&f3);						// ��ȡ��ǰ��������
	f3.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f3.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f3.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f3);						// ����������ʽ
	outtextxy(START_NAME_X, START_N_Y+6, s3);

}

//���������˴��ڲ������Ϣ
void Lost() {
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_lost, SRCAND);//����ͼ
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_lost, SRCPAINT);//ԭͼ
	isLost = 1;

	//�����ʣ
	char s1[10];
	sprintf_s(s1, "%d", player_now.remain);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f1;
	gettextstyle(&f1);						// ��ȡ��ǰ��������
	f1.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f1.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f1.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f1);						// ����������ʽ
	outtextxy(LOST_REMAIN_X, LOST_REMAIN_Y, s1);

	//����÷�
	char s2[10];
	sprintf_s(s2, "%d", player_now.score);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f2;
	gettextstyle(&f2);						// ��ȡ��ǰ��������
	f2.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f2.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f2.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f2);						// ����������ʽ
	outtextxy(LOST_X, LOST_SCORE_Y, s2);

	//�������
	char s3[10];
	sprintf_s(s3, "%d", player_now.rank);
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f3;
	gettextstyle(&f3);						// ��ȡ��ǰ��������
	f3.lfHeight = START_NAME_SIZE;			// ��������߶ȣ��뿪ʼ�����ϵ��������С������ͬ
	_tcscpy(f3.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f3.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f3);						// ����������ʽ
	outtextxy(LOST_X, LOST_RANK_Y, s3);
}

//��������ݰ�˳��д���ļ�
void WritePlayer()
{
	Player player1;//��ʱ�ṹ����������ڴ�Ŷ�ȡ�ļ��е��������
	int flag = 1;//���ڱ���Ƿ���д�뵱ǰ�������
	int rank_count = 1;//һ����������������÷�����
	FILE *f1, *f2, *f3, *f4;
	f1 = fopen("player_rank1_little.txt", "a+");//player_rank1_little.txtΪԭ���ļ� 10X10��ģ
	f2 = fopen("player_rank1_medium.txt", "a+");//player_rank1_medium.txtΪԭ���ļ� 12X12��ģ
	f3 = fopen("player_rank1_large.txt", "a+");//player_rank_medium.txtΪԭ���ļ� 14X14��ģ
	f4 = fopen("player_rank2.txt", "w+");//player_rank2.txtΪ��ʱ�ļ������ڸ���player_rank1.txt

	if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL)
	{
		perror("Error opening file");
		return;
	}
	
	if (player_now.n == MAP_SIZE1) {
		while (!feof(f1))
		{
			int result = fscanf(f1, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//�ṹ�����player1Ϊ��f1�ж�����һ���ļ�
			if (result == 5)// ȷ���ɹ���ȡ��5��������
			{
				if (player_now.score >= player1.score && flag)//ԭ�ļ�f1�Ե÷ֽ�������
				{
					fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
					player_now.rank = rank_count;
					rank_count++;
					fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
					flag = 0;
					
				}
				else {
					fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
				}

				rank_count++;
			}
			else// ��ȡʧ��ʱ�Ĵ���
			{
				break;
			}
		}
		if (flag)
		{
			fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
			player_now.rank = rank_count;
			
		}
		
		fclose(f1);
		fclose(f2);
		fclose(f3);
		fclose(f4);
		
		if (remove("player_rank1_little.txt") != 0)
		{
			perror("Error deleting player_rank1_little.txt");// perror ������ӡ������Ϣ
		}
		
		// ����Ƿ�ɹ���������ʱ�ļ�
		if (rename("player_rank2.txt", "player_rank1_little.txt") != 0)
		{
			perror("Error renaming player_rank4.txt to player_rank1_little.txt");
		}
		
	}
	else {
		if (player_now.n == MAP_SIZE2) {
			while (!feof(f2))
			{
				int result = fscanf(f2, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//�ṹ�����player1Ϊ��f1�ж�����һ���ļ�
				if (result == 5)// ȷ���ɹ���ȡ��5��������
				{
					if (player_now.score >= player1.score && flag)//ԭ�ļ�f1�Ե÷ֽ�������
					{
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
						player_now.rank = rank_count;
						rank_count++;
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
						flag = 0;//�ṹ�����player_nowΪ��ǰ��ҵ�����
					}
					else {
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
					}

					rank_count++;
				}
				else// ��ȡʧ��ʱ�Ĵ���
				{
					break;
				}
			}
			if (flag)
			{
				fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
				player_now.rank = rank_count;
			}
				
			fclose(f1);
			fclose(f2);
			fclose(f3);
			fclose(f4);
			if (remove("player_rank1_medium.txt") != 0)
			{
				perror("Error deleting player_rank1_medium.txt");// perror ������ӡ������Ϣ
			}

			// ����Ƿ�ɹ���������ʱ�ļ�
			if (rename("player_rank2.txt", "player_rank1_medium.txt") != 0)
			{
				perror("Error renaming player_rank4.txt to player_rank1_medium.txt");
			}
		}
		else {
			if (player_now.n == MAP_SIZE3) {
				while (!feof(f3))
				{
					int result = fscanf(f3, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//�ṹ�����player1Ϊ��f1�ж�����һ���ļ�
					if (result == 5)// ȷ���ɹ���ȡ��5��������
					{
						if (player_now.score >= player1.score && flag)//ԭ�ļ�f1�Ե÷ֽ�������
						{
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
							player_now.rank = rank_count;
							rank_count++;
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
							flag = 0;//�ṹ�����player_nowΪ��ǰ��ҵ�����
							printf("����\n");
						}
						else {
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
						}

						rank_count++;
					}
					else// ��ȡʧ��ʱ�Ĵ���
					{
						break;
					}
				}
				if (flag)
				{
					fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
					player_now.rank = rank_count;
					printf("����\n");
				}

				fclose(f1);
				fclose(f2);
				fclose(f3);
				fclose(f4);
				if (remove("player_rank1_large.txt") != 0)
				{
					perror("Error deleting player_rank1_large.txt");// perror ������ӡ������Ϣ
				}

				// ����Ƿ�ɹ���������ʱ�ļ�
				if (rename("player_rank2.txt", "player_rank1_large.txt") != 0)
				{
					perror("Error renaming player_rank2.txt to player_rank1_large.txt");
				}
			}
			
		}
	}
}

//������ͣ����
void Suspend()
{
	isSuspend = 1;
	putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_mask_continue, SRCAND);
	putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_continue, SRCPAINT);
	iconClicking = 0;
	endTime = time(NULL);
	preTime += endTime - startTime;
	
}

//������ʾ���а����
void rankingList()
{
	putimage(0, 0, &img_mask_rankinglist, SRCAND);
	putimage(0, 0, &img_rankinglist, SRCPAINT);
	isRankinglist = 1;
	
	//д������
	setbkmode(TRANSPARENT);//����ģʽ��Ϊ͸��
	settextcolor(DARKGRAY);//������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = RANKLIST_TITLE_SIZE;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	char s1[] = "����";
	outtextxy(RANKLIST_TITLE_RANK_X,RANKLIST_TITLE_Y ,s1);
	char s2[] = "�����";
	outtextxy(RANKLIST_TITLE_NAME_X, RANKLIST_TITLE_Y, s2);
	char s3[] = "�÷�";
	outtextxy(RANKLIST_TITLE_SCORE_X, RANKLIST_TITLE_Y, s3);
	char s4[] = "����";
	outtextxy(RANKLIST_TITLE_DATE_X, RANKLIST_TITLE_Y, s4);

	FILE* f1, * f2, * f3;
	f1 = fopen("player_rank1_little.txt", "r");
	f2 = fopen("player_rank1_medium.txt", "r");
	f3 = fopen("player_rank1_large.txt", "r");
	if (f1 == NULL || f2 == NULL || f3 == NULL )
	{
		perror("Error opening file");
		return;
	}

	// ����������ʽ  
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = RANKLIST_DATA_SIZE;		// ��������߶�
	settextstyle(&f);

	if (n_choose == 10)
	{
		setlinecolor(RED);
		rectangle(RANKLIST_N1_X,RANKLIST_N1_Y,RANKLIST_N1_X+RANKLIST_N_WIDTH,RANKLIST_N1_Y+RANKLIST_N_HEIGHT);
		for (int i = 0; i < RANKLIST_DATA_N; i++)
		{
			Player player;

			if (feof(f1) != 0)//����ĩβ
				break;
			if (fscanf(f1, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("��ȡ�ļ�ʧ�ܣ�\n");
				break;
			}
			
			char rank[10];
			sprintf_s(rank, "%d", player.rank);
		    outtextxy(RANKLIST_TITLE_RANK_X,RANKLIST_TITLE_Y+RANKLIST_TITLE_SIZE+(i+1)*RANKLIST_DATA_sY+i*RANKLIST_DATA_SIZE, rank);

			outtextxy(RANKLIST_DATA_NAME_X, RANKLIST_TITLE_Y +RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.name);

			char score[15];
			sprintf_s(score, "%d", player.score);
			outtextxy(RANKLIST_TITLE_SCORE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, score);

			outtextxy(RANKLIST_DATA_DATE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.date);
		}
	}
	else if (n_choose == 12)
	{
		setlinecolor(RED);
		rectangle(RANKLIST_N1_X+RANKLIST_N_WIDTH, RANKLIST_N1_Y, RANKLIST_N1_X + RANKLIST_N_WIDTH*2, RANKLIST_N1_Y + RANKLIST_N_HEIGHT);
		for (int i = 0; i < RANKLIST_DATA_N; i++)
		{
			Player player;
			if (feof(f2)!=0)//����ĩβ
				break;
			if (fscanf(f2, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("��ȡ�ļ�ʧ�ܣ�\n");
				break;
			}
			char rank[10];
			sprintf_s(rank, "%d", player.rank);
			outtextxy(RANKLIST_TITLE_RANK_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, rank);

			outtextxy(RANKLIST_DATA_NAME_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.name);

			char score[15];
			sprintf_s(score, "%d", player.score);
			outtextxy(RANKLIST_TITLE_SCORE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, score);

			outtextxy(RANKLIST_DATA_DATE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.date);
		}
	}
	else if (n_choose == 14)
	{
		setlinecolor(RED);
		rectangle(RANKLIST_N1_X + RANKLIST_N_WIDTH*2, RANKLIST_N1_Y, RANKLIST_N1_X + RANKLIST_N_WIDTH * 3, RANKLIST_N1_Y + RANKLIST_N_HEIGHT);
		for (int i = 0; i < RANKLIST_DATA_N; i++)
		{
			Player player;
			if (feof(f3)!=0)//����ĩβ
				break;
			if (fscanf(f3, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("��ȡ�ļ�ʧ�ܣ�\n");
				break;
			}
			char rank[10];
			sprintf_s(rank, "%d", player.rank);
			outtextxy(RANKLIST_TITLE_RANK_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, rank);

			outtextxy(RANKLIST_DATA_NAME_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.name);

			char score[15];
			sprintf_s(score, "%d", player.score);
			outtextxy(RANKLIST_TITLE_SCORE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, score);

			outtextxy(RANKLIST_DATA_DATE_X, RANKLIST_TITLE_Y + RANKLIST_TITLE_SIZE + (i + 1) * RANKLIST_DATA_sY + i * RANKLIST_DATA_SIZE, player.date);
		}
	}
	else {
		printf("�ļ���ģ����\n");
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}

int main()
{
	gameInit();//��Ϸ��ʼ��������ͼƬ������ԭʼ��ͼ��

	while (1)
	{
		mouseGet();
	}
	
	return 1;
}