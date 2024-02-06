# Simple Server-Client Communication Program

## Overview
This program demonstrates a simple form of Inter-Process Communication (IPC) using UNIX signals. The client sends bits to the server one at a time using `SIGUSR1` and `SIGUSR2`, and the server acknowledges receipt of each byte by sending a `SIGUSR1` signal back to the client.
