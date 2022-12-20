#ifndef __MEMBERCOLLECTION_H__
#define __MEMBERCOLLECTION_H__

#include "Member.h"

#define MAX_NUM_MEMBER 40

using namespace std;

class MemberCollection
{
private:
    Member MemberList[MAX_NUM_MEMBER];
    bool Login;
    bool Reserved;
    int LoginMemberIdx;
    int LoginReserveIdx;
    int MemberNum;
public:
    MemberCollection();
    void GetMember(QString ID, QString PW, QString StudentID);
    int CheckMember(QString ID, QString PW);
    bool CheckMember2(QString StudentID, QString ID);
    void GetLogin(int idx);
    void getLogout();
    bool CheckLogin();
    bool CheckReserved();
    Member* GetLoginMember();
    void refresh(int oldtime);
};

#endif
