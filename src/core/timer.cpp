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

#include <ctime>
#include <unistd.h>

namespace Core
{
    using namespace std;

    Timer::Timer(int seconds)
    {
        leftTime = seconds;
        initialize();
    }

    void Timer::initialize()
    {
        if (leftTime > 0)
        {
            initialized = 1;
            getCurrentTime();
            timer();
        }
    }

    bool Timer::getCurrentTime()
    {
        if (initialized == 1)
        {
            time_t currentTime = time(0);
            startTime = currentTime;
            return 1;
        }
        else return 0;
    }

    void Timer::timer()
    {
        if (getCurrentTime() == 1)
        {
            sleep (leftTime);
            state = 1;
        }
    }

    bool Timer::GetState()
    {
        return state;
    }
}
