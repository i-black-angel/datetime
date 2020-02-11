/**
 * Copyright 2020 Shusheng Shao <iblackangel@163.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

namespace mpl {
// FORMAT: [2020-02-11 15:10:27]
std::string now() {
    char buffer[64] = {0x00};
    struct timeval tv;
    gettimeofday(&tv, NULL);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
             localtime(&(tv.tv_sec)));
    return std::string(buffer);
}

// FORMAT: [2020-02-11 15:10:27.628]
std::string now_ms() {
    char buffer[64] = {0x00};
    char msbuf[64] = {0x00};
    struct timeval tv;
    gettimeofday(&tv, NULL);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
             localtime(&(tv.tv_sec)));    
    snprintf(msbuf, sizeof(msbuf) - 1, "%s.%03d", buffer, tv.tv_usec / 1000);
    return std::string(msbuf);
}
}  // namespace mpl

int main(int argc, char *argv[]) {
    printf("mpl::now()\t%s\n", mpl::now().c_str());
    printf("mpl::now_ms()\t%s\n", mpl::now_ms().c_str());
    return 0;
}
