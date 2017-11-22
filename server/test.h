#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstring>
#include <mutex>
#include <thread>
#include <bitset>
#include <QtCore>
#include <QUdpSocket>
#include <QNetworkInterface>

using namespace std;

class Tools
{

public:
    enum FIXED_VALUE{
        PATH_LENGTH=200,
        BUF_LENGTH=200
    };
    static mutex lock;
private:
    int cc=0;

    static  char filename[FIXED_VALUE::PATH_LENGTH];
    const int static buf_size=200;

public:

    Tools()
    {
    }
    inline static void prt(const char *buf,const int line_no,const char *func_name,const char *file_name,const char *label,const char *time)
    {
        char buffer[buf_size];
        memset(buffer,0,buf_size);
        memcpy(buffer,time,strlen(time));
        int i;
        for( i=0;buffer[i]!='\n';i++)
            ;
        buffer[i]='\0';

        cout<<'['<<label<<']'<<'['<<buf<<']'<<'['<<file_name<<']'<<'['<<line_no<<']'<<'['<<func_name<<']'<<'['<<buffer<<']'<<endl;

    }
    inline static char* get_time()
    {
        chrono::system_clock::time_point today= chrono::system_clock::now();
        time_t tt= chrono::system_clock::to_time_t(today);
        return ctime(&tt);
    }
    static void init(const char *)
    {
    }
    static int  aaaa;
    static const int ss=123;
    enum test{
        ABC=1,
        BCD=2
    };
    typedef test sss;

    void aaa()
    {



    }
};

class Protocol{
public :
    enum VER{
        VERSION=1
    };
    enum LEN{
        HEAD_LENGTH=8
    };

    enum AABB{
        SS=0,
        PP=1
    };
    enum CMD{
        GET_CONFIG,
        ADD_CAMERA,
        DEL_CAMERA,
        MOD_CAMERA
    };
    enum RET{
        RET_SUCCESS,
        RET_FAIL,
        RET_REFRESH
    };
    enum PORTS{
        SERVER_PORT=12345,
        SERVER_DATA_OUTPUT_PORT=12346,
        CLIENT_REPORTER_PORT=12347,
        SERVER_REPORTER_PORT=12348
    };

    static void pkg_set_len(char *c,int len)//encode length of pkg
    {
        char *dst=c;
        quint16 *p_len=( quint16 *)dst;
        *p_len=len;
    }
    static int pkg_get_len(char *c)//decode length of pkg
    {
        char *dst=c;
        quint16 *p_len=( quint16 *)dst;
        return *p_len;
    }
    static void pkg_set_ret(char *c,int ret)//encode ret of pkg
    {
        char *dst=c+2+2+2;
        quint16 *p_ret=( quint16 *)dst;
        *p_ret=ret;
    }
    static int pkg_get_ret(char *c)//decode ret of pkg
    {
        char *dst=c+2+2+2;
        quint16 *p_ret=( quint16 *)dst;
        return *p_ret;
    }
    static void pkg_set_version(char *c,int version)
    {
        char *dst=c+2;
        quint16 *p_version=( quint16 *)dst;
        *p_version=version;
    }
    static int pkg_get_version(char *c)
    {
        char *dst=c+2;
        quint16 *p_version=( quint16 *)dst;
        return *p_version;
    }
    static void pkg_set_op(char *c,int op)
    {
        char *dst=c+2+2;
        quint16 *p_op=( quint16 *)dst;
        *p_op=op;
    }
    static int pkg_get_op(char *c)
    {
        char *dst=c+2+2;
        quint16 *p_op=( quint16 *)dst;
        return *p_op;
    }

    //    static int pkg_get_len(QByteArray &ba)
    //    {
    //              return 0;
    //    }
    //    static void pkg_set_version(QByteArray &ba)
    //    {

    //    }
    //    static int pkg_get_version(QByteArray &ba)
    //    {
    //              return ba;
    //    }
    //    static void pkg_set_op(QByteArray &ba)
    //    {

    //    }
    //    static int pkg_get_get(QByteArray &ba)
    //    {
    //              return ba;
    //    }



    static int encode_configuration_request(char *buf){
        //   pkg_set_len(ba);
        memset(buf,0,Tools::BUF_LENGTH);
        pkg_set_len(buf,0);
        pkg_set_version(buf,VERSION);
        pkg_set_op(buf,GET_CONFIG);
        pkg_set_ret(buf,RET_SUCCESS);
        return HEAD_LENGTH;
    }
    static int encode_configuration_reply(char *buf,int len,int ret){
        //   pkg_set_len(ba);
        //   memset(buf,0,BUF_MAX_LEN);
        pkg_set_len(buf,len);
        pkg_set_version(buf,VERSION);
        pkg_set_op(buf,GET_CONFIG);
        pkg_set_ret(buf,ret);
        return HEAD_LENGTH;
    }
    static int encode_addcam_request(char *buf,int len){
        //   pkg_set_len(ba);
        memset(buf,0,Tools::BUF_LENGTH);
        pkg_set_len(buf,len);
        pkg_set_version(buf,VERSION);
        pkg_set_op(buf,ADD_CAMERA);
        pkg_set_ret(buf,RET_SUCCESS);
        return HEAD_LENGTH+len;
    }
    static int encode_delcam_request(char *buf,int index){
        //   pkg_set_len(ba);
        memset(buf,0,Tools::BUF_LENGTH);
        pkg_set_len(buf,0);
        pkg_set_version(buf,VERSION);
        pkg_set_op(buf,DEL_CAMERA);
        pkg_set_ret(buf,index);
        return HEAD_LENGTH;
    }
    static int get_operation(char *buf){
        return pkg_get_op(buf);
    }
    static int get_length(char *buf){
        return pkg_get_len(buf);
    }
    static int get_cam_index(char *buf){
        return pkg_get_ret(buf);
    }
};


#define prt(label,...) {Tools::lock.lock(); Tools::init("log.txt"); char buf[1000];sprintf(buf,__VA_ARGS__);\
    Tools::prt(buf,__LINE__,__FUNCTION__,__FILE__,#label,Tools::get_time());Tools::lock.unlock();}

#define THREAD_DEF(cls,fun) new thread(std::mem_fn(&cls::fun),*(cls*)this);




//void fun()
//{

//    try {
//        throw std::invalid_argument("test  error!");
//    }
//    catch (const invalid_argument& ia) {
//        std::cerr << "Invalid argument: " << ia.what() << '\n';
//    }
//}
//#include <mutex>
//using namespace std;
//#include <windows.h>


class TestThread{

    static void thread_fun1()
    {

        //      this_thread::sleep_for(chrono::seconds(10));
        while(1) {

            //        Sleep(1000);
            this_thread::sleep_for(chrono::microseconds(1));
            //  lk.lock();
            prt(info,"thread fun11 ");
            // lk.unlock();
            // cout<<"1"<<endl;
        }

    }
    static void thread_fun2()
    {
        //      this_thread::sleep_for(chrono::seconds(10));


        while(1) {
            //  Sleep(1000);
            this_thread::sleep_for(chrono::microseconds(1));
            //    this_thread::sleep_for(chrono::seconds(1));
            //  lk.lock();
            prt(info,"thread fun22 ");
            // lk.unlock();
            // cout<<"1"<<endl;
        }

    }
public:
    TestThread(){

        //        while(1)
        //        {
        //           //   this_thread::sleep_for(chrono::milliseconds(1000));
        //            Sleep(1000);
        //            cout<<"aa"<<endl;

        //        }
        thread tmp1(thread_fun1);
        thread tmp2(thread_fun2);
        //   tmp.detach();
        //   this_thread::sleep_for(chrono::seconds(1));
        tmp1.join();
        tmp2.join();
    }
    ~TestThread(){}
};


class TestThread1{
public:
    void fun()
    {
        while(1)
        {
            this_thread::sleep_for(chrono::milliseconds(1000));
            //    Sleep(1000);
            cout<<t<<endl;

        }
    }

public:
    TestThread1():t(12){



    }

    int t;
};
class PrintNum1{
public:
    PrintNum1():start(17){}
    void fun()
    {
        while(1)
        {
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout<<start++<<endl;
        }
    }
    void start_thread()
    {
        t=new thread(std::mem_fn(&PrintNum1::fun),*this);
    }
    void stop_thread()
    {
        t->join();
    }
private:
    int start;
    // thread t(std::mem_fn(&PrintNum1::fun),*(PrintNum1 *)obj);
    thread *t;
};
class AThread{
public:
    AThread()
    {

    }

};
class AbstructThread{
public:

    AbstructThread(thread *th):t(th){
        thread_started=1;
        cout<<thread_started<<endl;

        //sss=11;
    }
    //virtual void fun()=0;
    ~AbstructThread()
    {
        //    t->join();
    }
    int is_started()
    {
        cout<<thread_started<<endl;
        return thread_started;
    }

    void start_thread()
    {
        cout<<"thread_started"<<endl;
        thread_started=1;
    }
    void stop_thread()
    {
        cout<<"stoping thread"<<endl;
        thread_started=0;
    }
    void ter()
    {
        t->join();

    }
private:
    // thread t(std::mem_fn(&PrintNum1::fun),*(PrintNum1 *)obj);
    thread *t;
    int thread_started;

    //void *obj;
    //   / int num;
};

class Thread1{
public:
    Thread1(){
        // th=new AbstructThread(  thread(std::mem_fn(&Thread1::fun),*(Thread1*)obj));
        ttt=10;

        // p_thread=new thread(std::mem_fn(&Thread1::fun),*(Thread1*)obj);
        p_thread_fun1=THREAD_DEF(Thread1,fun1);
        p_thread_fun1->detach();
        p_thread_fun2=THREAD_DEF(Thread1,fun2);
        p_thread_fun2->detach();
    }
    void fun1()
    {
        while(1){
            if(1)
            {
                this_thread::sleep_for(std::chrono::milliseconds(10)); //休眠三秒
                cout<<__FUNCTION__<<endl;

            }
            else{
                this_thread::sleep_for(std::chrono::seconds(1)); //休眠三秒
            }
        }
    }
    void fun2()
    {
        while(1){
            if(1)
            {
                this_thread::sleep_for(std::chrono::milliseconds(10)); //休眠三秒
                cout<<__FUNCTION__<<endl;

            }
            else{
                this_thread::sleep_for(std::chrono::seconds(1)); //休眠三秒
            }
        }
    }
    thread *p_thread_fun1;
    thread *p_thread_fun2;
    //    AbstructThread *th;
    int ttt;
};



//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <string.h>
//#include <sys/ioctl.h>
//#include <net/if.h>
//#include <fcntl.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <linux/netlink.h>
//#include <linux/rtnetlink.h>
//#include <errno.h>
////#include <tcp.h>
//#include <sys/ioctl.h>
#define BROADCAST_STR "pedestrian"
/*
    ServerInfoReporter:check port 12348  per sec. if string "pedestrian" recived , send string "ssssss" to the port 12347 of incoming ip
*/

//#include "common.h"
//#include "protocol.h"

class ServerInfoReporter : public QObject{
    Q_OBJECT
public:
    ServerInfoReporter(){
        timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(check_client()));//TODO:maybe replace with readReady signal
        udp_skt = new QUdpSocket(this);
        udp_skt->bind(Protocol::SERVER_REPORTER_PORT,QUdpSocket::ShareAddress);
        timer->start(1000);
    }
    ~ServerInfoReporter()
    {
        delete timer;
        delete udp_skt;
    }

public  slots:
    void check_client()
    {
        QByteArray client_msg;
        char *msg;
        if(udp_skt->hasPendingDatagrams())
        {
            client_msg.resize((udp_skt->pendingDatagramSize()));
            udp_skt->readDatagram(client_msg.data(),client_msg.size());
            prt(info,"msg :%s",msg=client_msg.data());
            if(!strcmp(msg,"pedestrian"))
                send_buffer_to_client();
            //   udp_skt->flush();
        }else{
            prt(debug,"searching client on port %d",Protocol::SERVER_REPORTER_PORT)
        }
    }

    void send_buffer_to_client()
    {
        QByteArray datagram;
        datagram.clear();
        QList <QNetworkInterface>list_interface=QNetworkInterface::allInterfaces();
        foreach (QNetworkInterface i, list_interface) {
            if(i.name()!="lo"){
                QList<QNetworkAddressEntry> list_entry=i.addressEntries();
                foreach (QNetworkAddressEntry e, list_entry) {
                    if(e.ip().protocol()==QAbstractSocket::IPv4Protocol)
                    {
                        datagram.append(QString(e.ip().toString())).append(QString(",")).\
                                append(QString(e.netmask().toString())).append(QString(",")).append(QString(e.broadcast().toString()));
                    }

                }
            }
        }
        udp_skt->writeDatagram(datagram.data(), datagram.size(),
                               QHostAddress::Broadcast, Protocol::CLIENT_REPORTER_PORT);
    }
private:
    QTimer *timer;
    QUdpSocket *udp_skt;
};


#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextStream>
class FileDataBase{
    QByteArray data;
    QString config_filename;
public:
    FileDataBase(QString name):config_filename(name)
    {
       load_config_from_file(config_filename);
    }
    ~FileDataBase()
    {

    }
    QByteArray get()
    {
        return data;
    }
    void set(QByteArray d)
    {
        data=d;
        save_config_to_file();
    }


private:
    int load_config_from_file()
    {

        QFile *f=new QFile(config_filename);
        bool ret = f->open(QIODevice::ReadOnly);
        if(!ret){
            delete f;
            return 0;
        }
        data=f->readAll();
        f->close();
        return 1;
    }
    int load_config_from_file(QString file_name)
    {

        QFile *f=new QFile(file_name);
        bool ret = f->open(QIODevice::ReadOnly);
        if(!ret){
            delete f;
            return 0;
        }
        data=f->readAll();
        f->close();
        return 1;
    }
    void save_config_to_file()
    {
        QFile *f=new QFile(config_filename);
        bool ret = f->open(QIODevice::ReadWrite|QIODevice::Truncate);
        if(!ret){
            prt(info,"fail to open %s",config_filename.toStdString().data());
            delete f;
        }
        f->write(data);
        f->close();
    }
    void save_config_to_file(QString file_name)
    {
        QFile *f=new QFile(file_name);
        bool ret = f->open(QIODevice::ReadWrite|QIODevice::Truncate);
        if(!ret){
            prt(info,"fail to open %s",file_name.toStdString().data());
            delete f;
        }
        f->write(data);
        f->close();
    }
};
class CameraConfiguration{
    /*
        config save in cfg(config_t),which is load from p_database(FileDatabase).
    */
    FileDataBase *p_database;
    typedef struct camera_config{
        QString ip;
        int port;
    }camera_config_t;
    typedef struct config{
        int camera_amount;
        QList<camera_config_t> camera;
    }config_t;
    config_t cfg;
public:
    CameraConfiguration(QString name)
    {
        p_database=new FileDataBase(name);
        QByteArray b=p_database->get();
        cfg=decode_from_json(b);
    }
    ~CameraConfiguration()
    {
        delete p_database;
    }
    void save()
    {
        p_database->set(encode_to_json(cfg));
    }
    void add_camera()
    {

    }
    void append_camera(QString url,int port)
    {

    }

    void del_camera()
    {

    }
    void mod_camera()
    {

    }

private:
    /*
        parse structure from data
    */
    config_t decode_from_json(QByteArray &json_src)
    {
        QJsonDocument json_doc=QJsonDocument::fromJson(json_src);
        QJsonObject root_obj=json_doc.object();
        config_t data;
        data.camera.clear();
        data.camera_amount=get_int(root_obj,"camera_total_number");
        QJsonArray cams=get_child_array(root_obj,"camera");

        foreach (QJsonValue v, cams) {
            QJsonObject obj=v.toObject();
            camera_config_t t;
            t.ip=get_string(obj,"ip");
            t.port=get_int(obj,"port");
            data.camera.append(t);
        }
        return data;
    }
    /*
        pack data from structure
    */
    QByteArray encode_to_json(config_t data)
    {
        QJsonDocument json_doc_new;
        QJsonObject root_obj;

        root_obj["camera_total_number"]=data.camera_amount;
        QJsonArray cams;

        for(int i=0;i<data.camera_amount;i++)
        {
            QJsonObject o;
            o["ip"]=data.camera[i].ip;
            o["port"]=data.camera[i].port;
            cams.append(o);
        }
        root_obj["camera"]=cams;
        json_doc_new.setObject(root_obj);
        return json_doc_new.toJson();

    }

    inline int get_int(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toInt();
    }
    inline QString get_string(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toString();
    }
    inline bool get_bool(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toBool();
    }
    inline QJsonObject get_child_obj(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toObject();
    }
    inline QJsonArray get_child_array(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toArray();
    }
};

class Config
{
    typedef struct camera_data{
        QString ip;
        int port;
    }camera_data_t;
    typedef struct data{
        int camera_amount;
        QList<camera_data_t> camera;
    }data_t;
public:

    Config(char *name)
    {
        config_filename.clear();
        config_filename.append(name);
        load_config_from_file();
    }
    ~Config()
    {

    }




    //    void set_ba(QByteArray ba){
    //        decode_from_json(ba);
    //        save_config_to_file();
    //    }
    //    QByteArray get_ba(){
    //        return encode_to_json();
    //    }
    //    void save(){
    //        save_config_to_file();
    //    }
    //    void append_camera(QString url,int port)
    //    {
    //        camera_data_t cam;
    //        cam.ip=url;
    //        cam.port=port;
    //        data.camera.append(cam);
    //        data.camera_amount++;
    //        save();
    //    }
    //    void del_camera(int index)
    //    {
    //        data.camera.removeAt(index-1);
    //        data.camera_amount--;
    //        save();
    //    }




    int load_config_from_file()
    {

        QFile *f=new QFile(config_filename);
        bool ret = f->open(QIODevice::ReadOnly);
        if(!ret){
            delete f;
            return 0;
        }
        QByteArray json_data;
        json_data=f->readAll();
        decode_from_json(json_data);
        f->close();
        return 1;
    }
    int load_config_from_file(QString file_name)
    {

        QFile *f=new QFile(file_name);
        bool ret = f->open(QIODevice::ReadOnly);
        if(!ret){
            delete f;
            return 0;
        }
        QByteArray json_data;
        json_data=f->readAll();
        decode_from_json(json_data);
        f->close();
        return 1;
    }
    void save_config_to_file()
    {
        QFile *f=new QFile(config_filename);
        bool ret = f->open(QIODevice::ReadWrite|QIODevice::Truncate);
        if(!ret){
            prt(info,"fail to open %s",config_filename.toStdString().data());
            delete f;
        }
        f->write(encode_to_json());
        f->close();
    }
    void save_config_to_file(QString file_name)
    {
        QFile *f=new QFile(file_name);
        bool ret = f->open(QIODevice::ReadWrite|QIODevice::Truncate);
        if(!ret){
            prt(info,"fail to open %s",file_name.toStdString().data());
            delete f;
        }
        f->write(encode_to_json());
        f->close();
    }


private:
    /*
        parse structure from data
    */
    void decode_from_json(QByteArray &json_src)
    {
        QJsonDocument json_doc=QJsonDocument::fromJson(json_src);
        QJsonObject root_obj=json_doc.object();

        data.camera.clear();
        data.camera_amount=get_int(root_obj,"camera_total_number");
        QJsonArray cams=get_child_array(root_obj,"camera");

        foreach (QJsonValue v, cams) {
            QJsonObject obj=v.toObject();
            camera_data_t t;
            t.ip=get_string(obj,"ip");
            t.port=get_int(obj,"port");
            data.camera.append(t);
        }
    }
    QByteArray encode_to_json()
    {
        QJsonDocument json_doc_new;
        QJsonObject root_obj;

        root_obj["camera_total_number"]=data.camera_amount;
        QJsonArray cams;

        for(int i=0;i<data.camera_amount;i++)
        {
            QJsonObject o;
            o["ip"]=data.camera[i].ip;
            o["port"]=data.camera[i].port;
            cams.append(o);
        }
        root_obj["camera"]=cams;
        json_doc_new.setObject(root_obj);
        return json_doc_new.toJson();

    }

    inline int get_int(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toInt();
    }
    inline QString get_string(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toString();
    }
    inline bool get_bool(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toBool();
    }
    inline QJsonObject get_child_obj(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toObject();
    }
    inline QJsonArray get_child_array(QJsonObject obj,const char *member_name)
    {
        return obj[member_name].toArray();
    }
    QString config_filename;
    data_t data;
};
class Test
{
public:
    ServerInfoReporter r;
    Test() {
        Config cfg("/root/repo-github/pedestrian-v12/server/config.json");
        cfg.save_config_to_file(QString("/root/repo-github/pedestrian-v12/server/config.json-test"));

    }
    void fun111()
    {
        //    abcd::test_fun();
        //Tools::aaaa=4;
        //        cout<<Tools::BCD<<endl;
        //        cout<<Tools::sss::ABC<<endl;
        // Tools::prt_time();
        //   http://blog.csdn.net/qq_31175231/article/details/77923212
        //        chrono::milliseconds ms{3};


        //        using namespace std::chrono;
        //        typedef duration<int,std::ratio<60*60*24*356>> days_type;
        //        time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());
        //        std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

        //cout<< Tools::FIXED_VALUE::BUF_LENGTH;
        //   TestThread t;
        //        TestThread1 t1;
        //        thread t(std::mem_fn(&TestThread1::fun),t1);
        //        t.join();

        //        PrintNum p;
        //        p.start_thread(&p);
        //        cout<<"ok1"<<endl;
        //         p.stop_thread();

        //         PrintNum1 p;
        //         p.start_thread();
        //         cout<<"ok1"<<endl;
        //         p.stop_thread();

        //    Thread1 t1;

        //   t1.start_thread();
        //   t1.stop_thread();
        //  this_thread::sleep_for(std::chrono::seconds(3)); //休眠三秒
        //   cout<<"done"<<endl;
        //   t1.stop_thread();


        //    while(1)
        //        ;
        //     ThreadTool1 t1;
        //       t1.start_thread();
        //    cout<<"ok2"<<endl;
        // t1.stop_thread();

        //   Tools::init("aa");
        //  this_thread::sleep_for(std::chrono::seconds(3)); //休眠三秒
        //   prt(info,"the name is %d %s",11,"FDASFASDF" );
    }
};





#endif
