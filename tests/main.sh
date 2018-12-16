#!/bin/bash

set -vx

cat << EOF
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>

int main() {
EOF

suites=
for t in *.c
do
  suites=$suites\ ${t##.c}
done