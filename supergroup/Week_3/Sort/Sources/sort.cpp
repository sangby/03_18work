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

int data[100000005]; // ȫ�ֹ�����,�Ͳ�Ҫ���Ǵ�����ô���������
int temp[100000005];

// ʱ����ʼ,������
clock_t start_time;
clock_t end_time;

// �ж����ǲ������ִ�,�ǵĻ��ͷ���1,���Ǿͷ���0
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
    // ǳǳд���˵�
    char input[100];
    char choice;
    while (true)
    {
        cout << ">>================<<" << endl;
        cout << "  | 1.����ʱ��   |" << endl;
        cout << "  | 2.����Ӧ���� |" << endl;
        cout << "  | 3.ѡ���Ż�   |" << endl;
        cout << "  | 4.�˳�����   |" << endl;
        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ������,����Ҫ��ֻ��1��4,���Ժܺ�ɸ,���Ȼ�Ҫɸ
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
                    cout << "��������ȷ����!" << endl;
                }
            }
            else
            {
                cout << "������һ���ַ���" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            // ���Գ���
            computetime();
            break;
        case '2':
        application();
            // ����Ӧ����
            break;

        case '3':
        selectoptimize();
            // ѡ���Ż�
            break;
        case '4':
            // �˳�����
            return 0;
        }
    }
}

void computetime()
{
    // ������
    // ��������,10000,50000,200000
    // ��������,100������100������
    // ����������
    // ������Ӧ�����������װ��ָ���ļ�
    // ��ָ���ļ���������
    // ���˿��ٲ���
    char input[100];
    char choice;
    // ��Ҫд�˵�
    while (true)
    {
        cout << "=======>>>��������ʱ��" << endl;
        cout << "=================" << endl;
        cout << "1.���˿��ٲ���" << endl;
        cout << "2.����������" << endl;
        cout << "3.������" << endl;
        cout << "4.�˳�" << endl;
        cout << "=================" << endl;

        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // �ҷ�����д,�������ȶ������ٶ���ʽ
            if (strlen(input) != 1)
            {
                cout << "�������" << endl;
            }
            else
            {
                if (input[0] < '1' || input[0] > '4')
                {
                    cout << "�������" << endl;
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
            // ���˿��ٲ���
            cout<<"���ܺ�ʱ�ϳ�,�����ĵȴ�...ʱ�䵥λ�Ǻ���"<<endl;
            quick_test();
            break;
        case '2':
            int num_data;
            // ����������
            while (true)
            {
                cout << "��������������";
                fgets(input, 100, stdin);
                // ȡ���س�
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
                        cout << "̫����" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            // ���������������ֵ
            int max_value;
            while (true)
            {
                cout << "�������������ֵ��";
                fgets(input, 100, stdin);
                // ȡ���س�
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
                        cout << "̫����" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            // �����ļ���
            char filename[100];
            while (true)
            {
                cout << "���������ݴ����ļ�����test.txt:";
                fgets(input, 100, stdin);
                // ȡ���س�
                input[strlen(input) - 1] = '\0';
                char partOfileName[5];
                // ��ȡ���ĸ��ַ���partOfileName,�����ַ���и�����
                strncpy(partOfileName, input + strlen(input) - 4, 4);
                if (strcmp(partOfileName, ".txt") == 0)
                {
                    strcpy(filename, input);
                    break;
                }
                else
                {
                    cout << "�ļ�������,���������룡" << endl;
                }
            }

            getTestData(num_data, max_value, filename);
            // ����������
            break;
        case '3':
            // ������
            Sort();
            break;

        case '4':
            // �˳�
            return;
        }
    }
}
// void application() {
// //����Ӧ����
//     //��ɫ����Ҫ��ͦ��,������һ������012���ַ���,Ȼ������
//     //�ҵ���kС����,������һ���ַ���,��˵,�һ�û����
// }

// void selectoptimize() {
// //ѡ���Ż�

// }

void insertSort(int *a, int n)
{

    // ��������
    /*forѭ��1��n,��ÿ��i������ֵ����key,����j = i-1,ȷ�������������,Ȼ��while��ʼ����,����
�и��ص����һ·��һ·��λ�ø�����*/
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
// �鲢����
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
    int i = begin;   // ����������ʼ
    int j = mid + 1; // �Ұ��������ʼ
    int k = begin;   // ��������  ָ��
    // ���������鶼��Ԫ��,��Ƚ�,����С��Ԫ�ظ���temp����
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

    // ������黹��Ԫ��,��ֱ�ӽ�����Ԫ�ظ���temp����
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }

    // ��temp�����е�Ԫ�ظ���a����
    for (int i = begin; i <= end; i++)
    {
        a[i] = temp[i];
    }
}
// ��һ������ݹ��Ϊ��������,Ȼ��ϲ�
void MergeSort(int *a, int begin, int end, int *temp)
{
    // ͨ��begin,end��Ϊ��������
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        // ���ַ���,������ż�����������ҵȷ�,��������ʱ��߱��ұ߶�һ��Ԫ��
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);

        MergeArray(a, begin, mid, end, temp);
    } // ��begin>end,��˵������ֻ��һ��Ԫ��,�ݵ���,�������,��ʼ��
}
// ��������ݹ��
void QuickSort_Recursion(int *a, int begin, int end)
{
    if (begin < end)
    {

        int pivotIndex = Partition(a, begin, end);

        QuickSort_Recursion(a, begin, pivotIndex - 1);
        QuickSort_Recursion(a, pivotIndex + 1, end);
    } // �����鳤��Ϊ��ʱ,���ֹ������Ѿ��������,��begin>endʱ,�ݹ鿪ʼ����
}

int Partition(int *a, int begin, int end)
{
    int pivot = a[end]; // ѡȡ���һ��Ԫ����Ϊ��׼
    int i = begin - 1;  // ����������i++
    // �������黮��
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
// ��������
void CountSort(int *a, int size, int max)
{
    // ������������
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL)
    {
        perror("calloc error");
        exit(1);
    }
    // ��������Ԫ�س��ִ���
    for (int i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    // ����ǰ׺��,�γ��ۼ�����
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // �����������
    int *output = (int *)malloc(size * sizeof(int));
    if (output == NULL)
    {
        perror("malloc error");
        free(count);
        exit(1);
    }
    // ����������
    for (int i = size - 1; i >= 0; i--)
    {
        /*����count��ʾ�ۼ���,����ֵ�����ʾ��˳�������Ϣ,
        ����a[i]ȥ����������һ������a[i]�����,a[i]�Ĵ���
        ���Ƕ�Ӧ���ۼ�ֵ,Ҫ����������,��Ҫ��������һ
        ���ǾͿ��Խ�������������,�����Ҫ���ۼ�ֵ��һ��Ϊ�˷�
        ������ͬ������,�����ظ�����
        */
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    // ��������鸳��ԭ����
    for (int i = 0; i < size; i++)
    {
        a[i] = output[i];
    }
    // �ͷſռ�
    free(count);
    free(output);
}

// ������������
void RadixCountSort(int *a, int size)
{
    int max = a[0];
    // �ҳ������е������
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    // �����������λ��
    int maxDigit = 0;
    while (max != 0)
    {
        max /= 10;
        maxDigit++;
    }
    // ��ʼ����������ͽ������
    int *count = (int *)malloc(size * sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));
    if (count == NULL || output == NULL)
    {
        perror("calloc error");
        exit(1);
    }

    for (int i = 0; i < maxDigit; i++)
    {
        // ��ʼ����������
        for (int j = 0; j < 10; j++)
        {
            count[j] = 0;
        }

        // ͳ��
        for (int j = 0; j < size; j++)
        {
            int index = (int)(a[j] / pow(10, i)) % 10;
            count[index]++;
        }
        // ����ǰ׺��
        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }

        // ����������
        for (int j = size - 1; j >= 0; j--)
        {
            // ͨ��ֵ����������
            int index = (int)(a[j] / pow(10, i)) % 10;
            output[count[index] - 1] = a[j];
            count[index]--;
        }
        // ��������鸳��ԭ����
        for (int j = 0; j < size; j++)
        {
            a[j] = output[j];
        }
    }

    // �ͷ��ڴ�
    free(count);
    free(output);
}

void getTestData(int num_data, int max_value, const char *filename)
{

    // ��ʼ�����������
    srand((unsigned int)time(NULL));
    // ���ļ�
    FILE *fn = fopen(filename, "w");
    if (fn == NULL)
    {
        perror("fopen error");
        exit(1);
    }
    // ��д
    for (int i = 0; i < num_data; i++)
    {
        fprintf(fn, "%d\n", rand() % (max_value + 1)); // �������0~max_value֮��,�����߽����
    }
    // ���ļ�
    fclose(fn);
}

// void quick_test(){
//     cout<<"������Ҫ��ʾ�ܶණ����"<<endl;
//     //������������,10000,50000,200000
//     int data10000[10005];
//     int data50000[50005];
//     int data200000[200005];

//     // �н��ļ�����
// }

void ISort_test(const char *filename, int n)
{
    // �����������

    // �н��ļ�����
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������
    insertSort(data, n);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void MSort_test(const char *filename, int n)
{
    // �鲢�������
    // �н��ļ�����
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������

    MergeSort(data, 0, n - 1, temp);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void QSort_test(const char *filename, int n)
{
    // �����������
    // �н��ļ�����
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������

    QuickSort_Recursion(data, 0, n - 1);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void CSort_test(const char *filename, int n)
{
    // �����������

    // �н��ļ�����
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
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
    // ��������
    CountSort(data, n, max_value);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void RCSort_test(const char *filename, int n)
{
    // ���������������

    // �н��ļ�����
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
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
    // ��������
    RadixCountSort(data, n);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }
    // �ر���Դ
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
        cout << "  | 1.��������   |" << endl;
        cout << "  | 2.�鲢����   |" << endl;
        cout << "  | 3.��������   |" << endl;
        cout << "  | 4.��������   |" << endl;
        cout << "  | 5.������������|" << endl;
        cout << "  | 6.�˳�       |" << endl;
        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
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
                    cout << "��������ȷ����!" << endl;
                }
            }
            else
            {
                cout << "������һ���ַ���" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            // ��Ϊ�ں�������Ѿ��жϹ��ļ��Ƿ������,���������ҾͲ��ж���
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            int n;
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            ISort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;

            break;
        case '2':
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��

            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            MSort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;

        case '3':
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            QSort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;
        case '4':
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            CSort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;
        case '5':
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            RCSort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
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
    // ��ʼ����
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

    cout << "�г���Ϣ,һ�����ݰ����ݲ��,10000,50000,200000,��λΪ����" << endl;
    cout << "����������ʱ:" << I_time1 << " " << I_time5 << " " << I_time20 << endl;
    cout << "�鲢������ʱ:" << M_time1 << " " << M_time5 << " " << M_time20 << endl;
    cout << "����������ʱ:" << Q_time1 << " " << Q_time5 << " " << Q_time20 << endl;
    cout << "����������ʱ:" << C_time1 << " " << C_time5 << " " << C_time20 << endl;
    cout << "����������ʱ:" << R_time1 << " " << R_time5 << " " << R_time20 << endl;

    cout << endl
         << "====================================================" << endl;
    double I_timea, I_timeb, I_timec;
    double M_timea, M_timeb, M_timec;
    double Q_timea, Q_timeb, Q_timec;
    double C_timea, C_timeb, C_timec;
    double R_timea, R_timeb, R_timec;
    cout << "������������������ʱ" << endl;
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

    cout << "����������������100,�����������Ϊ100,500,1000" << endl;
    cout << "����������ʱ:" << I_timea << " " << I_timeb << " " << I_timec << endl;

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

    cout << "�鲢������ʱ:" << M_timea << " " << M_timeb << " " << M_timec << endl;

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

    cout << "����������ʱ:" << Q_timea << " " << Q_timeb << " " << Q_timec << endl;

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

    cout << "����������ʱ:" << C_timea << " " << C_timeb << " " << C_timec << endl;

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

    cout << "����������ʱ:" << R_timea << " " << R_timeb << " " << R_timec << endl;

}


void ColorSort(int *a,int size){
    //ֻ��ʹ��һ������forѭ��,�����С�����������
     int temp;
     //ʹ��������������0��2��λ��,����һ���������б���,����
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
    //��ɫ��������
    int a[10] = {2, 0, 1, 2, 1, 0, 2, 0, 1, 2};
    int b[10] = {1,2,5,7,31,8,9,67,3,10};

    int k;
    char input[100];
    char choice;
    while (true)
    {
        cout << ">>=====================<<" << endl;
        cout << "  | 1.��ɫ����        |" << endl;
        cout << "  | 2.�ҵ���K��/С����|" << endl;
        cout << "  | 3.�˳�����        |" << endl;
        cout << ">>=====================<<" << endl;
        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
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
                    cout << "��������ȷ����!" << endl;
                }
            }
            else
            {
                cout << "������һ���ַ���" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            
            //������ʾһ����
            for (int i = 0; i < 10; i++)
                cout << a[i] << " ";

            ColorSort(a, 10);
            //��ʾһ��������
            cout << endl;
            for (int i = 0; i < 10; i++)
                cout << a[i] << " ";
            
            cout<<endl;
            cout<<"�������"<<endl;
            break;

        case '2':
            cout<<"���ȸ��㿴��ԭ����"<<endl;
            for(int i=0;i<10;i++){
                cout<<b[i]<<" ";
            }
            while(true){
                cout<<"������k��ֵ,����1~10��:";
                fgets(input,100,stdin);
                //ȡ���س�
                input[strlen(input)-1]='\0';
                if(is_int(input)){
                    k = atoi(input);
                    if(k>=1&&k<=10){
                        break;
                    }else{
                        cout<<"������1~10������"<<endl;
                    }
                }else{
                    cout<<"����������"<<endl;
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
    //СС͵����,ֱ�������
        int pivotIndex = Partition(a, 0, size-1);
        
        while(pivotIndex+1!=k){
            if(pivotIndex+1<k){
                pivotIndex = Partition(a,pivotIndex+1,size-1);
            }
            else if(pivotIndex+1>k){
                pivotIndex = Partition(a,0,pivotIndex-1);
            }
            
        }
        
        cout<<"��"<<k<<"С������:"<<a[pivotIndex]<<endl;
    
}

void selectoptimize(){
    int n;

    char input[100];
    char choice;
    while (true)
    {
        cout << ">>==========================<<" << endl;
        cout << "  | 1.��������ǵݹ�   " << endl;
        cout << "  | 2.������������ͻ�׼�Ż� " << endl;
        cout << "  | 3.ð������   " << endl;
        cout << "  | 4.�˳�����   " << endl;
        cout << ">>==========================<<" << endl;
        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
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
                    cout << "��������ȷ����!" << endl;
                }
            }
            else
            {
                cout << "������һ���ַ���" << endl;
            }
        }
        switch (choice)
        {
        case '1':
            //ջ��������
            cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            StackQuickSort_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;
        case '2':
        //��������������,����Ż�
        cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            quickSort_Recurtion_RandomAndPivot_optimize_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;

        case '3':
        cout << "�������ļ�����";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            // ���鳤��
            while (true)
            {
                cout << "���ҿ�����,�ļ����ж���������" << endl;
                char str[100];
                fgets(str, 100, stdin);
                // ȡ���س�
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
                        cout << "ȷ������ô�����δ�" << endl;
                    }
                }
                else
                {
                    cout << "������һ��������" << endl;
                }
            }
            start_time = clock();
            bubbleSort_optimize_test(input, n);
            end_time = clock();
            cout << "�������,����ʱ" << (double)(end_time - start_time) << "����" << endl;
            cout << "����ȥresult�ļ��鿴������" << endl;
            break;
        case '4':
            // �˳�����
            return ;
        }
    }
}
//�ǵݹ��
void StackQuickSort(int *a,int size){
    //����һ��ջ,ģ��ݹ�,ջ�д洢һϵ������
    typedef struct{
        int start;
        int end;
    }Stack;
    Stack stack[size];
    int top = 0;
    //�Ƚ���ʼ�ͽ���λ����ջ
    stack[top].start = 0;
    stack[top].end = size-1;
    //�������軮���������������
    while(top>=0){
        
        //ȡ��ջ��Ԫ��
        int start = stack[top].start;
        int end = stack[top].end;
        top--;

        
            int pivotIndex = Partition(a,start,end);
            //��piovtIndex����һ��λ����ջ
            if(pivotIndex+1<end){
                stack[++top].start = pivotIndex+1;
                stack[top].end = end;
            }
            //��piovtIndex����һ��λ����ջ
            if(pivotIndex-1>start){
                stack[++top].start = start;
                stack[top].end = pivotIndex-1;
            }
        }
    }


//ð�������Ż�
void bubbleSort_optimize(int *a,int n){
    //���ٲ���Ҫ�ıȽ�,�Ż�����,˫�����
    int j,temp;
    int is_swap;
    int isSorted = 0;
    for(int i = 0;i<n/2&&!isSorted;i++){
            //������
            
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
            //���ҵ���,����n-2����Ϊ����������Ѿ�����һ�����Ĺ�ȥ��
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
            //�����һ��û�н���,˵���Ѿ��ź�����
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
        //�һ����û��ֺ���,����
        temp = a[pivotIndex];
        a[pivotIndex] = a[end];
        a[end] = temp;
        //���ֺ���
        pivotIndex = Partition(a,begin,end);
        //�ݹ�
        quickSort_Recurtion_RandomAndPivot_optimize(a,begin,pivotIndex-1);
        quickSort_Recurtion_RandomAndPivot_optimize(a,pivotIndex+1,end);
    }
}

void StackQuickSort_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������
    StackQuickSort(data, n);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void bubbleSort_optimize_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������
    bubbleSort_optimize(data, n);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

void quickSort_Recurtion_RandomAndPivot_optimize_test(const char *filename,int n){
    FILE *fn = fopen(filename, "r");
    if (fn == NULL)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fn, "%d", &data[i]);
    }

    // ��������
    quickSort_Recurtion_RandomAndPivot_optimize(data,0,n-1);

    // ����������һ���ļ���
    FILE *fw = fopen("result.txt", "w");
    if (fw == NULL)
    {
        cout << "result�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d\n", data[i]);
    }

    // �ر���Դ
    fclose(fn);
    fclose(fw);
}

