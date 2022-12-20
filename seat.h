#ifndef __SEAT_H__
#define __SEAT_H__

#define MAX_SEATS 50

#include "Member.h"

class Seat
{
protected:
    int SeatNum;
    bool Reservation[24];
    Member* ReserveMember[24];

public:
    Seat(int n);
    bool Reserve(int starting, int hours, Member* member);
    int Warn(int time, Member* member);
    bool Cancel(int starting, int hours, Member* member);
    bool isReserved(int n) { return Reservation[n]; }
    void AutoOffReserve(int time);
    Member* GetReserveMember(int n);
};

class SeatCollection
{
private:
    Seat* Seats[MAX_SEATS];

public:
    SeatCollection();
    Seat* GetSeat(int n);
    void refresh(int oldtime);
};

#endif
