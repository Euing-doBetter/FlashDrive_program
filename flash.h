#pragma once
//int spare_block = 5;
//int spare_area = 16;
//int pare_of_sector = 32;
int sector_num;//���� ��ȣ�� �޾ƿ��� ������
char insert_im[5];// char insert_im[5];//�ȿ� �־��� ���ڸ� ��Ƴ��� ����
char tmp[5];//����� ���� ��Ƴ��� ����
//fread,fwrite,fseek���
int insert_num;//��ް�������� �˷��ִ� ����
//int total_sector_num=0;
int block_num;//����� ��

int init(int insert_num);
void Flash_read(int sector_num);
void Flash_write(int sector_num, char insert_im[5]);
void Flash_erase(int block_num);