
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;
#include<windows.h>
#include<time.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);





/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);




/**
 * @description: �ҵ���k��Ԫ�غ����
 * @param {int} *a
 * @param {int} size
 * @param {int} k
 * @return {*}
 */
void getKth(int *a,int size,int k);


/**
 * @name        : void computetime()
 * @description : ��һ����ҵ, �����������ʱ��
 * 
 */
void computetime();

/**
 * @description: �ڶ�����ҵ,Ӧ����
 * @return {*}
 */
void application();
/**
 * @description: �Ż�����
 * @return {*}
 */
void selectoptimize();


/**
 * @description: ����һ���ļ��Ĳ�������
 * @param {int} num_data ������
 * @param {int} max_value ���ֵ
 * @param {char} *filename �ļ���
 * @return {*}
 */
void getTestData(int num_data, int max_value, const char *filename);

/**
 * @description: ���˿��ٲ���
 * @return {*}
 */
void quick_test();

/**
 * @description: ����������������
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void ISort_test(const char *filename,int n);

/**
 * @description: �鲢������������
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void MSort_test(const char *filename,int n);

/**
 * @description: ����������������
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void QSort_test(const char *filename,int n);

/**
 * @description: ����������������
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void COSort_test(const char *filename,int n);

/**
 * @description: ����������������
 * @param {char} *filename
 * @param {int} n
 * @return {*}
 */
void RCSort_test(const char *filename,int n);


/**
 * @description: ���������
 * @return {*}
 */
void Sort();


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void StackQuickSort(int *a,int size);

/**
 * @description: ð�����������Ż�
 * @param {int} *a
 * @param {int} n
 * @return {*}
 */
void bubbleSort_optimize(int *a,int n);

/**
 * @description: ��������ݹ��������������Ż�
 * @param {int} *a
 * @param {int} n
 * @return {*}
 */
void quickSort_Recurtion_RandomAndPivot_optimize(int *a,int begin, int end);

//��������Խӿ�
void StackQuickSort_test(const char *fliename,int size);

void bubbleSort_optimize_test(const char *fliename,int size);

void quickSort_Recurtion_RandomAndPivot_optimize_test(const char *fliename,int size);

//����ȡ��
int choiceOfThree(int *a,int begin,int mid,int end);
#endif // QUEUE_H_INCLUDED
