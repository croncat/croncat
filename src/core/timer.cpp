/*
 * core/timer.cpp
 * Copyright (C) 2013 Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
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

#ifndef TIMER_H
    #include "timer.h"
#endif

#include <unistd.h>
#include <time.h>

namespace Core
{
    Timer::Timer(Seconds seconds)
    {
        leftTime = seconds.ToInt();
        initialize();
    }

    Timer::Timer(UnixTime unixtime)
    {
        leftTime = unixtime.ToInt() - getCurrentTime();
        initialize();
    }

    void Timer::initialize()
    {
        if (leftTime > 0) {
            initialized = true;
            timer();
        } else {
            /* leftTime error here */
        }
    }

    int Timer::getCurrentTime()
    {
        return time(0);
    }

    void Timer::timer()
    {
        if (initialized) {
            /* Replace with so::Msleep(mseconds) */
            sleep (leftTime);
            state = true;
        } else {
            /* initialized error here */
        }
    }

    bool Timer::GetState()
    {
        return state;
    }
}
