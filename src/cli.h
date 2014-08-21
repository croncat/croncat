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
    char *command;

    void Action()
    {
        system(command);
    }

    void DateTimeFeature(int argc, char *argv[])
    {
        if (argc == 10 && strncmp(argv[1],"-dt", 3) == 0 && strlen(argv[1]) == 3) {

            int hour = atoi(argv[2]);
            int minutes = atoi(argv[3]);
            int seconds = atoi(argv[4]);
            int day = atoi(argv[5]);
            int month = atoi(argv[6]);
            int year = atoi(argv[7]);
            int dst = atoi(argv[8]);
            
            command = argv[9];

            Features::DateTimeClock(hour, minutes, seconds, day, month, year, dst, Action);

            exit(0);
        }
    }

    void DelayFeature(int argc, char *argv[])
    {
        if (argc == 5 && strncmp(argv[1],"-d", 2) == 0 && strlen(argv[1]) == 2) {

            int intTime = atoi(argv[2]);
            command = argv[4];

            if (strncmp(argv[3],"ms", 2) == 0 && strlen(argv[3]) == 2)
            {
                Features::DelayMilliseconds(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"s", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::DelaySeconds(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"m", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::DelayMinutes(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"h", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::DelayHours(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"d", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::DelayDays(intTime, Action);
                exit(0);
            }
        }
    }

    void IntervalFeature(int argc, char *argv[])
    {
        if (argc == 6 && strncmp(argv[1],"-i", 2) == 0 && strlen(argv[1]) == 2) {

            int amount = atoi(argv[2]);
            int intTime = atoi(argv[3]);
            command = argv[5];

            if (strncmp(argv[4],"ms", 2) == 0 && strlen(argv[4]) == 2)
            {
                Features::IntervalsMilliseconds(amount, intTime, Action);
                exit(0);
            }

            if (strncmp(argv[4],"s", 1) == 0 && strlen(argv[4]) == 1)
            {
                Features::IntervalsSeconds(amount, intTime, Action);
                exit(0);
            }

            if (strncmp(argv[4],"m", 1) == 0 && strlen(argv[4]) == 1)
            {
                Features::IntervalsMinutes(amount, intTime, Action);
                exit(0);
            }

            if (strncmp(argv[4],"h", 1) == 0 && strlen(argv[4]) == 1)
            {
                Features::IntervalsHours(amount, intTime, Action);
                exit(0);
            }

            if (strncmp(argv[4],"d", 1) == 0 && strlen(argv[4]) == 1)
            {
                Features::IntervalsDays(amount, intTime, Action);
                exit(0);
            }
        }
    }

    void InfiniteLoop(int argc, char *argv[])
    {
        if (argc == 5 && strncmp(argv[1],"-il", 3) == 0 && strlen(argv[1]) == 3) {

            int intTime = atoi(argv[2]);
            command = argv[4];

            if (strncmp(argv[3],"ms", 2) == 0 && strlen(argv[3]) == 2)
            {
                Features::InfiniteLoopMilliseconds(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"s", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::InfiniteLoopSeconds(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"m", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::InfiniteLoopMinutes(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"h", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::InfiniteLoopHours(intTime, Action);
                exit(0);
            }

            if (strncmp(argv[3],"d", 1) == 0 && strlen(argv[3]) == 1)
            {
                Features::InfiniteLoopDays(intTime, Action);
                exit(0);
            }
        }
    }

    void HelpFeature()
    {
        printf("croncat 0.2b [beta] ( http://github.com/croncat )\n");
        printf("Usage: ccat [OPTION] {ARGUMENT/S} \"COMMAND\"\n");
        printf("OPTIONS:\n");
        printf("  -dt: time and date (format HOUR MINUTES SECONDS DAY MONTH YEAR DST)\n");
        printf("  -i: interval time (format CYCLES TIME UNIT[ms, s, m, h, d])\n");
        printf("  -d: delay (format TIME UNIT[ms, s, m, h, d])\n");
        printf("  -il: infinite loop (format TIME UNIT[ms, s, m, h, d])\n");
        printf("EXAMPLES:\n");
        printf("  ccat -dt 16 01 30 18 07 2014 0 \"gxmessage hello\"\n");
        printf("  ccat -i 3 4000 ms \"gxmessage hello\"\n");
        printf("  ccat -d 30 s \"gxmessage hello\"\n");
        printf("  ccat -il 1 m \"gxmessage hello\"\n");
        printf("croncat: The Portable and Lightweight Time Manager!\n");

        exit(0);
    }
}

#endif
