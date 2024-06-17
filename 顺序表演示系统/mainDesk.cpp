#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType; 

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  
	ElemType * elem;
	int length;
	int listsize;
}SqList;
typedef struct
{
     struct { char name[30];
     		  SqList L;	
      } elem[10];
      int length;
      int listsize;
 }LISTS;

status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType& e);
status LocateElem(SqList L,ElemType e); 
status PriorElem(SqList L,ElemType cur,ElemType& pre_e);
status NextElem(SqList L,ElemType cur,ElemType& next_e);
status ListInsert(SqList&L,int i,ElemType e);
status ListDelete(SqList&L,int i,ElemType& e);
status ListTrabverse(SqList L); 
status  SaveList(SqList L,char FileName[]);
status  LoadList(SqList &L,char FileName[]);
status AddList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
status MaxSubArray(SqList&L);
status SubArrayNum(SqList&L,int k);
status SortList(SqList&L);
status GetList(LISTS&Lists,SqList &L,int num);
int main(void)
{
	SqList L;  
	LISTS List;
	List.length = 0;
	List.listsize = 10;
	int op = 1 , num = 0 , e = 0,pre_e = 0,next_e = 0,result = 0, num2= 0;
	char filename[30];
	DestroyList(L);
	while(op)
	{
		system("cls");	
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList\t\t2.DestroyList\n");
		printf("    	  3. ClearList\t\t4.ListEmpty\n");
		printf("    	  5. ListLength\t\t6.GetElem\n");
		printf("    	  7. LocateElem\t\t8.PriorElem\n");
		printf("    	  9. NextElem\t\t10.ListInsert\n");
		printf("    	  11. ListDelete\t12.ListTrabverse\n");
		printf("    	  13. MaxSubArray\t14.SubArrayNum\n");
		printf("    	  15. SortList\t\t16.SaveList\n");
		printf("    	  17. LoadList\t\t18.EnterListManagerMode\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~18]:");
		scanf("%d",&op);
	    switch(op)
		{
		   	case 1:
			 	if(InitList(L)==OK) 
					printf("线性表创建成功！\n");
			    else 
					printf("线性表创建失败！\n");
			 	getchar();
				getchar();
			 	break;
		   	case 2:
				if(DestroyList(L)==OK)
					printf("线性表销毁成功！\n");
				else
					printf("线性表销毁失败！\n");
			 	getchar();
				getchar();
			 	break;
		   	case 3:
			 	if(ClearList(L)==OK)
				 	printf("线性表清空成功！\n");
				else
				 	printf("线性表清空失败！\n");   
			 	getchar();
				getchar();
			 	break;
		   	case 4:
			 	if((result = ListEmpty(L))==TRUE)
					printf("线性表是空的！\n");
				else if(result ==FALSE)
					printf("线性表不是空的！\n");
				else
					printf("线性表判空失败！\n");
			 	getchar();
				getchar();
			 	break;
		   	case 5:
				if(ListLength(L)==INFEASTABLE)
					printf("获取长度失败！\n");
				else
					printf("线性表长度为%d\n",ListLength(L));
				getchar();
				getchar();
				break;
		   	case 6:
		   		printf("请输入你想获取第几个元素:\n");
		   		scanf("%d",&num);
				if(GetElem(L,num,e)==INFEASTABLE)
					printf("获取元素失败！\n");
				else
					printf("线性表第%d个元素的值为%d\n",num,e);
				getchar();
				getchar();
				break;
		   	case 7:
				printf("请输入你想查找的元素:\n");
				scanf("%d",&e);
				if((result = LocateElem(L,e))==INFEASTABLE)
					printf("查找元素失败！\n");
				else if (result == 0)
					printf("表里没有这个元素哦！\n");
				else
					printf("这个元素是表里面的第%d个元素\n",LocateElem(L,e));
				getchar();
				getchar();
				break;
		   	case 8:
				printf("请输入你想获得前驱的元素：\n");
				scanf("%d",&e);
				if((result=PriorElem(L,e,pre_e))==INFEASTABLE)
					printf("获取失败了！\n");
				else if(result == ERROR)
					printf("是第一个，或者根本没找到\n");
				else
					printf("是%d哦!\n",pre_e);
				getchar();
				getchar();
				break;
		   	case 9:
				printf("请输入你想获得后继的元素:\n");
				scanf("%d",&e);
				if((result = NextElem(L,e,next_e) )== INFEASTABLE)
					printf("获取失败\n");
				else if (result==ERROR)
					printf("最后一个，或者根本没找到\n");
				else
					printf("是%d哦！\n",next_e);
				getchar();
				getchar();
				break;
		   	case 10:
				printf("请输入你想插入的位置及元素:\n");
				scanf("%d %d",&num,&e);
				if((result=ListInsert(L,num,e))==INFEASTABLE)
					printf("插入失败\n");
				else if(result==ERROR)
					printf("给的位置不合法\n");
				else
				{
					printf("插入成功！\n");
//					printf("现在这个列表是这样的:\n");
//					ListTrabverse(L);
// 					测试用临时代码
				}
				getchar();
				getchar();
				break;
		   	case 11:
				printf("请输入你想删除的元素的序号：\n");
				scanf("%d",&num);
				if((result = ListDelete(L,num,e))==INFEASTABLE)
					printf("删除失败\n");
				else if(result == ERROR)
					printf("找不到\n");
				else
					printf("删除了%d\n",e);
				getchar();
				getchar();
				break;
		   	case 12: 
				if(ListTrabverse(L)==INFEASTABLE) 
					printf("线性表是空表！\n");
				getchar();
				getchar();
			 	break;
			case 13:
				if((result = MaxSubArray(L))==INFEASTABLE)
					printf("失败\n");
				else
					printf("%d\n",result);
				getchar();
				getchar();
				break;
			case 14:
				printf("请输入你的和：\n");
				scanf("%d",&num);
				if((result = SubArrayNum(L,num))==INFEASTABLE)
					printf("失败\n");
				else
					printf("%d\n",result);
				getchar();
				getchar();
				break;
			case 15:
				if((result = SortList(L))==INFEASTABLE)
					printf("失败\n");
				else if(result == ERROR)
					printf("表为空\n");
				else
					printf("整理完毕\n");
				getchar();
				getchar();
				break;
			case 16:
				printf("请输入文件名:\n");
				scanf("%s",filename);
				if((result = SaveList(L,filename)) == OK)printf("保存完成\n");
				else printf("保存失败\n");
				getchar();
				getchar();
				break;
			case 17:
				printf("请输入文件名:\n");
				scanf("%s",filename);
				if((result = LoadList(L,filename))==OK)printf("加载完成\n");
				else printf("加载失败\n");
				getchar();
				getchar();
				break;
			case 18:
				printf("-------------------------------------------------\n");
				printf("             已进入多线性表管理模式\n");
				printf("-------------------------------------------------\n");
				printf("    	  1. LocateList\t\t2.RemoveList\n");
				printf("    	  3. ClearList\t\t4.ListEmpty\n");
				printf("    	  5. ListLength\t\t6.GetElem\n");
				printf("    	  7. LocateElem\t\t8.PriorElem\n");
				printf("    	  9. NextElem\t\t10.ListInsert\n");
				printf("    	  11. ListDelete\t12.ListTrabverse\n");
				printf("    	  13. MaxSubArray\t14.SubArrayNum\n");
				printf("    	  15. SortList\t\t16.SaveList\n");
				printf("    	  17. LoadList\t\t18.AddList\n");
				printf("          0. Quit\n");
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~18]:");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						printf("请输入线性表名字：\n");
						scanf("%s",filename);
						if((result = LocateList(List,filename))!= 0) printf("是第%d个\n",result);
						else printf("没找到\n");
						getchar();
						getchar();
						break;
					case 2:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						if(RemoveList(List,List.elem[num-1].name)==OK)
							printf("线性表移除成功！\n");
						else
							printf("线性表移除失败！\n");
						getchar();
						getchar();
						break;
				   	case 3:
				   		printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
					 	if(ClearList(List.elem[num-1].L)==OK)
						 	printf("线性表清空成功！\n");
						else
							printf("线性表清空失败！\n");   
					 	getchar();
						getchar();
					 	break;
				   	case 4:
				   		printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
					 	if((result = ListEmpty(List.elem[num-1].L))==TRUE)
							printf("线性表是空的！\n");
						else if(result ==FALSE)
							printf("线性表不是空的！\n");
						else
							printf("线性表判空失败！\n");
					 	getchar();
						getchar();
					 	break;
				   	case 5:
				   		printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						if(ListLength(List.elem[num-1].L)==INFEASTABLE)
							printf("获取长度失败！\n");
						else
							printf("线性表长度为%d\n",ListLength(L));
						getchar();
						getchar();
						break;
					case 6:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想获取第几个元素:\n");
						scanf("%d",&num2);
						if(GetElem(List.elem[num-1].L,num2,e)==INFEASTABLE)
							printf("获取元素失败！\n");
						else
							printf("线性表第%d个元素的值为%d\n",num2,e);
						getchar();
						getchar();
						break;
					case 7:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想查找的元素:\n");
						scanf("%d",&e);
						if((result = LocateElem(List.elem[num-1].L,e))==INFEASTABLE)
							printf("查找元素失败！\n");
						else if (result == 0)
							printf("表里没有这个元素哦！\n");
						else
							printf("这个元素是表里面的第%d个元素\n",LocateElem(List.elem[num-1].L,e));
						getchar();
						getchar();
						break;
					case 8:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想获得前驱的元素：\n");
						scanf("%d",&e);
						if((result=PriorElem(List.elem[num-1].L,e,pre_e))==INFEASTABLE)
							printf("获取失败了！\n");
						else if(result == ERROR)
							printf("是第一个，或者根本没找到\n");
						else
							printf("是%d哦!\n",pre_e);
						getchar();
						getchar();
						break;
					case 9:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想获得后继的元素:\n");
						scanf("%d",&e);
						if((result = NextElem(List.elem[num-1].L,e,next_e) )== INFEASTABLE)
							printf("获取失败\n");
						else if (result==ERROR)
							printf("最后一个，或者根本没找到\n");
						else
							printf("是%d哦！\n",next_e);
						getchar();
						getchar();
						break;
					case 10:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想插入的位置及元素:\n");
						scanf("%d %d",&num2,&e);
						if((result=ListInsert(List.elem[num-1].L,num2,e))==INFEASTABLE)
							printf("插入失败\n");
						else if(result==ERROR)
							printf("给的位置不合法\n");
						else
						{
							printf("插入成功！\n");
		//					printf("现在这个列表是这样的:\n");
		//					ListTrabverse(L);
		// 					测试用临时代码
						}
						getchar();
						getchar();
						break;
					case 11:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你想删除的元素的序号：\n");
						scanf("%d",&num2);
						if((result = ListDelete(List.elem[num-1].L,num2,e))==INFEASTABLE)
							printf("删除失败\n");
						else if(result == ERROR)
							printf("找不到\n");
						else
							printf("删除了%d\n",e);
						getchar();
						getchar();
						break;
					case 12: 
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						if(ListTrabverse(List.elem[num-1].L)==INFEASTABLE) 
							printf("线性表是空表！\n");
						getchar();
						getchar();
						break;
					case 13:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						if((result = MaxSubArray(List.elem[num-1].L))==INFEASTABLE)
							printf("失败\n");
						else
							printf("%d\n",result);
						getchar();
						getchar();
						break;
					case 14:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入你的和：\n");
						scanf("%d",&num2);
						if((result = SubArrayNum(List.elem[num-1].L,num))==INFEASTABLE)
							printf("失败\n");
						else
							printf("%d\n",result);
						getchar();
						getchar();
						break;
					case 15:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						if((result = SortList(List.elem[num-1].L))==INFEASTABLE)
							printf("失败\n");
						else if(result == ERROR)
							printf("表为空\n");
						else
							printf("整理完毕\n");
						getchar();
						getchar();
						break;
					case 16:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入文件名:\n");
						scanf("%s",filename);
						if((result = SaveList(List.elem[num-1].L,filename)) == OK)printf("保存完成\n");
						else printf("保存失败\n");
						getchar();
						getchar();
						break;
					case 17:
						printf("请输入你想操作的线性表序号:\n");
						scanf("%d",&num);
						printf("请输入文件名:\n");
						scanf("%s",filename);
						if((result = LoadList(List.elem[num-1].L,filename))==OK)printf("加载完成\n");
						else printf("加载失败\n");
						getchar();
						getchar();
						break;
					case 18:
						printf("请输入线性表名字:\n");
						scanf("%s",filename);
						if((result = AddList(List,filename))==OK)printf("保存完毕\n");
						else printf("保存失败\n");
						getchar();
						getchar();
						break;
					case 0:
						break;
				}
//			case 18:
//				printf("请输入线性表名字:\n");
//				scanf("%s",filename);
//				if((result = AddList(List,filename))==OK)printf("保存完毕\n");
//				else printf("保存失败\n");
//				getchar();
//				getchar();
//				break;
//			case 19:
//				printf("请输入线性表名字：\n");
//				scanf("%s",filename);
//				if((result = LocateList(List,filename))!= 0) printf("是第%d个\n",result);
//				else printf("没找到\n");
//				getchar();
//				getchar();
//				break;
//			case 20:
//				printf("请输入线性表名字：\n");
//				scanf("%s",filename);
//				if((result = RemoveList(List,filename)) == OK) printf("删除完毕\n");
//				else printf("删除失败\n");
//				getchar();
//				getchar();
//				break;
//			case 21:
//				printf("请输入要加载的线性表的序号：\n");
//				scanf("%d",&num);
//				if((result = GetList(List,L,num))== OK) printf("加载完毕\n");
//				else printf("加载失败\n");
//				getchar();
//				getchar();
//				break;
			case 0:
	         	break;
		}
	}
	printf("\t欢迎下次再使用本系统！\n");
}
status InitList(SqList& L)
{
    if(L.elem != NULL)
    {
        return INFEASTABLE;
    }
    else
    {
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
    }
    return OK;
}
status DestroyList(SqList& L)
{
    if(L.elem == NULL)
    {
        return INFEASTABLE;
    }
    else
    {
        free(L.elem);
        L.elem = NULL;//置空
        L.length = 0 ;
        L.listsize = 0;
    }
    return OK;
}
status ClearList(SqList& L)
{

    if(L.elem == NULL)
        return INFEASTABLE;
    else
    {
        free(L.elem);
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);//分配空间
        L.length = 0;
        L.listsize = 0;
    }
    return OK;
}
status ListEmpty(SqList L)
{
    if(L.elem != NULL)
    {
        if(L.length == 0)//看length就行
            return TRUE;
        return FALSE;
    }
    else
        return INFEASTABLE;
}
status ListLength(SqList L)
{
    if(L.elem != NULL)
        return L.length;//返回length就行
    else
        return INFEASTABLE; 
}
status GetElem(SqList L,int i,ElemType &e)
{
    if(L.elem != NULL)
    {
        if(i>L.length || i < 1)
            return ERROR;
        e = L.elem[i-1];
        return OK;
    }
    else
        return INFEASTABLE;
}
int LocateElem(SqList L,ElemType e)
{
    if(L.elem != NULL)
    {
        for(int i = 0; i < L.length;i++)
        {
            if(L.elem[i] == e) // 确定e的位置
                return i+1;
        }
        return 0;
    }
    else
        return INFEASTABLE;
}
status PriorElem(SqList L,ElemType e,ElemType &pre)
{
    if(L.elem != NULL)
    {
        for(int i = 0; i < L.length;i++)
        {
            if(L.elem[i] == e)//遍历找到e
            {
                if(i == 0)
                    return ERROR;
                pre = L.elem[i-1];
                return OK;
            }
        }
        return ERROR;
    }
    else
        return INFEASTABLE;
}
status NextElem(SqList L,ElemType e,ElemType &next)
{
    if(L.elem != NULL)
    {
        for(int i = 0; i < L.length;i++)
        {
            if(L.elem[i] == e) //遍历找到e
            {
                if(i == L.length-1)
                    return ERROR;
                next = L.elem[i+1];
                return OK;
            }
        }
        return ERROR;
    }
    else
        return INFEASTABLE;
}
status ListInsert(SqList &L,int i,ElemType e)
{
    if(L.elem != NULL)
    {
        if(i>L.length+1||i<1)
            return ERROR;
        ElemType * temp = (ElemType *)malloc(sizeof(ElemType)*(LIST_INIT_SIZE+1));//留出空间
        for(int j = 0; j < i-1 ; j++)
            temp[j] = L.elem[j];
        temp[i-1] = e; //插入e
        for(int j = i-1 ; j < L.length;j++)
            temp[j+1] = L.elem[j];
        L.length ++;
        L.listsize ++;
        free(L.elem);
        L.elem = temp;
        return OK;
    }
    else
        return INFEASTABLE;
}
status ListDelete(SqList &L,int i,ElemType &e)
{
    if(L.elem != NULL)
    {
        if(i>L.length||i<1)
            return ERROR;
        ElemType * temp = (ElemType *)malloc(sizeof(ElemType)*(LIST_INIT_SIZE-1)); //创造临时线性表
        for(int j = 0; j < i-1 ; j++)
            temp[j] = L.elem[j];
        e = L.elem[i-1]; //剔除要去掉的元素，同时存到e里面
        for(int j = i-1 ; j < L.length-1;j++)
            temp[j] = L.elem[j+1];
        L.length --;
        L.listsize --;
        free(L.elem);
        L.elem = temp; 
        return OK;
    }
    else
        return INFEASTABLE;
}
status ListTrabverse(SqList L)
{
    bool flag = false;
    if(L.elem != NULL)
    {
    	printf("\n-----------all elements -----------------------\n");
        for(int i = 0; i < L.length; i++)//遍历输出
        {
            if(flag)
                printf(" ");
            else
                flag = true;//flag用来标识第一个，第一个前面不打空格
            printf("%d",L.elem[i]);
        }
        printf("\n------------------ end ------------------------\n");
        return OK;
    }
    else
        return INFEASTABLE;
}
status  SaveList(SqList L,char FileName[])
{
    if(L.elem != NULL)
    {
        FILE  *fp; //保存为二进制文件
        fp=fopen(FileName,"wb");
        fwrite(L.elem,sizeof(ElemType),L.length,fp);
        fclose(fp);
        return OK;
    }
    else
        return INFEASTABLE;
}
status  LoadList(SqList &L,char FileName[])
{
    if(L.elem == NULL)
    {
        FILE *fp;
        L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE); 
        L.listsize = LIST_INIT_SIZE;
        L.length=0;
        fp=fopen(FileName,"rb");
        while(fread(L.elem+L.length,sizeof(ElemType),1,fp))//快读
            L.length++;
        return OK;
    }
    else
        return INFEASTABLE;
}
status AddList(LISTS &Lists,char ListName[])
{
    if(Lists.length<10)
    {
        int i = 0;
        while(ListName[i]!='\0') //输入名字
        {
            Lists.elem[Lists.length].name[i] = ListName[i];
            i++;
        }
        Lists.elem[Lists.length].L.elem = NULL;
        InitList(Lists.elem[Lists.length].L);//初始化
        Lists.length++;
        return OK;
    }
    return ERROR;
}
status RemoveList(LISTS &Lists,char ListName[])
{
    bool flag = true;
    int j = 0;
    for(int i = 0; i < Lists.length; i++)
    {
        flag = true;
        j = 0;
        while(ListName[j]!='\0') //比对名字
        {
            if(Lists.elem[i].name[j] != ListName[j])
                flag = false;
            j++;
        }
        if(flag)//如果找到了就删除
        {
            for(int j = i;j < Lists.length;j++)
                Lists.elem[j] = Lists.elem[j+1];
            Lists.length--;
            return OK;
        }
    }
    return ERROR;//没找到报错
}
int LocateList(LISTS Lists,char ListName[])
{
    bool flag = true;
    int j = 0;
    for(int i = 0; i < Lists.length; i++)
    {
        flag = true;
        j = 0;
        while(ListName[j]!='\0')//比对顺序表名字
        {
            if(Lists.elem[i].name[j] != ListName[j])
                flag = false;
            j++;
        }
        if(flag)
        {
            return i+1; //记住返回的是逻辑上的位置，不是数组里的序号
        }
    }
    return 0;
}
status MaxSubArray(SqList&L)
{
	int res=-114514,sum = 0;
	int e = 0;
	if(L.elem == NULL || L.length == 0)
		return INFEASTABLE;
	for(int i=0;i<L.length;i++) //遍历所有可能，寻找最大
	{
	    for(int j=i+1;j<=L.length;j++)
		{
	        sum=0;
	        for(int k=i+1;k<=j;k++)
	        {
				GetElem(L,k,e);
				sum += e;
	        }
	        res= res > sum ? res : sum;
	    }
	}
	return res;
}
status SubArrayNum(SqList&L,int k)
{
	if(L.elem == NULL)
		return INFEASTABLE;
	int e = 0,cnt = 0,sum = 0;
	for(int i=0;i<L.length;i++) //遍历寻找值相等的子数组，用cnt记录个数
	{
		for(int j=i+1;j<=L.length;j++) 
		{
		    sum=0;
		    for(int k=i+1;k<=j;k++)
		    {
				GetElem(L,k,e);
				sum += e;
		    }
		    if(sum == k)
		        cnt ++;
		}
	}
	return cnt;
}
status SortList(SqList&L)
{
	if(L.elem != NULL)
	{
		if(L.length == 0)
			return ERROR;
		else
		{ //冒泡排序
			int max = L.elem[0],maxNum = 0,temp = 0;
			for(int i = 0 ; i < L.length; i ++)
			{
				max = L.elem[0];
				maxNum = 0;
				for(int j = 0 ; j < L.length - i;j++)
				{
					if(max < L.elem[j])
					{
						max = L.elem[j];
						maxNum = j;
					}
				}
				temp = L.elem[L.length-1-i];
				L.elem[L.length-1-i] = max;
				L.elem[maxNum] = temp;
			}
		}
		return OK;
	}
	return INFEASTABLE;
}
