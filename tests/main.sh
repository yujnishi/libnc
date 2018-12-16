#!/bin/bash

#set -vx

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
  echo "    CU_pSuite ${s}_suite;"
done

echo
echo "    CU_initialize_registry();"

for s in $suites
do
  echo "    ${s}_suite = CU_add_suite(\"${s}\",NULL,NULL);"

  for f in `ctags -x --declarations -r '/^test_/' ${s}.c | cut -f1`
  do
    echo "    CU_add_test(${s}_suite,\"${f}\",${f});"
  done
done


cat << EOF
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    CU_automated_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
EOF
