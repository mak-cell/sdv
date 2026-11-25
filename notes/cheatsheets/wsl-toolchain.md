# WSL Ubuntu toolchain (VS Code)

Everything builds and debugs inside Ubuntu 24.04 on WSL2, so pthreads, signals,
SocketCAN and kernel modules behave like on a Linux target.

## Open the folder
- VS Code: `F1` -> **WSL: Open Folder in WSL...** -> `/mnt/d/Codes/sdv-study`
- or from an Ubuntu shell: `cd /mnt/d/Codes/sdv-study && code .`
- Bottom-left corner must say **WSL: Ubuntu**. Install `C/C++` (ms-vscode.cpptools)
  in WSL when VS Code prompts (it is per-remote).

## Daily use
| Key | Does |
|---|---|
| `Ctrl+Shift+B` | `gcc -g -O0 -Wall -Wextra -pthread <active file>` -> `build/<name>` |
| `F5` | builds, then runs `build/<name>` under gdb (pick the C or C++ config once in Run and Debug) |
| Terminal -> Run Task -> *Run active file* | build + run without the debugger |
| Run Task -> *C++: build active file* | same with `g++ -std=c++17` |

The debug cwd is the source file's folder.

## Packages
- Base: `sudo apt install build-essential gdb cmake`
- Cortex-M weeks (optional): `sudo apt install gcc-arm-none-eabi gdb-multiarch openocd`
  (USB ST-Link needs `usbipd-win` to attach the probe to WSL.)
