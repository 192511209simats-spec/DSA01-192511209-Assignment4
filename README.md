# DSA01-192511209-Assignment4

| | |
|---|---|
| **Name** | Jason Joshva M J |
| **Register number** | 192511209 |
| **Course** | Object Oriented Programming with C++ (DSA01) |
| **Assignment** | Assignment 4 - CO4: Designing Reusable Class Hierarchies |
| **Compiler and version** | MSVC `cl` (Visual Studio ____ , `cl` version ____ ) for Tasks 1-6; g++ ____ (WSL/Linux) for the Task 4 sanitizer runs |
| **Compile command (MSVC)** | `cl /nologo /std:c++17 /EHsc /W4 <file>.cpp` |
| **Compile command (g++)** | `g++ -std=c++17 -Wall -Wextra <file>.cpp -o <name>` |

> Fill in the blanks after running `cl` (it prints its version) and `g++ --version`.

## Repository layout

| Folder | Programs |
|---|---|
| Task01 | `payroll_hierarchy.cpp`, `alt_single_class_switch.cpp` |
| Task02 | `predict_diamond.cpp`, `predict_diamond_nonvirtual.cpp`, `ambiguity_demo.cpp`, `university.cpp`, `access_table_demo.cpp`, `alt_composition.cpp` |
| Task03 | `ctor_dtor_trace.cpp`, `predict_engine.cpp`, `complete_code.cpp`, `complete_code_swapped.cpp`, `alt_pointer_member.cpp` |
| Task04 | `defective.cpp`, `repaired.cpp`, `predict_account.cpp`, `alt_unique_ptr.cpp` |
| Task05 | `cart_four_ways.cpp`, `complete_code.cpp`, `return_by_value_experiment.cpp`, `alt_vector_of_objects.cpp` |
| Task06 | `Vehicle.h`, `Fleet.h`, `ElectricBus.h`, `main.cpp`, `alt_switch_vehicle.cpp` |

Each task folder also contains the output screenshots (`screenshots/`).

## How to run each program

Open **Developer Command Prompt for VS**, `cd` into the task folder, and run:

    set F=/nologo /std:c++17 /EHsc /W4

### Task 1
    cl %F% payroll_hierarchy.cpp && payroll_hierarchy.exe
    cl %F% alt_single_class_switch.cpp && alt_single_class_switch.exe

### Task 2
    cl %F% predict_diamond.cpp && predict_diamond.exe
    cl %F% predict_diamond_nonvirtual.cpp && predict_diamond_nonvirtual.exe
    cl %F% ambiguity_demo.cpp                      (expected: ambiguity error)
    cl %F% /DFIXED ambiguity_demo.cpp /Fe:ambiguity_fixed.exe && ambiguity_fixed.exe
    cl %F% university.cpp && university.exe
    cl %F% access_table_demo.cpp && access_table_demo.exe
    cl %F% alt_composition.cpp && alt_composition.exe

### Task 3
    cl %F% ctor_dtor_trace.cpp && ctor_dtor_trace.exe
    cl %F% /DNOVIRTUAL ctor_dtor_trace.cpp /Fe:trace_novirtual.exe && trace_novirtual.exe
    cl %F% predict_engine.cpp && predict_engine.exe
    cl %F% complete_code.cpp && complete_code.exe
    cl %F% complete_code_swapped.cpp && complete_code_swapped.exe   (expected: reorder warning)
    cl %F% alt_pointer_member.cpp && alt_pointer_member.exe

### Task 4
    cl %F% defective.cpp && defective.exe
    cl %F% repaired.cpp && repaired.exe
    cl %F% predict_account.cpp && predict_account.exe
    cl %F% alt_unique_ptr.cpp && alt_unique_ptr.exe

AddressSanitizer / LeakSanitizer runs (WSL or Linux):

    g++ -std=c++17 -Wall -Wextra -fsanitize=address -g defective.cpp -o defective_asan
    ./defective_asan                                              (new-delete-type-mismatch)
    ASAN_OPTIONS=new_delete_type_mismatch=0 ./defective_asan      (leak report)
    g++ -std=c++17 -Wall -Wextra -fsanitize=address -g repaired.cpp -o repaired_asan && ./repaired_asan   (clean)

### Task 5
    cl %F% cart_four_ways.cpp && cart_four_ways.exe
    cl %F% complete_code.cpp && complete_code.exe
    cl %F% return_by_value_experiment.cpp && return_by_value_experiment.exe
    cl %F% alt_vector_of_objects.cpp && alt_vector_of_objects.exe

### Task 6
    cl %F% main.cpp /Fe:fleet.exe && fleet.exe
    cl %F% alt_switch_vehicle.cpp && alt_switch_vehicle.exe

## Result of each task

* **Task 1:** (write 2-3 lines: deficiencies found, hierarchy used, new category added without editing old classes)
* **Task 2:** (predicted vs actual output of the diamond program; why Person prints once; ambiguity error seen without virtual)
* **Task 3:** (construction/destruction order rule observed; sizeof(TeachingAssistant) virtual vs non-virtual; -Wreorder warning text)
* **Task 4:** (three defects proved: non-virtual rate, missing ~SeniorAccount call, slicing; sanitizer output; repaired program clean)
* **Task 5:** (output 324.00; what happens when add() returns Cart by value; highest-total search result)
* **Task 6:** (each vehicle type rented, late return charged, ElectricBus added without changing existing classes)

## Commit history

One or more commits per task (see `git log`).
