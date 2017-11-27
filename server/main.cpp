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
int test()
{
    int i=10;
    return i;
}
void test1(  int &t)
{
    cout<<t<<endl;
}
class A
{

public:
    A()
    {
        QTimer *t=new QTimer;
        thread *p=THREAD_DEF(A,fun);
    }
    void fun(){

        cout<<"fun"<<endl;
    }
};
A ssss()
{
    A aa;
    return aa;
}
void ttss(const A &tmp)
{

}
class Test1{
    mutex ccmd_list_lock;
public:
    //       Test1(Test1 &&)
    //       {}
    Test1(const Test1 &){}//std:move use copy-constructor
    Test1()=default;//constructor can be: default/delete/self-defined
    Test1(int t){}

    void test_fun()
    {
        std::thread  *fetch_cmd_thread=new std::thread(std::mem_fn(&Test1::fun),*this);
        fetch_cmd_thread->join();
    }

    void fun(){
        cout<<"fun"<<endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //        Test1 t1;
    //        t1.test_fun();
    Test t;
    t.fun111();
    return a.exec();
}
