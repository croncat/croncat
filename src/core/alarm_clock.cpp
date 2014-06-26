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

#include <unistd.h>
#include <time.h>

namespace Core
{
    using namespace std;

    AlarmClock::AlarmClock(int unixTime)
    {
        leftTime = unixTime - getCurrentTime();
        initialize();
    }

    void AlarmClock::initialize()
    {
        if (leftTime > 0) {
            initialized = true;
            timer();
        } else {
            /* leftTime error here */
        }
    }

    int AlarmClock::getCurrentTime()
    {
        int currentTime = time(0);
        return currentTime;
    }

    void AlarmClock::timer()
    {
        if (initialized) {
            sleep (leftTime);
            state = true;
        } else {
            /* initialized error here */
        }
    }

    bool AlarmClock::GetState()
    {
        return state;
    }

}
