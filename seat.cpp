#include "seat.h"
#include <iostream>

using namespace std;

Seat::Seat(int n) : SeatNum(n)
{
    for (int i = 0; i < 24; i++)
    {
        Reservation[i] = false;
    }
}

Member* Seat::GetReserveMember(int n)
{
    if (Reservation[n]) return ReserveMember[n];
    else return nullptr;
}

void Seat::AutoOffReserve(int time)
{
    Reservation[time]=false;
}

bool Seat::Reserve(int starting, int hours, Member* member)
{

    for (int i = 0; i < hours; i++)
    {
        if (Reservation[(starting + i)%24])
        {
            return false;
        }
        if (member->GetSeatNum((starting+i)%24)!=-1)
        {
            return false;
        }
    }
    for (int i = 0; i < hours; i++)
    {
        Reservation[(starting + i)%24] = true;
        ReserveMember[(starting + i)%24] = member;
        member->SetSeatNum((starting+i)%24,SeatNum);
        member->Reserveio(0);
    }
    return true;
}

int Seat::Warn(int time, Member* member)
{
    if (member->GetStudentID() == ReserveMember[time]->GetStudentID())
    {
        return 1;
    }
    else if (!Reservation[time])
    {
        return 2;
    }
    else if (ReserveMember[time]->GetIsBreak())
    {
        return 3;
    }
    else
    {
        int duration = GetReserveMember(time)->GetReserveTime();
        int warn = ReserveMember[time]->Warn();
        if(warn==0)
            return 0;
        else if(warn==1)
        {
            int dur = (duration+24-time)%24;
            Cancel(time,dur,GetReserveMember(time));
            return 0;
        }
        return 0;
    }
}
bool Seat::Cancel(int starting, int duration, Member* member)
{
    for (int i = 0; i < duration; i++)
    {
        if (!Reservation[(starting + i)%24])
        {
            return false;
        }
    }

    for (int i = 0; i < duration; i++)
    {
        Reservation[(starting + i)%24] = false;
        ReserveMember[(starting + i)%24] = nullptr;
        member->SetSeatNum((starting+i)%24,-1);
        member->Reserveio(1);
    }
    return true;
}

SeatCollection::SeatCollection()
{
    for (int i = 0; i < MAX_SEATS; i++)
    {
        Seats[i] = new Seat(i);
    }
}

Seat* SeatCollection::GetSeat(int n)
{
    return Seats[n];
}

void SeatCollection::refresh(int oldtime)
{
    for(int i=0;i<MAX_SEATS;i++)
    {
        Seats[i]->AutoOffReserve(oldtime);
    }
}
