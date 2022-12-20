#ifndef __MEMBER_H__
#define __MEMBER_H__

#include <iostream>
#include <fstream>
#include <QString>
#include <sstream>
#include <QTime>

using namespace std;

#define MAX_WARN_COUNT 3

class Member
{
private:
    QString ID, PW, StudentID;
    bool IsReserve;
    bool IsLogin;   // (login : true, logout : false)
    bool IsBreak;
    int SeatNum[24];
    int WarnCount;

public:
    void GetMemberInfo(QString get_id, QString get_pw, QString get_stuid);  //enter the information of member
    bool CheckMemberInfo(QString info, int mode);   //compare the member information (same = true, not = false)
    bool CheckReserveInfo(int get_time);
    void Logio(int mode);
    void Reserveio(int mode);
    int Warn();
    void Raon1(int mode);
    void Raon2();
    bool GetIsReserve();
    bool GetIsBreak();
    QString GetID();
    QString GetPW();
    QString GetStudentID();
    int GetWarncount();
    int GetSeatNum();
    int GetSeatNum(int time);
    void SetSeatNum(int time, int seatnum);
    int GetTimeSum();
    int GetReserveTime();
};

#endif
