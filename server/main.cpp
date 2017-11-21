#include "test.h"
//static int ttt=1;
//class abcd

//{

//public:
//    abcd() {}
//   //   static int aaa;
//    static void test_fun()
//    {
//      //      aaa++;
//       //     aaa=7;
//    }

//};
//int main()
//{
//    abcd aa;
//    aa.test_fun();
//    ttt=2;
//  //  abcd::aaa=3;
////     abc a;
////    int a1=a.aaa;
////    abc a;
////    a.aaa=123;
// //   Tools::aaaa=23;
//  //  abc a;
// //   a.test_fun();
//   //abc::aaa=1;
// //   abcd::aaa++;
//    Test t;
//    t.fun();
//    return 0;
//}
#include <iostream>
using namespace std;
class Myclass1
{
private:
        int a,b,c;

public:
            static int Sum;    //声明静态数据成员
        Myclass1(){};
};
class Myclass
{
private:
        int a,b,c;

public:
           static int Sum;    //声明静态数据成员
        Myclass(int a,int b,int c);
        void GetSum();
};
int Myclass::Sum=0;       //定义并初始化静态数据成员
int Myclass1::Sum=0;       //定义并初始化静态数据成员
Myclass::Myclass(int a,int b,int c)
{
        this->a=a;
        this->b=b;
        this->c=c;
        Sum+=a+b+c;
}
void Myclass::GetSum()
{
        cout <<"Sum=" <<Sum <<endl;
}
mutex Tools::lock;
//int main(void)
//{
////        Myclass me(10,20,30);
////        me.Sum=123;
////        Myclass1::Sum=1234;
////        me.GetSum();
//    Test t;
//    t.fun111();
//     //   system("pause");
//        return 0;
//}




#include <QCoreApplication>


//int log_level=3;// 1.no log  2.print log 3 print and write log 4.write without print log

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test t;
    t.fun111();

//    Server *p_server=new Server();
//    p_server->print_server_info();
    return a.exec();
}
