#!/bin/bash
cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d out -vvv -p publication/publication.xml source/main.ptx -r functions-testing -x debug.rs.dev yes html.quick-dirty yes"
cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d published/tourcs -vvv -p publication/publication-runestone.xml source/main.ptx -r vector-references -x debug.rs.dev yes html.quick-dirty yes"
#cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d published/tourcs -vvv -p publication/publication-runestone.xml source/main.ptx -x debug.rs.dev yes html.quick-dirty yes"
#cmd="python /mnt/f/Programming/pretext/pretext/pretext -f html -c all -d published/tourcs -vvv -p publication/publication-runestone.xml source/main.ptx"
$cmd
