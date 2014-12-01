/* Copyright (c) 2014, Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
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

#ifndef FEATURES_H
#define FEATURES_H

#include <time.h>
#include <stdlib.h>
#include "core/types.h"
#include "core/timer.h"
#include "core/service_mode.h"

namespace Features
{
    int ConvertDateToUnixtime(int hour, int minutes, int seconds, int day, int mon, int year, int dst)
    {
        tm fgtime;

        fgtime.tm_sec = seconds;
        fgtime.tm_min = minutes;
        fgtime.tm_hour = hour;
        fgtime.tm_mday = day;
        fgtime.tm_mon = mon - 1;
        fgtime.tm_year = year - 1900;
        fgtime.tm_isdst = dst;

        #ifdef __unix__
            return timelocal(&fgtime);
        #elif _WIN32
            return mktime(&fgtime);
        #else
            // others platforms here
        #endif
    }

    void DateTimeClock(int hour, int minutes, int seconds, int day, int month, int year, int dst, void (*action)())
    {
        Core::ServiceMode CtxDaemon;

        Core::UnixTime ctxUnixtime(ConvertDateToUnixtime(hour, minutes, seconds, day, month, year, dst));
        Core::Timer CtxTimer(ctxUnixtime);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void IntervalsMilliseconds (int amount, int milliseconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Milliseconds ctxMilliseconds(milliseconds);

        for (int i = 0; i < amount; i++)
        {
            Core::Timer CtxTimer(ctxMilliseconds);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void IntervalsSeconds (int amount, int seconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Seconds ctxSeconds(seconds);

        for (int i = 0; i < amount; i++)
        {
            Core::Timer CtxTimer(ctxSeconds);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void IntervalsMinutes (int amount, int minutes, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Minutes ctxMinutes(minutes);

        for (int i = 0; i < amount; i++)
        {
            Core::Timer CtxTimer(ctxMinutes);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void IntervalsHours (int amount, int hours, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Hours ctxHours(hours);

        for (int i = 0; i < amount; i++)
        {
            Core::Timer CtxTimer(ctxHours);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void IntervalsDays (int amount, int days, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Days ctxDays(days);

        for (int i = 0; i < amount; i++)
        {
            Core::Timer CtxTimer(ctxDays);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }    

    void DelayMilliseconds (int milliseconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Milliseconds ctxMilliseconds(milliseconds);

        Core::Timer CtxTimer(ctxMilliseconds);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void DelaySeconds (int seconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Seconds ctxSeconds(seconds);

        Core::Timer CtxTimer(ctxSeconds);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void DelayMinutes (int minutes, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Minutes ctxMinutes(minutes);

        Core::Timer CtxTimer(ctxMinutes);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void DelayHours (int hours, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Hours ctxHours(hours);

        Core::Timer CtxTimer(ctxHours);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void DelayDays (int days, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Days ctxDays(days);

        Core::Timer CtxTimer(ctxDays);

        if(CtxTimer.GetState()) {
            (*action)();
        }
    }

    void InfiniteLoopMilliseconds (int milliseconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Milliseconds ctxMilliseconds(milliseconds);

        while(true)
        {
            Core::Timer CtxTimer(ctxMilliseconds);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void InfiniteLoopSeconds (int seconds, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Seconds ctxSeconds(seconds);

        while(true)
        {
            Core::Timer CtxTimer(ctxSeconds);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void InfiniteLoopMinutes (int minutes, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Minutes ctxMinutes(minutes);

        while(true)
        {
            Core::Timer CtxTimer(ctxMinutes);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void InfiniteLoopHours (int hours, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Hours ctxHours(hours);

        while(true)
        {
            Core::Timer CtxTimer(ctxHours);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }

    void InfiniteLoopDays (int days, void (*action)())
    {
        Core::ServiceMode CtxDaemon;
        Core::Days ctxDays(days);

        while(true)
        {
            Core::Timer CtxTimer(ctxDays);

            if(CtxTimer.GetState()) {
                (*action)();
            }
        }
    }
}

#endif
