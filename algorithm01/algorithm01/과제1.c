#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, feof, fread, fclose �Լ��� ����� ��� ����
#include <string.h>    // strlen, memset �Լ��� ����� ��� ����
#include <stdlib.h>  //malloc,free �Լ� ����
#define MAX 1000
#define MAX_2 1000000


int main()
{
	int count = 0;
	char *pStr;
	char strTemp[MAX];
	char dict_name[100] = { 0, };
	char dict_meaning[1000];
	char *result;

	//����ü ������ ����
	//struct dict *p[MAX_2];
	//for (int i = 0; i < sizeof(p) / sizeof(struct dict *); i++)
	//{
	//	p[i] = malloc(sizeof(struct dict));
	//}
	
	printf("���������ϸ� �Է� :\n");		//�޾ƿ� ���ϸ� �Է�
	scanf("%s", &dict_name);

	FILE *fp = fopen(dict_name, "r+");    // ������ �б� ���(r)�� ����.
										   // ���� �����͸� ��ȯ


	//���ڿ��� ���پ� �޾ƿ��� ����
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			pStr = fgets(strTemp, sizeof(strTemp), fp);
			//printf("%s", strTemp);
			if (strTemp[0] != '\n')	//������ ���� ī��Ʈ ����
			{
				//strcpy(diction[count].name, pStr);
				//strcpy(diction[count].meaning, pStr);
				count++;				//���� �޾ƿԴ��� üũ
				result = strtok(pStr, "(");
				while (result != NULL)
				{
					printf("%s\b", result);
					result = strtok(NULL, "(");
				}
				//printf("\n%s", pStr);	//�о�� �� ���
			}
		}
		fclose(fp);    // ���� ������ �ݱ�
	}
	else { printf("����"); }


	printf("�о�� �ܾ��: %d\n", count);
	//�޾ƿ� ��ü�� �迭�� ���
	for (int i = 0; i <= count; i++) {
		//printf("%s", diction[i].name);
	}

	getchar();
	getchar();
	return 0;


}

