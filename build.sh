#!/bin/bash
# cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d out -vvv -p publication/publication.xml source/main.ptx -r functions-testing -x debug.rs.dev yes html.quick-dirty yes"
cmd="python /mnt/c/Code/pretext-ascholer/pretext/pretext -f html-incremental -c all -d out -vvv -p publication/publication.xml source/main.ptx -r objects -x debug.rs.dev yes html.build-preview yes"
#cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d published/tourcs -vvv -p publication/publication-runestone.xml source/main.ptx -x debug.rs.dev yes html.quick-dirty yes"
#cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d published/tourcs -vvv -p publication/publication-runestone.xml source/main.ptx"
$cmd
