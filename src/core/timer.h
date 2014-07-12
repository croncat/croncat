/*
 * core/timer.h
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
#define TIMER_H

#include "tipes.h"

namespace Core
{
    class Timer
    {
        private:   
        int leftTime;
        bool state;
        bool initialized;
        int getCurrentTime();
        void initialize();
        void timer(Seconds seconds);
        void timer(Milliseconds milliseconds);

        public:
        Timer (Milliseconds milliseconds);
        Timer (UnixTime unixtime);
        Timer (Seconds seconds);
        Timer (Minutes minutes);
        Timer (Hours hours);
        Timer (Days days);
        bool GetState();
    };
}

#endif
