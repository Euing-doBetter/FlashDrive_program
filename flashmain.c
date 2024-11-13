#include <stdio.h>
#include "flash.h"

int main() {
	int menu;
	/*flash* insert_im;
	insert_im = (flash*)malloc(sizeof(flash) * 90);*/
	while (1) {
		printf("1.메모리생성\n");
		printf("2.읽어올 섹터 넘버\n");
		printf("3.작성할 섹터 넘버\n");
		printf("4.지울 블록 넘버\n");
		printf("번호입력\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:printf("메모리 생성\n");
			   scanf("%d", &insert_num);
			   int numbox = init(insert_num);
			   printf("%d megabyte\n", numbox);
			   break;
		case 2:printf("읽어올 섹터 넘버\n");
			   scanf("%d", &sector_num);
			   Flash_read(sector_num);
			   break;
		case 3:printf("작성할 섹터 넘버\n");
			   scanf("%d %S", &sector_num, insert_im);
			   Flash_write(sector_num, insert_im);
			   break;
		case 4:printf("지울 블록 넘버\n");
			   scanf("%d", &block_num);
			   Flash_erase(block_num);
			   break;
		default:
			free(insert_im);
			return 0;
		}
	}
}