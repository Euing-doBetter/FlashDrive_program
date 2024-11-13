#include <stdio.h>
#include "flash.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int pare_of_sector = 32;
int total_sector_num;
int total_block_num;

int init(int insert_num) {//x megabyte 나타내기
	FILE* fp;
	fp = fopen("flash.txt", "w");
	total_sector_num = insert_num * 1024 * 1024 / 512;
	for (int i = 0; i < total_sector_num; i++) {
		fprintf(fp, "%d",0);
	}
	fclose(fp);
	return total_sector_num;
}
void Flash_read(int sector_num) {//PSN의 data return
	FILE* fp;
	fp = fopen("flash.txt", "rb");
	fseek(fp, sector_num, SEEK_SET);//처음위치에서 sector_num만큼 떨어진 위치로 이동
	fgets(tmp, 2, fp);//fp스트림에서 NULL포함 2byte를 긁어와 tmp에 저장
	printf("%s\n", tmp);
	fclose(fp);
}
void Flash_write(int sector_num,/*flash*/char insert_im[5]) {//write가 수행된 PSN 데이터 표시
	FILE* fp;
	fp = fopen("flash.txt", "r+");
	fseek(fp, sector_num, SEEK_SET);
	fwrite(insert_im, sizeof(char),strlen(insert_im),fp);
	//pos = ftell(fp);//현재 파일 포인터의 위치를 알려줌 정수값으로
	printf("현재 수행된 PSN: %s \n", insert_im);
	fclose(fp);
}
void Flash_erase(int block_num) {
	FILE* fp;
	fp = fopen("flash.txt", "r+");
	total_block_num = total_sector_num / pare_of_sector;
	if (total_block_num>block_num) {
		if (block_num == 0) {
			for (int i = 0; i <= 31; i++) {
				fprintf(fp, "%d", 0);
			}
		}
		else{
			for (int i = (block_num * 31) + 1; i <= (31 *block_num+32); i++) {
				fseek(fp, i, SEEK_SET);
				fprintf(fp, "%d", 0);
			}
		}
	}
	else {
		return 0;
	}
	fclose(fp);
}