/*
 * Copyright (c)2020 ZeroTier, Inc.
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file in the project's root directory.
 *
 * Change Date: 2025-01-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2.0 of the Apache License.
 */
/****/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>

#include "../../node/Constants.hpp"

#ifdef __WINDOWS__
#include <winsock2.h>
#include <windows.h>
#include <tchar.h>
#include <wchar.h>
#include <lmcons.h>
#include <newdev.h>
#include <atlbase.h>
#include <iphlpapi.h>
#include <iomanip>
#include <shlobj.h>
#include "../../osdep/WindowsEthernetTap.hpp"
#else
#include <unistd.h>
#include <pwd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <dirent.h>
#include <signal.h>
#ifdef __LINUX__
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <sys/ioctl.h>
#ifndef ZT_NO_CAPABILITIES
#include <linux/capability.h>
#include <linux/securebits.h>
#endif
#endif
#endif

#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "../../version.h"

#include "../../node/Identity.hpp"
#include "../../node/CertificateOfMembership.hpp"
#include "../../node/Utils.hpp"
#include "../../node/NetworkController.hpp"
#include "../../node/Buffer.hpp"
#include "../../node/World.hpp"

#include "../../osdep/OSUtils.hpp"
#include "../../osdep/Http.hpp"
#include "../../osdep/Thread.hpp"

#include "../../node/Bond.hpp"

#include "../../service/OneService.hpp"

#include <nlohmann/json.hpp>

#ifdef __APPLE__
#include <SystemConfiguration/SystemConfiguration.h>
#include <CoreServices/CoreServices.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#endif

#include "../../node/Metrics.hpp"
#include "../../osdep/Phy.hpp"
#include "../../tcp-proxy/tcp-proxy.cpp"