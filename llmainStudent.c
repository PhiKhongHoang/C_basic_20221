/*
    - Khổng Hoàng Phi - 20205012
    - Ngày hoàn thành: 15/11/2022
    - Mục tiêu của chương trình: sử dụng dslk đơn để thực hiện thêm, xóa, 
        tìm kiếm, thay đổi điểm của sinh viên trong dslk.  
*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define ID_LENGTH 10
#define NAME_LENGTH 30

// struct Student
typedef struct
{
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;
} data_t;

// struct node

typedef struct Student_t
{
    data_t data;
    struct Student_t *next;
} Student, *root_t;

// in
void showData(data_t data)
{
    printf("%s - %s - %d\n", data.id, data.name, data.grade);
}

// xuất dslk
root_t llPrint(root_t root)
{
	Student *p;
    for(p = root; p != NULL; p = p->next)
        showData(p->data);
    printf("\n");
    return root;
}

// khởi tạo node
Student *createNewNode(const data_t data)
{
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// khởi tạo
root_t llInit()
{
    return NULL;
}

// tìm node thứ index
Student *llSeek(root_t root, int index)
{
    Student *p;
    for (p = root; index > 0 && (p != NULL); index--)
        p = p->next;
    return p;
}

// thêm vào đầu
root_t llInsertHead(root_t root, const data_t data)
{
    Student *pNewNode = createNewNode(data);
    pNewNode->next = root;
    return (root_t)pNewNode;
}

// thêm vào cuối
root_t llInsertTail(root_t root, const data_t data)
{
    Student *pNewNode = createNewNode(data);

    if (root == NULL)
        return (root_t)pNewNode;

    Student *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

//  thêm vào sau node pAElem
root_t llInsertAfter(root_t root, Student *pAElem, const data_t data)
{
    if (pAElem == NULL)
        return root;

    Student *pNewNode = createNewNode(data);
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;

    return root;
}

// xóa node đầu
root_t llDeleteHead(root_t root)
{
    if (root == NULL)
        return NULL;

    Student *p = root->next;
    free(root);
    return (root_t)p;
}

// xóa node cuối
root_t llDeleteTail(root_t root)
{
    if (root == NULL)
        return NULL;
    if (root->next == NULL)
    {
        free(root);
        return NULL;
    }
    Student *p;
    // duyệt đến node trước node cuối
    for (p = root; p->next->next != NULL; p = p->next)
        ;

    free(p->next);
    p->next = NULL;
    return (root_t)root;
}

// xóa node sau node pA
root_t llDeleteAfter(root_t root, Student *pA)
{
    if ((pA == NULL) || (pA->next == NULL))
        return root;

    Student *pToDelElem = pA->next;
    pA->next = pA->next->next;

    free(pToDelElem);
    return root;
}

// xóa toàn bộ
root_t llDeleteAll(root_t root)
{
    Student *p = NULL;
    for (; root != NULL; root = p)
    {
        p = root->next;
        free(root);
    }
    return NULL;
}

// đếm số node
int llLength(root_t root)
{
    int count;
    for (count = 0; root != NULL; root = root->next)
        count++;
    return count;
}

// đảo ngược dslk
root_t reverseLL(root_t root)
{
    Student *cur, *prev;

    for (cur = prev = NULL; root != NULL;)
    {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return root;
}

// convert
data_t convert(int i)
{
    data_t data = {i};
    return data;
}

// thêm sinh viên mới
/* Khi truyền tham số là đầu danh sách và data vào hàm llINsertStudent thì
    hàm sẽ gọi đến hàm llInsertHead để thêm thông tin vào đầu danh sách 
    với dữ liệu là data vừa nhập.
*/
root_t llINsertStudent(root_t root, data_t data)
{
    return llInsertHead(root, data);
}

// tìm sinh viên bằng id
/* Khi truyền tham số là đầu danh sách và id vào hàm llFindStuden thì 
    sẽ duyệt lần lượt từ đầu dslk đến node có id trùng với 
    id ở tham số đầu vào sau đó trả về địa chỉ của phần data của node đó.
*/
data_t *llFindStuden(root_t root, char id[])
{
    Student *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
    {
        if(strcmp(id, p->data.id) == 0)
        {
            return &(p->data);
        }        
    }
    return NULL;
}

// xóa sv theo id
/* Khi truyền tham số đầu vào là đầu danh sách và id thì hàm llDeleteStudent
    sẽ duyệt đến trước node có id trùng với id nhập vào sau đó tạo ra node 
    phụ q rồi giải phóng node phụ và trả về đầu danh sách. khi hết vòng for
    mà vẫn chưa thấy node cần xóa thì node cần xóa sẽ là node đầu và gọi
    hàm llDeleteHead.
*/
root_t llDeleteStudent(root_t root, char id[])
{
    Student *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
    {
    	if(strcmp(id, p->next->data.id) == 0)
    	{
            Student *q = p;
            free(q->next);
            p->next = p->next->next;
            return root;
		}
	}
    llDeleteHead(root);
}

// đổi điểm sv trong ds
/*
    Khi truyền tham số vào là đầu danh sách, id và điểm cần đổi thì hàm
    llChangeGrade sẽ duyệt từ đầu đến node có id trùng với id truyền vào
    và tiến hành gán điểm bằng điểm nhập và sau đó trả về đầu danh sách.
*/
root_t llChangeGrade(root_t root, char id[], int newGrade)
{
    Student *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
    {
        if(strcmp(id, p->data.id)==0)
        {
            p->data.grade = newGrade;
            return root;
        }
    }
}

int main()
{
    root_t lst = llInit();

// 1. tạo mảng 5 sv
    data_t sv[] = 
    {
        {"001", "sv1", 1},
        {"002", "sv2", 2},
        {"003", "sv3", 3},
        {"004", "sv4", 4},
        {"005", "sv5", 5}
    };

// 2. Tạo dslk từ mảng
	int i;
    for(i = 0; i < sizeof(sv)/sizeof(sv[0]); i++){
        lst = llInsertHead(lst, sv[i]);
    }

// 3. hiện thị nội dung dslk
    printf("\nThong tin sv ban dau:\n");
    llPrint(lst);
    printf("===================================================================\n");

// ======= thêm sinh viên mới =====0==
    data_t data;
    printf("\nNhap thong tin sv can them: ");
    scanf("%s %s %d",data.id, data.name, &data.grade);
    lst = llINsertStudent(lst, data);
    printf("\n");
    llPrint(lst);
    printf("===================================================================\n");

// 4. tìm và hiển thị thông tin sv có id = "002"
    printf("\nThong tin sv co id 002:\n");
    data_t *data1 = llFindStuden(lst, "002");
    printf("%s - %s -%d\n", data1->id, data1->name, data1->grade);
    printf("\n===================================================================\n");

// 5. thay đổi điểm sv có id "002" thành 9
    printf("\nDoi diem sv co id \"002\" thanh 9\n");
    lst = llChangeGrade(lst, "002", 9);

// 6. hiển thị danh sách sv
    llPrint(lst);
    printf("\n===================================================================\n");

// 7. xóa sv có id là "001"  
    printf("\ndslk sau khi xoa sv co id \"001\"\n");
    lst = llDeleteStudent(lst, "001");
    llPrint(lst);
    printf("\n===================================================================\n");

// 8. hiển thị dslk sv
    printf("\nHien thi lai dslk chua thong tin sv\n");
    llPrint(lst);
    printf("\n===================================================================\n");
    
// Giải phóng bộ nhớ
    lst = llDeleteAll(lst);
    return 0;
}
