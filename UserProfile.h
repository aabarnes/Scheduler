#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QList>
#include "MeetingGroup.h"

class UserProfile
{
public:
    UserProfile();

private:
    int **calendarState;
    QList<MeetingGroup *> groupList;
};

#endif // USERPROFILE_H
