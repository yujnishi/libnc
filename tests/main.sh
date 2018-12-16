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
  suites=$suites\ ${t%.c}
done

for s in $suites
do
  echo “    CU_pSuite ${s}_suite;”
done

echo “    CU_initialize_registry();”

for s in $suites
do
  echo “${s}_suite = CU_add_suite(\"${s}\",NULL,NULL);”
  for f in `ctags -x —c-kinds=f ${s}.c`
  do
    echo “    CU_add_test(${s}_suite,\"${f}\",${f});”
  done
done

    
    