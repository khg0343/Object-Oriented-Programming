#include "Member.h"

void Member::GetMemberInfo(QString get_id, QString get_pw, QString get_stuid)
{
    ID = get_id;
    PW = get_pw;
    StudentID = get_stuid;
    IsLogin = false;
    IsReserve = false;
    IsBreak = false;
    for (int i = 0; i < 24; i++)
    {
        SeatNum[i] = -1;
    }
    WarnCount = 0;
}
void Member::SetSeatNum(int time, int seatnum)
{
    SeatNum[time] = seatnum;
}
bool Member::CheckMemberInfo(QString info, int mode)
{
    switch (mode)
    {
    case 1:      //ID
    {
        if (ID == info)
            return true;
        else
            return false;
    }
    case 2:      //password
    {
        if (PW == info)
            return true;
        else
            return false;
    }
    case 3:      //StudentId
    {
        if (StudentID == info)
            return true;
        else
            return false;
    }
    }
}
void Member::Logio(int mode)
{
    switch (mode)
    {
    case 1: IsLogin = true; break;
    case 2: IsLogin = false; break;
    }
}
void Member::Reserveio(int mode)
{
    switch (mode)
    {
    case 1: IsReserve = true; break;
    case 2: IsReserve = false; break;
    }
}

int Member::Warn()
{
    WarnCount++;
    if (WarnCount < MAX_WARN_COUNT) return 0;
    else
    {
        int i=1;
        int time = QTime::currentTime().hour();
        for(int i=0;i<(GetReserveTime()-time+24)%24;i++)
        {
            SetSeatNum(i,-1);
        }
        IsReserve=false;
        WarnCount=0;
        return 1;
    }
}
void Member::Raon1(int mode)
{
    if(mode == 0)
        IsBreak = true;
    else
        IsBreak = false;
}
void Member::Raon2()
{
    IsReserve = false;
}

bool Member::GetIsReserve() { return IsReserve; }
bool Member::GetIsBreak() { return IsBreak; }
QString Member::GetID() { return ID; }
QString Member::GetPW() { return PW; }
QString Member::GetStudentID() { return StudentID; }
int Member::GetWarncount() { return WarnCount; }
int Member::GetSeatNum() { return SeatNum[QTime::currentTime().hour()]; }
int Member::GetSeatNum(int time) {return SeatNum[time];}
int Member::GetReserveTime()
{
    int seatnum = SeatNum[QTime::currentTime().hour()];
    int i = 1;
    while(SeatNum[(QTime::currentTime().hour()+i)%24] == seatnum)
    {
        i++;
    }
    return (QTime::currentTime().hour()+i)%24;
}
