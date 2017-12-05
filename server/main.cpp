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
//    aa.test_fun();kj
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

//class TA{
////public:
//    struct S1{
//        int a;
//        int b;
//        int flg;
//    };
//     static int flg;
//     static struct S1 s1;
//     static void sss()
//     {
//           prt(info,"sss");
//     }

//public:

//    TA(){
//        thread *t1=new thread(fun1);
//      //  thread *t1=THREAD_DEF(TA,fun1);
//     //   thread *t2=THREAD_DEF(TA,fun2);
//     //   sss();
//      //  t1->detach();
//      //  t2->detach();
////        t1->join();
////        t2->join();
//    }
//    static void fun1(int i, int p,void * vd){
//        while(1){
//            prt(info,"thread1 %d %d  %d",s1.flg++);
//            this_thread::sleep_for(chrono::seconds(1));
//        }
//    }
//    static void fun2(){
//        while(1){
//               prt(info,"thread2 %d",s1.flg++);
//            this_thread::sleep_for(chrono::seconds(1));
//        }
//    }
//};
//int TA::flg=1;
//struct TA::S1 TA::s1={
//    17,118};
//Camera::data_t Camera::d={};

class MyTool{
    typedef void (*ss)() ;
public:
    static void start_fun(void *fun)
    {
        ss p=(ss)fun;
        p();
    }
};
void test_fun(...)
{
    prt(info,"111");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //        Test1 t1;
    //        t1.test_fun();
    Test *t=new Test();
    //  MyTool::start_fun((void *)test_fun);
    // prt(info,"111");
    //  this_thread::sleep_for(chrono::seconds(3));
    //   delete t;
    prt(info,"loop begin");
    // t.fun111();
    // TA ta;
    //    TA ta1;
    //   ta.s1.a=111;
    //  ta.sss();
    // TA::flg=111;
    return a.exec();
}
//class SString
//{
//public:
//  SString(const char* cstr) { std::cout << "SString()" << std::endl; }

//  // 1
//  SString(const SString& v)
//  { std::cout << "SString(const SString& v)" << std::endl; }

//  // 2
//  SString(const SString&& v) noexcept
//  { std::cout << "SString(const SString&& v)" << std::endl; }

//  // 3
//  SString& operator=(const SString& v)
//  { std::cout << "SString& operator=(const SString& v)" << std::endl; return *this; }
//};

//void ttest(int i, SString const& s) {}

//int main()
//{
//  SString s("hello");
//  std::cout << "----------------" << std::endl;

//  // 输出 1, 2
//  thread t1(ttest, 3, s);
//  t1.join();
//  std::cout << "----------------" << std::endl;

//  // 输出 2, 2
//  std::thread t2(ttest, 3, std::move(s));
//  t2.join();
//  std::cout << "----------------" << std::endl;

//  // 只输出 1
//  std::thread t3(ttest, 3, "hello");
//  t3.join();
//  std::cout << "----------------" << std::endl;

//  // 无输出
//  std::thread t4(ttest, 3, std::ref(s));
//  std::cout << "----------------" << std::endl;
//  t4.join();
//}
