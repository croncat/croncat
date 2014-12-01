/* Copyright (c) 2013, Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * * Neither the name of croncat nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
    Timer::Timer(Milliseconds milliseconds)
    {
        initialize();
        timer(milliseconds);
    }

    Timer::Timer(Seconds seconds)
    {
        initialize();
        timer(seconds);
    }

    Timer::Timer(Minutes minutes)
    {
        Seconds seconds(minutes.ToInt() * 60);
        initialize();
        timer(seconds);
    }

    Timer::Timer(Hours hours)
    {
        Seconds seconds(hours.ToInt() * 3600);
        initialize();
        timer(seconds);
    }

    Timer::Timer(Days days)
    {
        Seconds seconds(days.ToInt() * 86400);
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
                sleep (seconds.ToInt());
                /* struct timespec time;
                time.tv_sec = seconds.ToInt();
                time.tv_nsec = (1000 % seconds.ToInt()) * (1000 * 1000 * 1000);
                nanosleep(&time,NULL); */ 
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
                usleep (milliseconds.ToInt() * 1000);
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
