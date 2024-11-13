#include <stdio.h>
#include "flash.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int pare_of_sector = 32;
int total_sector_num;
int total_block_num;

int init(int insert_num) {//x megabyte ��Ÿ����
	FILE* fp;
	fp = fopen("flash.txt", "w");
	total_sector_num = insert_num * 1024 * 1024 / 512;
	for (int i = 0; i < total_sector_num; i++) {
		fprintf(fp, "%d",0);
	}
	fclose(fp);
	return total_sector_num;
}
void Flash_read(int sector_num) {//PSN�� data return
	FILE* fp;
	fp = fopen("flash.txt", "rb");
	fseek(fp, sector_num, SEEK_SET);//ó����ġ���� sector_num��ŭ ������ ��ġ�� �̵�
	fgets(tmp, 2, fp);//fp��Ʈ������ NULL���� 2byte�� �ܾ�� tmp�� ����
	printf("%s\n", tmp);
	fclose(fp);
}
void Flash_write(int sector_num,/*flash*/char insert_im[5]) {//write�� ����� PSN ������ ǥ��
	FILE* fp;
	fp = fopen("flash.txt", "r+");
	fseek(fp, sector_num, SEEK_SET);
	fwrite(insert_im, sizeof(char),strlen(insert_im),fp);
	//pos = ftell(fp);//���� ���� �������� ��ġ�� �˷��� ����������
	printf("���� ����� PSN: %s \n", insert_im);
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