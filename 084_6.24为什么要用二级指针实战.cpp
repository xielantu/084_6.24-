// 084_6.24为什么要用二级指针实战.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
//int* getPosPerson(int pos, int(*pstu)[4])//pstu 是一个指向长度为4的一维 int 数组的指针。
//{
//    int* p=NULL;
//    p = (int*)(pos + pstu);
//    return p;
//}

 

//int* getPosPerson(int pos, int(*pstu)[4], int totalRows)//pstu 是一个指向长度为4的一维 int 数组的指针。
//{                                                               //使用了 totalRows 来验证 pos 的有效性，确保不会越界访问
//    if (pos < 0 || pos >= totalRows || pstu == NULL) {
//        return NULL;  // 参数无效，返回空指针
//        exit(-1);
//    }
//
//    int* p = *(pstu + pos); // 使用指针算术访问正确的内存位置
//                            //使用指针算术：避免对指针进行不必要的类型转换和数值运算。
//                            //可以使用指针算术来访问正确的内存位置。例如，可以使用 pstu + pos 来获取指向指定位置的指针，而无需进行类型转换。
//    return p;
//}

//void getPosPerson(int pos, int(*pstu)[4], int totalRows,int** ppos)
//{                                                        
//    if (pos < 0 || pos >= totalRows || pstu == NULL) 
//    {
//        exit(-1);
//    }
//    *ppos = *(pstu + pos);
//
//}
//
//
//
//int main()
//{
//    int scores[3][4] = {
//        {55,66,77,88},
//        {66,55,99,100},
//        {11,22,33,59}
//    };
//
//    int* ppos = NULL;
//    int pos = 0;
//    printf("请输入你需要看到学生号数0，1，2\n");
//    scanf_s("%d", &pos);
//
//    getPosPerson(pos, scores,4,&ppos);
//    for (int i = 0; i < 4; i++) 
//    {
//        printf("%d ", *ppos++);
//
//
//    }
//
//    return 0;
//}



void getPosPerson(int pos, int(*pstu)[4], int totalRows, int** ppos)
{
    if (pos < 0 || pos >= totalRows || pstu == NULL)
    {
        printf("Invalid position or NULL pointer.\n“无效的位置或空指针。”\n");
        *ppos = NULL;  // 设置ppos为NULL，表示错误条件
        return;
    }

    *ppos = *(pstu + pos);
}

int main()
{
    int scores[3][4] = {
        {55, 66, 77, 88},
        {66, 55, 99, 100},
        {11, 22, 33, 59}
    };

    int* ppos;  // 声明为int*，不需要初始化为NULL
    int pos = 0;
    printf("请输入你需要看到学生号数0，1，2\n");
    scanf_s("%d", &pos);

    getPosPerson(pos, &scores[0], 3, &ppos);
    if (ppos != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", *ppos++);
        }
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
