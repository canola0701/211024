#include<stdio.h> 
#include<malloc.h> 
#define _CRT_SECURE_NO_WARNINGS



#define TRUE 1
#define TRUE 2 
//char형을 덱 element의 자료형으로 정의 
typedef char element;
//이중 연결 리스트 덱의 노드 구조를 구조체로 정의 
typedef struct DQNode {
    element data;
    struct DQNode* llink;
    struct DQNode* rlink;
}DQNode;

//덱에서 사용하는 포인터 front와 rear를 구조체로 정의 
typedef struct {
    DQNode* front, * rear;
} DQueType;

void Initialization(DQueType* DQ) {

   DQ->front = DQ->rear = NULL;

}



//공백 덱을 생성하는 연산 
DQueType* createDQue()
{
    DQueType* DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

//덱이 공백인지 확인하는 연산 
int isEmpty(DQueType* DQ)
{
    if (DQ->front == NULL) {
        printf("\n Linked Queue is empty! \n");
        return 1;
    }
    else return 0;
}

//덱의 front 앞으로 삽입하는 연산 
void insertFront(DQueType* DQ, element item)
{
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    //덱이 공백인 경우 
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

//덱의 rear 뒤로 삽입하는 연산 
void insertRear(DQueType* DQ, element item)
{
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    //덱이 공백인 경우 
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

//덱의 front 노드를 삭제하고 반환하는 연산 
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

//덱의 rear 노드를 삭제하고 반환하는 연산 
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

//덱의 front 노드를 삭제하는 연산 
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

//덱의 front 노드의 데이터 필드를 반환하는 연산 
element peekFront(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->front->data;
        return item;
    }
}

//덱의 rear 노드를 삭제하는 연산 
int removeRear(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->front->data;
        return item;
    }
}

//덱의 rear 노드의 데이터 필드를 반환하는 연산 
element peekRear(DQueType* DQ)
{
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ->rear->data;
        return item;
    }
}

//덱의 front 노드부터 rear 노드까지 출력하는 연산 
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

    printf("<이중 연결리스트를 이용한 데크>\n");

    while (1) {

        printf("[번호를 입력하십시오]\n");

        printf("[1. FRONT 삽입]  ");

        printf("[2. REAR 삽입]  ");

        printf("[3. FRONT 삭제]  ");

        printf("[4. REAR 삭제]  ");

        printf("[5. 데크 출력] ");

     

        printf("입력 번호 : ");

        scanf_s("%d", &num);

        switch (num) {

        case 1:

            printf("[삽입 값] : ");

            scanf_s("%d", &item);

            printf("\n");

            insertFront(&deque, item);

            break;

        case 2:

            printf("[삽입 값] : ");

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

            printf("수를 잘못 입력하셨습니다.\n\n");

        }
        getchar();
    }

}

