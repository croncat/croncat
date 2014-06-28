/*
 * core/tipes.h
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

#ifndef TIPES_H
#define TIPES_H

namespace Core
{
	class UnixTime
    {
        private:
        int value;

        public:
        UnixTime(int integer) : value(integer) { }
        int ToInt() { return value; }
    };

    class Seconds
    {
        private:
        int value;

        public:
        Seconds(int integer) : value(integer) { }
        int ToInt() { return value; }
    };

    class Minutes
    {
        private:
        int value;

        public:
        Minutes(int integer) : value(integer) { }
        int ToInt() { return value; }
    };

    class Hours
    {
        private:
        int value;

        public:
        Hours(int integer) : value(integer) { }
        int ToInt() { return value; }
    };

    class Days
    {
        private:
        int value;

        public:
        Days(int integer) : value(integer) { }
        int ToInt() { return value; }
    };
}

#endif