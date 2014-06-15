/*
 * core/alarm_clock.cpp
 * Copyright (C) 2012 Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
 *
 * croncat is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * croncat is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ALARM_CLOCK_H
    #include "alarm_clock.h"
#endif

#include <iostream>
#include <ctime>
#include <unistd.h>

namespace Core
{
    using namespace std;

    AlarmClock::AlarmClock(int unixTime)
    {
        goalTime = unixTime;
        initialize();
    }

    void AlarmClock::initialize()
    {
        if (goalTime > 0)
        {
            initialized = 1;
            getCurrentTime();
            timer();
        }
    }

    void AlarmClock::getCurrentTime()
    {
        if (initialized == 1)
        {
            int current_time = time(0);
            startTime = current_time;
        }
    }

    void AlarmClock::timer()
    {
        if (goalTime > startTime)
        {
            courseTime = goalTime - startTime;
            sleep (courseTime);
            state = true;
        }
    }

    bool AlarmClock::GetState()
    {
        return state;
    }

}
