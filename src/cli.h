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
