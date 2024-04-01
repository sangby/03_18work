
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;
#include<windows.h>
#include<time.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);





/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);




/**
 * @description: 找到第k个元素后输出
 * @param {int} *a
 * @param {int} size
 * @param {int} k
 * @return {*}
 */
void getKth(int *a,int size,int k);


/**
 * @name        : void computetime()
 * @description : 第一类作业, 计算程序运行时间
 * 
 */
void computetime();

/**
 * @description: 第二类作业,应用题
 * @return {*}
 */
void application();
/**
 * @description: 优化排序
 * @return {*}
 */
void selectoptimize();


/**
 * @description: 生成一个文件的测试数据
 * @param {int} num_data 数据量
 * @param {int} max_value 最大值
 * @param {char} *filename 文件名
 * @return {*}
 */
void getTestData(int num_data, int max_value, const char *filename);

/**
 * @description: 懒人快速测试
 * @return {*}
 */
void quick_test();

/**
 * @description: 插入排序的排序测试
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void ISort_test(const char *filename,int n);

/**
 * @description: 归并排序的排序测试
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void MSort_test(const char *filename,int n);

/**
 * @description: 快速排序的排序测试
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void QSort_test(const char *filename,int n);

/**
 * @description: 计数排序的排序测试
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void COSort_test(const char *filename,int n);

/**
 * @description: 基数排序的排序测试
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void RCSort_test(const char *filename,int n);


/**
 * @description: 排序总入口
 * @return {*}
 */
void Sort();


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void StackQuickSort(int *a,int size);

/**
 * @description: 冒泡排序三个优化
 * @param {int} *a
 * @param {int} n
 * @return {*}
 */
void bubbleSort_optimize(int *a,int n);

/**
 * @description: 快速排序递归版随机和三枢轴优化
 * @param {int} *a
 * @param {int} n
 * @return {*}
 */
void quickSort_Recurtion_RandomAndPivot_optimize(int *a,int begin, int end);

//三排序测试接口
void StackQuickSort_test(const char *fliename,int size);

void bubbleSort_optimize_test(const char *fliename,int size);

void quickSort_Recurtion_RandomAndPivot_optimize_test(const char *fliename,int size);

//三数取中
int choiceOfThree(int *a,int begin,int mid,int end);
#endif // QUEUE_H_INCLUDED
