/* Copyright (c) 2012, Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
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

#ifndef SERVICE_MODE_H
    #include "service_mode.h"
#endif

#ifdef __unix__
    #include <sys/stat.h>
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#else
    // others platforms here
#endif

#include <stdlib.h>

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
            #ifdef __unix__
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
            #elif _WIN32
                FreeConsole(void);
            #else
                // others platforms here
            #endif
            state = true;
        }
    }

    bool ServiceMode::GetState()
    {
        return state;
    }
}
