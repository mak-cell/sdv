# SDV study

Plan: 19 Oct 2026 to 16 May 2027. Weeks 0-1 done in Oct; re-dated 25 Nov 2026 so week 2 restarts Mon 23 Nov (day 1) and everything after moved 3 weeks. Tracker: https://mak-cell.github.io/sdv/

## Layout
- `weeks/week-NN-topic/` one folder per week
  - `README.md` the week's daily topics with links and tick boxes
  - `notes/` numbered lesson notes and that week's cheat sheet
  - `code/` that week's exercises
- `mistakes/` one log for all weeks: `mistakes-log.md` (quiz misses), `dsa-log.md` (LeetCode misses)
- `notes/interview-qa/` interview material that spans weeks (DSA track)
- `notes/teach-back/` Sunday teach-back write-ups
- `capstone/` the portfolio project (ECU, gateway, SOME/IP, OTA)
- `resources/` setup notes (WSL toolchain)
- `build/` compiled programs (git-ignored)

Build any file in VS Code with the task "C: build active file", or `gcc -Wall -Wextra file.c -o ../../../build/name`.
