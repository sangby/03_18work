/*
 * @Author: Sangby
 * @Date: 2024-03-30 11:20:59
 * @LastEditors: Sangby
 * @LastEditTime: 2024-04-01 22:39:38
 * @FilePath: \third_week\Sources\sort.cpp
 * @Description:
 *
 * Copyright (c) 2024 by $, All Rights Reserved.
 */

#include "../Headers/sort.h"

int data[100000005]; // 全局共用了,就不要老是创建这么大的数组了
int temp[100000005];

// 时间起始,结束点
clock_t start_time;
clock_t end_time;

// 判断下是不是数字串,是的话就返回1,不是就返回0
int is_int(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // 浅浅写个菜单
    char input[100];
    char choice;
    while (true)
    {
        cout << ">>================<<" << endl;
        cout << "  | 1.测算时间   |" << endl;
        cout << "  | 2.排序应用题 |" << endl;
        cout << "  | 3.选做优化   |" << endl;
        cout << "  | 4.退出程序   |" << endl;
        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 输入检测,我需要的只是1到4,所以很好筛,长度还要筛
            if (strlen(input) == 1)
            {
                if (input[0] >= '1' && input[0] <= '4')
                {
                    system("cls");

                    choice = input[0];
                    break;
                }
                else
                {
                    cout << "请输入正确序数!" << endl;
                }
            }
            else
            {
                cout << "请输入一个字符！" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            // 测试程序
            computetime();
            break;
        case '2':
        application();
            // 排序应用题
            break;

        case '3':
        selectoptimize();
            // 选做优化
            break;
        case '4':
            // 退出程序
            return 0;
        }
    }
}

void computetime()
{
    // 再排序
    // 大量数据,10000,50000,200000
    // 大量排序,100个数据100次排序
    // 先生成数据
    // 生成相应数量的随机数装入指定文件
    // 对指定文件进行排序
    // 懒人快速测试
    char input[100];
    char choice;
    // 还要写菜单
    while (true)
    {
        cout << "=======>>>测算排序时间" << endl;
        cout << "=================" << endl;
        cout << "1.懒人快速测试" << endl;
        cout << "2.先生成数据" << endl;
        cout << "3.再排序" << endl;
        cout << "4.退出" << endl;
        cout << "=================" << endl;

        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 我反过来写,依旧是先定长度再定形式
            if (strlen(input) != 1)
            {
                cout << "输入错误" << endl;
            }
            else
            {
                if (input[0] < '1' || input[0] > '4')
                {
                    cout << "输入错误" << endl;
                }
                else
                {
                    system("cls");

                    choice = input[0];
                    break;
                }
            }
        }

        switch (choice)
        {
        case '1':
            // 懒人快速测试
            cout<<"可能耗时较长,请耐心等待...时间单位是毫秒"<<endl;
            quick_test();
            break;
        case '2':
            int num_data;
            // 输入数据量
            while (true)
            {
                cout << "请输入数据量：";
                fgets(input, 100, stdin);
                // 取出回车
                input[strlen(input) - 1] = '\0';
                if (is_int(input))
                {
                    if (strlen(input) < 9 && strlen(input) > 0)
                    {
                        num_data = atoi(input);
                        break;
                    }
                    else
                    {
                        cout << "太多辣" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            // 输入生成数据最大值
            int max_value;
            while (true)
            {
                cout << "请输入数据最大值：";
                fgets(input, 100, stdin);
                // 取出回车
                input[strlen(input) - 1] = '\0';
                if (is_int(input))
                {
                    if (strlen(input) < 9 && strlen(input) > 0)
                    {
                        max_value = atoi(input);
                        break;
                    }
                    else
                    {
                        cout << "太大辣" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            // 输入文件名
            char filename[100];
            while (true)
            {
                cout << "请输入数据储存文件名如test.txt:";
                fgets(input, 100, stdin);
                // 取出回车
                input[strlen(input) - 1] = '\0';
                char partOfileName[5];
                // 截取后四个字符到partOfileName,计算地址得切割数组
                strncpy(partOfileName, input + strlen(input) - 4, 4);
                if (strcmp(partOfileName, ".txt") == 0)
                {
                    strcpy(filename, input);
                    break;
                }
                else
                {
                    cout << "文件名错误,请重新输入！" << endl;
                }
            }

            getTestData(num_data, max_value, filename);
            // 先生成数据
            break;
        case '3':
            // 再排序
            Sort();
            break;

        case '4':
            // 退出
            return;
        }
    }
}
// void application() {
// //排序应用题
//     //颜色排序要求还挺多,先输入一串包含012的字符串,然后就输出
//     //找到第k小的数,先输入一串字符串,再说,我还没看懂
// }

// void selectoptimize() {
// //选做优化

// }

void insertSort(int *a, int n)
{

    // 插入排序
    /*for循环1到n,将每次i索引的值赋给key,定义j = i-1,确定已排序的区域,然后while开始插入,插入
有个特点就是一路验一路空位置给它插*/
    int j, key;

    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
// 归并数组
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
    int i = begin;   // 左半边数组起始
    int j = mid + 1; // 右半边数组起始
    int k = begin;   // 承载数组  指针
    // 若两个数组都有元素,则比较,将较小的元素赋给temp数组
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    // 如果数组还有元素,则直接将数组元素赋给temp数组
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }

    // 将temp数组中的元素赋回a数组
    for (int i = begin; i <= end; i++)
    {
        a[i] = temp[i];
    }
}
// 将一个数组递归分为两个数组,然后合并
void MergeSort(int *a, int begin, int end, int *temp)
{
    // 通过begin,end分为两个数组
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        // 这种分组,可以在偶数数组是左右等分,奇数数组时左边比右边多一个元素
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);

        MergeArray(a, begin, mid, end, temp);
    } // 若begin>end,则说明数组只有一个元素,递到底,无需操作,开始归
}
// 快速排序递归版
void QuickSort_Recursion(int *a, int begin, int end)
{
    if (begin < end)
    {

        int pivotIndex = Partition(a, begin, end);

        QuickSort_Recursion(a, begin, pivotIndex - 1);
        QuickSort_Recursion(a, pivotIndex + 1, end);
    } // 当数组长度为三时,划分过程中已经排序完成,当begin>end时,递归开始返回
}

int Partition(int *a, int begin, int end)
{
    int pivot = a[end]; // 选取最后一个元素作为基准
    int i = begin - 1;  // 适配后面的先i++
    // 遍历数组划分
    for (int j = begin; j <= end; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return i;
}
// 计数排序
void CountSort(int *a, int size, int max)
{
    // 创建计数数组
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL)
    {
        perror("calloc error");
        exit(1);
    }
    // 遍历计算元素出现次数
    for (int i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    // 计算前缀和,形成累计数组
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // 创建结果数组
    int *output = (int *)malloc(size * sizeof(int));
    if (output == NULL)
    {
        perror("malloc error");
        free(count);
        exit(1);
    }
    // 构造结果数组
    for (int i = size - 1; i >= 0; i--)
    {
        /*由于count表示累计数,他的值间接显示了顺序这个信息,
        而用a[i]去当索引表明一定存在a[i]这个数,a[i]的次序
        就是对应的累计值,要填入结果数组,就要次序数减一
        于是就可以将其填入结果数组,填完后要把累计值减一是为了防
        还存在同样的数,避免重复填入
        */
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    // 将结果数组赋给原数组
    for (int i = 0; i < size; i++)
    {
        a[i] = output[i];
    }
    // 释放空间
    free(count);
    free(output);
}

// 基数计数排序
void RadixCountSort(int *a, int size)
{
    int max = a[0];
    // 找出数组中的最大数
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    // 计算最大数的位数
    int maxDigit = 0;
    while (max != 0)
    {
        max /= 10;
        maxDigit++;
    }
    // 初始化计数数组和结果数组
    int *count = (int *)malloc(size * sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));
    if (count == NULL || output == NULL)
    {
        perror("calloc error");
        exit(1);
    }

    for (int i = 0; i < maxDigit; i++)
    {
        // 初始化计数数组
        for (int j = 0; j < 10; j++)
        {
            count[j] = 0;
        }

        // 统计
        for (int j = 0; j < size; j++)
        {
            int index = (int)(a[j] / pow(10, i)) % 10;
            count[index]++;
        }
        // 计算前缀和
        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }

        // 构造结果数组
        for (int j = size - 1; j >= 0; j--)
        {
            // 通过值来拿索引了
            int index = (int)(a[j] / pow(10, i)) % 10;
            output[count[index] - 1] = a[j];
            count[index]--;
        }
        // 将结果数组赋给原数组
        for (int j = 0; j < size; j++)
        {
            a[j] = output[j];
        }
    }

    // 释放内存
    free(count);
    free(output);
}

void getTestData(int num_data, int max_value, const char *filename)
{

    // 初始化随机生成器
    srand((unsigned int)time(NULL));
    // 打开文件
    FILE *fn = fopen(filename, "w");
    if (fn == NULL)
    {
        perror("fopen error");
        exit(1);
    }
    // 开写
    for (int i = 0; i < num_data; i++)
    {
        fprintf(fn, "%d\n", rand() % (max_value + 1)); // 随机生成0~max_value之间,包括边界的数
    }
    // 关文件
    fclose(fn);
}

// void quick_test(){
//     cout<<"接下来要显示很多东西捏"<<endl;
//     //先来三个数组,10000,50000,200000
//     int data10000[10005];
//     int data50000[50005];
//     int data200000[200005];

//     // 承接文件数据
// }

void ISort_test(const char *filename, int n)
{
    // 插入排序测试

    // 承接文件数据
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序
    insertSort(data, n);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void MSort_test(const char *filename, int n)
{
    // 归并排序测试
    // 承接文件数据
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序

    MergeSort(data, 0, n - 1, temp);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void QSort_test(const char *filename, int n)
{
    // 快速排序测试
    // 承接文件数据
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序

    QuickSort_Recursion(data, 0, n - 1);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void CSort_test(const char *filename, int n)
{
    // 计数排序测试

    // 承接文件数据
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    int max_value = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > max_value)
        {
            max_value = data[i];
        }
    }
    // 调用排序
    CountSort(data, n, max_value);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void RCSort_test(const char *filename, int n)
{
    // 基数计数排序测试

    // 承接文件数据
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    int max_value = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > max_value)
        {
            max_value = data[i];
        }
    }
    // 调用排序
    RadixCountSort(data, n);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }
    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void Sort()
{
    char input[100];
    char choice;
    while (true)
    {
        cout << ">>================<<" << endl;
        cout << "  | 1.插入排序   |" << endl;
        cout << "  | 2.归并排序   |" << endl;
        cout << "  | 3.快速排序   |" << endl;
        cout << "  | 4.计数排序   |" << endl;
        cout << "  | 5.基数计数排序|" << endl;
        cout << "  | 6.退出       |" << endl;
        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if (strlen(input) == 1)
            {
                if (input[0] >= '1' && input[0] <= '6')
                {
                    system("cls");
                    choice = input[0];
                    break;
                }
                else
                {
                    cout << "请输入正确序数!" << endl;
                }
            }
            else
            {
                cout << "请输入一个字符！" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            // 因为在函数里边已经判断过文件是否存在了,所以这里我就不判断了
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            int n;
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            ISort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;

            break;
        case '2':
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度

            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            MSort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;

        case '3':
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            QSort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;
        case '4':
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            CSort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;
        case '5':
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            RCSort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;

        case '6':
            return;
        }
    }
}
void quick_test()
{
    double I_time1, I_time5, I_time20;
    double M_time1, M_time5, M_time20;
    double Q_time1, Q_time5, Q_time20;
    double C_time1, C_time5, C_time20;
    double R_time1, R_time5, R_time20;
    // 开始爆算
    start_time = clock();
    ISort_test("test10000-10000.txt", 10000);
    end_time = clock();
    I_time1 = (double)(end_time - start_time);

    start_time = clock();
    ISort_test("test50000-50000.txt", 50000);
    end_time = clock();
    I_time5 = (double)(end_time - start_time);

    start_time = clock();
    ISort_test("test200000-200000.txt", 200000);
    end_time = clock();
    I_time20 = (double)(end_time - start_time);

    start_time = clock();
    MSort_test("test10000-10000.txt", 10000);
    end_time = clock();
    M_time1 = (double)(end_time - start_time);

    start_time = clock();
    MSort_test("test50000-50000.txt", 50000);
    end_time = clock();
    M_time5 = (double)(end_time - start_time);

    start_time = clock();
    MSort_test("test200000-200000.txt", 200000);
    end_time = clock();
    M_time20 = (double)(end_time - start_time);

    start_time = clock();
    QSort_test("test10000-10000.txt", 10000);
    end_time = clock();
    Q_time1 = (double)(end_time - start_time);

    start_time = clock();
    QSort_test("test50000-50000.txt", 50000);
    end_time = clock();
    Q_time5 = (double)(end_time - start_time);

    start_time = clock();
    QSort_test("test200000-200000.txt", 200000);
    end_time = clock();
    Q_time20 = (double)(end_time - start_time);

    start_time = clock();
    CSort_test("test10000-10000.txt", 10000);
    end_time = clock();
    C_time1 = (double)(end_time - start_time);

    start_time = clock();
    CSort_test("test50000-50000.txt", 50000);
    end_time = clock();
    C_time5 = (double)(end_time - start_time);

    start_time = clock();
    CSort_test("test200000-200000.txt", 200000);
    end_time = clock();
    C_time20 = (double)(end_time - start_time);

    start_time = clock();
    RCSort_test("test10000-10000.txt", 10000);
    end_time = clock();
    R_time1 = (double)(end_time - start_time);

    start_time = clock();
    RCSort_test("test50000-50000.txt", 50000);
    end_time = clock();
    R_time5 = (double)(end_time - start_time);

    start_time = clock();
    RCSort_test("test200000-200000.txt", 200000);
    end_time = clock();
    R_time20 = (double)(end_time - start_time);

    cout << "中场休息,一下数据按数据层次,10000,50000,200000,单位为毫秒" << endl;
    cout << "插入排序用时:" << I_time1 << " " << I_time5 << " " << I_time20 << endl;
    cout << "归并排序用时:" << M_time1 << " " << M_time5 << " " << M_time20 << endl;
    cout << "快速排序用时:" << Q_time1 << " " << Q_time5 << " " << Q_time20 << endl;
    cout << "计数排序用时:" << C_time1 << " " << C_time5 << " " << C_time20 << endl;
    cout << "基数排序用时:" << R_time1 << " " << R_time5 << " " << R_time20 << endl;

    cout << endl
         << "====================================================" << endl;
    double I_timea, I_timeb, I_timec;
    double M_timea, M_timeb, M_timec;
    double Q_timea, Q_timeb, Q_timec;
    double C_timea, C_timeb, C_timec;
    double R_timea, R_timeb, R_timec;
    cout << "接下来看大量排序用时" << endl;
    start_time = clock();
    for (int i = 0; i < 100; i++)
        ISort_test("test100-100.txt", 100);
    end_time = clock();
    I_timea = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 500; i++)
        ISort_test("test100-100.txt", 100);
    end_time = clock();
    I_timeb = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        ISort_test("test100-100.txt", 100);
    end_time = clock();
    I_timec = (double)(end_time - start_time);

    cout << "接下来数据量都是100,排序次数依次为100,500,1000" << endl;
    cout << "插入排序用时:" << I_timea << " " << I_timeb << " " << I_timec << endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        MSort_test("test100-100.txt", 100);
    end_time = clock();
    M_timea = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 500; i++)
        MSort_test("test100-100.txt", 100);
    end_time = clock();
    M_timeb = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        MSort_test("test100-100.txt", 100);
    end_time = clock();
    M_timec = (double)(end_time - start_time);

    cout << "归并排序用时:" << M_timea << " " << M_timeb << " " << M_timec << endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        QSort_test("test100-100.txt", 100);
    end_time = clock();

    Q_timea = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 500; i++)
        QSort_test("test100-100.txt", 100);
    end_time = clock();

    Q_timeb = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        QSort_test("test100-100.txt", 100);
    end_time = clock();

    Q_timec = (double)(end_time - start_time);

    cout << "快速排序用时:" << Q_timea << " " << Q_timeb << " " << Q_timec << endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        CSort_test("test100-100.txt", 100);
    end_time = clock();

    C_timea = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 500; i++)
        CSort_test("test100-100.txt", 100);
    end_time = clock();

    C_timeb = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        CSort_test("test100-100.txt", 100);
    end_time = clock();

    C_timec = (double)(end_time - start_time);

    cout << "计数排序用时:" << C_timea << " " << C_timeb << " " << C_timec << endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        RCSort_test("test100-100.txt", 100);
    end_time = clock();

    R_timea = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 500; i++)
        RCSort_test("test100-100.txt", 100);
    end_time = clock();

    R_timeb = (double)(end_time - start_time);

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        RCSort_test("test100-100.txt", 100);
    end_time = clock();

    R_timec = (double)(end_time - start_time);

    cout << "基数排序用时:" << R_timea << " " << R_timeb << " " << R_timec << endl;

}


void ColorSort(int *a,int size){
    //只能使用一个单层for循环,将其从小到大进行排序
     int temp;
     //使用两个索引控制0和2的位置,再用一个索引进行遍历,遇到
    int*p0 = a,*p1 = a,*p2 = a+size-1;
    while(p0!=p2){
        while(true){
        if(*p0==0){
            temp = *p0;
            *p0 = *p1;
            *p1 = temp;
            p1++;
        }
        if(*p0==2){
            temp = *p0;
            *p0 = *p2;
            *p2 = temp;
            p2--;
        }
        if(*p0==1){
            p0++;
            break;
            
        }
        }
    }
    
}

void application(){
    //颜色排序数组
    int a[10] = {2, 0, 1, 2, 1, 0, 2, 0, 1, 2};
    int b[10] = {1,2,5,7,31,8,9,67,3,10};

    int k;
    char input[100];
    char choice;
    while (true)
    {
        cout << ">>=====================<<" << endl;
        cout << "  | 1.颜色排序        |" << endl;
        cout << "  | 2.找到第K大/小的数|" << endl;
        cout << "  | 3.退出程序        |" << endl;
        cout << ">>=====================<<" << endl;
        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if (strlen(input) == 1)
            {
                if (input[0] >= '1' && input[0] <= '3')
                {
                    system("cls");

                    choice = input[0];
                    break;
                }
                else
                {
                    cout << "请输入正确序数!" << endl;
                }
            }
            else
            {
                cout << "请输入一个字符！" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            
            //遍历显示一下先
            for (int i = 0; i < 10; i++)
                cout << a[i] << " ";

            ColorSort(a, 10);
            //显示一下排序后的
            cout << endl;
            for (int i = 0; i < 10; i++)
                cout << a[i] << " ";
            
            cout<<endl;
            cout<<"排序完成"<<endl;
            break;

        case '2':
            cout<<"来先给你看看原数组"<<endl;
            for(int i=0;i<10;i++){
                cout<<b[i]<<" ";
            }
            while(true){
                cout<<"请输入k的值,输入1~10哈:";
                fgets(input,100,stdin);
                //取出回车
                input[strlen(input)-1]='\0';
                if(is_int(input)){
                    k = atoi(input);
                    if(k>=1&&k<=10){
                        break;
                    }else{
                        cout<<"请输入1~10的整数"<<endl;
                    }
                }else{
                    cout<<"请输入数字"<<endl;
                }
            }
            getKth(b,10,k);
            break;

        case '3':

            return;
            
            }
        }
    
}

void getKth(int *a,int size,int k){
    //小小偷个懒,直接输出了
        int pivotIndex = Partition(a, 0, size-1);
        
        while(pivotIndex+1!=k){
            if(pivotIndex+1<k){
                pivotIndex = Partition(a,pivotIndex+1,size-1);
            }
            else if(pivotIndex+1>k){
                pivotIndex = Partition(a,0,pivotIndex-1);
            }
            
        }
        
        cout<<"第"<<k<<"小的数是:"<<a[pivotIndex]<<endl;
    
}

void selectoptimize(){
    int n;

    char input[100];
    char choice;
    while (true)
    {
        cout << ">>==========================<<" << endl;
        cout << "  | 1.快速排序非递归   " << endl;
        cout << "  | 2.快速排序随机和基准优化 " << endl;
        cout << "  | 3.冒泡排序   " << endl;
        cout << "  | 4.退出程序   " << endl;
        cout << ">>==========================<<" << endl;
        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if (strlen(input) == 1)
            {
                if (input[0] >= '1' && input[0] <= '4')
                {
                    system("cls");

                    choice = input[0];
                    break;
                }
                else
                {
                    cout << "请输入正确序数!" << endl;
                }
            }
            else
            {
                cout << "请输入一个字符！" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            //栈快速排序
            cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            StackQuickSort_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;
        case '2':
        //快速排序三枢轴,随机优化
        cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            quickSort_Recurtion_RandomAndPivot_optimize_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;

        case '3':
        cout << "请输入文件名：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            // 数组长度
            while (true)
            {
                cout << "让我考考你,文件里有多少数据呢" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // 取出回车
                str[strlen(str) - 1] = '\0';
                if (is_int(str))
                {
                    if (strlen(str) <= 9 && strlen(str) > 0)
                    {
                        n = atoi(str);
                        break;
                    }
                    else
                    {
                        cout << "确定有这么多吗牢大" << endl;
                    }
                }
                else
                {
                    cout << "请输入一个整数！" << endl;
                }
            }
            start_time = clock();
            bubbleSort_optimize_test(input, n);
            end_time = clock();
            cout << "排序完成,共耗时" << (double)(end_time - start_time) << "毫秒" << endl;
            cout << "可以去result文件查看排序结果" << endl;
            break;
        case '4':
            // 退出程序
            return ;
        }
    }
}
//非递归版
void StackQuickSort(int *a,int size){
    //定义一个栈,模拟递归,栈中存储一系列区间
    typedef struct{
        int start;
        int end;
    }Stack;
    Stack stack[size];
    int top = 0;
    //先将起始和结束位置入栈
    stack[top].start = 0;
    stack[top].end = size-1;
    //若已无需划分区间则排序完成
    while(top>=0){
        
        //取出栈顶元素
        int start = stack[top].start;
        int end = stack[top].end;
        top--;

        
            int pivotIndex = Partition(a,start,end);
            //将piovtIndex的下一个位置入栈
            if(pivotIndex+1<end){
                stack[++top].start = pivotIndex+1;
                stack[top].end = end;
            }
            //将piovtIndex的下一个位置入栈
            if(pivotIndex-1>start){
                stack[++top].start = start;
                stack[top].end = pivotIndex-1;
            }
        }
    }


//冒泡排序优化
void bubbleSort_optimize(int *a,int n){
    //减少不必要的比较,优化交换,双向遍历
    int j,temp;
    int is_swap;
    int isSorted = 0;
    for(int i = 0;i<n/2&&!isSorted;i++){
            //从左到右
            
            for(int j = i;j<n-i-1;j++){
                is_swap = 0;
                if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    is_swap = 1;
                }
            }
            //从右到左,这里n-2是因为上面从左到右已经堆了一个最大的过去了
            for(int j = n-i-2;j>=i;j--){
                is_swap = 0;
                if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    is_swap = 1;

                }
            }
            //如果这一轮没有交换,说明已经排好序了
            if(!is_swap){
                isSorted = 1;
            }
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
int choiceOfThree(int *a,int begin,int mid,int end){
    int temp;
    if(a[begin]<a[mid]){
       temp =  a[begin];
       a[begin] = a[mid];
        a[mid] = temp;
    }
    if(a[mid]<a[end]){
        temp =  a[mid];
        a[mid] = a[end];
        a[end] = temp;
    }
    if(a[begin]<a[mid]){
        temp =  a[begin];
        a[begin] = a[mid];
        a[mid] = temp;
    }

    return mid;
}
void quickSort_Recurtion_RandomAndPivot_optimize(int *a,int begin,int end){
    int temp;
    if(begin<end){
        srand(time(NULL));
        int pivotIndex = rand()%(end-begin+1)+begin;
        choiceOfThree(a,begin,pivotIndex,end);
        //我还想用划分函数,所以
        temp = a[pivotIndex];
        a[pivotIndex] = a[end];
        a[end] = temp;
        //划分函数
        pivotIndex = Partition(a,begin,end);
        //递归
        quickSort_Recurtion_RandomAndPivot_optimize(a,begin,pivotIndex-1);
        quickSort_Recurtion_RandomAndPivot_optimize(a,pivotIndex+1,end);
    }
}

void StackQuickSort_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序
    StackQuickSort(data, n);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void bubbleSort_optimize_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序
    bubbleSort_optimize(data, n);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

void quickSort_Recurtion_RandomAndPivot_optimize_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // 调用排序
    quickSort_Recurtion_RandomAndPivot_optimize(data,0,n-1);

    // 将结果输出到一个文件中
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // 关闭资源
    fclose(fn);
    fclose(fw);
}

