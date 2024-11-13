#pragma once
//int spare_block = 5;
//int spare_area = 16;
//int pare_of_sector = 32;
int sector_num;//섹터 번호를 받아오는 정수값
char insert_im[5];// char insert_im[5];//안에 넣어줄 문자를 담아놓을 상자
char tmp[5];//출력할 문자 담아놓을 상자
//fread,fwrite,fseek사용
int insert_num;//몇메가만들건지 알려주는 정수
//int total_sector_num=0;
int block_num;//블록의 수

int init(int insert_num);
void Flash_read(int sector_num);
void Flash_write(int sector_num, char insert_im[5]);
void Flash_erase(int block_num);