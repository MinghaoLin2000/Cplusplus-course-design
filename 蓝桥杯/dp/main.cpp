#include <string>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <io.h>

#define ROOM 256

void rc4_init(unsigned char *Sbox, std::string key);

bool rc4(std::string key, const char *in_file_name, const char *out_file_name);

void decode_dir(const char *jsonFileName);

long file_size(const char *filename);

std::string key = "00cd717da97ae7c71ddc";

int main(int argc, char *argv[]) {
    const char *dir_name = "C:\\Users\\0xEASONs\\Desktop\\widget";
    decode_dir(dir_name);
    std::cout << "Over" << std::endl;
    system("pause");
    return 0;
}

/*��ʼ������*/
void rc4_init(unsigned char *s,std::string key)
{
    int i=0,j=0;
    //char k[256]={0};
    int Len = key.length();
    unsigned char k[256]={0};
    unsigned char tmp=0;
    for(i=0;i<256;i++) {
        s[i]=i;
        k[i]=key[i%Len];
    }
    for(i=0;i<256;i++) {
        j=(j+s[i]+k[i])%256;
        tmp=s[i];
        s[i]=s[j];//����s[i]��s[j]
        s[j]=tmp;
    }
}

bool rc4(std::string key, const char *in_file_name, const char *out_file_name) {
    unsigned char s[ROOM];      //S���ı�
    FILE *pr;                      //������ļ�ָ��pr
    pr = fopen(in_file_name, "rb");    //ֻ��
    if (pr == NULL)                 //������ļ��������˳�
    {
        std::cout << "open fail��" << std::endl;
        return false;
    }

    FILE *pw;                      //����д�ļ�ָ��pw
    unsigned char *data;           //�洢ԭʼ�ļ����ݣ�������������г䵱���������ԭ���е������
    long size;
    size = file_size(in_file_name);
    data = (unsigned char *) malloc(size);//�����ڴ�
    memset(data, 0, size);
    FILE* tt = fopen(out_file_name, "rb");    //ֻ��
    if(tt!= NULL){
        fclose(tt);
        if (DeleteFile(out_file_name))//ɾ���ɹ�
            std::cout << out_file_name << " �ѳɹ�ɾ��." << std::endl;
        else
            std::cout << out_file_name << " ɾ��ʧ��" << std::endl;
    }
    pw = fopen(out_file_name, "wb");    //ģʽΪֻд��ˢ���ļ�

    if (pw == NULL)                            //������ļ��������˳�
    {
        std::cout << "output fail��" << std::endl;
        return false;
    }
    fread(data, sizeof(char), size, pr);//��ȡ��������(��Ҫ��/���ܵ��ļ�)
    rc4_init(s, key);      //�����S��
    int i=0,j=0,t=0;
    unsigned long k=0;
    unsigned char tmp;
    for(k=0;k<size;k++)
    {
        i=(i+1)%256;
         j=(j+s[i])%256;
        tmp=s[i];
        s[i]=s[j];//����s[x]��s[y]
        s[j]=tmp;
        t=(s[i]+s[j])%256;
        data[k]^=s[t];
    }

    std::cout << "success out " << out_file_name << std::endl;

    fwrite(data, sizeof(unsigned char), size, pw);//д���������
    fclose(pw);//�ر��ļ���
    fclose(pr);
    free(data);//�ͷ��ڴ�
    return true;
}

void decode_dir(const char *dir) {
    //���ڲ��ҵľ��
    long handle;
    // ·��ĩβ׷�� '\*.*'
    char newpath[200];
    strcpy(newpath, dir);
    strcat(newpath, "\\*.*");
    _finddata_t findData;
    //��һ�β���
    handle = _findfirst(newpath, &findData);
    if (handle == -1) {
        puts("����ʧ��");
        return;
    }
    // �����ļ����ļ���
    while (_findnext(handle, &findData) == 0) {
        // �ļ���
        if (findData.attrib & _A_SUBDIR) {
            // �ļ����������������ַ� '.'��'..'
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0) { continue; }
            // ��������ļ��м�������
            strcpy(newpath, dir);
            strcat(newpath, "\\");
            strcat(newpath, findData.name);
            decode_dir(newpath);
            printf("DIR:%s\n", newpath);
        }
            // �ļ�
        else {
            // ȡ�ļ�ȫ·��
            std::string str_fullPath = dir;
            str_fullPath += "\\";
            std::string outname = str_fullPath + "decoded_" + findData.name;
            str_fullPath += findData.name;
            printf("FILE:%s\n", str_fullPath.c_str());
            if (strstr(findData.name, "xml") || strstr(findData.name, "js") || strstr(findData.name, "css")|| strstr(findData.name, "html")) {
                if (!rc4(key, str_fullPath.c_str(), outname.c_str())) {
                    std::cout << "fail to decrypt " << str_fullPath.c_str() << std::endl;
                    return;
                }
                std::cout << "success decrypt " << str_fullPath.c_str() << std::endl;
            }
        }
    }
    _findclose(handle);
}

long file_size(const char *filename) //��ȡ�ļ�����
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return -1;
    fseek(fp, 0L, SEEK_END);    //����fseek������ָ�붨λ���ļ���β��λ��
    long size = ftell(fp);    //����ftell��������ָ��������ļ���ͷ��λ�ã����ֽڼ���
    fclose(fp);
    return size;
}
kk