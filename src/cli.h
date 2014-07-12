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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "features.h"

namespace Cli
{
    void DateTimeFeature(int argc, char *argv[])
    {
        if (argc == 10 && strncmp(argv[1],"-d", 2) == 0) {

            int hour = atoi(argv[2]);
            int minutes = atoi(argv[3]);
            int seconds = atoi(argv[4]);
            int day = atoi(argv[5]);
            int month = atoi(argv[6]);
            int year = atoi(argv[7]);
            int dst = atoi(argv[8]);

            Features::DateTimeClock(hour, minutes, seconds, day, month, year, dst, argv[9]);

            exit(0);
        }
    }

    void LeftFeature(int argc, char *argv[])
    {
        if (argc == 5 && strncmp(argv[1],"-l", 2) == 0) {

            int intTime = atoi(argv[2]);

            if (strncmp(argv[3],"ms", 2) == 0)
            {
                Features::DelayMilliseconds(intTime, argv[4]);
                exit(0);
            }

            if (strncmp(argv[3],"s", 1) == 0)
            {
                Features::DelaySeconds(intTime, argv[4]);
                exit(0);
            }

            if (strncmp(argv[3],"m", 1) == 0)
            {
                Features::DelayMinutes(intTime, argv[4]);
                exit(0);
            }

            if (strncmp(argv[3],"h", 1) == 0)
            {
                Features::DelayHours(intTime, argv[4]);
                exit(0);
            }

            if (strncmp(argv[3],"d", 1) == 0)
            {
                Features::DelayDays(intTime, argv[4]);
                exit(0);
            }
        }
    }

    void IntervalFeature(int argc, char *argv[])
    {
        if (argc == 6 && strncmp(argv[1],"-i", 2) == 0) {

            int amount = atoi(argv[2]);
            int intTime = atoi(argv[3]);

            if (strncmp(argv[4],"ms", 2) == 0)
            {
                Features::IntervalsMilliseconds(amount, intTime, argv[5]);
                exit(0);
            }

            if (strncmp(argv[4],"s", 1) == 0)
            {
                Features::IntervalsSeconds(amount, intTime, argv[5]);
                exit(0);
            }

            if (strncmp(argv[4],"m", 1) == 0)
            {
                Features::IntervalsMinutes(amount, intTime, argv[5]);
                exit(0);
            }

            if (strncmp(argv[4],"h", 1) == 0)
            {
                Features::IntervalsHours(amount, intTime, argv[5]);
                exit(0);
            }

            if (strncmp(argv[4],"d", 1) == 0)
            {
                Features::IntervalsDays(amount, intTime, argv[5]);
                exit(0);
            }
        }
    }

    void HelpFeature()
    {
        printf("croncat 0.2a [alpha] ( http://github.com/croncat )\n");
        printf("Usage: ccat [OPTION] {ARGUMENT/S} \"COMMAND\"\n");
        printf("OPTIONS:\n");
        printf("  -d: time and date (format HOUR MINUTES SECONDS DAY MONTH YEAR DST)\n");
        printf("  -i: interval time (format CYCLES TIME UNIT[ms, s, m, h, d])\n");
        printf("  -l: left time (format TIME UNIT[ms, s, m, h, d])\n");
        printf("EXAMPLES:\n");
        printf("  ccat -d 15 53 30 22 03 2013 0 \"gxmessage hello\"\n");
        printf("  ccat -i 3 4000 ms \"gxmessage hello\"\n");
        printf("  ccat -i 5 45 m \"gxmessage hello\"\n");
        printf("  ccat -l 30 s \"gxmessage hello\"\n");
        printf("  ccat -l 1 h \"gxmessage hello\"\n");
        printf("croncat: The Portable and Lightweight Time Manager!\n");

        exit(0);
    }
}

#endif
