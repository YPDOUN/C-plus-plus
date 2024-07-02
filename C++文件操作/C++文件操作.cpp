#include<iostream>
#include<fstream>
#include<string>
/*
        C++文件操作需要包含头文件<fstream>
        文件操作类: ofstream写操作    ifstream读操作    fstream读写操作
        写文件  
        1.创建流对象ofstream ofs 或 fstream ffs
        2.打开文件 1.调用成员函数 -> ofs.open("filename"); 2.调用构造函数ofstream ofs("filename");
        3.写入信息ofs<<"infomation";
        4.关闭文件ofs.close();

        其中文件打开方式：ios::in/out 默认读/写可以不用写 ios::ate初始在文件尾  ios::app追加  ios::trunc 文件存在便删除再创建
                       ios::binary 二进制写入

        读文件 
        1.创建流对象ifstream ifs 或 fstream ffs
        2.打开文件 同样可以调用open或者直接调用构造函数
        3.判断文件是否打开成功  1.调用成员函数返回bool值 -> ifs.isopen();  2.检查文件流状态，打开失败ifs会被标记为fail state ->if(!ifs)
        4.读取文件  标记在下方
        5.关闭文件
*/


int main()
{
    std::ofstream ofs("myword.txt");
    ofs << "Hello World!";
    ofs.close();

    std::ifstream ifs("myword.txt");

    if (!ifs)
    {
        std::cout << "打开文件失败" << std::endl;
        return 1;
    }
    //1.逐字读取 例如一整个单词
    std::string myword;
    while (ifs >> myword)
        std::cout << myword << std::endl;

    //2.逐字符读取 例如一个单词
    char ch;
    while(ifs.get(ch)) //注意调用类的成员函数get();
        std::cout << ch << std::endl;

    //3.逐行读取 读取一整行信息
    std::string line;
    while (std::getline(ifs, line))//注意调用标准库的getline();
        std::cout << line << std::endl;

    return 0;
}