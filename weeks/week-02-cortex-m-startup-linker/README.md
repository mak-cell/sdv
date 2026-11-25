# Week 2: Cortex-M startup + linker (restart week, light)

Mon 30 Nov 2026 to Sun 06 Dec 2026

Restart week: each task is about 30 minutes and ends with something small you can see. Doing it at all is the goal.

| Day | Topic | Done |
|---|---|---|
| Mon 30 Nov | [Cortex-M4 registers (ch. 2)](https://developer.arm.com/documentation/dui0553/latest/): write R0-R15, MSP, PSP and xPSR in one line each | [ ] |
| Tue 01 Dec | [Cortex-M4 memory map (ch. 2)](https://developer.arm.com/documentation/dui0553/latest/): draw the map and label Flash, SRAM and peripherals | [ ] |
| Wed 02 Dec | [Vector table (ch. 2)](https://developer.arm.com/documentation/dui0553/latest/): what entries 0 and 1 hold and why | [ ] |
| Thu 03 Dec | [Startup code: what runs before main()](https://www.state-machine.com/video-course): watch the one startup lesson, write 3 bullets | [ ] |
| Fri 04 Dec | [GNU linker scripts](https://sourceware.org/binutils/docs/ld/Scripts.html): read only the MEMORY command, write one FLASH and one RAM line | [ ] |
| Sat 05 Dec | Build (Sat 10:00 to 12:00): leftover from weeks 0-1, struct padding and alignment: print `sizeof` of 3 structs, reorder one to shrink it | [ ] |
| Sun 06 Dec | Teach-back with Claude, 3 interview questions | [ ] |

## Folders
- `notes/`: numbered lesson notes and this week's cheat sheet
- `code/`: exercises (build with VS Code task "C: build active file" or `gcc -Wall -Wextra`)

Wrong quiz answers go in `/mistakes/mistakes-log.md` (one log for all weeks).
