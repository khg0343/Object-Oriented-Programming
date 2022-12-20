#include "MemberCollection.h"

MemberCollection::MemberCollection()
{
    Login = false;	//로그아웃 상태로 초기화
    MemberNum = 0;	//멤버 수 0로 초기화
}
void MemberCollection::GetMember(QString ID, QString PW, QString StudentID)	//member 추가하는 함수
{
    MemberList[MemberNum].GetMemberInfo(ID, PW, StudentID);	//리스트 마지막에 멤버의 info 입력
    MemberNum++;	//인원수 증가
}

int MemberCollection::CheckMember(QString ID, QString PW)			//member의 ID와 그에 대한 PW가 일치하는지 확인하는 함수
{
    for (int i = 0; i < MemberNum; i++)
    {
        if (MemberList[i].CheckMemberInfo(ID, 1))				//ID 비교
        {
            if (MemberList[i].CheckMemberInfo(PW, 2))	//PW 비교
                return i;								//그 회원의 index값 return
            else
                return -1;								//일치하지 않을 경우 -1 return
        }
    }
    return -1;		//ID가 존재하지않을 경우도 -1 return
}

bool MemberCollection::CheckMember2(QString StudentID, QString ID)				//member와 동일 RRN또는 ID가 존재하는지 확인하는 함수
{
    for (int i = 0; i < MemberNum; i++)
    {
        if (MemberList[i].CheckMemberInfo(StudentID, 3) || MemberList[i].CheckMemberInfo(ID, 1))
            return true;
    }
    return false;
}

void MemberCollection::GetLogin(int idx)		//해당 index의 member 로그인하는 함수
{
    Login = true;
    LoginMemberIdx = idx;
    MemberList[idx].Logio(1);
}
void MemberCollection::getLogout()			//로그인되어있는 member 로그아웃하는 함수
{
    Login = false;
    MemberList[LoginMemberIdx].Logio(2);
    LoginMemberIdx = -1;
}
bool MemberCollection::CheckLogin() { return Login; };	//로그인여부 확인하는 함수
bool MemberCollection::CheckReserved() { return Reserved; };	//로그인여부 확인하는 함수

Member* MemberCollection::GetLoginMember()
{
    return &MemberList[LoginMemberIdx];
}

void MemberCollection::refresh(int oldtime)
{
    for(int i=0;i<MemberNum;i++)
    {
        MemberList[i].SetSeatNum(oldtime,-1);
        MemberList[i].Raon1(1);
    }
}
