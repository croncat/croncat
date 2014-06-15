/*
 * cli.h
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

#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string.h>
#include "features.h"

namespace Cli
{
    void DateTimeFeature(int argc, char *argv[])
    {
        if (argc == 10) {

            if(strncmp(argv[1],"-d", 2) == 0) {

                int hour = atoi(argv[2]);
                int minutes = atoi(argv[3]);
                int seconds = atoi(argv[4]);
                int day = atoi(argv[5]);
                int month = atoi(argv[6]);
                int year = atoi(argv[7]);
                int dst = atoi(argv[8]);

                Features::DateTimeClock(hour, minutes, seconds, day, month, year, dst, argv[9]);

                /* Replace exit(0) with a except mechanism! */
                exit(0);
            }
        }
    }

    void LeftFeature(int argc, char *argv[])
    {
        if (argc == 4) {

            if(strncmp(argv[1],"-l", 2) == 0) {

                int seconds = atoi(argv[2]);

                Features::LeftTime(seconds, argv[3]);

                /* Replace exit(0) with a except mechanism! */
                exit(0);
            }
        }
    }

    void IntervalFeature(int argc, char *argv[])
    {
        if (argc == 5) {

            if(strncmp(argv[1],"-i", 2) == 0)
            {
                int amount = atoi(argv[2]);
                int seconds = atoi(argv[3]);

                Features::IntervalsTime(amount, seconds, argv[4]);

                /* Replace exit(0) with a except mechanism! */
                exit(0);
            }
        }
    }

    void HelpFeature()
    {
        std::cout << "croncat 0.1a [alpha] ( http://github.com/emilianocanedo/croncat )" << std::endl
        << "Usage: ccat [OPTION] {ARGUMENT/S} \"COMMAND\"" << std::endl
        << "OPTIONS:" << std::endl
        << "  -d: time and date (format HOUR MINUTES SECONDS DAY MONTH YEAR DST)" << std::endl
        << "  -i: interval time (format CYCLES SECONDS)" << std::endl
        << "  -l: left time (format SECONDS)" << std::endl
        << "EXAMPLES:" << std::endl
        << "  ccat -d 15 53 30 22 03 2013 0 \"gxmessage hello\"" << std::endl
        << "  ccat -i 3 4000 \"gxmessage hello\"" << std::endl
        << "  ccat -l 4000 \"gxmessage hello\"" << std::endl
        << "croncat: The Portable and Lightweight Time Manager!" << std::endl;

        /* Replace exit(0) with a except mechanism! */
        exit(0);
    }
}

#endif
