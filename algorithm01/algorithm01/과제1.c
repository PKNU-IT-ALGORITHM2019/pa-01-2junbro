#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // fopen, feof, fread, fclose 함수가 선언된 헤더 파일
#include <string.h>    // strlen, memset 함수가 선언된 헤더 파일
#include <stdlib.h>  //malloc,free 함수 선언
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

	//구조체 포인터 선언
	//struct dict *p[MAX_2];
	//for (int i = 0; i < sizeof(p) / sizeof(struct dict *); i++)
	//{
	//	p[i] = malloc(sizeof(struct dict));
	//}
	
	printf("데이터파일명 입력 :\n");		//받아올 파일명 입력
	scanf("%s", &dict_name);

	FILE *fp = fopen(dict_name, "r+");    // 파일을 읽기 모드(r)로 열기.
										   // 파일 포인터를 반환


	//문자열을 한줄씩 받아오는 과정
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			pStr = fgets(strTemp, sizeof(strTemp), fp);
			//printf("%s", strTemp);
			if (strTemp[0] != '\n')	//공백인 줄은 카운트 안함
			{
				//strcpy(diction[count].name, pStr);
				//strcpy(diction[count].meaning, pStr);
				count++;				//몇줄 받아왔는지 체크
				result = strtok(pStr, "(");
				while (result != NULL)
				{
					printf("%s\b", result);
					result = strtok(NULL, "(");
				}
				//printf("\n%s", pStr);	//읽어온 줄 출력
			}
		}
		fclose(fp);    // 파일 포인터 닫기
	}
	else { printf("에러"); }


	printf("읽어온 단어수: %d\n", count);
	//받아온 전체를 배열로 출력
	for (int i = 0; i <= count; i++) {
		//printf("%s", diction[i].name);
	}

	getchar();
	getchar();
	return 0;


}

