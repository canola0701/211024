#include<stdio.h> 
#include<malloc.h> 
#define _CRT_SECURE_NO_WARNINGS



#define TRUE 1
#define TRUE 2 
//char���� �� element�� �ڷ������� ���� 
typedef char element;
//���� ���� ����Ʈ ���� ��� ������ ����ü�� ���� 
typedef struct DQNode {
    element data;
    struct DQNode* llink;
    struct DQNode* rlink;
}DQNode;

//������ ����ϴ� ������ front�� rear�� ����ü�� ���� 
typedef struct {
    DQNode* front, * rear;
} DQueType;

void Initialization(DQueType* DQ) {

   DQ->front = DQ->rear = NULL;

}



//���� ���� �����ϴ� ���� 
DQueType* createDQue()
{
    DQueType* DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

//���� �������� Ȯ���ϴ� ���� 
int isEmpty(DQueType* DQ)
{
    if (DQ->front == NULL) {
        printf("\n Linked Queue is empty! \n");
        return 1;
    }
    else return 0;
}

//���� front ������ �����ϴ� ���� 
void insertFront(DQueType* DQ, element item)
{
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    //���� ������ ��� 
    if (DQ->front == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        DQ->front = newNode;
    }
}

//���� rear �ڷ� �����ϴ� ���� 
void insertRear(DQueType* DQ, element item)
{
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    //���� ������ ��� 
    if (DQ->rear == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->rear->rlink = newNode;
        newNode->rlink = NULL;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

//���� front ��带 �����ϰ� ��ȯ�ϴ� ���� 
element deleteFront(DQueType* DQ)
{
    DQNode* old = DQ->front;
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = old->data;
        if (DQ->front->rlink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    }
}

//���� rear ��带 �����ϰ� ��ȯ�ϴ� ���� 
element deleteRear(DQueType* DQ)
{
    DQNode* old = DQ->rear;
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = old->data;
        if (DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

//���� front ��带 �����ϴ� ���� 
int removeFront(DQueType* DQ)
{
    DQNode* old = DQ->front;
    if (isEmpty(DQ)) return 0;
    else if (DQ->front->rlink = NULL) {
        DQ->front = NULL;
        DQ->rear = NULL;
    }
    else {
        DQ->front = DQ->front->rlink;
        DQ->front->llink = NULL;
    }
    free(old);    return 1;
}

//���� front ����� ������ �ʵ带 ��ȯ�ϴ� ���� 
element peekFront(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->front->data;
        return item;
    }
}

//���� rear ��带 �����ϴ� ���� 
int removeRear(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->front->data;
        return item;
    }
}

//���� rear ����� ������ �ʵ带 ��ȯ�ϴ� ���� 
element peekRear(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->rear->data;
        return item;
    }
}

//���� front ������ rear ������ ����ϴ� ���� 
void printDQ(DQueType* DQ)
{
    DQNode* temp = DQ->front;
    printf("DeQue : [");
    while (temp) {
        printf("%3c", temp->data);
        temp = temp->rlink;
    }
    printf(" ] \n");
}

int main() {

    DQueType deque;

    Initialization(&deque);



    int num, item;

    printf("<���� ���Ḯ��Ʈ�� �̿��� ��ũ>\n");

    while (1) {

        printf("[��ȣ�� �Է��Ͻʽÿ�]\n");

        printf("[1. FRONT ����]  ");

        printf("[2. REAR ����]  ");

        printf("[3. FRONT ����]  ");

        printf("[4. REAR ����]  ");

        printf("[5. ��ũ ���] ");

     

        printf("�Է� ��ȣ : ");

        scanf_s("%d", &num);

        switch (num) {

        case 1:

            printf("[���� ��] : ");

            scanf_s("%d", &item);

            printf("\n");

            insertFront(&deque, item);

            break;

        case 2:

            printf("[���� ��] : ");

            scanf_s("%d", &item);

            printf("\n");

            insertRear(&deque, item);

            break;

        case 3:

            deleteFront(&deque);

            printf("\n");

            break;

        case 4:

            deleteRear(&deque);

            printf("\n");

            break;

        case 5:

            printDQ(&deque);

            printf("\n");

            break;

       

        default:

            printf("���� �߸� �Է��ϼ̽��ϴ�.\n\n");

        }
        getchar();
    }

}

