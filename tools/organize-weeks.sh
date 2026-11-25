#!/usr/bin/env bash
# One-time move of the old layout into weeks/. Run from the repo root in WSL:
#   bash tools/organize-weeks.sh
set -e
cd "$(dirname "$0")/.."
mvf() {  # mvf <src> <dest-dir>: git mv if tracked, plain mv otherwise; skip if missing
  [ -e "$1" ] || return 0
  mkdir -p "$2"
  if git ls-files --error-unmatch "$1" >/dev/null 2>&1; then git mv "$1" "$2/"; else mv "$1" "$2/"; fi
  echo "moved $1 -> $2/"
}
for d in weeks/week-*/; do mkdir -p "$d/notes" "$d/code"; done

W0=weeks/week-00-c-recap-warm-up
W1=weeks/week-01-c-in-depth
for f in notes/month1-c-baremetal/*.md; do mvf "$f" $W0/notes; done
mvf notes/cheatsheets/c-week1.md $W0/notes
mvf notes/cheatsheets/memory-map-output.md $W0/notes
for f in where.c memory_sections.c pointers_hello.c volatile_time_test.c; do mvf code/c-basics/$f $W0/code; done
mvf code/c-basics/Variadic.c $W1/code
mvf notes/cheatsheets/wsl-toolchain.md resources

# compiled programs go to build/ (already git-ignored)
mkdir -p build
for f in code/c-basics/a.out code/c-basics/Var code/c-basics/where; do [ -f "$f" ] && mv "$f" build/ && echo "moved $f -> build/"; done

# remove the old folders only if they are now empty
for d in notes/month1-c-baremetal notes/month2-rtos-autosar notes/month3-uds-safety notes/month4-linux-yocto \
         notes/month5-adaptive-cpp notes/month6-security-ota notes/cheatsheets \
         code/c-basics code/bare-metal code/rtos code/linux code/cpp code; do
  rmdir "$d" 2>/dev/null && echo "removed empty $d" || true
done
echo; echo "Done. Anything left in code/ or notes/cheatsheets was not moved, check it by hand."
for p in weeks resources tools README.md; do [ -e "$p" ] && git add -A -- "$p"; done
git status --short | head -40
