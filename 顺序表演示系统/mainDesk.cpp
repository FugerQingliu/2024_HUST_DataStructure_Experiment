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
		printf("    ��ѡ����Ĳ���[0~18]:");
		scanf("%d",&op);
	    switch(op)
		{
		   	case 1:
			 	if(InitList(L)==OK) 
					printf("���Ա����ɹ���\n");
			    else 
					printf("���Ա���ʧ�ܣ�\n");
			 	getchar();
				getchar();
			 	break;
		   	case 2:
				if(DestroyList(L)==OK)
					printf("���Ա����ٳɹ���\n");
				else
					printf("���Ա�����ʧ�ܣ�\n");
			 	getchar();
				getchar();
			 	break;
		   	case 3:
			 	if(ClearList(L)==OK)
				 	printf("���Ա���ճɹ���\n");
				else
				 	printf("���Ա����ʧ�ܣ�\n");   
			 	getchar();
				getchar();
			 	break;
		   	case 4:
			 	if((result = ListEmpty(L))==TRUE)
					printf("���Ա��ǿյģ�\n");
				else if(result ==FALSE)
					printf("���Ա��ǿյģ�\n");
				else
					printf("���Ա��п�ʧ�ܣ�\n");
			 	getchar();
				getchar();
			 	break;
		   	case 5:
				if(ListLength(L)==INFEASTABLE)
					printf("��ȡ����ʧ�ܣ�\n");
				else
					printf("���Ա���Ϊ%d\n",ListLength(L));
				getchar();
				getchar();
				break;
		   	case 6:
		   		printf("�����������ȡ�ڼ���Ԫ��:\n");
		   		scanf("%d",&num);
				if(GetElem(L,num,e)==INFEASTABLE)
					printf("��ȡԪ��ʧ�ܣ�\n");
				else
					printf("���Ա��%d��Ԫ�ص�ֵΪ%d\n",num,e);
				getchar();
				getchar();
				break;
		   	case 7:
				printf("������������ҵ�Ԫ��:\n");
				scanf("%d",&e);
				if((result = LocateElem(L,e))==INFEASTABLE)
					printf("����Ԫ��ʧ�ܣ�\n");
				else if (result == 0)
					printf("����û�����Ԫ��Ŷ��\n");
				else
					printf("���Ԫ���Ǳ�����ĵ�%d��Ԫ��\n",LocateElem(L,e));
				getchar();
				getchar();
				break;
		   	case 8:
				printf("������������ǰ����Ԫ�أ�\n");
				scanf("%d",&e);
				if((result=PriorElem(L,e,pre_e))==INFEASTABLE)
					printf("��ȡʧ���ˣ�\n");
				else if(result == ERROR)
					printf("�ǵ�һ�������߸���û�ҵ�\n");
				else
					printf("��%dŶ!\n",pre_e);
				getchar();
				getchar();
				break;
		   	case 9:
				printf("�����������ú�̵�Ԫ��:\n");
				scanf("%d",&e);
				if((result = NextElem(L,e,next_e) )== INFEASTABLE)
					printf("��ȡʧ��\n");
				else if (result==ERROR)
					printf("���һ�������߸���û�ҵ�\n");
				else
					printf("��%dŶ��\n",next_e);
				getchar();
				getchar();
				break;
		   	case 10:
				printf("��������������λ�ü�Ԫ��:\n");
				scanf("%d %d",&num,&e);
				if((result=ListInsert(L,num,e))==INFEASTABLE)
					printf("����ʧ��\n");
				else if(result==ERROR)
					printf("����λ�ò��Ϸ�\n");
				else
				{
					printf("����ɹ���\n");
//					printf("��������б���������:\n");
//					ListTrabverse(L);
// 					��������ʱ����
				}
				getchar();
				getchar();
				break;
		   	case 11:
				printf("����������ɾ����Ԫ�ص���ţ�\n");
				scanf("%d",&num);
				if((result = ListDelete(L,num,e))==INFEASTABLE)
					printf("ɾ��ʧ��\n");
				else if(result == ERROR)
					printf("�Ҳ���\n");
				else
					printf("ɾ����%d\n",e);
				getchar();
				getchar();
				break;
		   	case 12: 
				if(ListTrabverse(L)==INFEASTABLE) 
					printf("���Ա��ǿձ�\n");
				getchar();
				getchar();
			 	break;
			case 13:
				if((result = MaxSubArray(L))==INFEASTABLE)
					printf("ʧ��\n");
				else
					printf("%d\n",result);
				getchar();
				getchar();
				break;
			case 14:
				printf("��������ĺͣ�\n");
				scanf("%d",&num);
				if((result = SubArrayNum(L,num))==INFEASTABLE)
					printf("ʧ��\n");
				else
					printf("%d\n",result);
				getchar();
				getchar();
				break;
			case 15:
				if((result = SortList(L))==INFEASTABLE)
					printf("ʧ��\n");
				else if(result == ERROR)
					printf("��Ϊ��\n");
				else
					printf("�������\n");
				getchar();
				getchar();
				break;
			case 16:
				printf("�������ļ���:\n");
				scanf("%s",filename);
				if((result = SaveList(L,filename)) == OK)printf("�������\n");
				else printf("����ʧ��\n");
				getchar();
				getchar();
				break;
			case 17:
				printf("�������ļ���:\n");
				scanf("%s",filename);
				if((result = LoadList(L,filename))==OK)printf("�������\n");
				else printf("����ʧ��\n");
				getchar();
				getchar();
				break;
			case 18:
				printf("-------------------------------------------------\n");
				printf("             �ѽ�������Ա����ģʽ\n");
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
				printf("    ��ѡ����Ĳ���[0~18]:");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						printf("���������Ա����֣�\n");
						scanf("%s",filename);
						if((result = LocateList(List,filename))!= 0) printf("�ǵ�%d��\n",result);
						else printf("û�ҵ�\n");
						getchar();
						getchar();
						break;
					case 2:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						if(RemoveList(List,List.elem[num-1].name)==OK)
							printf("���Ա��Ƴ��ɹ���\n");
						else
							printf("���Ա��Ƴ�ʧ�ܣ�\n");
						getchar();
						getchar();
						break;
				   	case 3:
				   		printf("������������������Ա����:\n");
						scanf("%d",&num);
					 	if(ClearList(List.elem[num-1].L)==OK)
						 	printf("���Ա���ճɹ���\n");
						else
							printf("���Ա����ʧ�ܣ�\n");   
					 	getchar();
						getchar();
					 	break;
				   	case 4:
				   		printf("������������������Ա����:\n");
						scanf("%d",&num);
					 	if((result = ListEmpty(List.elem[num-1].L))==TRUE)
							printf("���Ա��ǿյģ�\n");
						else if(result ==FALSE)
							printf("���Ա��ǿյģ�\n");
						else
							printf("���Ա��п�ʧ�ܣ�\n");
					 	getchar();
						getchar();
					 	break;
				   	case 5:
				   		printf("������������������Ա����:\n");
						scanf("%d",&num);
						if(ListLength(List.elem[num-1].L)==INFEASTABLE)
							printf("��ȡ����ʧ�ܣ�\n");
						else
							printf("���Ա���Ϊ%d\n",ListLength(L));
						getchar();
						getchar();
						break;
					case 6:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("�����������ȡ�ڼ���Ԫ��:\n");
						scanf("%d",&num2);
						if(GetElem(List.elem[num-1].L,num2,e)==INFEASTABLE)
							printf("��ȡԪ��ʧ�ܣ�\n");
						else
							printf("���Ա��%d��Ԫ�ص�ֵΪ%d\n",num2,e);
						getchar();
						getchar();
						break;
					case 7:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("������������ҵ�Ԫ��:\n");
						scanf("%d",&e);
						if((result = LocateElem(List.elem[num-1].L,e))==INFEASTABLE)
							printf("����Ԫ��ʧ�ܣ�\n");
						else if (result == 0)
							printf("����û�����Ԫ��Ŷ��\n");
						else
							printf("���Ԫ���Ǳ�����ĵ�%d��Ԫ��\n",LocateElem(List.elem[num-1].L,e));
						getchar();
						getchar();
						break;
					case 8:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("������������ǰ����Ԫ�أ�\n");
						scanf("%d",&e);
						if((result=PriorElem(List.elem[num-1].L,e,pre_e))==INFEASTABLE)
							printf("��ȡʧ���ˣ�\n");
						else if(result == ERROR)
							printf("�ǵ�һ�������߸���û�ҵ�\n");
						else
							printf("��%dŶ!\n",pre_e);
						getchar();
						getchar();
						break;
					case 9:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("�����������ú�̵�Ԫ��:\n");
						scanf("%d",&e);
						if((result = NextElem(List.elem[num-1].L,e,next_e) )== INFEASTABLE)
							printf("��ȡʧ��\n");
						else if (result==ERROR)
							printf("���һ�������߸���û�ҵ�\n");
						else
							printf("��%dŶ��\n",next_e);
						getchar();
						getchar();
						break;
					case 10:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("��������������λ�ü�Ԫ��:\n");
						scanf("%d %d",&num2,&e);
						if((result=ListInsert(List.elem[num-1].L,num2,e))==INFEASTABLE)
							printf("����ʧ��\n");
						else if(result==ERROR)
							printf("����λ�ò��Ϸ�\n");
						else
						{
							printf("����ɹ���\n");
		//					printf("��������б���������:\n");
		//					ListTrabverse(L);
		// 					��������ʱ����
						}
						getchar();
						getchar();
						break;
					case 11:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("����������ɾ����Ԫ�ص���ţ�\n");
						scanf("%d",&num2);
						if((result = ListDelete(List.elem[num-1].L,num2,e))==INFEASTABLE)
							printf("ɾ��ʧ��\n");
						else if(result == ERROR)
							printf("�Ҳ���\n");
						else
							printf("ɾ����%d\n",e);
						getchar();
						getchar();
						break;
					case 12: 
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						if(ListTrabverse(List.elem[num-1].L)==INFEASTABLE) 
							printf("���Ա��ǿձ�\n");
						getchar();
						getchar();
						break;
					case 13:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						if((result = MaxSubArray(List.elem[num-1].L))==INFEASTABLE)
							printf("ʧ��\n");
						else
							printf("%d\n",result);
						getchar();
						getchar();
						break;
					case 14:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("��������ĺͣ�\n");
						scanf("%d",&num2);
						if((result = SubArrayNum(List.elem[num-1].L,num))==INFEASTABLE)
							printf("ʧ��\n");
						else
							printf("%d\n",result);
						getchar();
						getchar();
						break;
					case 15:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						if((result = SortList(List.elem[num-1].L))==INFEASTABLE)
							printf("ʧ��\n");
						else if(result == ERROR)
							printf("��Ϊ��\n");
						else
							printf("�������\n");
						getchar();
						getchar();
						break;
					case 16:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("�������ļ���:\n");
						scanf("%s",filename);
						if((result = SaveList(List.elem[num-1].L,filename)) == OK)printf("�������\n");
						else printf("����ʧ��\n");
						getchar();
						getchar();
						break;
					case 17:
						printf("������������������Ա����:\n");
						scanf("%d",&num);
						printf("�������ļ���:\n");
						scanf("%s",filename);
						if((result = LoadList(List.elem[num-1].L,filename))==OK)printf("�������\n");
						else printf("����ʧ��\n");
						getchar();
						getchar();
						break;
					case 18:
						printf("���������Ա�����:\n");
						scanf("%s",filename);
						if((result = AddList(List,filename))==OK)printf("�������\n");
						else printf("����ʧ��\n");
						getchar();
						getchar();
						break;
					case 0:
						break;
				}
//			case 18:
//				printf("���������Ա�����:\n");
//				scanf("%s",filename);
//				if((result = AddList(List,filename))==OK)printf("�������\n");
//				else printf("����ʧ��\n");
//				getchar();
//				getchar();
//				break;
//			case 19:
//				printf("���������Ա����֣�\n");
//				scanf("%s",filename);
//				if((result = LocateList(List,filename))!= 0) printf("�ǵ�%d��\n",result);
//				else printf("û�ҵ�\n");
//				getchar();
//				getchar();
//				break;
//			case 20:
//				printf("���������Ա����֣�\n");
//				scanf("%s",filename);
//				if((result = RemoveList(List,filename)) == OK) printf("ɾ�����\n");
//				else printf("ɾ��ʧ��\n");
//				getchar();
//				getchar();
//				break;
//			case 21:
//				printf("������Ҫ���ص����Ա����ţ�\n");
//				scanf("%d",&num);
//				if((result = GetList(List,L,num))== OK) printf("�������\n");
//				else printf("����ʧ��\n");
//				getchar();
//				getchar();
//				break;
			case 0:
	         	break;
		}
	}
	printf("\t��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
        L.elem = NULL;//�ÿ�
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
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);//����ռ�
        L.length = 0;
        L.listsize = 0;
    }
    return OK;
}
status ListEmpty(SqList L)
{
    if(L.elem != NULL)
    {
        if(L.length == 0)//��length����
            return TRUE;
        return FALSE;
    }
    else
        return INFEASTABLE;
}
status ListLength(SqList L)
{
    if(L.elem != NULL)
        return L.length;//����length����
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
            if(L.elem[i] == e) // ȷ��e��λ��
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
            if(L.elem[i] == e)//�����ҵ�e
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
            if(L.elem[i] == e) //�����ҵ�e
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
        ElemType * temp = (ElemType *)malloc(sizeof(ElemType)*(LIST_INIT_SIZE+1));//�����ռ�
        for(int j = 0; j < i-1 ; j++)
            temp[j] = L.elem[j];
        temp[i-1] = e; //����e
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
        ElemType * temp = (ElemType *)malloc(sizeof(ElemType)*(LIST_INIT_SIZE-1)); //������ʱ���Ա�
        for(int j = 0; j < i-1 ; j++)
            temp[j] = L.elem[j];
        e = L.elem[i-1]; //�޳�Ҫȥ����Ԫ�أ�ͬʱ�浽e����
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
        for(int i = 0; i < L.length; i++)//�������
        {
            if(flag)
                printf(" ");
            else
                flag = true;//flag������ʶ��һ������һ��ǰ�治��ո�
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
        FILE  *fp; //����Ϊ�������ļ�
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
        while(fread(L.elem+L.length,sizeof(ElemType),1,fp))//���
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
        while(ListName[i]!='\0') //��������
        {
            Lists.elem[Lists.length].name[i] = ListName[i];
            i++;
        }
        Lists.elem[Lists.length].L.elem = NULL;
        InitList(Lists.elem[Lists.length].L);//��ʼ��
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
        while(ListName[j]!='\0') //�ȶ�����
        {
            if(Lists.elem[i].name[j] != ListName[j])
                flag = false;
            j++;
        }
        if(flag)//����ҵ��˾�ɾ��
        {
            for(int j = i;j < Lists.length;j++)
                Lists.elem[j] = Lists.elem[j+1];
            Lists.length--;
            return OK;
        }
    }
    return ERROR;//û�ҵ�����
}
int LocateList(LISTS Lists,char ListName[])
{
    bool flag = true;
    int j = 0;
    for(int i = 0; i < Lists.length; i++)
    {
        flag = true;
        j = 0;
        while(ListName[j]!='\0')//�ȶ�˳�������
        {
            if(Lists.elem[i].name[j] != ListName[j])
                flag = false;
            j++;
        }
        if(flag)
        {
            return i+1; //��ס���ص����߼��ϵ�λ�ã���������������
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
	for(int i=0;i<L.length;i++) //�������п��ܣ�Ѱ�����
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
	for(int i=0;i<L.length;i++) //����Ѱ��ֵ��ȵ������飬��cnt��¼����
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
		{ //ð������
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
