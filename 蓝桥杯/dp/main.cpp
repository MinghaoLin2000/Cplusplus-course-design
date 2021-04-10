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

/*初始化函数*/
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
        s[i]=s[j];//交换s[i]和s[j]
        s[j]=tmp;
    }
}

bool rc4(std::string key, const char *in_file_name, const char *out_file_name) {
    unsigned char s[ROOM];      //S核心表
    FILE *pr;                      //定义读文件指针pr
    pr = fopen(in_file_name, "rb");    //只读
    if (pr == NULL)                 //如果打开文件错误，则退出
    {
        std::cout << "open fail！" << std::endl;
        return false;
    }

    FILE *pw;                      //定义写文件指针pw
    unsigned char *data;           //存储原始文件数据，并在运算过程中充当输出序列与原序列的异或结果
    long size;
    size = file_size(in_file_name);
    data = (unsigned char *) malloc(size);//分配内存
    memset(data, 0, size);
    FILE* tt = fopen(out_file_name, "rb");    //只读
    if(tt!= NULL){
        fclose(tt);
        if (DeleteFile(out_file_name))//删除成功
            std::cout << out_file_name << " 已成功删除." << std::endl;
        else
            std::cout << out_file_name << " 删除失败" << std::endl;
    }
    pw = fopen(out_file_name, "wb");    //模式为只写且刷新文件

    if (pw == NULL)                            //如果打开文件错误，则退出
    {
        std::cout << "output fail！" << std::endl;
        return false;
    }
    fread(data, sizeof(char), size, pr);//读取二进制流(需要加/解密的文件)
    rc4_init(s, key);      //随机化S表
    int i=0,j=0,t=0;
    unsigned long k=0;
    unsigned char tmp;
    for(k=0;k<size;k++)
    {
        i=(i+1)%256;
         j=(j+s[i])%256;
        tmp=s[i];
        s[i]=s[j];//交换s[x]和s[y]
        s[j]=tmp;
        t=(s[i]+s[j])%256;
        data[k]^=s[t];
    }

    std::cout << "success out " << out_file_name << std::endl;

    fwrite(data, sizeof(unsigned char), size, pw);//写入二进制流
    fclose(pw);//关闭文件流
    fclose(pr);
    free(data);//释放内存
    return true;
}

void decode_dir(const char *dir) {
    //用于查找的句柄
    long handle;
    // 路径末尾追加 '\*.*'
    char newpath[200];
    strcpy(newpath, dir);
    strcat(newpath, "\\*.*");
    _finddata_t findData;
    //第一次查找
    handle = _findfirst(newpath, &findData);
    if (handle == -1) {
        puts("遍历失败");
        return;
    }
    // 遍历文件和文件夹
    while (_findnext(handle, &findData) == 0) {
        // 文件夹
        if (findData.attrib & _A_SUBDIR) {
            // 文件夹名不能有敏感字符 '.'、'..'
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0) { continue; }
            // 进入这个文件夹继续遍历
            strcpy(newpath, dir);
            strcat(newpath, "\\");
            strcat(newpath, findData.name);
            decode_dir(newpath);
            printf("DIR:%s\n", newpath);
        }
            // 文件
        else {
            // 取文件全路径
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

long file_size(const char *filename) //读取文件长度
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return -1;
    fseek(fp, 0L, SEEK_END);    //利用fseek函数将指针定位在文件结尾的位置
    long size = ftell(fp);    //利用ftell函数返回指针相对于文件开头的位置，以字节计算
    fclose(fp);
    return size;
}
kk