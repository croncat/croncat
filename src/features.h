/*
 * features.h
 * Copyright (C) 2014 Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
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

#ifndef FEATURES_H
#define FEATURES_H

#include <ctime>
#include <stdlib.h>
#include "core/tipes.h"
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

        int UNIXtime = timelocal(&fgtime);
        return UNIXtime;
    }

    void DateTimeClock(int hour, int minutes, int seconds, int day, int month, int year, int dst, char *command)
    {
        Core::ServiceMode CtxDaemon;

        int CtxGoalTime = ConvertDateToUnixtime(hour, minutes, seconds, day, month, year, dst);
        Core::UnixTime ctxUnixtime(CtxGoalTime);
        Core::Timer CtxTimer(ctxUnixtime);

        if(CtxTimer.GetState()) {
            system(command);
        }
    }

    void IntervalsTime (int amount, int seconds, char *command)
    {
        Core::ServiceMode CtxDaemon;

        if (amount <= 0)
        {
            while(true)
            {
                Core::Seconds ctxSeconds(seconds);
                Core::Timer CtxTimer(ctxSeconds);

                if(CtxTimer.GetState()) {
                    system(command);
                }
            }
        }
        else
        {
            for (int i = 0; i < amount; i++)
            {
                Core::Seconds ctxSeconds(seconds);
                Core::Timer CtxTimer(ctxSeconds);

                if(CtxTimer.GetState()) {
                    system(command);
                }
            }
        }
    }

    void LeftTime (int seconds, char *command)
    {
        Core::ServiceMode CtxDaemon;

        Core::Seconds ctxSeconds(seconds);
        Core::Timer CtxTimer(ctxSeconds);

        if(CtxTimer.GetState()) {
            system(command);
        }
    }
}

#endif
