# DSA01-192511209-Assignment4

**Name:** Jason Joshva M J
**Register number:** 192511209
**Course:** Object Oriented Programming with C++ (DSA01) - Assignment 4 (CO4)
**Compiler:** g++ (write your version here, e.g. `g++ --version` -> g++ 13)
**Compile command used:** `g++ -std=c++17 -Wall -Wextra <file>.cpp -o <name>`
(Task 4 sanitizer builds add `-fsanitize=address -g`; Task 6 is built from `main.cpp`.)

## Folder layout

| Folder | Files | What it covers |
|---|---|---|
| Task01 | `payroll_hierarchy.cpp`, `alt_single_class_switch.cpp` | Repaired payroll hierarchy (1.2), single-class/switch alternative |
| Task02 | `predict_diamond.cpp`, `predict_diamond_nonvirtual.cpp`, `ambiguity_demo.cpp`, `university.cpp`, `access_table_demo.cpp`, `alt_composition.cpp` | Diamond, virtual base, university classes, access table, composition + `sizeof` |
| Task03 | `ctor_dtor_trace.cpp`, `predict_engine.cpp`, `complete_code.cpp`, `complete_code_swapped.cpp`, `alt_pointer_member.cpp` | Constructor/destructor order, member classes, `-DNOVIRTUAL` experiment, `-Wreorder` warning |
| Task04 | `defective.cpp`, `repaired.cpp`, `predict_account.cpp`, `alt_unique_ptr.cpp` | Forensics, ASan/LeakSanitizer, repair, `unique_ptr` |
| Task05 | `cart_four_ways.cpp`, `complete_code.cpp`, `return_by_value_experiment.cpp`, `alt_vector_of_objects.cpp` | Four ways to reach an object, `this`, array-of-pointers search |
| Task06 | `Vehicle.h`, `Fleet.h`, `ElectricBus.h`, `main.cpp`, `alt_switch_vehicle.cpp` | Rental fleet + new type added without editing old classes |

## How to run

Run everything and save every output to `TaskNN/output/*.txt`:

    chmod +x run_all.sh
    ./run_all.sh

Run one task only (recommended, so you can write predictions first):

    ./run_all.sh Task03

Or run any program by hand, e.g.:

    cd Task03
    g++ -std=c++17 -Wall -Wextra ctor_dtor_trace.cpp -o ctor_dtor_trace && ./ctor_dtor_trace
    g++ -std=c++17 -Wall -Wextra -DNOVIRTUAL ctor_dtor_trace.cpp -o ctor_dtor_trace_nv && ./ctor_dtor_trace_nv

Windows: use WSL or MinGW/Git-Bash; if you only have cmd, run the g++ lines manually
(for the sanitizer builds in Task 4, use WSL/Linux - MinGW does not ship ASan).

## Programs where a compile error / warning / sanitizer report is the EXPECTED result

* `Task02/ambiguity_demo.cpp` (no flag): error "request for member 'name' is ambiguous". With `-DFIXED` it compiles.
* `Task03/complete_code_swapped.cpp`: `-Wreorder` warnings, program still runs.
* `Task04/defective.cpp` with `-fsanitize=address`: ASan reports `new-delete-type-mismatch` and aborts.
  Then run with `ASAN_OPTIONS=new_delete_type_mismatch=0 ./defective_asan` to get the leak report.

## Do NOT skip: Predict-the-Output rule

Predictions are credited only if written BEFORE running. Write them on paper/report first for:
`Task02/predict_diamond.cpp` (+ the non-virtual version), `Task03/predict_engine.cpp`, `Task04/predict_account.cpp`.

## Screenshots checklist (one per program, show the command AND the output)

Task01: 2 | Task02: 6 | Task03: 6 (incl. the -Wreorder warning) | Task04: 5 (plain, ASan error, leak report, repaired, predict) | Task05: 4 | Task06: 2

## Suggested commit history (at least one commit per task)

    git init
    git add Task01 && git commit -m "Task 1: payroll hierarchy and switch alternative"
    git add Task02 && git commit -m "Task 2: university hierarchy, virtual base, access table"
    git add Task03 && git commit -m "Task 3: constructor/destructor order and member classes"
    git add Task04 && git commit -m "Task 4: account forensics, sanitizer, repair"
    git add Task05 && git commit -m "Task 5: pointers to objects and this"
    git add Task06 && git commit -m "Task 6: vehicle rental fleet with ElectricBus extension"
    git add README.md run_all.sh && git commit -m "README and run script"

## Result notes (fill in after running)

* Task 1:
* Task 2:
* Task 3:
* Task 4:
* Task 5:
* Task 6:
