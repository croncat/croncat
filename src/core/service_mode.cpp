/*
 * core/service_mode.cpp
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

#ifndef SERVICE_MODE_H
    #include "service_mode.h"
#endif

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

namespace Core
{
    using namespace std;

    ServiceMode::ServiceMode()
    {
        state = false;
        start();
    }

    void ServiceMode::start()
    {
        if (!state)
        {
            pid_t pid, sid;
            pid = fork();
            if (pid < 0) exit(EXIT_FAILURE);
            if (pid > 0) exit(EXIT_SUCCESS);
            umask(0);
            sid = setsid();
            if (sid < 0) exit(EXIT_FAILURE);
            if ((chdir("/")) < 0) exit(EXIT_FAILURE);
            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);
            state = true;
        }
    }

    bool ServiceMode::GetState()
    {
        return state;
    }
}
