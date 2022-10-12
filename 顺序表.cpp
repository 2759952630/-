#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define OK 1    //�ɹ���ʶ
#define ERROR 0 //ʧ�ܱ�ʶ
#define TURE 1
#define FALSE 0
typedef int Status;	//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
typedef int ElemType;   //ElemType�����͸���ʵ���������������ٶ�Ϊint

//˳������ݽṹ
typedef struct
{
    ElemType* elem;
    int length;
}SqList;

//����һ���յ����Ա�
Status InitList(SqList* L)
{
    L->elem = new ElemType(MAXSIZE);
    //C��������:L.->elme = (ElemType*)malloc(MAXSIZE*sizeof(ElemType);
    if (!L->elem) {
        return ERROR;
    }
    L->length = 0;
    return OK;
}

/*
�������
��ʼ������˳���L�Ѵ���
�����������L�еĵ�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
*/
Status ListInsert(SqList* L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) {
        return ERROR;//���Ա�����
    }
    if (i<1 || i>L->length + 1) {
        return ERROR;//����λ�ò������Ա�Χ��
    }
    if (i <= L->length) {//������λ�ò��ڱ�β��������λ���ڱ�β��������ִ��Ԫ�غ��Ʋ���
        for (k = L->length - 1; k >= i - 1; k--) {
            L->elem[k + 1] = L->elem[k];//��iλ��֮���Ԫ�������һ��λ��
        }
    }
    L->elem[i - 1] = e;//������Ԫ��e
    L->length++;//���Ա���һ
    return OK;
}

/*
ɾ������
��ʼ������˳���L�Ѵ���
���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
*/
Status ListDelete(SqList* L, int i, ElemType* e) {
    int k;
    if (L->length == 0) {
        return ERROR;//���Ա�Ϊ��
    }
    if (i<1 || i>L->length) {
        return ERROR;//ɾ��λ�ò������Ա�Χ
    }
    *e = L->elem[i - 1];//������ɾ��Ԫ�ص�ֵ
    if (i <= L->length) {//��ɾ��λ�ò��ڱ�β
        for (k = i; k <= L->length; k++) {
            L->elem[k - 1] = L->elem[k];//��iλ��֮���Ԫ��ǰ��
        }
    }
    L->length--;//����һ
    return OK;
}

/*���Ҳ���---------˳�����
���������L�в��������ֵe��ȵ�Ԫ�أ����ɹ����ظ�Ԫ���ڱ��е���ţ����򷵻�0
*/
Status LocateList1(SqList* L, ElemType e) {
    if (L->length == 0) {
        return ERROR;//���Ա�Ϊ��
    }
    int i, k = 0;
    for (i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

/*���Ҳ���--------���ֲ���*/
Status LocateList2(SqList* L, ElemType e) {
    if (L->length == 0) {
        return ERROR;//���Ա�Ϊ��
    }
    int low = 0, high = L->length - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (L->elem[mid] == e) {
            return mid + 1;
        }
        else if (L->elem[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

/*
��ȡԪ�ز���
�����������e����L�е�i������Ԫ�ص�ֵ
*/
Status GetElem(SqList L, int i, ElemType* e) {
    if (L.length == 0 || i<1 || i>L.length) {
        return ERROR;//ͬ��
    }
    *e = L.elem[i - 1];
    return OK;
}

//������Ա�
Status ClearList(SqList* L)
{
    L->length = 0;
    return OK;
}

//�������Ա��Ԫ�ظ���
Status ListLength(SqList* L) {
    return L->length;
}

//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty(SqList* L) {
    if (L->elem) {
        return TURE;
    }
    else return FALSE;
}

//��ӡ���Ա��е�����Ԫ��
void OutPut(SqList L) {
    printf("��ǰ˳���ĳ���:%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    printf("����һ���յ����Ա�L\n");
    InitList(&L);
    OutPut(L);  //��ӡ���
    printf("���Բ���10����\n");
    for (int i = 1; i <= 10; i++) {
        ListInsert(&L, i, i);
    }
    OutPut(L);  //��ӡ���
    printf("�ڵ���λ֮ǰ����0\n");
    ListInsert(&L, 3, 0);
    OutPut(L);  //��ӡ���
    printf("ɾ����6λ������\n");
    ElemType e;
    ListDelete(&L, 6, &e);
    printf("ɾ��������Ϊ��%d\n", e);
    OutPut(L);  //��ӡ���
    printf("��ȡԪ�ز���\n");
    GetElem(L, 5, &e);
    printf("�õ���5��Ԫ�أ�%d\n", e);
    cout << LocateList1(&L, 6) << endl;
    //cout << LocateList2(&L, 5) << endl;
}