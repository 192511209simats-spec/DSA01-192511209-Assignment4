#!/usr/bin/env bash
# Compiles and runs every program, saving each output to <Task>/output/<name>.txt
# Usage: ./run_all.sh            -> everything
#        ./run_all.sh Task03     -> only one task (do this AFTER writing your Predict-the-Output answers)
FLAGS="-std=c++17 -Wall -Wextra"
RUNENV=""
ONLY="$1"
cd "$(dirname "$0")"

run() {           # run <task> <name> <extra-flags> <sources...>
  local task=$1 name=$2 extra=$3; shift 3
  if [ -n "$ONLY" ] && [ "$ONLY" != "$task" ]; then return; fi
  mkdir -p "$task/output"
  local out="$task/output/$name.txt"
  {
    echo "\$ g++ $FLAGS $extra $* -o $name"
    ( cd "$task" && g++ $FLAGS $extra "$@" -o "$name" ) 2>&1
    if [ -x "$task/$name" ]; then
      echo "\$ ./$name"
      ( cd "$task" && env $RUNENV ./"$name" ) 2>&1
    else
      echo "(compilation failed - this may be the EXPECTED result for this experiment)"
    fi
  } > "$out" 2>&1
  echo "=== $task / $name ==="; cat "$out"; echo
}

run Task01 payroll_hierarchy        ""                        payroll_hierarchy.cpp
run Task01 alt_single_class_switch  ""                        alt_single_class_switch.cpp

run Task02 predict_diamond              ""                    predict_diamond.cpp
run Task02 predict_diamond_nonvirtual   ""                    predict_diamond_nonvirtual.cpp
run Task02 ambiguity_demo_ERROR         ""                    ambiguity_demo.cpp          # expected: ambiguity error
run Task02 ambiguity_demo_FIXED         "-DFIXED"             ambiguity_demo.cpp
run Task02 university                   ""                    university.cpp
run Task02 access_table_demo            ""                    access_table_demo.cpp
run Task02 alt_composition              ""                    alt_composition.cpp

run Task03 ctor_dtor_trace_virtual      ""                    ctor_dtor_trace.cpp
run Task03 ctor_dtor_trace_NOVIRTUAL    "-DNOVIRTUAL"         ctor_dtor_trace.cpp
run Task03 predict_engine               ""                    predict_engine.cpp
run Task03 complete_code                ""                    complete_code.cpp
run Task03 complete_code_swapped        ""                    complete_code_swapped.cpp   # expected: -Wreorder warning
run Task03 alt_pointer_member           ""                    alt_pointer_member.cpp

run Task04 defective_plain              ""                    defective.cpp          # destructor/rate evidence (no sanitizer)
run Task04 defective_asan_mismatch      "-fsanitize=address -g"  defective.cpp       # ASan aborts: new-delete-type-mismatch
RUNENV="ASAN_OPTIONS=new_delete_type_mismatch=0" run Task04 defective_asan_leak "-fsanitize=address -g" defective.cpp   # leak report
run Task04 repaired                     "-fsanitize=address -g"  repaired.cpp
run Task04 predict_account              ""                    predict_account.cpp
run Task04 alt_unique_ptr               "-fsanitize=address -g"  alt_unique_ptr.cpp

run Task05 cart_four_ways               ""                    cart_four_ways.cpp
run Task05 complete_code                ""                    complete_code.cpp
run Task05 return_by_value_experiment   ""                    return_by_value_experiment.cpp
run Task05 alt_vector_of_objects        ""                    alt_vector_of_objects.cpp

run Task06 rental_fleet                 ""                    main.cpp
run Task06 alt_switch_vehicle           ""                    alt_switch_vehicle.cpp
