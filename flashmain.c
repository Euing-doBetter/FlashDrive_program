#include <stdio.h>
#include "flash.h"

int main() {
	int menu;
	/*flash* insert_im;
	insert_im = (flash*)malloc(sizeof(flash) * 90);*/
	while (1) {
		printf("1.�޸𸮻���\n");
		printf("2.�о�� ���� �ѹ�\n");
		printf("3.�ۼ��� ���� �ѹ�\n");
		printf("4.���� ��� �ѹ�\n");
		printf("��ȣ�Է�\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:printf("�޸� ����\n");
			   scanf("%d", &insert_num);
			   int numbox = init(insert_num);
			   printf("%d megabyte\n", numbox);
			   break;
		case 2:printf("�о�� ���� �ѹ�\n");
			   scanf("%d", &sector_num);
			   Flash_read(sector_num);
			   break;
		case 3:printf("�ۼ��� ���� �ѹ�\n");
			   scanf("%d %S", &sector_num, insert_im);
			   Flash_write(sector_num, insert_im);
			   break;
		case 4:printf("���� ��� �ѹ�\n");
			   scanf("%d", &block_num);
			   Flash_erase(block_num);
			   break;
		default:
			free(insert_im);
			return 0;
		}
	}
}