#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int, int);
int sub(int, int);
int multiply(int,int);
int divide(int,int);

typedef struct CalculatorNode{
    int a;
    int b;
    char name[20];
    int (*fptr) (int,int);
    struct CalculatorNode* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
}List;

List* createList(){
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void calcu(Node* node){
    if(!strcmp(node->name,"add"))
        node->fptr = add;
    else if(!strcmp(node->name,"sub"))
        node->fptr = sub;
    else if(!strcmp(node->name,"multiply"))
        node->fptr = multiply;
    else if(!strcmp(node->name,"divide"))
        node->fptr = divide;
}

void insert_last(List* plist,int a, int b,char name[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->a = a;
    newNode->b = b;
    strcpy(newNode->name,name);
    calcu(newNode);
    if(plist->head == NULL){
        plist->head = newNode;
    }
    else{
        plist->tail->next = newNode;
    }

    plist->tail = newNode;
}


void print_list(List* plist){
    Node* cur = plist->head;
    if(cur == NULL)
        printf("현재 생성된 노드가 없습니다.");
    else{
        while(cur != NULL){
            if(cur->next == NULL)
                printf("%d %d %s",cur->a,cur->b,cur->name);
            else
                printf("%d %d %s -> ", cur->a,cur->b,cur->name);
            cur = cur->next;
        }
    }
}

void cal_list(List* plist){
    Node* cur = plist->head;
    int result = 0;
    while(cur != NULL){
        result = cur->fptr(cur->a,cur->b);
        if(cur->next == NULL)
            printf("%d",result);
        else
            printf("%d -> ", result);
        cur = cur->next;
    }
}

void del_list(List* plist){
    plist->head = NULL;
}

int main(void){
    int n;
    int a,b;
    char name[20];
    List* plist = createList();
    while(1){
        printf("========================================\n");
        printf("1.계산 노드 생성(add/sub/multiply/divide)\n");
        printf("2.현재까지 생성된 계산 노드 출력\n");
        printf("3.현재까지 생성된 계산 노드들의 계산 결과를 출력\n");
        printf("4.전체 삭제\n");
        printf("5.프로그램 종료\n");
        printf("========================================\n");
        scanf("%d", &n);
        if(n==5){
            printf("프로그램을 종료합니다.");
            break;
        }
        switch(n){
            case 1:
                printf("두 정수를 입력하세요:");
                scanf("%d %d",&a,&b);    
                printf("원하는 계산을 입력하세요:");
                scanf("%s",name);
                insert_last(plist, a, b, name);
                break;
            case 2:
                print_list(plist);
                break;
            case 3:
                cal_list(plist);
                break;
            case 4:
                del_list(plist);
                break;
        }
        printf("\n");
    }
    return 0;
}

int add(int a, int b){
    int result;
    result = a + b;
    return result;
}

int sub(int a,int b){
    int result;
    result = a - b;
    return result;
}

int multiply(int a,int b){
    int result;
    result = a * b;
    return result;
}

int divide(int a,int b){
    int result;
    result = a/b;
    return result;
}

