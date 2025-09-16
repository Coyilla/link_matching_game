#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include<Mmsystem.h>//播放音乐需要的头文件
#pragma comment(lib,"winmm.lib")//加载静态库，告诉编译器，加载winmm.lib库文件
#define MAP_SIZE1 10  //简单：每一行10个图标
#define MAP_SIZE2 12  //中等：每一行12个图标
#define MAP_SIZE3 14  //困难：每一行14个图标
#define TIME 250  //总计时得分
#define BIGGER_SIZE 8//图片点击后放大的图标尺寸

#define BACKGROUND_WIDTH 1136 //背景宽度
#define BACKGROUND_HEIGHT 800  //背景高度
#define SUM_ICON_WIDTH 360  //控制台上整张图标图片的宽度
#define SUM_ICON_HEIGHT 90  //控制台上整张图标图片的高度
#define ICON_ROW_NUM 8//图标图片一行的个数
#define ICON_COLUMN_NUM 2//图标图片一列的个数
#define ICON_SIZE 45 //图标尺寸
#define GAMEPLACE_Y (112+5)//游戏框开始的y坐标
#define ABOUT_WINDOW_SIZE  900 //“关于”窗口图片尺寸
#define ABOUT_YES_WIDTH 102//关于窗口的“确定”按钮宽度
#define ABOUT_YES_HEIGHT 33//关于窗口的“确定”按钮高度
#define ABOUT_YES_X (391+(BACKGROUND_WIDTH-ABOUT_WINDOW_SIZE)/2) //关于窗口的“确定”按钮横坐标
#define ABOUT_YES_Y 525//关于窗口的“确定”按钮纵坐标
#define BUTTON_WIDTH 107 //主页面上的按钮宽度
#define BUTTON_HEIGHT 38 //主页面上的按钮高度
#define ABOUT_BUTTON_X 937//关于按钮左上角位置横坐标
#define BUTTON_Y 39//按钮左上角位置纵坐标(几个按钮是一样的)
#define TIMER_X 211//计时器横坐标
#define TIMER_Y 33//计时器纵坐标
#define TIMER_LINE_Y 95//计时线纵坐标
#define TIMER_LINE_LENGTH 850//计时线总长
#define EXIT_BUTTON_X 343//退出按钮左上角位置横坐标
#define BEGIN_BUTTON_X 500//开始按钮左上角位置横坐标
#define SUSPEND_BUTTON_X 646//暂停按钮左上角位置横坐标
#define RANKINGLIST_BUTTON_X 791//排行榜按钮左上角位置横坐标
#define START_WINDOW_WIDTH 900//“开始”“你赢了”“你输了”窗口宽度
#define START_WINDOW_HEIGHT 634//“开始”“你赢了”“你输了”窗口高度
#define START_NAME_SIZE 23//开始窗口中名字输出字体大小
#define START_NAME_X (342+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口中名字开始输出位置横坐标
#define START_NAME_Y (237+GAMEPLACE_Y)//开始窗口中名字开始输出位置，你赢了窗口中用时开始输出位置纵坐标
#define START_N_WIDTH 100//开始窗口中规模选择按钮的宽度
#define START_N_HEIGHT 34//开始窗口中规模选择按钮的高度
#define START_N_Y (360+GAMEPLACE_Y)//开始窗口中规模选择按钮的纵坐标（三个按钮的纵坐标相同）和你赢了窗口中排名的纵坐标
#define START_N1_X (329+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口中规模选择n=10按钮的横坐标
#define START_N2_X (449+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口中规模选择n=12按钮的横坐标
#define START_N3_X (570+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口中规模选择n=14按钮的横坐标
#define START_YES_WIDTH 138//开始窗口,你赢了窗口中确定按钮的宽度
#define START_YES_HEIGHT 48//开始窗口,你赢了窗口中确定按钮的高度
#define START_YES_X (369+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口,你赢了窗口中确定按钮开始位置横坐标
#define START_YES_Y (451+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//开始窗口,你赢了窗口中确定按钮开始位置纵坐标
#define WIN_SCORE_Y (303+GAMEPLACE_Y)//你赢了窗口中得分开始输出位置纵坐标
#define LOST_REMAIN_X (420+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//你输了窗口中“还剩”开始输出位置横坐标
#define LOST_REMAIN_Y (250+GAMEPLACE_Y)//你输了窗口中“还剩”开始输出位置纵坐标
#define LOST_X (385+(BACKGROUND_WIDTH-START_WINDOW_WIDTH)/2)//你输了窗口中“得分”“排名”开始输出位置横坐标
#define LOST_SCORE_Y (324+GAMEPLACE_Y)//你输了窗口中“得分”开始输出位置纵坐标
#define LOST_RANK_Y (387+GAMEPLACE_Y)//你输了窗口中“排名”开始输出位置纵坐标
#define RANKLIST_TITLE_SIZE 35//排行榜窗口标题行字体大小
#define RANKLIST_TITLE_Y 209//排行榜窗口标题行纵坐标
#define RANKLIST_TITLE_RANK_X 183//排行榜窗口标题行排名横坐标
#define RANKLIST_TITLE_NAME_X 300//排行榜窗口标题行玩家名横坐标
#define RANKLIST_TITLE_SCORE_X 551//排行榜窗口标题行得分横坐标
#define RANKLIST_TITLE_DATE_X 758//排行榜窗口标题行日期横坐标
#define RANKLIST_DATA_SIZE 27//排行榜窗口数据行字体大小
#define RANKLIST_DATA_N 15//排行榜窗口数据行个数
#define RANKLIST_DATA_sY 8//排行榜窗口数据行间距
#define RANKLIST_DATA_NAME_X 260//排行榜窗口标题行玩家名横坐标
#define RANKLIST_DATA_DATE_X 675//排行榜窗口数据行日期横坐标
#define RANKLIST_QUIT_SIZE 38//排行榜窗口中退出“叉”按钮的尺寸
#define RANKLIST_QUIT_X 943//排行榜窗口中退出“叉”按钮的横坐标
#define RANKLIST_QUIT_Y 208//排行榜窗口中退出“叉”按钮的纵坐标
#define RANKLIST_N_WIDTH 282//排行榜窗口中规模按钮的宽度
#define RANKLIST_N_HEIGHT 50//排行榜窗口中规模按钮的高度
#define RANKLIST_N1_X 140//排行榜窗口中第一个规模按钮的横坐标
#define RANKLIST_N1_Y 145//排行榜窗口中第一个规模按钮的纵坐标

struct Index//记录点击坐标
{
	int x;
	int y;
}begin = { -1,-1 }, end = {-1,-1};//开始点击和结束点击(x，y范围是[1,n])

struct Player//玩家信息
{
	char name[20];//玩家名
	int score;//得分
	int n;//规模
	double time;//所用时间
	int rank;//排名
	int remain;//剩下没消掉的图标的个数
	char date[20];//开始游戏的日期
}player_now;

IMAGE img_beijing;//背景图片
IMAGE img_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//图标图片（原图）
IMAGE img_mask_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//图标图片（掩码图）
IMAGE big_img_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//图标图片（原图）(放大版)
IMAGE big_img_mask_icon[ICON_COLUMN_NUM][ICON_ROW_NUM];//图标图片（掩码图）
IMAGE img_about, img_mask_about;//关于窗口图片
IMAGE img_start, img_mask_start;//开始窗口图片
IMAGE img_win, img_mask_win;//你赢了窗口图片
IMAGE img_lost, img_mask_lost;//你输了窗口图片
IMAGE img_continue, img_mask_continue;//继续按钮图片
IMAGE img_rankinglist, img_mask_rankinglist;//排行榜图片

static int iconClicking = 0;//图标点击状态。1表示第一次点，2表示第二次点，第二次点后归1。0表示不使用。
static int map[MAP_SIZE3 + 2][MAP_SIZE3 + 2] = {0};  //数字地图
int startIcon_x, startIcon_y;//图标开始画的位置
int size;//图标＋边框的尺寸
int n = MAP_SIZE1;//实际选择的游戏图标个数
double sumTime = 0.0;//总时间
double preTime = 0.0;//暂停之前的时间
int numRemain;//还剩的没消掉的图标个数
int isAbout = 0;//关于窗口是否开着
int isStart = 0;//开始窗口是否开着
int isWin = 0;//你赢了窗口是否开着
int isLost = 0;//你输了窗口是否开着
int isSuspend = 0;//是否处于暂停状态
int isRankinglist = 0;//排行榜窗口是否开着
int n_choose = 10;//排行榜中选择的规模
int first_xiao = 1;//判断是不是第一次消除
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

//创建新的数字地图
void newMap()
{
	//用不同数字表示不同图标，0表示没有图标
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

//数字地图+图片初始化
void gameInit()//n为图标数量
{
	srand((unsigned)time(NULL));//随机数种子
	newMap();//数字地图初始化

	//加载背景图
	initgraph(BACKGROUND_WIDTH, BACKGROUND_HEIGHT, SHOWCONSOLE);//创建图像窗口
	loadimage(&img_beijing, "连连看背景(3).png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
	putimage(0, 0, &img_beijing);

	IMAGE icon;
	loadimage(&icon, "原图2.png", SUM_ICON_WIDTH, SUM_ICON_HEIGHT);
	//切割图片
	SetWorkingImage(&icon);//设置工作区
	for (int i=0;i< ICON_COLUMN_NUM;i++)
	{
		for (int j=0;j< ICON_ROW_NUM;j++)
		{
			// 从当前绘图设备获取图像
			if(j==4)//调整大小不一的图片，使之切割后不会留边
				getimage(&img_icon[i][j], j * ICON_SIZE+3, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if(j==5)
				getimage(&img_icon[i][j], j * ICON_SIZE + 2, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else if (j == 6)
				getimage(&img_icon[i][j], j * ICON_SIZE + 1, i * ICON_SIZE, ICON_SIZE, ICON_SIZE);
			else
			    getimage(&img_icon[i][j], j*ICON_SIZE,i* ICON_SIZE, ICON_SIZE, ICON_SIZE);	
		}
	}
	SetWorkingImage();//恢复默认工作区窗口

	IMAGE mask_icon;
	loadimage(&mask_icon, "掩码图2.png", SUM_ICON_WIDTH, SUM_ICON_HEIGHT);
	SetWorkingImage(&mask_icon);//设置工作区
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// 从当前绘图设备获取图像
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
	SetWorkingImage();//恢复默认工作区窗口




	//制作放大版图标图片
	IMAGE big_icon;
	loadimage(&big_icon, "原图2.png", (ICON_SIZE + BIGGER_SIZE) *ICON_ROW_NUM, (ICON_SIZE + BIGGER_SIZE) *ICON_COLUMN_NUM);
	//切割图片
	SetWorkingImage(&big_icon);//设置工作区
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// 从当前绘图设备获取图像
			if (j == 4)//调整大小不一的图片，使之切割后不会留边
				getimage(&big_img_icon[i][j], j * (ICON_SIZE+BIGGER_SIZE) + 3, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 5)
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 2, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 6)
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 1, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else
				getimage(&big_img_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE), i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
		}
	}
	SetWorkingImage();//恢复默认工作区窗口

	IMAGE big_mask_icon;
	loadimage(&big_mask_icon, "掩码图2.png", SUM_ICON_WIDTH + BIGGER_SIZE * ICON_ROW_NUM, SUM_ICON_HEIGHT + BIGGER_SIZE * ICON_COLUMN_NUM);
	SetWorkingImage(&big_mask_icon);//设置工作区
	for (int i = 0; i < ICON_COLUMN_NUM; i++)
	{
		for (int j = 0; j < ICON_ROW_NUM; j++)
		{
			// 从当前绘图设备获取图像
			if (j == 4)//调整大小不一的图片，使之切割后不会留边
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 3, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 5)
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 2, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else if (j == 6)
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE) + 1, i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
			else
				getimage(&big_img_mask_icon[i][j], j * (ICON_SIZE + BIGGER_SIZE), i * (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE), (ICON_SIZE + BIGGER_SIZE));
		}
	}
	SetWorkingImage();//恢复默认工作区窗口

	//加载关于窗口图片
	loadimage(&img_about, "关于_原图.png", ABOUT_WINDOW_SIZE, ABOUT_WINDOW_SIZE);
	loadimage(&img_mask_about, "关于_掩码图.png", ABOUT_WINDOW_SIZE, ABOUT_WINDOW_SIZE);

	//加载开始窗口图片
	loadimage(&img_start, "开始_原图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_start, "开始_掩码图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//加载你赢了窗口图片
	loadimage(&img_win, "你赢了_原图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_win, "你赢了_掩码图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//加载你输了窗口图片
	loadimage(&img_lost, "你输了_原图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);
	loadimage(&img_mask_lost, "你输了_掩码图.png", START_WINDOW_WIDTH, START_WINDOW_HEIGHT);

	//加载继续按钮图片
	loadimage(&img_continue, "继续_原图.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	loadimage(&img_mask_continue, "继续_掩码图.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	
	//加载排行榜背景图片
	loadimage(&img_rankinglist, "排行榜原图.png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
	loadimage(&img_mask_rankinglist, "排行榜掩码图.png", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
}

//数字地图打印
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

//绘制图标
void iconDraw()
{
	for (int i = 1; i <= n; i++)//（y）
	{
		for (int j = 1; j <= n; j++)//（x）
		{
			//画的是map[i][j]个图标
			if (map[i][j] == 0)
				continue;//map为0处没有图标
			putimage(startIcon_x+(j-1) * size, startIcon_y+(i-1) * size, &img_mask_icon[(map[i][j]-1) / ICON_ROW_NUM][(map[i][j]-1) % ICON_ROW_NUM], SRCAND);//掩码图
			putimage(startIcon_x + (j - 1) * size, startIcon_y + (i - 1) * size, &img_icon[(map[i][j]-1)/ ICON_ROW_NUM][(map[i][j]-1) % ICON_ROW_NUM], SRCPAINT);//原图
		}
	}
	if (iconClicking == 2 &&begin.x != 0 && begin.y != 0  && begin.x != -1 && begin.y != -1 &&end.x==-1&&end.y==-1&& map[begin.y][begin.x] != 0)
	{
		putimage(startIcon_x + (begin.x - 1) * size-BIGGER_SIZE/2, startIcon_y + (begin.y - 1) * size- BIGGER_SIZE / 2, &big_img_mask_icon[(map[begin.y][begin.x] - 1) / ICON_ROW_NUM][(map[begin.y][begin.x] - 1) % ICON_ROW_NUM], SRCAND);//掩码图
		putimage(startIcon_x + (begin.x - 1) * size-BIGGER_SIZE / 2, startIcon_y + (begin.y - 1) * size- BIGGER_SIZE / 2, &big_img_icon[(map[begin.y][begin.x] - 1) / ICON_ROW_NUM][(map[begin.y][begin.x] - 1) % ICON_ROW_NUM], SRCPAINT);//原图
	}
}

//随机打乱数字地图
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

//处理游戏的对图标的鼠标信息，获取点击的图标下标（鼠标）+对其的相消处理
void mouseIcon(MOUSEMSG msg)
{
	if (iconClicking != 0)
	{
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= startIcon_x && msg.x <= startIcon_x + n * size && msg.y >= startIcon_y && msg.y <= startIcon_y + n * size && (msg.x - startIcon_x) % size <= ICON_SIZE && (msg.y - startIcon_y) % size <= ICON_SIZE && iconClicking == 1)
		{
			begin.x = (msg.x - startIcon_x) / size + 1;
			begin.y = (msg.y - startIcon_y) / size + 1;
			if (map[begin.y][begin.x] != 0)//排除点击已消过空白处
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
				printf("begin=%d,end=%d。消！\n", map[begin.y][begin.x], map[end.y][end.x]);
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

//处理点击“关于”按钮的情况
void About()
{	
	printf("按下“关于”\n");
	putimage((BACKGROUND_WIDTH-ABOUT_WINDOW_SIZE)/2, 0 , &img_mask_about, SRCAND);//掩码图
	putimage((BACKGROUND_WIDTH - ABOUT_WINDOW_SIZE) / 2, 0, &img_about, SRCPAINT);//原图
	isAbout = 1;
}

//处理点击“开始”按钮的情况
void Start() 
{
	first_xiao = 1;
	sumTime = 0.0;
	preTime = 0.0;
	//对地图的处理：创建+打乱+展示
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_start, SRCAND);//掩码图
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_start, SRCPAINT);//原图
	isStart = 1;

	InputBox(player_now.name, 20, "请输入玩家名：");//用对话框获取输入

    //玩家名的输出
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	// 设置字体样式  设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = START_NAME_SIZE;						// 设置字体高度
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(START_NAME_X,START_NAME_Y,player_now.name);//输入玩家名

	//选择游戏规模
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
		GameRun();//连连看游戏功能

}

//处理选择规模
void SizeN1()
{
	n = MAP_SIZE1;
	printf("选择规模为n=10！\n");
	setlinecolor(WHITE);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
	setlinecolor(RED);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
}
void SizeN2()
{
	n = MAP_SIZE2;
	printf("选择规模为n=12！\n");
	setlinecolor(WHITE);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
	setlinecolor(RED);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
}
void SizeN3()
{
	n = MAP_SIZE3;
	printf("选择规模为n=14！\n");
	setlinecolor(WHITE);
	rectangle(START_N1_X, START_N_Y, START_N1_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	rectangle(START_N2_X, START_N_Y, START_N2_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT);
	setlinecolor(RED);
	rectangle(START_N3_X, START_N_Y, START_N3_X + START_N_WIDTH, START_N_Y + START_N_HEIGHT+1);
}

//刷新页面，计时器+背景+图标
void pageRefresh()
{
	
	putimage(0, 0, &img_beijing);//刷新页面
	if (isSuspend == 1)//如果处于暂停状态下
	{
		//恢复原来页面上的一切
		
		//画继续键
		putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_mask_continue, SRCAND);
		putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_continue, SRCPAINT);
		
        iconDraw();//放图标

		//画计时  
		// 输出数值，先将数字格式化输出为字符串（MBCS 字符集）
		char s[10];
		sprintf_s(s, "%d", TIME - (int)preTime);
		setbkmode(TRANSPARENT);//背景模式设为透明
		settextcolor(DARKGRAY);//设置颜色
		// 设置字体样式  设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
		LOGFONT f;
		gettextstyle(&f);						// 获取当前字体设置
		f.lfHeight = 48;						// 设置字体高度为 48
		_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
		f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
		settextstyle(&f);						// 设置字体样式

		outtextxy(TIMER_X, TIMER_Y, s);//画倒计时
		setlinecolor(BLUE);
		line(TIMER_X, TIMER_LINE_Y, TIMER_X + TIMER_LINE_LENGTH * (TIME - preTime) / TIME, TIMER_LINE_Y);
	}
	
}
//获取并处理鼠标信息
void mouseGet()
{
	if (MouseHit())//获取一次鼠标消息
	{
		MOUSEMSG msg = GetMouseMsg();
		
		//左击+处于关于范围内+不处于游戏/开始状态
		if (iconClicking==0&&isStart==0&&msg.uMsg == WM_LBUTTONDOWN && msg.x >= ABOUT_BUTTON_X && msg.x <= ABOUT_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT) {
			About();
		}
		//左击+处于关于的确定按钮范围内+关于窗口已打开
		if (isAbout == 1 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= ABOUT_YES_X && msg.x <= ABOUT_YES_X + ABOUT_YES_WIDTH && msg.y >= ABOUT_YES_Y && msg.y <= ABOUT_YES_Y + ABOUT_YES_HEIGHT)
		{
			isAbout = 0;
			pageRefresh();
			printf("按下关于页面的确定!\n");
		}
		
		//判断加处理
		//左击+处于游戏图标范围内点击图标+开始游戏
		mouseIcon(msg);
		
		//左击+处于退出按钮范围内
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= EXIT_BUTTON_X && msg.x <= EXIT_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			closegraph();//关闭图像窗口
			exit(0);//正常退出
		}

		//左击+开始窗口未打开+处于开始按钮范围内
		if (msg.uMsg == WM_LBUTTONDOWN &&isStart==0&& msg.x >= BEGIN_BUTTON_X && msg.x <=BEGIN_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			Start();
		}
		
		//左击+开始窗口打开+处于n=10规模按钮范围内
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N1_X && msg.x <= START_N1_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN1();
		}
		//左击+开始窗口打开+处于n=12规模按钮范围内
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N2_X && msg.x <= START_N2_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN2();
		}
		//左击+开始窗口打开+处于n=14规模按钮范围内
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_N3_X && msg.x <= START_N3_X + START_N_WIDTH && msg.y >= START_N_Y && msg.y <= START_N_HEIGHT + START_N_Y)
		{
			SizeN3();
		}
		//左击+开始窗口打开+处于确定按钮范围内->关闭窗口
		if (msg.uMsg == WM_LBUTTONDOWN && isStart == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isStart = 0;
			putimage(0, 0, &img_beijing);//刷新页面
			printf("按下开始页面的确定!\n");
		}
		//左击+你赢了窗口打开+处于确定按钮范围内->关闭窗口
		if (msg.uMsg == WM_LBUTTONDOWN && isWin == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isWin = 0;
			putimage(0, 0, &img_beijing);//刷新页面
			printf("按下你赢了页面的确定!\n");
		}
		//左击+你输了窗口打开+处于确定按钮范围内->关闭窗口
		if (msg.uMsg == WM_LBUTTONDOWN && isLost == 1 && msg.x >= START_YES_X && msg.x <= START_YES_X + START_YES_WIDTH && msg.y >= START_YES_Y && msg.y <= START_YES_HEIGHT + START_YES_Y)
		{
			isLost = 0;
			putimage(0, 0, &img_beijing);//刷新页面
			printf("按下你输了页面的确定!\n");
		}

		//左击+处于排行榜按钮范围内
		if ( msg.uMsg == WM_LBUTTONDOWN && msg.x >= RANKINGLIST_BUTTON_X && msg.x <= RANKINGLIST_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			rankingList();
			printf("按下排行榜按钮!\n");
		}
		//左击+排行榜窗口打开+处于排行榜的退出按钮中
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_QUIT_X && msg.x <= RANKLIST_QUIT_X + RANKLIST_QUIT_SIZE && msg.y >= RANKLIST_QUIT_Y && msg.y <= RANKLIST_QUIT_Y + RANKLIST_QUIT_SIZE)
		{
			isRankinglist = 0;
			pageRefresh();
			printf("按下排行榜页面的退出!\n");
		}
		//左击+排行榜窗口打开+处于排行榜的10*10规模按钮中
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 10;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("按下排行榜页面的10*10规模键!\n");
		}
		//左击+排行榜窗口打开+处于排行榜的12*12规模按钮中
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X+ RANKLIST_N_WIDTH && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH*2 && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 12;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("按下排行榜页面的12*12规模键!\n");
		}
		//左击+排行榜窗口打开+处于排行榜的14*14规模按钮中
		if (msg.uMsg == WM_LBUTTONDOWN && isRankinglist == 1 && msg.x >= RANKLIST_N1_X+RANKLIST_N_WIDTH*2 && msg.x <= RANKLIST_N1_X + RANKLIST_N_WIDTH*3 && msg.y >= RANKLIST_N1_Y && msg.y <= RANKLIST_N1_Y + RANKLIST_N_HEIGHT)
		{
			n_choose = 14;
			putimage(0, 0, &img_beijing);
			rankingList();
			printf("按下排行榜页面的14*14规模键!\n");
		}
		//左击+处于暂停按钮范围内+处于游戏状态
		if (iconClicking != 0 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= SUSPEND_BUTTON_X && msg.x <= SUSPEND_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT) 
		{
			Suspend();
			printf("按下暂停按钮!\n");
			return;//退出，避免执行下面的继续
		}
		//左击+处于继续按钮范围内+处于游戏状态
		if (isSuspend== 1 && msg.uMsg == WM_LBUTTONDOWN && msg.x >= SUSPEND_BUTTON_X && msg.x <= SUSPEND_BUTTON_X + BUTTON_WIDTH && msg.y >= BUTTON_Y && msg.y <= BUTTON_Y + BUTTON_HEIGHT)
		{
			isSuspend = 0;
			iconClicking = 1;
			startTime = time(NULL);
			putimage(0, 0, &img_beijing);//刷新页面
			printf("按下继续按钮\n");
		}

	}
}



//判断某位位置是否有图标
bool isIcon(int x, int y)
{
	return map[y][x];
}

//直线消除
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

//一个转角的情况
bool oneTurn(struct Index begin, struct Index end)
{
	struct Index turn1 = { begin.x,end.y }, turn2 = { end.x,begin.y };
	if (!isIcon(turn1.x, turn1.y))//第一个转角没有图标
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

//两个转角的情况
bool twoTure(struct Index begin, struct Index end)
{
	//两个拐角位于同一行
	for (int i = 0; i < n+2 ; i++)
	{
		if (i == begin.x || i == end.x)//排除与begin和end位于同一行的情况
			continue;
		struct Index turn1 = { i,begin.y }, turn2 = { i,end.y };
		if (isIcon(turn1.x, turn1.y) || isIcon(turn2.x, turn2.y))//turn1和turn2不能有图标
			continue;
		if(line(begin,turn1)&&line(turn1,turn2)&&line(turn2,end))
			return true;
	}
	//两个拐角位于同一列
	for (int i = 0; i < n+2; i++)
	{
		if (i == begin.y || i == end.y)//排除与begin和end位于同一行的情况
			continue;
		struct Index turn1 = { begin.x,i }, turn2 = { end.x,i };
		if (isIcon(turn1.x, turn1.y) || isIcon(turn2.x, turn2.y))
			continue;
		if (line(begin, turn1) && line(turn1, turn2) && line(turn2, end))
			return true;
	}
	return false;
}

//判断能否消除begin和end的两个图标
bool earse(struct Index begin, struct Index end)
{
	if (map[begin.y][begin.x] != map[end.y][end.x])//如果图标不一样
		return false;
	if (begin.x == end.x && begin.y == end.y)//如果两个图标为同一个
		return false;
	bool flag = false;
	if (line(begin, end))//处于同一条直线上的消除
		flag = true;
	else if (oneTurn(begin, end))//一个转角的消除
		flag = true;
	else if (twoTure(begin, end))//两个转角消除
		flag = true;
	return flag;
}

//计算游戏得分
int score(int remain, double time)
{
	return (TIME - (int)time) * 50 + (n * n - remain) * 25;//剩下时间+所消图标
}

//运行游戏
void GameRun()
{
	if (iconClicking == 0)
		return;
	//iconClicking = 1;//要玩连连看的时候把这个调到1
	mciSendString("open 侯俊杰-一决高下（轻松版）.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);//播放音乐
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
		BeginBatchDraw();//开始双缓冲绘图
		putimage(0, 0, &img_beijing);//放背景图
		iconDraw();//放图标
		//画计时  
		// 输出数值，先将数字格式化输出为字符串（MBCS 字符集）
		char s[10];
		sprintf_s(s, "%d", TIME-(int)(sumTime+preTime));
		setbkmode(TRANSPARENT);//背景模式设为透明
		settextcolor(DARKGRAY);//设置颜色
		// 设置字体样式  设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
		LOGFONT f;
		gettextstyle(&f);						// 获取当前字体设置
		f.lfHeight = 48;						// 设置字体高度为 48
		_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
		f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
		settextstyle(&f);						// 设置字体样式
		
		outtextxy(TIMER_X, TIMER_Y, s);//画倒计时
		setlinecolor(BLUE);
		line(TIMER_X, TIMER_LINE_Y, TIMER_X+ TIMER_LINE_LENGTH*(TIME-(sumTime+preTime))/TIME, TIMER_LINE_Y);
		EndBatchDraw();//结束双缓冲绘图

		//地图画面刷新完再判断，避免最后两个图标消不掉的情况
		if ((int)(sumTime+ preTime)== TIME)
		{
			iconClicking = 0;
			endTime = time(NULL);//停止计时
			sumTime = TIME;
			player_now.time = sumTime;
			player_now.score = score(numRemain, sumTime);
			player_now.remain = numRemain;
			printf("游戏失败！用时：%.2f,得分：%d\n", player_now.time,player_now.score);
			WritePlayer();
			mciSendString("stop bgm", NULL, 0, NULL);
			mciSendString("close bgm", NULL, 0, NULL);
			Lost();

			break;
		}

		if (numRemain == 0)//全部消完，游戏结束
		{
			iconClicking = 0;
			Sleep(500);//让玩家看一下全消玩的界面，比较有成就感
			endTime = time(NULL);//停止计时
			sumTime = endTime - startTime+preTime;
			//把玩家信息存入文件，并得到比较后的排名
			player_now.time = sumTime;
			player_now.score = score(numRemain, sumTime);
			player_now.remain = 0;
			WritePlayer();
			printf("游戏结束！用时：%.2f,得分：%d\n", player_now.time, player_now.score);
			mciSendString("stop bgm", NULL, 0, NULL);
			mciSendString("close bgm", NULL, 0, NULL);
			Win();

			break;
		}
		mouseGet();
		//计算此时时间
		while (isSuspend == 1)//暂停时不断判断
		{
			mouseGet();
		}
		endTime = time(NULL);
		sumTime = endTime - startTime;

	}
}

//把开始玩时间放到player_now中里
int GetTime()
{
	time_t now;
	time(&now);
	struct tm* tm = localtime(&now);// 转换为 struct tm 以便分解各个组件
	// 将时间组件格式化为字符串
	char timeString[100];
	sprintf(timeString, "%04d-%02d-%02d-%02d:%02d:%02d",
		tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	
	snprintf(player_now.date, sizeof(player_now.date), "%s", timeString);
	return 0;
}

//开启你赢了窗口并输出信息
void Win()
{
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_win, SRCAND);//掩码图
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_win, SRCPAINT);//原图
	isWin = 1;
	
	//输出用时
	char s1[10];
	sprintf_s(s1, "%d", (int)player_now.time);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f1;
	gettextstyle(&f1);						// 获取当前字体设置
	f1.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f1.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f1.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f1);						// 设置字体样式
	outtextxy(START_NAME_X, START_NAME_Y, s1);

	//输出得分
	char s2[10];
	sprintf_s(s2, "%d", player_now.score);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f2;
	gettextstyle(&f2);						// 获取当前字体设置
	f2.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f2.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f2.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f2);						// 设置字体样式
	outtextxy(START_NAME_X, WIN_SCORE_Y, s2);

	//输出排名
	char s3[10];
	sprintf_s(s3, "%d", player_now.rank);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f3;
	gettextstyle(&f3);						// 获取当前字体设置
	f3.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f3.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f3.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f3);						// 设置字体样式
	outtextxy(START_NAME_X, START_N_Y+6, s3);

}

//开启你输了窗口并输出信息
void Lost() {
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_mask_lost, SRCAND);//掩码图
	putimage((BACKGROUND_WIDTH - START_WINDOW_WIDTH) / 2, GAMEPLACE_Y, &img_lost, SRCPAINT);//原图
	isLost = 1;

	//输出还剩
	char s1[10];
	sprintf_s(s1, "%d", player_now.remain);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f1;
	gettextstyle(&f1);						// 获取当前字体设置
	f1.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f1.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f1.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f1);						// 设置字体样式
	outtextxy(LOST_REMAIN_X, LOST_REMAIN_Y, s1);

	//输出得分
	char s2[10];
	sprintf_s(s2, "%d", player_now.score);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f2;
	gettextstyle(&f2);						// 获取当前字体设置
	f2.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f2.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f2.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f2);						// 设置字体样式
	outtextxy(LOST_X, LOST_SCORE_Y, s2);

	//输出排名
	char s3[10];
	sprintf_s(s3, "%d", player_now.rank);
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f3;
	gettextstyle(&f3);						// 获取当前字体设置
	f3.lfHeight = START_NAME_SIZE;			// 设置字体高度，与开始界面上的玩家名大小坐标相同
	_tcscpy(f3.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f3.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f3);						// 设置字体样式
	outtextxy(LOST_X, LOST_RANK_Y, s3);
}

//把玩家数据按顺序写入文件
void WritePlayer()
{
	Player player1;//临时结构体变量，用于存放读取文件中的玩家数据
	int flag = 1;//用于标记是否已写入当前玩家数据
	int rank_count = 1;//一个个数过来排序算得分排名
	FILE *f1, *f2, *f3, *f4;
	f1 = fopen("player_rank1_little.txt", "a+");//player_rank1_little.txt为原有文件 10X10规模
	f2 = fopen("player_rank1_medium.txt", "a+");//player_rank1_medium.txt为原有文件 12X12规模
	f3 = fopen("player_rank1_large.txt", "a+");//player_rank_medium.txt为原有文件 14X14规模
	f4 = fopen("player_rank2.txt", "w+");//player_rank2.txt为临时文件，用于覆盖player_rank1.txt

	if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL)
	{
		perror("Error opening file");
		return;
	}
	
	if (player_now.n == MAP_SIZE1) {
		while (!feof(f1))
		{
			int result = fscanf(f1, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//结构体变量player1为从f1中读出的一行文件
			if (result == 5)// 确保成功读取了5个数据项
			{
				if (player_now.score >= player1.score && flag)//原文件f1以得分降序排序
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
			else// 读取失败时的处理
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
			perror("Error deleting player_rank1_little.txt");// perror 函数打印错误消息
		}
		
		// 检查是否成功重命名临时文件
		if (rename("player_rank2.txt", "player_rank1_little.txt") != 0)
		{
			perror("Error renaming player_rank4.txt to player_rank1_little.txt");
		}
		
	}
	else {
		if (player_now.n == MAP_SIZE2) {
			while (!feof(f2))
			{
				int result = fscanf(f2, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//结构体变量player1为从f1中读出的一行文件
				if (result == 5)// 确保成功读取了5个数据项
				{
					if (player_now.score >= player1.score && flag)//原文件f1以得分降序排序
					{
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
						player_now.rank = rank_count;
						rank_count++;
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
						flag = 0;//结构体变量player_now为当前玩家的数据
					}
					else {
						fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
					}

					rank_count++;
				}
				else// 读取失败时的处理
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
				perror("Error deleting player_rank1_medium.txt");// perror 函数打印错误消息
			}

			// 检查是否成功重命名临时文件
			if (rename("player_rank2.txt", "player_rank1_medium.txt") != 0)
			{
				perror("Error renaming player_rank4.txt to player_rank1_medium.txt");
			}
		}
		else {
			if (player_now.n == MAP_SIZE3) {
				while (!feof(f3))
				{
					int result = fscanf(f3, "%d %s %d %lf %s\n", &player1.rank, player1.name, &player1.score, &player1.time, player1.date);//结构体变量player1为从f1中读出的一行文件
					if (result == 5)// 确保成功读取了5个数据项
					{
						if (player_now.score >= player1.score && flag)//原文件f1以得分降序排序
						{
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
							player_now.rank = rank_count;
							rank_count++;
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
							flag = 0;//结构体变量player_now为当前玩家的数据
							printf("计入\n");
						}
						else {
							fprintf(f4, "%d %s %d %f %s\n", rank_count, player1.name, player1.score, player1.time, player1.date);
						}

						rank_count++;
					}
					else// 读取失败时的处理
					{
						break;
					}
				}
				if (flag)
				{
					fprintf(f4, "%d %s %d %f %s\n", rank_count, player_now.name, player_now.score, player_now.time, player_now.date);
					player_now.rank = rank_count;
					printf("计入\n");
				}

				fclose(f1);
				fclose(f2);
				fclose(f3);
				fclose(f4);
				if (remove("player_rank1_large.txt") != 0)
				{
					perror("Error deleting player_rank1_large.txt");// perror 函数打印错误消息
				}

				// 检查是否成功重命名临时文件
				if (rename("player_rank2.txt", "player_rank1_large.txt") != 0)
				{
					perror("Error renaming player_rank2.txt to player_rank1_large.txt");
				}
			}
			
		}
	}
}

//处理暂停操作
void Suspend()
{
	isSuspend = 1;
	putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_mask_continue, SRCAND);
	putimage(SUSPEND_BUTTON_X, BUTTON_Y, &img_continue, SRCPAINT);
	iconClicking = 0;
	endTime = time(NULL);
	preTime += endTime - startTime;
	
}

//处理显示排行榜操作
void rankingList()
{
	putimage(0, 0, &img_mask_rankinglist, SRCAND);
	putimage(0, 0, &img_rankinglist, SRCPAINT);
	isRankinglist = 1;
	
	//写标题行
	setbkmode(TRANSPARENT);//背景模式设为透明
	settextcolor(DARKGRAY);//设置颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = RANKLIST_TITLE_SIZE;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	char s1[] = "排名";
	outtextxy(RANKLIST_TITLE_RANK_X,RANKLIST_TITLE_Y ,s1);
	char s2[] = "玩家名";
	outtextxy(RANKLIST_TITLE_NAME_X, RANKLIST_TITLE_Y, s2);
	char s3[] = "得分";
	outtextxy(RANKLIST_TITLE_SCORE_X, RANKLIST_TITLE_Y, s3);
	char s4[] = "日期";
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

	// 设置字体样式  
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = RANKLIST_DATA_SIZE;		// 设置字体高度
	settextstyle(&f);

	if (n_choose == 10)
	{
		setlinecolor(RED);
		rectangle(RANKLIST_N1_X,RANKLIST_N1_Y,RANKLIST_N1_X+RANKLIST_N_WIDTH,RANKLIST_N1_Y+RANKLIST_N_HEIGHT);
		for (int i = 0; i < RANKLIST_DATA_N; i++)
		{
			Player player;

			if (feof(f1) != 0)//读到末尾
				break;
			if (fscanf(f1, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("读取文件失败！\n");
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
			if (feof(f2)!=0)//读到末尾
				break;
			if (fscanf(f2, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("读取文件失败！\n");
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
			if (feof(f3)!=0)//读到末尾
				break;
			if (fscanf(f3, "%d %s %d %lf %s\n", &player.rank, player.name, &player.score, &player.time, player.date) !=5)
			{
				printf("读取文件失败！\n");
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
		printf("文件规模出错！\n");
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}

int main()
{
	gameInit();//游戏初始化，加载图片，创建原始地图等

	while (1)
	{
		mouseGet();
	}
	
	return 1;
}