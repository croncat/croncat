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

#ifdef __unix__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#else
    // others platforms here
#endif

#include <time.h>

namespace Core
{
    Timer::Timer(Seconds seconds)
    {
        initialize();
        timer(seconds);
    }

    Timer::Timer(UnixTime unixtime)
    {
        Seconds seconds(unixtime.ToInt() - getCurrentTime());
        initialize();
        timer(seconds);
    }

    void Timer::initialize()
    {
        initialized = true;
    }

    int Timer::getCurrentTime()
    {
        return time(0);
    }

    void Timer::timer(Seconds seconds)
    {
        if (initialized) {
            
            #ifdef __unix__
                struct timespec time;
                time.tv_sec = seconds.ToInt();
                time.tv_nsec = (1000 % seconds.ToInt()) * (1000 * 1000 * 1000);
                nanosleep(&time,NULL); 
            #elif _WIN32
                Sleep (seconds.ToInt() * 1000);
            #else
                // others platforms here
            #endif

            state = true;
        } else {
            /* initialized error here */
        }
    }

    void Timer::timer(Milliseconds milliseconds)
    {
        if (initialized) {
            
            #ifdef __unix__
                struct timespec time;
                time.tv_sec = milliseconds.ToInt();
                time.tv_nsec = (1000 % milliseconds.ToInt()) * (1000 * 1000);
                nanosleep(&time,NULL); 
            #elif _WIN32
                Sleep (milliseconds.ToInt());
            #else
                // others platforms here
            #endif

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
