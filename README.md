# C++ Modules 00-09

Ten modules of C++98, from the first class to the implementation of a
merge-insertion sort on top of two different STL containers. Every exercise is
self-contained: its own directory, its own Makefile, its own binary. The
constraint that shapes all of it is the standard itself, C++98, with no access
to `auto`, range-based loops, smart pointers, move semantics or `nullptr`, and
with the printf and malloc families forbidden outright. Memory is managed by
hand, and the orthodox canonical form (default constructor, copy constructor,
copy assignment operator, destructor) is written out explicitly on every class
that owns a resource.

## Modules

| Module | Topic | Exercises | Binaries |
|---|---|---|---|
| CPP00 | Classes, member functions, static members, stdio streams | 3 | `megaphone`, `phoneBook`, `account` |
| CPP01 | Stack versus heap allocation, references, pointers to member functions, file streams | 7 | `zombie`, `horde`, `brain`, `violence`, `losers`, `harl`, `harlFilter` |
| CPP02 | Operator overloading and the orthodox canonical form, on a fixed-point number class | 4 | `fixedPoint`, `fixedPointSecond`, `fixedPointThird`, `bsp` |
| CPP03 | Inheritance, and the diamond problem solved with virtual inheritance | 4 | `clapTrap`, `scavTrap`, `fragTrap`, `diamondTrap` |
| CPP04 | Subtype polymorphism, deep copy, abstract classes and interfaces | 4 | `zoo`, `brainZoo`, `abstractZoo`, `interfaceMateria` |
| CPP05 | Exception classes and an abstract form hierarchy with grade requirements | 4 | `bureaucrat`, `form`, `aform`, `intern` |
| CPP06 | The four C++ casts: scalar conversion, `reinterpret_cast`, `dynamic_cast` identification | 3 | `convert`, `castData`, `identify` |
| CPP07 | Function and class templates, with a bounds-checked array | 3 | `whatever`, `iter`, `array` |
| CPP08 | Templated containers, iterators and algorithms, including an iterable `std::stack` | 3 | `easyfind`, `span`, `mutantStack` |
| CPP09 | STL containers applied: `std::map`, `std::stack`, and Ford-Johnson merge-insertion sort | 3 | `btc`, `RPN`, `PmergeMe` |

Totals: 38 exercises, 195 source files, 8690 lines.

## Build and run

Requirements on the host: a C++ compiler and `make`. Nothing else, no external
libraries. Every Makefile already carries `-Wall -Wextra -Werror -std=c++98`.

```bash
# one exercise
make -C CPP00/ex00
./CPP00/ex00/megaphone "hello world"

# all thirty-eight
for d in CPP*/ex*; do make -C "$d"; done

# the programs that take arguments
./CPP01/ex04/losers file.txt search replace   # writes file.txt.replace
./CPP01/ex06/harlFilter "warning"
./CPP09/ex01/RPN "8 9 * 4 -"
./CPP09/ex02/PmergeMe 3 5 9 7 4

# btc reads data.csv from the working directory, so run it from its own
cd CPP09/ex00 && ./btc input.txt

# cleaning up
for d in CPP*/ex*; do make -C "$d" fclean; done
```

Compiled without a single warning with clang on macOS (arm64) and with g++ 12 on
Debian, both x86_64 and aarch64.

## Repository layout

```
.
├── CPP00/              # classes and member functions
│   ├── ex00/           # each exercise: sources, headers, Makefile
│   ├── ex01/
│   ├── ex02/
│   └── setup_phonebook.sh   # regenerates ex01 from scratch in a new directory
├── CPP01/              # allocation, references, member function pointers
├── CPP02/              # operator overloading, fixed-point arithmetic
├── CPP03/              # inheritance and virtual inheritance
├── CPP04/              # polymorphism, abstract classes, interfaces
├── CPP05/              # exceptions and the form hierarchy
├── CPP06/              # C++ casts
├── CPP07/              # templates (.tpp files hold the definitions)
├── CPP08/              # templated containers and iterators
└── CPP09/              # STL containers
    └── ex00/
        ├── data.csv    # historical bitcoin prices, read by btc
        └── input.txt   # sample query file
```

## Notes

`btc` resolves `data.csv` relative to the working directory, so it has to be
started from `CPP09/ex00`. Running it from the repository root fails to open the
file, by design rather than by accident: the subject specifies the argument as
the input file, not as the database path.

In CPP00/ex02, `Account.hpp` and `tests.cpp` are provided by the subject and are
left exactly as they were given, which is why their formatting differs from the
rest of the repository.

Character signedness is not the same everywhere: `char` is signed on macOS arm64
and on Linux x86_64, unsigned on Linux aarch64. The character classification in
CPP00 and CPP06 was checked on all three, since the same byte reaches `isdigit`
and `toupper` as a negative value on some of them and as a positive one on
others.

`PmergeMe` is a template over the container type, so both required containers
run the same algorithm rather than two parallel implementations. Its Jacobsthal
insertion order comes from a precomputed table: the generator that builds the
sequence at runtime is kept in the file as a commented reference, because the
insertion order never needs more than 31 terms.
