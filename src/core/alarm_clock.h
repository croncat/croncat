/*
 * core/alarm_clock.h
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
#define ALARM_CLOCK_H

namespace Core
{
    class AlarmClock
    {
        private:
        /* hack this */
        int startTime;
        int courseTime;
        int goalTime;
        bool initialized;
        bool state;
        void getCurrentTime();
        void timer();
        void initialize();

        public:
        AlarmClock(int unixTime);
        bool GetState();
    };
}

#endif